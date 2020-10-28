#pragma once
#include "Sequence.hpp"

template <typename  T>
class ISorter
{
public:
	virtual Sequence<T>* Sort(Sequence<T>* input) = 0;
protected:
	void Swap(Sequence<T>* seq, int index1, int index2)
	{
		T item = seq->Get(index1);
		seq->Get(index1) = seq->Get(index2);
		seq->Get(index2) = item;
	}
};

template <typename T>
class BubbleSorter : ISorter<T>
{
public:
	virtual Sequence<T>* Sort(Sequence<T>* input) override
	{
		//
		return nullptr;
	}
};