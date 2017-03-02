#ifndef STACK_H
#define STACK_H
#include "Node.h"

template <class itemType>
class Stack
{
private:
	Node <itemType> *top; //points to the top of the stack.
	int size;
public:
	//Constructors.
	Stack();
	Stack(Node<itemType>* newNode) : top(newNode), size(0) {}

	//Destructor
	virtual ~Stack();

	//Accessors
	int getSize();
	void push(const itemType & data);
	void pop();
	bool isEmpty() const;
	void print() const;
	void clear();
};

template <class itemType>
int Stack<itemType>::getSize()
{
	return size;
}

template <class itemType>
Stack<itemType>::Stack() : top(nullptr)
{
}

template <class itemType>
Stack<itemType>::~Stack()
{
	while (!isEmpty())
	{
		pop(); //pop out the nodes until stack is empty.
	}
}

template<class itemType>
bool Stack<itemType>::isEmpty() const
{
	if (top == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class itemType>
void Stack<itemType>::push(const itemType & data)
{
	Node <itemType>* temp = new Node <itemType>();
	temp->data = data;
	temp->next = top;
	top = temp;
	size++;
}

template<class itemType>
void Stack<itemType>::pop()
{
	Node <itemType>* temp;
	if (top == NULL)
	{
		return;
	}
	else
	{
		temp = top;
		top = top->next;
		size--;
	}
}

template<class itemType>
void Stack<itemType>::print() const
{
	Node<itemType>* temp = top;
	while (temp)
	{
		std::cout << temp->data << "--->";
		temp = temp->next;
	}
	std::cout << "Null" << std::endl;
}

template<class itemType>
void Stack<itemType>::clear()
{
	while (!isEmpty())
	{
		pop();
		size--;
	}
}

#endif