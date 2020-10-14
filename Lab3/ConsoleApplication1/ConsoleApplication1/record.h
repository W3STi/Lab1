#pragma once
#include <string>

using namespace std;

struct car
{
	int nomer;
};

// ���������� ������1
class List
{
public:
	List();
	~List();

	void pop_front();
	void push_back(car data);
	void clear();
	int GetSize() { return Size; }

	void push_front(car data);
	void insert(car data, int index);
	void pop_back();

	void removeAt(int index);

	car& operator[](const int index);
private:

	template<typename T>
	class Node
	{
	public:
		Node *pNext;
		T data;

		Node(T data = NULL, Node *pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<car> *head;
};

