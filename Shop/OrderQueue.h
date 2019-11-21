#pragma once

#include <iostream>
#include "Order.h"

using namespace std;

template <class Order>
struct NodeType {
	Order data;
	NodeType<Order>* next;
};

template <class Order>
class OrderQueue {
public:
	OrderQueue();
	~OrderQueue();

	bool IsEmpty() const;
	void Enqueue(Order menu);
	void Dequeue(Order& menu);
	void PrintOrderQueue();

private:
	NodeType<Order>* qFront;
	NodeType<Order>* qRear;
 
};

template<class Order>
OrderQueue<Order>::OrderQueue()
{
	qFront = NULL:
	qRear = NULL;

}


template<class Order>
OrderQueue<Order>::~OrderQueue()
{
	Order tmp;
	while (!IsEmpty()) {
		Dequeue(tmp);
	}
}


template<class Order>
bool OrderQueue<Order>::IsEmpty() const
{
	return (qFront == NULL);
}


// Adds newItem to the rear of the queue.
// Pre: Queue has been initialized.
// Post: newItem is at rear of queue.
template<class Order>
void OrderQueue<Order>::Enqueue(Order newMenu)
{
	NodeType<Order>* ptr;
	ptr = new NodeType<Order>;
	ptr->data = newMenu;
	ptr->next = NULL;
	if (qRear == NULL)
		qFront = ptr;
	else
		qRear->next = ptr;
	qRear = ptr;
}

/**
*	@brief	Order Queue�� front�� ��ġ�ϴ� �޴��� ���� �� �Է��Ķ������ menu�� ����
*	@pre	Queue has been initialized. ť�� ������� �ʾƾ� ��
*	@post	���� front�� �޴��� ���� �� front�� �޴��� ��ȭ
*/

template<class Order>
void OrderQueue<Order>::Dequeue(Order& menu)
{
	NodeType<Order>* tempPtr;
	tempPtr = qFront;
	menu = qFront->data; 
	qFront = qFornt->next;
	if (qFront == NULL)
		qRear = NULL;
	delete tempPtr;
}

/**
*	@brief	Order Queue���� �޴����� display
*	@pre	Queue has been initialized.
*	@post	none.
*/
template<class Order>
void OrderQueue<Order>::PrintOrderQueue()
{	
	cout << endl;
	cout<<"[Order Oueue]"<<endl;
	NodeType<Order>* tempPtr;
	tempPtr = qFront;
	while (!IsEmpty()) {
		qFront->data.PrintOrder(); // order ��ü print �Լ�
		qFront->next;
	}
	cout << endl;
}
