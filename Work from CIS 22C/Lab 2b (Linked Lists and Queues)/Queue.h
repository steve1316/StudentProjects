#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"

template <class itemType>
class Queue
{
private:
	Node <itemType> *frontPtr; //points to the top of the stack.
	Node <itemType> *rearPtr;
public:
	//Constructors.
	Queue();
	Queue(Node<itemType>* newNode) : frontPtr(newNode), rearPtr(newNode) {}

	//Destructor
	virtual ~Queue();

	//Accessors
	void enqueue(const itemType &newdata);
	void dequeue();
	void front();
	void rear();
	void clear();
	void print() const;
};

template <class itemType>
Queue<itemType>::Queue() : frontPtr(nullptr), rearPtr(nullptr)
{
}

template <class itemType>
Queue<itemType>::~Queue()
{
	while (frontPtr)
	{
		Node<itemType>* temp = frontPtr;
		if (frontPtr == rearPtr)
		{
			frontPtr = NULL;
			rearPtr = NULL;
		}
		else
		{
			frontPtr = frontPtr->next;
		}
		delete temp;
	}
}

template <class itemType>
void Queue<itemType>::enqueue(const itemType &newdata)
{
	Node<itemType>* temp = new Node<itemType>(newdata);
	temp->data = newdata;
	temp->next = NULL;
	if (frontPtr == NULL && rearPtr == NULL)
	{
		rearPtr = temp;
		frontPtr = rearPtr;
		return;
	}
	rearPtr->next = temp;
	rearPtr = temp;
}

template <class itemType>
void Queue<itemType>::dequeue()
{
	Node<itemType>* temp = new Node<itemType>();
	if (frontPtr == NULL)
	{
		return;
	}
	else if (frontPtr == rearPtr)
	{
		rearPtr = NULL;
		frontPtr = rearPtr;
	}
	else
	{
		frontPtr = frontPtr->next;
	}
	delete(temp);
}

template<class itemType>
void Queue<itemType>::front()
{
	if (frontPtr)
	{
		Node<itemType>* temp = frontPtr;
		std::cout << temp->data;
	}
	else
	{
		return;
	}
}

template<class itemType>
void Queue<itemType>::rear()
{
	if (rearPtr)
	{
		Node<itemType>* temp = rearPtr;
		std::cout << temp->data;
	}
	else
	{
		return;
	}
}

template<class itemType>
void Queue<itemType>::print() const
{
	Node<itemType>* temp = frontPtr;
	while (temp)
	{
		std::cout << temp->data << "--->";
		temp = temp->next;
	}
	std::cout << "Null" << std::endl;
}

template<class itemType>
void Queue<itemType>::clear()
{
	while (frontPtr)
	{
		if (frontPtr == NULL && rearPtr == NULL)
		{
			return;
		}
		else
		{
			Node<itemType>* temp = frontPtr;
			if (frontPtr == rearPtr)
			{
				frontPtr = NULL;
				rearPtr = NULL;
			}
			else
			{
				frontPtr = frontPtr->next;
			}
			delete temp;
		}
	}
}

#endif
