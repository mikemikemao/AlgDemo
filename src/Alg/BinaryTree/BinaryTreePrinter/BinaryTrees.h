/*
 * BinaryTrees.h
 *
 *  Created on: 2022��9��7��
 *      Author: maochaoqun
 */

#ifndef ALG_BINARYTREE_BINARYTREEPRINTER_BINARYTREES_H_
#define ALG_BINARYTREE_BINARYTREEPRINTER_BINARYTREES_H_

#include "BinaryTreeInfo.h"

typedef enum {
	LEVEL_ORDER = 0,
	INORDER
}PRINT_STYLE_E;

template<typename E>
class BinaryTrees{
public:
	BinaryTrees() {
	}
	static void print(BinaryTreeInfo<E>* tree) {
		print(tree, NULL);
	}
	static void println(BinaryTreeInfo<E>* tree) {
		println(tree, NULL);
	}
private:

};



#endif /* ALG_BINARYTREE_BINARYTREEPRINTER_BINARYTREES_H_ */
