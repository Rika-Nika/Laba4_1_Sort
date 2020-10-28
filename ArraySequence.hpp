#pragma once
#include "Sequence.hpp"
#include "DynamicArray.hpp"
#include "Exception.h"
#include <iostream>



template <class T>
class ArraySequence : public Sequence<T>
{
private:
	DynamicArray<T>* items;
	int count;
public:
	//������� ������ ������
	ArraySequence(const int count = 0)
	{
		int actualCount = count > 0 ? 1.5 * count : 20;
		this->items = new DynamicArray<T>(actualCount);
		this->count = 0;
	}
	//���������� �������� �� ����������� �������
	ArraySequence(T* items, int count) {
		// ��� ���� Exception � DynamicArray
		//if (count < 1) {
		//	throw Exception("Invalid Array Size");
		//}
		this->count = count;
		this->items = new DynamicArray<T>(items, 1.5 * count);
	}

	//���������� �����������
	ArraySequence(const ArraySequence<T>& other) {
		this->count = other.count;
		this->items = new DynamicArray<T>(*other.items);
	};
public:
	//�������� ����� ������
	int GetLength() const override
	{
		int v = this->count;
		return v;
	}
	//�������� ������ ������� � ������
	T GetFirst() const override
	{
		int count = this->count;
		if (count < 1)
			throw Exception("Invalid index");
		//if (this.items[0].HasValue())
		//	return this.items[0].GetValue();
		//throw Exception("Invalid index");
		return this->items->Get(0);
	}
	//�������� ��������� ������� � ������
	T GetLast() const override {
		int count = this->count;
		int size = this->GetLength();
		if (count < 1)
			throw Exception("Invalid index");
		return this->items->Get(size - 1);
	};
	//�������� ������� �� �������
	T Get(const int i) const override {
		if (i < 0 || i >= this->GetLength())
			throw Exception("Invalid index");
		return this->items->Get(i);
	};
	//�������� ������ �� ���� ���������, ������� � startIndex � ���������� endIndex
	//������� � 0.
	Sequence<T>* GetSubsequence(const int start, const int end) const override
	{
		Sequence<T>* subSeq = new ArraySequence <T>();
		for (int i = start; i < end+1; i++) {
			subSeq->Prepend(this->Get(i));
		}
		return subSeq;
	};
	void Print() const override {
		int size = this->GetLength();
		this->items->PrintArray(size);
	}

	bool Equals(const Sequence<T>& sequence) const override {
		if (this == &sequence) return true;
		if (this->GetLength() != sequence.GetLength()) return false;
		for (int i = 0; i < this->GetLength(); i++) {
			return this->items->EqualsItems(sequence.Get(i), this->Get(i));
		}
	}
private:
	int MakeSizeArr(const int curentLength) {
		int sizeArr = curentLength;
		if (sizeArr == 0) {
			sizeArr = 20;
		}
		else if (sizeArr > 0 && sizeArr < 20) {
			sizeArr = 20 + sizeArr;
		}
		return sizeArr;
	}
public:
	//��������� ������� � ������ ������
	void Append(T value) override
	{
		DynamicArray<T>* da = this->items;
		int sizeArr = this->GetLength();
		sizeArr = MakeSizeArr(sizeArr);
		this->items = new DynamicArray<T>((int)(sizeArr) * 1.5);
		this->items->Set(0, value);
		for (int i = 1; i < this->GetLength() + 1; i++) {
			this->items->Set(i, da->Get(i-1));
		}
		this->count = this->GetLength() + 1;
	};
	//��������� ������� � ����� ������
	void Prepend(T value) override {
		int sizeArr = this->GetLength();
		sizeArr = MakeSizeArr(sizeArr);
		DynamicArray<T>* da = this->items;
		if (this->GetLength() >= this->items->GetSize()) {
			this->items = new DynamicArray<T>((int)(sizeArr * 1.5));
			for (int i = 0; i < this->GetLength(); i++) {
				this->items->Set(i, da->Get(i));
			}
		}
		this->items->Set(this->GetLength(), value);
		this->count = this->GetLength() + 1;
	};
	//��������� ������� � �������� �������
	void InsertAt(const int index, T value) override {
		int sizeArr = this->GetLength();
		sizeArr = MakeSizeArr(sizeArr);
		DynamicArray<T>* da = this->items;
		this->items = new DynamicArray<T>((int)(sizeArr * 1.5));
		for (int i = 0; i < this->GetLength() + 1; i++) {
			if (i < index) {
				this->items->Set(i, da->Get(i));
			}
			else if (i > index) {
				this->items->Set(i, da->Get(i - 1));
			}
			else {
				this->items->Set(i, value);
			}
		}
		this->count = this->GetLength() + 1;
	};
	//������� ������� �� �������� �������
	void RemoveAt(const int index) override {
		int sizeArr = this->GetLength();
		Sequence<T> * seq = this->GetSubsequence(index+1, sizeArr-1);
		for (int i = index; i < this->GetLength() - 1; i++) {
			this->items->Set(i, seq->Get(i - index));
		}
		this->count = this->GetLength() - 1;
	};
	//������� ������ ��������� value
	void Remove(T value) override {
		int sizeArr = this->GetLength();
		Sequence<T> * seq = NULL;
		int j = -1;
		for (int i = 0; i < sizeArr; i++) {
			if (this->items->EqualsItems(this->Get(i),value)) {
				j = i;
				seq = this->GetSubsequence(i + 1, sizeArr - 1);
			}
			if (j > -1 and i< sizeArr -1) {
				this->items->Set(i, seq->Get(i-j));
			}
		}
		this->count = this->GetLength() - 1;
	};
	//������� ������
	void RemoveAll() override {
		this->count = 0;

	};
	//�������� ��� ������
	Sequence<T>* Concat(Sequence<T>* other) override
	{
		int size1 = this->GetLength();
		int size2 = other->GetLength();
		Sequence<T>* seq = new ArraySequence <T>(size1 + size2);
		for (int i = 0; i < size1; i++) {
			seq->Prepend(this->Get(i));
		}
		for (int i = size1; i < size1 + size2; i++) {
			seq->Prepend(other->Get(i-size1));
		}
		return seq;
	};
public:
	virtual ~ArraySequence() {}

};
