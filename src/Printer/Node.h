/*
 * Node.h
 *
 *  Created on: 2022Äê7ÔÂ4ÈÕ
 *      Author: maochaoqun
 */

#ifndef PRINTER_NODE_H_
#define PRINTER_NODE_H_

template<typename E>
class Node {
public:
	Node(E element, Node *parent) {
		this->element = element;
		this->parent = parent;
	}

	bool isLeaf() {
		return left == nullptr && right == nullptr;
	}

	bool hasTwoChildren() {
		return left != nullptr && right != nullptr;
	}
	E getElement(){
		return element;
	}
public:
	E element;
	Node<E> *left;
	Node<E> *right;
	Node<E> *parent;
};

#endif /* PRINTER_NODE_H_ */
