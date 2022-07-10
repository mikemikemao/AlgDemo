/*
 * AlgDemo.h
 *
 *  Created on: 2022Äê7ÔÂ10ÈÕ
 *      Author: pirat
 */

#ifndef ALG_ALGTEST_H_
#define ALG_ALGTEST_H_

#include "BinarySearchTree.h"
#include "../common.h"

class AlgTest {
public:
	static void BSTTest() {
		BinarySearchTree<int> bst;
		int data[] = {7, 4, 9, 2, 5, 8, 11, 3, 12, 1};
		try {
			for (int i = 0; i < ARR_SIZE(data); i++) {
				bst.add(data[i]);
			}
		} catch (exception e) {
			cout << e.what() << "\ncode: "<< endl;
		}
		bst.output();
		bst.postorderTraversal();
	}

	static void main(){
		BSTTest();
	}
};



#endif /* ALG_ALGTEST_H_ */
