#pragma once
using namespace std;
// Модуль DList.h
// шаблон класса узла списка
template<typename T>
class Node {
public:
	T data;
	Node* prev;
	Node* next;
	Node() {
		prev = NULL;
		next = NULL;
	};
};
// шаблон класса двусвязного списка
template <typename T>
class ListNode {
private:
	Node<T>* head; //голова списка
	Node<T>* tail; //хвост списка
	Node<T>* curr; // указатель на текущий узел
	int count = 0;
	Node<T>* FindNodePos(int pos) // поиск узла по позиции
	{
		if (pos > count || pos < 1) return 0;
		Node<T>* temp = head;
		for (temp; pos > 1; temp = temp->next, pos--);
		return temp;
	}
	Node<T>* FindNode(T d) // поиск узла по информационному значению
	{
		for (Node<T>* temp = head; temp; temp = temp->data)
			if (temp->data == d) return temp;
		return 0;
	}
public:
	// конструктор по умолчанию
	ListNode() :head(NULL), tail(NULL), curr(NULL) {};
	// конструктор с параметром информационного значения узла
	ListNode(T d) { AddHead(d); };
	// конструктор с параметрами для заполнение узлов значениями из массива
	ListNode(T arr[], int length)
	{
		for (int i = 0; i < length; i++)
			AddHead(arr[i]);
	}

	ListNode(const ListNode& other) {
		head = nullptr;
		tail = nullptr;

		Node<T>* current = other.head;
		while (current != nullptr) {
			AddTail(current->data);
			current = current->next;
		}
	}
	// деструктор
	~ListNode() { Clear(); }

	Node<T>* GetHead()
	{
		return head;
	}
	// методы добавления и вставки узлов, вывода прямого и обратного, удаления,
	// очистки списка и дополнительные
	void AddHead(T d)
	{
		Node<T>* temp = new Node<T>;
		temp->data = d;
		temp->next = head;
		if (count == 0)
		{
			tail = temp;
		}
		else {
			temp->next = head;
			head->prev = temp;
		}
		head = temp;
		curr = temp;
		count++;
	}
	void AddTail(T d)
	{
		if (count == 0)
			this->AddHead(d);
		else {
			Node<T>* temp = new Node<T>;
			temp->data = d;
			temp->prev = tail;
			tail->next = temp;
			tail = temp;
			count++;
		}
	}
	void AddNode(T d, int pos)
	{
		if (pos > count + 1 || pos < 1) return;
		else if (pos == 1) AddHead(d);
		else if (pos == count + 1) AddTail(d);
		else {
			Node<T>* x = FindNodePos(pos);
			Node<T>* temp = new Node<T>;
			temp->data = d;
			temp->next = x;
			temp->prev = x->prev;
			temp->prev->next = temp;
			x->prev = temp;
			count++;
		}
		return;
	}
	void ListHead()
	{
		for (Node<T>* temp = head; temp; temp = temp->next)
			cout << temp->data << " ";
		cout << endl;
	}
	void ListTail()
	{
		for (Node<T>* temp = tail; temp; temp = temp->prev)
			cout << temp->data << " ";
		cout << endl;
	}
	void DeleteHead()
	{
		if (head == 0) return;
		Node<T>* temp = head;
		head = temp->next;
		if (head != 0)
			head->prev = 0;
		delete temp;
		count--;
	}
	void DeleteTail()
	{
		if (head == 0) return;
		Node<T>* temp = tail;
		tail = temp->prev;
		if (tail != 0)
			tail->next = 0;
		delete temp;
		count--;
	}
	void DeleteNode(Node<T>* node)
	{
		if (!node) return;
		else if (node == head) DeleteHead();
		else if (node == tail) DeleteTail();
		else {
			node->prev->next = node->next;
			node->next->prev = node->prev;
			delete node;
			count--;
		}
	}
	void DeleteNodePos(int i)
	{
		DeleteNode(FindNodePos(i));
	}
	void Clear()
	{
		Node<T>* temp = head;
		while (temp != nullptr) {
			Node<T>* nextNode = temp->next;
			delete temp;
			temp = nextNode;
			count--;
		}
		head = nullptr;
		tail = nullptr;
		curr = nullptr;
	}
	bool isEmpty()
	{
		return head == 0;
	}
	// методы работы с итераторами
	T CurrentNode() { return curr->data; }
	T Next() 
	{
		curr = curr->next;
	}
	T Pred()
	{
		curr = curr->prev;
	}
	T& operator[](int pos) {
		Node<T>* it = FindNodePos(pos);
		if (it)
			return it->data;
		else
			throw "Элемента на данной позиции не существует";
	};
	T& operator++(int)
	{
		Node<T>* n = curr;
		curr = curr->next;
		return n->data;
	}
	T& operator--(int)
	{
		Node<T>* n = curr;
		curr = curr->prev;
		return n->data;
	}
	T operator=(T t)
	{
		curr->data = t;
	}

	int GetCount()
	{
		return count;
	}
};