/*
 * BinaryTreeInfo.h
 *
 *  Created on: 2022Äê9ÔÂ3ÈÕ
 *      Author: maochaoqun
 */

#ifndef ALG_BINARYTREE_BINARYTREEPRINTER_BINARYTREEINFO_H_
#define ALG_BINARYTREE_BINARYTREEPRINTER_BINARYTREEINFO_H_

#include "Node.h"

template<typename E>
class BinaryTreeInfo {
	/**
	 * who is the root node
	 */
	Node<E>* root();
	/**
	 * how to get the left child of the node
	 */
	Node<E>* left(Node<E>* node);
	/**
	 * how to get the right child of the node
	 */
	Node<E>* right(Node<E>* node);
	/**
	 * how to print the node
	 */
	Node<E>* string(Node<E>* node);
};



#endif /* ALG_BINARYTREE_BINARYTREEPRINTER_BINARYTREEINFO_H_ */
