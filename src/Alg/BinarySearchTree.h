/*
 * BinarySearchTree.h
 *
 *  Created on: 2022年7月2日
 *      Author: pirat
 */

#ifndef ALG_BINARYSEARCHTREE_H_
#define ALG_BINARYSEARCHTREE_H_
#include "iostream"
using namespace std;


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

template<typename E>
class Comparator {
public:
	 virtual int compare(E o1, E o2) = 0;
};

template<typename E>
class Comparable {
public:
	 virtual int compareTo(E o) = 0;
};

template<typename E>
class BinarySearchTree {
public:
	BinarySearchTree() :
			root(NULL), m_size(0) {
	}

	void add(E element) {
		elementNotNullCheck(element);
		//添加根节点
		if (root == NULL) {
			root = new Node<E>(element, NULL);
			m_size++;
			return;
		}
		//添加子节点
		Node<E> *parent = root;
		Node<E> *node = root;
		int cmp = 0;
		do {
			cmp = compare(element, node->element);
			parent = node;
			if (cmp > 0) {
				node = node->right;
			} else if (cmp < 0) {
				node = node->left;
			} else { // 相等的替换
				node->element = element;
				return;
			}
		} while (node != NULL);
		//添加子节点
		if(cmp > 0){
			parent->left = new Node<E>(element,parent);
		}else{
			parent->right = new Node<E>(element,parent);
		}
		m_size++;

	}
private:
	void elementNotNullCheck(E element) {
		if (element == NULL) {
			throw std::out_of_range("element is NULL");
		}
	}
    int compare(E e1, E e2) {
		if(comparator!=NULL){
			return comparator->compare(e1, e2);
		}
		return (reinterpret_cast<Comparable<E>*>(e1))->compareTo(e2);
	}
private:
    Comparator<E>* comparator;
	Node<E> *root;
	int m_size;
};



#endif /* ALG_BINARYSEARCHTREE_H_ */
