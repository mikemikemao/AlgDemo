/*
 * Node.h
 *
 *  Created on: 2022Äê9ÔÂ3ÈÕ
 *      Author: maochaoqun
 */

#ifndef ALG_BINARYTREE_NODE_H_
#define ALG_BINARYTREE_NODE_H_

#include "iostream"
#include <iostream>     // std::cout

template<typename E>
class Node {
public:
	Node(E element, Node *parent) :
			element(element), parent(parent), left(NULL), right(NULL) {
	}

	bool isLeaf() {
		return left == NULL && right == NULL;
	}

	bool hasTwoChildren() {
		return left != NULL && right != NULL;
	}
	E getElement() {
		return element;
	}
public:
	E element;
	Node<E> *left;
	Node<E> *right;
	Node<E> *parent;
};



#endif /* ALG_BINARYTREE_NODE_H_ */
