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
	Node<car> *temp = head;

	head = head->pNext;
	delete temp;

	Size--;
}

// Добавление элемента в конец списка
void List::push_back(car data)
{
	if (head == nullptr) {
		head = new Node<car>(data);
	}
	else {
		Node<car> *current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<car>(data);
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
void List::push_front(car data)
{
	head = new Node<car>(data, head);
	Size++;
}

// Добавление элемента в середину списка
void List::insert(car data, int index)
{
	if (index == 0) {
		push_front(data);
	}
	else {
		Node<car> *previous = this->head;

		for (int i = 0; i < index - 1; i++) {
			previous = previous->pNext;
		}
		Node<car> *newNode = new Node<car>(data, previous->pNext);

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
		Node<car> *previous = this->head;

		for (int i = 0; i < index - 1; i++) {
			previous = previous->pNext;
		}
		Node<car> *toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;
	}
}

// перегзузка оператора []
car & List::operator[](const int index)
{
	int counter = 0;
	Node<car> *current = this->head;
	while (current != nullptr) {
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}
