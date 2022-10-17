/*
 * BinaryTree.h
 *
 *  Created on: 2022��9��3��
 *      Author: maochaoqun
 */

#ifndef ALG_BINARYTREE_BINARYTREE_H_
#define ALG_BINARYTREE_BINARYTREE_H_

#include "BinaryTreePrinter/BinaryTreeInfo.h"
#include <queue>

template<typename E>
class BinaryTree: public BinaryTreeInfo<E> {
public:
	int size() {
		return m_size;
	}

	bool isEmpty() {
		return m_size == 0;
	}

	void clear() {
		//��Ҫͨ������ɾ�������ڵ�
		root = null;
		size = 0;
	}
	//ǰ�����
	void preorder(Visitor<E> & visitor) {
		if (visitor == null)
			return;
		preorder(root, visitor);
	}
	void preorder(Node<E> *node, Visitor<E> & visitor) {
		if (node == null || visitor.stop)
			return;

		visitor.stop = visitor.visit(node->element);
		preorder(node->left, visitor);
		preorder(node->right, visitor);
	}

	//�������
	void inorder(Visitor<E> & visitor) {
		if (visitor == null)
			return;
		inorder(root, visitor);
	}

	void inorder(Node<E>* node, Visitor<E> & visitor) {
		if (node == null || visitor.stop)
			return;

		inorder(node->left, visitor);
		if (visitor.stop)
			return;
		visitor.stop = visitor.visit(node->element);
		inorder(node->right, visitor);
	}
	//��������
	void postorder(Visitor<E> & visitor) {
		if (visitor == null)
			return;
		postorder(root, visitor);
	}

	void postorder(Node<E>* node, Visitor<E> & visitor) {
		if (node == null || visitor.stop)
			return;

		postorder(node->left, visitor);
		postorder(node->right, visitor);
		if (visitor.stop)
			return;
		visitor.stop = visitor.visit(node->element);
	}

	//�������
	void levelOrder(Visitor<E> &visitor) {
		if (root == NULL || visitor == NULL)
			return;
		std::queue<Node<E>*> qNode;
		qNode.push(m_root);
		while (!qNode.empty()) {
			Node<E>* node = queue.poll();
			if (visitor.visit(node->element))
				return;

			if (node->left != NULL) {
				qNode.push(node->left);
			}

			if (node->right != NULL) {
				qNode.push(node->right);
			}
		}
	}

	static class Visitor{
		bool stop;
		/**
		 * @return 如果返回true，就代表停止遍历
		 */
		virtual bool visit(E element) = 0;
	};
protected:
	int m_size;
	Node<E> *m_root;
private:
};


#endif /* ALG_BINARYTREE_BINARYTREE_H_ */
