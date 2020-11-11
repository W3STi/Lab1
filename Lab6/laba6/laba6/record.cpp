#include "record.h"

// Конструктор
List::List() {
	Size = 0;
	head = nullptr;
}

// Деструктор
List::~List() {
	clear();
}

// Удаление первого элемента списка
void List::pop_front()
{
	Node<int> *temp = head;

	head = head->pNext;
	delete temp;

	Size--;
}

// Добавление элемента в конец списка
void List::push_back(int data)
{
	if (head == nullptr) {
		head = new Node<int>(data);
	}
	else {
		Node<int> *current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<int>(data);
	}
	Size++;
}

// Очистка списка
void List::clear()
{
	while (Size) {
		pop_front();
	}
}

// Добавление элемента в начало списка
void List::push_front(int data)
{
	head = new Node<int>(data, head);
	Size++;
}

// Добавление элемента в середину списка
void List::insert(int data, int index)
{
	if (index == 0) {
		push_front(data);
	}
	else {
		Node<int> *previous = this->head;

		for (int i = 0; i < index - 1; i++) {
			previous = previous->pNext;
		}
		Node<int> *newNode = new Node<int>(data, previous->pNext);

		previous->pNext = newNode;

		Size++;
	}
}

// удаление последнего элемента списка
void List::pop_back()
{
	removeAt(Size - 1);
}

// удаление выбранного элемента списка
void List::removeAt(int index)
{
	if (index == 0) {
		pop_front();
	}
	else {
		Node<int> *previous = this->head;

		for (int i = 0; i < index - 1; i++) {
			previous = previous->pNext;
		}
		Node<int> *toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;
	}
}

// перегзузка оператора []
int & List::operator[](const int index)
{
	int counter = 0;
	Node<int> *current = this->head;
	while (current != nullptr) {
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}
