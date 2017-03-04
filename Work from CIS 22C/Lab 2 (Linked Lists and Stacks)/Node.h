#ifndef NODE_H
#define NODE_H
#include <cstddef>


template <class itemType>
class Node
{
public:
	itemType data; //A data item of any sort
	Node *next; // Pointer to next node

	Node();
	Node(const itemType& aData);
	Node(const itemType& aData, Node *nextNodePtr);
};

template <class itemType>
Node <itemType>::Node() :next(nullptr)
{} // end default constructor

template <class itemType>
Node <itemType>::Node(const itemType& aData) :
data(aData),
next(nullptr)
{ } // end constructor

template <class itemType>
Node<itemType>::Node(const itemType &aData, Node<itemType> *nextNodePtr) :
data(aData),
next(nextNodePtr)
{
} // end constructor

#endif
