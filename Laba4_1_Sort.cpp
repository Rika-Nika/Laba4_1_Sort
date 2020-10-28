// Laba2_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include"ArraySequence.hpp"
#include"Sequence.hpp"
#include <iostream>
#include "DynamicArray.hpp"
#include "Exception.h"
#include "LinkedList.hpp"
#include "LinkedListSequence.hpp"
#include "Queue.hpp"
//#include "QueueArray.hpp"
#include "QueueLinkedList.hpp"
#include "Sorter.hpp"
void testDinArrGet() {
	const int SIZE = 5;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	try {
		DynamicArray<int>* da = new DynamicArray<int>(testArr, SIZE);
		for (int i = 0; i < SIZE; i++) {
			res = res && (testArr[i] == da->Get(i));
		}
		da->Get(SIZE + 1);
	}
	catch (Exception& exception) {
		if (res) {
			std::cout << "testDinArrGet passed\n";
		}
		else {
			std::cout << "testDinArrGet FAILED\n";
		}
	}

}
void testDinArrGetSize() {
	const int SIZE = 3;
	DynamicArray<int>* da = new DynamicArray<int>(SIZE);
	int v = da->GetSize();
	if (v == SIZE) {
		std::cout << "testDinArrGetSize passed\n";
	}
	else {
		std::cout << "testDinArrGetSize FAILED\n";
	}
}

