/*
 * BinaryTrees.h
 *
 *  Created on: 2022��7��3��
 *      Author: pirat
 */

#ifndef PRINTER_BINARYTREES_H_
#define PRINTER_BINARYTREES_H_
#include "BinaryTreeInfo.h"
#include "string"
template<typename E>
class BinaryTrees{
public:
	static string printString(BinaryTreeInfo<E> tree) {
		return printString(tree, null);
	}
};



#endif /* PRINTER_BINARYTREES_H_ */
