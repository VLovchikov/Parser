#pragma once

#include <iostream>

using namespace std;

template <class T>
class TStack
{
protected:
	int MaxSize;
	int Index;
	T *mas;
public:
	TStack(int len = 30);
	~TStack();
	TStack(const TStack &s);
	TStack&operator=(const TStack &s);
	bool IsEmpty();
	bool IsFull();
	T Top();
	T Pop();
	void Push(const T n);
	int Size();
};

template <class T>
TStack<T>::TStack(int len = 10)
{
	if (len <= 0) throw "TOO SMALL LEN";
	MaxSize = len;
	Index = -1;
	mas = new T[MaxSize];
}

template <class T>
TStack<T>::~TStack()
{
	delete[] mas;
}

template <class T>
TStack<T>::TStack(const TStack &s)
{
	MaxSize = s.MaxSize;
	Index = s.Index;
	mas = new T[MaxSize];
	for (int i = 0; i < Index + 1; i++)
		mas[i] = s.mas[i];
}

template <class T>
TStack<T> &TStack<T>::operator=(const TStack &s)
{
	if (MaxSize != s.MaxSize)
	{
		delete[] mas;
		MaxSize = s.Maxsize;
		mas = new T[MaxSize];
	}
	Index = s.Index;
	for (int i = 0; i < Index + 1; i++)
		mas[i] = s.mas[i];
	return *this;
}

template <class T>
bool TStack<T>::IsEmpty()
{
	return Index == -1;
}

template <class T>
bool TStack<T>::IsFull()
{
	return Index == MaxSize - 1;
}

template <class T>
T TStack<T>::Top()
{
	if (Index < 0) throw "TOO SMALL INDEX";
	return mas[Index];
}

template <class T>
T TStack<T>::Pop()
{
	if (Index < 0) throw "TOO SMALL INDEX";
	return mas[Index--];
}

template <class T>
void TStack<T>::Push(const T n)
{
	if (Index == MaxSize - 1) throw "INDEX IS FULL";
	mas[++Index] = n;
}

template <class T>
int  TStack<T>::Size()
{
	return (Index - 1);
}