void testDinArrCreateFromArray() {
	const int SIZE = 5;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	try {
		DynamicArray<int>* da = new DynamicArray<int>(testArr, SIZE);
		for (int i = 0; i < SIZE; i++) {
			res = res && (testArr[i] == da->Get(i));
		}
		if (res) {
			std::cout << "testDinArrCreateFromArray passed\n";
		}
		else {
			std::cout << "testDinArrCreateFromArray FAILED\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testDinArrCreateFromArray FAILED\nException: " << exception.what() << "\n";
	}

}
void testDinArrCreateFromDinArr() {
	const int SIZE = 5;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	try {
		DynamicArray<int>* da = new DynamicArray<int>(testArr, SIZE);
		DynamicArray<int>* da2 = new DynamicArray<int>(*da);
		if (da->Equals(*da2)) {
			std::cout << "testDinArrCreateFromDinArr passed\n";
		}
		else {
			std::cout << "testDinArrCreateFromDinArr FAILED\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testDinArrCreateFromDinArr FAILED\nException: " << exception.what() << "\n";
	}
}
void testDinArrResize() {
	const int SIZE = 5;
	const int SIZE1 = 7;
	const int SIZE2 = 3;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	int testArr1[SIZE1] = { 11, 112, 23, 153, 122222, 0, 0 };
	int testArr2[SIZE2] = { 11, 112, 23 };
	try {
		DynamicArray<int>* da = new DynamicArray<int>(testArr, SIZE);
		DynamicArray<int>* da1 = new DynamicArray<int>(testArr1, SIZE1);
		DynamicArray<int>* da2 = new DynamicArray<int>(testArr2, SIZE2);
		da->Resize(SIZE1);
		if (da->Equals(*da1)) {
			std::cout << "testDinArrResize to large passed\n";
		}
		else {
			std::cout << "testDinArrResize to large FAILED\n";
		}
		da->Resize(SIZE2);
		if (da->Equals(*da2)) {
			std::cout << "testDinArrResize to small passed\n";
		}
		else {
			std::cout << "testDinArrResize to small FAILED\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testDinArrResize FAILED\nexception\nException: " << exception.what() << "\n";
	}
}

void testDinArr() {
	std::cout << "________________ Start testing DynamicArray ________________\n";
	testDinArrGetSize();
	testDinArrCreateFromArray();
	testDinArrGet();
	testDinArrCreateFromDinArr();
	testDinArrResize();
	std::cout << "________________ End testing DynamicArray __________________\n";
}


void testArraySequenceCreateFromArray() {
	int const SIZE = 5;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	try {
		Sequence<int>* seq = new ArraySequence<int>(testArr, SIZE);
		for (int i = 0; i < SIZE; i++) {
			res = res && (testArr[i] == seq->Get(i));
		}
		if (res) {
			std::cout << "testArraySequenceCreateFromArray passed\n";
		}
		else {
			std::cout << "testArraySequenceCreateFromArray FAILED\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testArraySequenceCreateFromArray FAILED\nException: " << exception.what() << "\n";
	}
}

void testArraySequenceGetLength() {
	const int SIZE = 5;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	Sequence<int>* seq = new ArraySequence<int>(testArr, SIZE);
	int v = seq->GetLength();
	if (v == 5) {
		std::cout << "testArraySequenceGetLength passed\n";
	}
	else {
		std::cout << "testArraySequenceGetLength FAILED\n";
	}
}

void testArraySequenceGet() {
	const int SIZE = 5;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	try {
		Sequence<int>* seq = new ArraySequence<int>(testArr, SIZE);
		for (int i = 0; i < SIZE; i++) {
			res = res && (testArr[i] == seq->Get(i));
		}
		seq->Get(SIZE + 1);
	}
	catch (Exception& exception) {
		if (res) {
			std::cout << "testArraySequenceGet passed\n";
		}
		else {
			std::cout << "testArraySequenceGet FAILED\n";
		}
	}

}
void testArraySequenceGetFirst() {
	const int SIZE = 5;
	bool res = true;
	char testArr[SIZE] = { 'sf', 'se','sa', 'sj', 'sc' };
	int v;
	try {
		Sequence<char>* seq = new ArraySequence<char>(testArr, SIZE);
		v = seq->GetFirst();
		if (v == testArr[0]) {
			std::cout << "testArraySequenceGetFirst passed\n";
		}
		else {
			std::cout << "testArraySequenceGetFirst FAILED\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testArraySequenceGetFirst FAILED\nException: " << exception.what() << "\n";
	}
}
void testArraySequenceGetLast() {
	const int SIZE = 5;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	int v;
	try {
		Sequence<int>* seq = new ArraySequence<int>(testArr, SIZE);
		v = seq->GetLast();
		if (v == testArr[SIZE - 1]) {
			std::cout << "testArraySequenceGetLast passed\n";
		}
		else {
			std::cout << "testArraySequenceGetLast FAILED\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testArraySequenceGetLast FAILED\nException: " << exception.what() << "\n";
	}
}
void testArraySequencePrepend() {
	const int SIZE = 5;
	const int START = 2;
	const int END = 4;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	int testArr2[SIZE + 1] = { 11, 112, 23, 153, 122222, 777 };
	try {
		Sequence<int>* seq = new ArraySequence <int>(testArr, SIZE);
		seq->Prepend(777);
		for (int i = 0; i < seq->GetLength(); i++) {
			res = res && (seq->Get(i) == testArr2[i]);
		}
		if (res) {
			std::cout << "testArraySequencePrepend passed\n";
		}
		else {
			std::cout << "testArraySequencePrepend FAILED\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testArraySequencePrepend FAILED\nException: " << exception.what() << "\n";
	}
}

void testArraySequenceAppend() {
	const int SIZE = 5;
	const int START = 2;
	const int END = 4;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	int testArr2[SIZE + 1] = { 777, 11, 112, 23, 153, 122222 };
	try {
		Sequence<int>* seq = new ArraySequence <int>(testArr, SIZE);
		seq->Append(777);
		for (int i = 0; i < seq->GetLength(); i++) {
			res = res && (seq->Get(i) == testArr2[i]);
		}
		if (res) {
			std::cout << "testArraySequenceAppend passed\n";
		}
		else {
			std::cout << "testArraySequenceAppend FAILED\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testArraySequenceAppend FAILED\nException: " << exception.what() << "\n";
	}
}

void testArraySequenceInsertAt() {
	const int SIZE = 5;
	const int INDEX = 2;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	int testArr2[SIZE + 1] = { 11, 112, 777, 23, 153, 122222 };
	try {
		Sequence<int>* seq = new ArraySequence <int>(testArr, SIZE);
		seq->InsertAt(INDEX, 777);
		for (int i = 0; i < seq->GetLength(); i++) {
			res = res && (seq->Get(i) == testArr2[i]);
		}
		if (res) {
			std::cout << "testArraySequenceInsertAt passed\n";
		}
		else {
			std::cout << "testArraySequenceInsertAt FAILED\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testArraySequenceInsertAt FAILED\nException: " << exception.what() << "\n";
	}
}

void testArraySequenceRemoveAt() {
	const int SIZE = 5;
	const int INDEX = 2;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	int testArr2[SIZE - 1] = { 11, 112, 153, 122222 };
	try {
		Sequence<int>* seq = new ArraySequence <int>(testArr, SIZE);
		seq->RemoveAt(INDEX);
		for (int i = 0; i < seq->GetLength(); i++) {
			res = res && (seq->Get(i) == testArr2[i]);
		}
		if (res) {
			std::cout << "testArraySequenceRemoveAt passed\n";
		}
		else {
			std::cout << "testArraySequenceRemoveAt FAILED\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testArraySequenceRemoveAt FAILED\nException: " << exception.what() << "\n";
	}
}

void testArraySequenceRemove() {
	const int SIZE = 5;
	const int item = 23;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	int testArr2[SIZE - 1] = { 11, 112, 153, 122222 };
	try {
		Sequence<int>* seq = new ArraySequence <int>(testArr, SIZE);
		seq->Remove(item);
		for (int i = 0; i < seq->GetLength(); i++) {
			res = res && (seq->Get(i) == testArr2[i]);
		}
		if (res) {
			std::cout << "testArraySequenceRemove passed\n";
		}
		else {
			std::cout << "testArraySequenceRemove FAILED\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testArraySequenceRemove FAILED\nException: " << exception.what() << "\n";
	}
}
void testArraySequenceRemoveAll() {
	const int SIZE = 5;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	Sequence<int>* seq = new ArraySequence <int>(testArr, SIZE);
	seq->RemoveAll();

	if (seq->GetLength() == 0) {
		std::cout << "testArraySequenceRemoveAll passed\n";
	}
	else {
		std::cout << "testArraySequenceRemoveAll FAILED\n";
	}
}

void testArraySequenceConcat() {
	const int SIZE1 = 5;
	const int SIZE2 = 6;
	bool res = true;
	int testArr1[SIZE1] = { 11, 112, 23, 153, 122222 };
	int testArr2[SIZE2] = { 77, 177, 723, 7153, 7122222, 456 };
	int testArr3[SIZE1 + SIZE2] = { 11, 112, 23, 153, 122222, 77, 177, 723, 7153, 7122222, 456 };
	Sequence<int>* seq1 = new ArraySequence <int>(testArr1, SIZE1);
	Sequence<int>* seq2 = new ArraySequence <int>(testArr2, SIZE2);
	Sequence<int>* seq3 = seq1->Concat(seq2);
	//	seq1->PrintArray();
	//	seq2->PrintArray();
	//	seq3->PrintArray();
	if (seq3->GetLength() == SIZE1 + SIZE2) {
		for (int i = 0; i < SIZE1 + SIZE2; i++) {
			res = res && seq3->Get(i) == testArr3[i];
		}
		if (res) std::cout << "testArraySequenceConcat passed\n";
	}
	else {
		std::cout << "testArraySequenceConcat FAILED\n";
	}
}

void testArraySequenceGetSubsequence() {
	const int SIZE = 5;
	const int START = 2;
	const int END = 4;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	try {
		Sequence<int>* seq = new ArraySequence <int>(testArr, SIZE);
		Sequence<int>* subSeq = seq->GetSubsequence(START, END);
		for (int i = 0; i < END - START + 1; i++) {
			res = res && (subSeq->Get(i) == testArr[i + START]);
		}
		if (res) {
			std::cout << "testArraySequenceGetSubsequence passed\n";
		}
		else {
			std::cout << "testArraySequenceGetSubsequence FAILED\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testArraySequenceGetSubsequence FAILED\nException: " << exception.what() << "\n";
	}
}

void testArraySequenceCreateCopy() {
	const int SIZE = 5;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	try {
		ArraySequence<int>* seq = new ArraySequence <int>(testArr, SIZE);
		Sequence<int>* seq2 = new ArraySequence <int>(*seq);
		for (int i = 0; i < SIZE; i++) {
			res = res && (seq->Get(i) == testArr[i]);
		}
		if (res) {
			std::cout << "testArraySequenceCreateCopy passed\n";
		}
		else {
			std::cout << "testArraySequenceCreateCopy FAILED\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testArraySequenceCreateCopy FAILED\nException: " << exception.what() << "\n";
	}
}

void testArraySequence() {
	std::cout << "________________ Start testing ArraySequence _______________\n";
	testArraySequenceGetLength();
	testArraySequenceCreateFromArray();
	testArraySequenceGet();
	testArraySequenceGetFirst();
	testArraySequenceGetLast();
	testArraySequencePrepend();
	testArraySequenceAppend();
	testArraySequenceGetSubsequence();
	testArraySequenceInsertAt();
	testArraySequenceRemoveAt();
	testArraySequenceRemove();
	testArraySequenceRemoveAll();
	testArraySequenceConcat();
	testArraySequenceCreateCopy();
	std::cout << "________________ End testing ArraySequence _________________\n";
}
void testLinkedListCreate() {
	LinkedList<std::string>* ls = new LinkedList<std::string>();
	ls->add_node("List Created");

	ls->printList();
};

void testLinkedListGetFirst() {

	LinkedList <int>* first = new LinkedList <int>();
	int n = 100;
	for (int i = 0; i < n; i++) {
		first->add_node(i);
	}
	int f = first->GetFirst();
	if (f == 0) {
		std::cout << "testLinkedListGetFirst passed\n";
	}
	else {
		std::cout << "testLinkedListGetFirst FAILED\n";
	}
	LinkedList <int>* empty = new LinkedList <int>();
	try
	{
		int f = empty->GetFirst();
		std::cout << "testLinkedListGetFirst Exeption FAILED\n";
	}
	catch (Exception& exception)
	{
		std::cout << "testLinkedListGetFirst Exeption passed\n";
	};
};

void testLinkedListCopy() {
	const int SIZE = 5;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	try {
		LinkedList<int>* ls = new LinkedList<int>(testArr, SIZE);
		LinkedList<int>* ls2 = new LinkedList<int>(*ls);
		if (ls->Equals(*ls2)) {
			std::cout << "testLinkedListCopy passed\n";
		}
		else {
			std::cout << "testLinkedListCopy FAILED\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testLinkedListCopy FAILED\nException: " << exception.what() << "\n";
	}
}

void testLinkedListGetLast() {

	LinkedList <int>* last = new LinkedList <int>();
	int n = 100;
	for (int i = 0; i < n; i++) {
		last->add_node(i);
	}
	int l = last->GetLast();
	if (l == 99) {
		std::cout << "testLinkedListGetLast passed\n";
	}
	else {
		std::cout << "testLinkedListGetLast FAILED\n";
	}
	LinkedList <int>* empty = new LinkedList <int>();
	try
	{
		int l = empty->GetLast();
		std::cout << "testLinkedListGetLast Exeption FAILED\n";
	}
	catch (Exception& exception)
	{
		std::cout << "testLinkedListGetLast Exeption passed\n";
	};
};

void testLinkedListGetSize() {

	LinkedList <int>* first = new LinkedList <int>();
	int n = 100;
	for (int i = 0; i < n; i++) {
		first->add_node(i);
	}
	int f = first->GetSize();
	if (f == 100) {
		std::cout << "testLinkedListGetSize passed\n";
	}
	else {
		std::cout << "testLinkedListGetSize FAILED\n";
	}
};

void testLinkedListGetNth()
{
	LinkedList <int>* Nth = new LinkedList <int>();
	int n = 100;
	for (int i = 0; i < n; i++) {
		Nth->add_node(i);
	}
	int a = Nth->GetNth(10);
	if (a == 10) {
		std::cout << "testLinkedListGetNth passed\n";
	}
	else {
		std::cout << "testLinkedListGetNth FAILED\n";
	}
	LinkedList <int>* empty = new LinkedList <int>();
	try
	{
		int a = empty->GetNth(10);
		std::cout << "testLinkedListGetNth Exeption FAILED\n";
	}
	catch (Exception& exception)
	{
		std::cout << "testLinkedListGetNth Exeption passed\n";
	};

};

void testLinkedListAppend()
{
	const int SIZE = 7;
	bool res = true;
	int testArr[SIZE] = { 100, -100, 0, 1, 2, 3, 4 };
	LinkedList <int>* ls = new LinkedList <int>();
	ls->Append(-100);
	int n = 5;
	for (int i = 0; i < n; i++) {
		ls->add_node(i);
	}
	ls->Append(100);
	for (int i = 0; i < SIZE; i++) {
		res = res && ls->EqualsItem(testArr[i], ls->GetNth(i));
	}
	if (res) {
		std::cout << "testLinkedListAppend passed\n";
	}
	else {
		std::cout << "testLinkedListAppend FAILED\n";
	}
};

void testLinkedListPrepend()
{

	const int SIZE = 7;
	bool res = true;
	int testArr[SIZE] = { -100, 0, 1, 2, 3, 4, 100 };
	LinkedList <int>* ls = new LinkedList <int>();
	ls->Prepend(-100);
	int n = 5;
	for (int i = 0; i < n; i++) {
		ls->add_node(i);
	}
	ls->Prepend(100);
	//ls->printList();
	for (int i = 0; i < SIZE; i++) {
		res = res && ls->EqualsItem(testArr[i], ls->GetNth(i));
	}
	if (res) {
		std::cout << "testLinkedListPrepend passed\n";
	}
	else {
		std::cout << "testLinkedListPrepend FAILED\n";
	}
};

void testLinkedListInsertAt()
{

	const int SIZE = 6;
	bool res = true;
	int testArr[SIZE] = { 0, 1, 2, 100, 3, 4 };
	LinkedList <int>* ls = new LinkedList <int>();
	int n = 5;
	for (int i = 0; i < n; i++) {
		ls->add_node(i);
	}
	ls->InsertAt(100, 3);
	//ls->printList();
	for (int i = 0; i < SIZE; i++) {
		res = res && ls->EqualsItem(testArr[i], ls->GetNth(i));
	}
	if (res) {
		std::cout << "testLinkedListInsertAt passed\n";
	}
	else {
		std::cout << "testLinkedListInsertAt FAILED\n";
	}
	try {
		ls->InsertAt(100, 100);
		std::cout << "testLinkedListInsertAt Exeption FAILED\n";
	}
	catch (Exception& exception)
	{
		std::cout << "testLinkedListInsertAt Exeption passed\n";
	}
};


void testLinkedListGetSubList()
{
	const int SIZE = 4;
	bool res = true;
	int testArr[SIZE] = { 2, 3, 4, 5 };
	LinkedList <int>* ls = new LinkedList <int>();
	LinkedList <int>* ls2 = NULL;
	for (int i = 0; i < SIZE + 12; i++) {
		ls->add_node(i);
	}
	//ls->printList();
	ls2 = ls->GetSubList(2, 5);
	//ls2->printList();
	for (int i = 0; i < 1; i++) {
		res = res && ls2->EqualsItem(testArr[i], ls2->GetNth(i));
	}
	if (res) {
		std::cout << "testLinkedListGetSubList passed\n";
	}
	else {
		std::cout << "testLinkedListGetSubList FAILED\n";
	}
	try {
		ls->GetSubList(-1, 5);
		std::cout << "testLinkedListGetSubList Exeption FAILED\n";
	}
	catch (Exception& exception)
	{
		std::cout << "testLinkedListGetSubList Exeption passed\n";
	}

}

void testLinkedListConcat()
{
	const int SIZE1 = 4;
	const int SIZE2 = 5;
	const int SIZE3 = 9;
	bool res = true;
	int testArr1[SIZE1] = { 0, 1, 2, 3 };
	int testArr2[SIZE2] = { 4, 5, 6, 7, 8 };
	int testArr3[SIZE3] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	LinkedList <int>* ls1 = new LinkedList <int>();
	LinkedList <int>* ls2 = new LinkedList <int>();
	LinkedList <int>* ls3;

	for (int i = 0; i < SIZE1; i++) {
		ls1->add_node(i);
	}
	//ls1->printList();
	for (int i = SIZE1; i < SIZE1 + SIZE2; i++) {
		ls2->add_node(i);
	}
	//ls2->printList();
	ls3 = ls1->Concat(ls2);
	//ls3->printList();
	for (int i = 0; i < SIZE3; i++) {
		res = res && ls3->EqualsItem(testArr3[i], ls3->GetNth(i));
	}
	if (res) {
		std::cout << "testLinkedListConcat passed\n";
	}
	else {
		std::cout << "testLinkedListConcat FAILED\n";
	}
};


void testLinkedListCreateFromArray() {
	const int SIZE = 5;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	try {
		LinkedList<int>* da = new LinkedList<int>(testArr, SIZE);
		for (int i = 0; i < SIZE; i++) {
			res = res && (testArr[i] == da->GetNth(i));
		}
		if (res) {
			std::cout << "testLinkedListCreateFromArray passed\n";
		}
		else {
			std::cout << "testLinkedListCreateFromArray FAILED\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testLinkedListCreateFromArray FAILED\nException: " << exception.what() << "\n";
	}
}
void testLinkedListRemoveAt() {
	const int SIZE = 5;
	const int INDEX = 2;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	int testArr2[SIZE - 1] = { 11, 112, 153, 122222 };
	try {
		LinkedList<int>* seq = new LinkedList <int>(testArr, SIZE);
		seq->RemoveAt(INDEX);
		for (int i = 0; i < seq->GetSize(); i++) {
			res = res && (seq->GetNth(i) == testArr2[i]);
		}
		if (res) {
			std::cout << "testLinkedListRemoveAt passed\n";
		}
		else {
			std::cout << "testLinkedListRemoveAt FAILED\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testLinkedListRemoveAt FAILED\nException: " << exception.what() << "\n";
	}
}

void testLinkedListRemoveAll() {
	const int SIZE = 5;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	LinkedList<int>* seq = new LinkedList <int>(testArr, SIZE);
	seq->RemoveAll();

	if (seq->GetSize() == 0) {
		std::cout << "testLinkedListRemoveAll passed\n";
	}
	else {
		std::cout << "testLinkedListRemoveAll FAILED\n";
	}
}

void testLinkedListRemove() {
	const int SIZE = 5;
	const int item = 23;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	int testArr2[SIZE - 1] = { 11, 112, 153, 122222 };
	try {
		LinkedList<int>* seq = new LinkedList <int>(testArr, SIZE);
		seq->Remove(item);
		for (int i = 0; i < seq->GetSize(); i++) {
			res = res && (seq->GetNth(i) == testArr2[i]);
		}
		if (res) {
			std::cout << "testLinkedListRemove passed\n";
		}
		else {
			std::cout << "testLinkedListRemove FAILED\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testLinkedListRemove FAILED\nException: " << exception.what() << "\n";
	}
}

void testLinkedList() {
	std::cout << "________________ Start testing testLinkedList ______________\n";
	testLinkedListCreate();
	testLinkedListGetFirst();
	testLinkedListGetLast();
	testLinkedListGetSize();
	testLinkedListGetNth();
	testLinkedListAppend();
	testLinkedListPrepend();
	testLinkedListInsertAt();
	testLinkedListConcat();
	testLinkedListGetSubList();
	testLinkedListCopy();
	testLinkedListCreateFromArray();
	testLinkedListRemoveAt();
	testLinkedListRemoveAll();
	testLinkedListRemove();

	std::cout << "________________ End testing testLinkedList ________________\n";
}
void testLinkedListSequenceCreateFromArray() {
	const int SIZE = 5;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	Sequence<int>* sq = new LinkedListSequence<int>(testArr, SIZE);
	int v = sq->GetLength();
	//sq->Print();
	for (int i = 0; i < SIZE; i++) {
		res = res && testArr[i] == sq->Get(i);
	}
	if (v == SIZE) {
		std::cout << "testLinkedListSequenceCreateFromArray passed\n";
	}
	else {
		std::cout << "testLinkedListSequenceCreateFromArray FAILED\n";
	}

};

void testLinkedListSequenceGetLength() {
	const int SIZE = 5;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	Sequence<int>* sq = new LinkedListSequence<int>(testArr, SIZE);

	int v = sq->GetLength();
	if (v == SIZE) {
		std::cout << "testLinkedListSequenceGetLength passed\n";
	}
	else {
		std::cout << "testLinkedListSequenceGetLength FAILED\n";
	}

};

void testLinkedListSequenceGetFirst() {
	const int SIZE = 5;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	int v;
	try {
		Sequence<int>* seq = new LinkedListSequence<int>(testArr, SIZE);
		v = seq->GetFirst();
		if (v == testArr[0]) {
			std::cout << "testLinkedListSequenceGetFirst passed\n";
		}
		else {
			std::cout << "testLinkedListSequenceGetFirst FAILED\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testLinkedListSequenceGetFirst FAILED\nException: " << exception.what() << "\n";
	}
}
void testLinkedListSequenceGetLast() {
	const int SIZE = 5;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	int v;
	try {
		Sequence<int>* seq = new LinkedListSequence<int>(testArr, SIZE);
		v = seq->GetLast();
		if (v == testArr[SIZE - 1]) {
			std::cout << "testLinkedListSequenceGetLast passed\n";
		}
		else {
			std::cout << "testLinkedListSequenceGetLast FAILED\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testLinkedListSequenceGetLast FAILED\nException: " << exception.what() << "\n";
	}
}

void testLinkedListSequenceGet() {
	const int SIZE = 5;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	try {
		Sequence<int>* seq = new LinkedListSequence<int>(testArr, SIZE);
		for (int i = 0; i < SIZE; i++) {
			res = res && (testArr[i] == seq->Get(i));
		}
		seq->Get(SIZE + 1);
	}
	catch (Exception& exception) {
		if (res) {
			std::cout << "testLinkedListSequenceGet passed\n";
		}
		else {
			std::cout << "testLinkedListSequenceGet FAILED\n";
		}
	}

}

void testLinkedListSequencePrepend() {
	const int SIZE = 5;
	const int START = 2;
	const int END = 4;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	int testArr2[SIZE + 1] = { 11, 112, 23, 153, 122222, 777 };
	try {
		Sequence<int>* seq = new LinkedListSequence <int>(testArr, SIZE);
		seq->Prepend(777);
		for (int i = 0; i < seq->GetLength(); i++) {
			res = res && (seq->Get(i) == testArr2[i]);
		}
		if (res) {
			std::cout << "testLinkedListSequencePrepend passed\n";
		}
		else {
			std::cout << "testLinkedListSequencePrepend FAILED\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testLinkedListSequencePrepend FAILED\nException: " << exception.what() << "\n";
	}


}


void testLinkedListSequenceAppend() {
	const int SIZE = 5;
	const int START = 2;
	const int END = 4;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	int testArr2[SIZE + 1] = { 777, 11, 112, 23, 153, 122222 };
	try {
		Sequence<int>* seq = new LinkedListSequence <int>(testArr, SIZE);
		seq->Append(777);
		for (int i = 0; i < seq->GetLength(); i++) {
			res = res && (seq->Get(i) == testArr2[i]);
		}
		if (res) {
			std::cout << "testLinkedListSequenceAppend passed\n";
		}
		else {
			std::cout << "testLinkedListSequenceAppend FAILED\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testLinkedListSequenceAppend FAILED\nException: " << exception.what() << "\n";
	}
}

void testLinkedListSequenceConcat() {
	const int SIZE1 = 5;
	const int SIZE2 = 6;
	bool res = true;
	int testArr1[SIZE1] = { 11, 112, 23, 153, 122222 };
	int testArr2[SIZE2] = { 77, 177, 723, 7153, 7122222, 456 };
	int testArr3[SIZE1 + SIZE2] = { 11, 112, 23, 153, 122222, 77, 177, 723, 7153, 7122222, 456 };
	Sequence<int>* seq1 = new LinkedListSequence <int>(testArr1, SIZE1);
	Sequence<int>* seq2 = new LinkedListSequence <int>(testArr2, SIZE2);
	Sequence<int>* seq3 = seq1->Concat(seq2);

	if (seq3->GetLength() == SIZE1 + SIZE2) {
		for (int i = 0; i < SIZE1 + SIZE2; i++) {
			res = res && seq3->Get(i) == testArr3[i];
		}
		if (res) std::cout << "testArraySequenceConcat passed\n";
	}
	else {
		std::cout << "testArraySequenceConcat FAILED\n";
	}
}

void testLinkedListSequenceGetSubsequence() {
	const int SIZE = 5;
	const int START = 2;
	const int END = 4;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	try {
		Sequence<int>* seq = new LinkedListSequence <int>(testArr, SIZE);
		Sequence<int>* subSeq = seq->GetSubsequence(START, END);
		for (int i = 0; i < END - START + 1; i++) {
			res = res && (subSeq->Get(i) == testArr[i + START]);
		}
		if (res) {
			std::cout << "testLinkedListSequenceGetSubsequence passed\n";
		}
		else {
			std::cout << "testLinkedListSequenceGetSubsequence FAILED\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testLinkedListSequenceGetSubsequence FAILED\nException: " << exception.what() << "\n";
	}
}
void testLinkedListSequenceInsertAt() {
	const int SIZE = 5;
	const int INDEX = 2;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	int testArr2[SIZE + 1] = { 11, 112, 777, 23, 153, 122222 };
	try {
		Sequence<int>* seq = new LinkedListSequence <int>(testArr, SIZE);
		seq->InsertAt(INDEX, 777);
		for (int i = 0; i < seq->GetLength(); i++) {
			res = res && (seq->Get(i) == testArr2[i]);
		}
		if (res) {
			std::cout << "testLinkedListSequenceInsertAt passed\n";
		}
		else {
			std::cout << "testLinkedListSequenceInsertAt FAILED\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testLinkedListSequenceInsertAt FAILED\nException: " << exception.what() << "\n";
	}


}

void testLinkedListSequenceRemoveAt() {
	const int SIZE = 5;
	const int INDEX = 2;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	int testArr2[SIZE - 1] = { 11, 112, 153, 122222 };
	try {
		Sequence<int>* seq = new LinkedListSequence <int>(testArr, SIZE);
		seq->RemoveAt(INDEX);
		for (int i = 0; i < seq->GetLength(); i++) {
			res = res && (seq->Get(i) == testArr2[i]);
		}
		if (res) {
			std::cout << "testLinkedListSequenceRemoveAt passed\n";
		}
		else {
			std::cout << "testLinkedListSequenceRemoveAt FAILED\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testLinkedListSequenceRemoveAt FAILED\nException: " << exception.what() << "\n";
	}
}

void testLinkedListSequenceRemoveAll() {
	const int SIZE = 5;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	Sequence<int>* seq = new LinkedListSequence <int>(testArr, SIZE);
	seq->RemoveAll();

	if (seq->GetLength() == 0) {
		std::cout << "testLinkedListSequenceRemoveAll passed\n";
	}
	else {
		std::cout << "testLinkedListSequenceRemoveAll FAILED\n";
	}
}

void testLinkedListSequenceRemove() {
	const int SIZE = 5;
	const int item = 23;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	int testArr2[SIZE - 1] = { 11, 112, 153, 122222 };
	try {
		Sequence<int>* seq = new LinkedListSequence <int>(testArr, SIZE);
		seq->Remove(item);
		for (int i = 0; i < seq->GetLength(); i++) {
			res = res && (seq->Get(i) == testArr2[i]);
		}
		if (res) {
			std::cout << "testLinkedListSequenceRemove passed\n";
		}
		else {
			std::cout << "testLinkedListSequenceRemove FAILED\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testLinkedListSequenceRemove FAILED\nException: " << exception.what() << "\n";
	}

}

void testLinkedListSequenceCreateCopy() {
	const int SIZE = 5;
	bool res = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	try {
		LinkedListSequence<int>* seq = new LinkedListSequence <int>(testArr, SIZE);
		Sequence<int>* seq2 = new LinkedListSequence <int>(*seq);
		for (int i = 0; i < SIZE; i++) {
			res = res && (seq->Get(i) == testArr[i]);
		}
		if (res) {
			std::cout << "testLinkedListSequenceCreateCopy passed\n";
		}
		else {
			std::cout << "testLinkedListSequenceCreateCopy FAILED\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testLinkedListSequenceCreateCopy FAILED\nException: " << exception.what() << "\n";
	}
}

void testLinkedListSequence() {
	std::cout << "________________ Start testing LinkedListSequence _______________\n";
	testLinkedListSequenceGetLength();
	testLinkedListSequenceCreateFromArray();
	testLinkedListSequenceGet();
	testLinkedListSequenceGetFirst();
	testLinkedListSequenceGetLast();
	testLinkedListSequencePrepend();
	testLinkedListSequenceAppend();
	testLinkedListSequenceGetSubsequence();
	testLinkedListSequenceInsertAt();
	testLinkedListSequenceRemoveAt();
	testLinkedListSequenceRemove();
	testLinkedListSequenceRemoveAll();
	testLinkedListSequenceConcat();
	testLinkedListSequenceCreateCopy();
	std::cout << "________________ End testing LinkedListSequence _________________\n";
}

void testQueueGetSize() {
	const int SIZE = 5;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	Queue<int>* que = new Queue <int>(testArr, SIZE);
	if (que->GetSize() == SIZE and !que->IsEmpty()) {
		std::cout << "testQueueGetSize passed\n";
	}
	else {
		std::cout << "testQueueGetSize FAILED\n";
	}
};
void testQueueDequeue() {
	const int SIZE = 5;
	bool rez = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	int testArr2[SIZE - 1] = { 112, 23, 153, 122222 };
	LinkedListSequence<int>* seq = new LinkedListSequence <int>(testArr, SIZE);
	try {
		Queue<int>* que = new Queue <int>(seq);
		if (que->Dequeue() == testArr[0]) {
			for (int i = 0; i < SIZE - 1; i++) {
				rez = rez && que->Peek(i) == testArr2[i];
				if (!rez) {
					std::cout << "testQueueDequeue FAILED\n";
					break;
				}
			}
			std::cout << "testQueueDequeue passed\n";
		}
		else {
			std::cout << "testQueueDequeue FAILED\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testQueueDequeue FAILED\nException: " << exception.what() << "\n";
	}
}
void testQueueIsEmpty() {
	Queue<int>* que = new Queue <int>();
	if (que->IsEmpty()) {
		std::cout << "testQueueIsEmpty passed\n";
	}
	else {
		std::cout << "testQueueIsEmpty FAILED\n";
	}
}
void testQueuePeek() {
	const int SIZE = 5;
	bool rez = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	try {
		Queue<int>* que = new Queue <int>(testArr, SIZE);
		for (int i = 0; i < SIZE - 1; i++) {
			rez = rez && que->Peek(i) == testArr[i];
			if (!rez) {
				std::cout << "testQueuePeek FAILED\n";
				break;
			}
		}
		std::cout << "testQueuePeek passed\n";
	}
	catch (Exception& exception) {
		std::cout << "testQueuePeek FAILED\nException: " << exception.what() << "\n";
	}
}
void testQueueEnqueue() {
	const int SIZE = 5;
	bool rez = true;
	int testArr[SIZE] = { 11, 112, 23, 153, 122222 };
	int addValue = 777;
	int testArr2[SIZE + 1] = { 11, 112, 23, 153, 122222, addValue };
	Queue<int>* que = new Queue <int>(testArr, SIZE);
	que->Enqueue(addValue);
	for (int i = 0; i < SIZE + 1; i++) {
		rez = rez && que->Peek(i) == testArr2[i];
		if (!rez) {
			std::cout << "testQueueEnqueue FAILED\n";
			break;
		}
	}
	std::cout << "testQueueEnqueue passed\n";
};
void testQueue() {
	std::cout << "________________ Start testing testQueue _______________\n";
	testQueueIsEmpty();
	testQueueGetSize();
	testQueuePeek();
	testQueueEnqueue();
	testQueueDequeue();

	std::cout << "________________ End testing testQueue _________________\n";
}

int dscComp(int a, int b)
{
	if (a < b)
		return -1;
	if (a > b)
		return 1;
	return 0;
}

int ascComp(int a, int b)
{
	if (a > b)
		return -1;
	if (a < b)
		return 1;
	return 0;
}



void testSortBubble()
{
	std::cout << "________________ Start testing testSortBubble _______________\n";

	const int SIZE = 5;
	bool res = true;
	int testArr[SIZE] = { 345, 112, 23, 153, 122222 };
	try {
		Sequence<int>* seq = new ArraySequence <int>(testArr, SIZE);
		int a = 1;
		int b = 2;
		//ISorter<int>* descSort = new BubbleSorter<int>();
		ISorter<int>* descSort2 = new BubbleSorter<int>([](int a, int b)-> int
		{
				return 1;
		});
		Sequence<int>* seq2 = descSort2->Sort(seq);
		for (int i = 0; i < SIZE; i++) {
			res = res && (seq->Get(i) == testArr[i]);
		}
		if (res) {
			std::cout << "testArraySequenceCreateCopy passed\n";
		}
		else {
			std::cout << "testArraySequenceCreateCopy FAILED\n";
		}
	}
	catch (Exception& exception) {
		std::cout << "testArraySequenceCreateCopy FAILED\nException: " << exception.what() << "\n";
	}
	std::cout << "________________ End testing testSortBubble _________________\n";
}

void testSort()
{
	std::cout << "________________ Start testing testSort _______________\n";
	testSortBubble();
	std::cout << "________________ End testing testSort _______________\n";
}

int main() {
	testDinArr();
	testLinkedList();
	testArraySequence();
	testLinkedListSequence();
	testQueue();
	testSort();
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
