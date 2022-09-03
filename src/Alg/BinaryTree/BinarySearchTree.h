/*
 * BinarySearchTree.h
 *
 *  Created on: 2022年7月2日
 *      Author: pirat
 */

#ifndef ALG_BINARYSEARCHTREE_H_
#define ALG_BINARYSEARCHTREE_H_
#include "iostream"
#include <iostream>     // std::cout
#include <functional>   // std::less
#include <algorithm>
#include "Node.h"
using namespace std;


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

	int size() {
		return m_size;
	}

	bool isEmpty() {
		return m_size == 0;
	}
	//未实现 需要遍历才能实现
	void clear() {
		if (root != NULL) {
			//
		}
		m_size = 0;
	}
	//前序遍历
	void preorderTraversal() {
		preorderTraversal(root);
	}

	void preorderTraversal(Node<E> *node) {
		if (node == NULL)
			return;
		cout << node->element << endl;
		preorderTraversal(node->left);
		preorderTraversal(node->right);
	}

	void inorderTraversal() {
		inorderTraversal(root);
	}

	void inorderTraversal(Node<E>* node) {
		if (node == NULL)
			return;

		inorderTraversal(node->left);
		cout << node->element << endl;
		inorderTraversal(node->right);
	}

	void postorderTraversal() {
		postorderTraversal(root);
	}

	void postorderTraversal(Node<E>* node) {
		if (node == NULL)
			return;

		postorderTraversal(node->left);
		postorderTraversal(node->right);
		cout << node->element << endl;
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
		if (cmp > 0) {
			parent->right = new Node<E>(element, parent);
		} else {
			parent->left = new Node<E>(element, parent);
		}
		m_size++;

	}
	//  ************* 输出图形二叉树 *************
	void output_impl(Node<E> *n, bool left, string const &indent) {
		if (n->right) {
			output_impl(n->right, false, indent + (left ? "|     " : "      "));
		}
		cout << indent;
		cout << (left ? '\\' : '/');
		cout << "-----";
		cout << n->element << endl;
		if (n->left) {
			output_impl(n->left, true, indent + (left ? "      " : "|     "));
		}
	}

	void output(Node<E> *root) {

		if (root->right) {
			output_impl(root->right, false, "");
		}
		cout << root->element << endl;
		if (root->left) {
			output_impl(root->left, true, "");
		}
	}
	void output() {
		output(root);
	}
private:
	void elementNotNullCheck(E element) {
		if (element == NULL) {
			throw std::out_of_range("element is NULL");
		}
	}
	int compare(E e1, E e2) {
		if (std::less<E>()(e1, e2) == 1) {
			return -1;
		} else if (std::equal_to<E>()(e1, e2) == 1) {
			return 0;
		} else {
			return 1;
		}
	}
private:
	Comparator<E> *comparator;
	Node<E> *root;
	int m_size;


public:
	static void main(){

	}
};

#endif /* ALG_BINARYSEARCHTREE_H_ */
