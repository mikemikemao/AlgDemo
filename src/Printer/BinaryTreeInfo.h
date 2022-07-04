/*
 * BinaryTreeInfo.h
 *
 *  Created on: 2022Äê7ÔÂ3ÈÕ
 *      Author: pirate
 */

#ifndef PRINTER_BINARYTREEINFO_H_
#define PRINTER_BINARYTREEINFO_H_

#include "Node.h"
template<typename E>
class BinaryTreeInfo {
	/**
	 * who is the root node
	 */
	virtual Node<E>* root() = 0;
	/**
	 * how to get the left child of the node
	 */
	virtual Node<E>* left(Node<E>* node) = 0;
	/**
	 * how to get the right child of the node
	 */
	virtual Node<E>* right(Node<E>* node) = 0;
	/**
	 * how to print the node
	 */
	virtual Node<E>* string(Node<E>* node) = 0;

};



#endif /* PRINTER_BINARYTREEINFO_H_ */
