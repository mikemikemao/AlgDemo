//============================================================================
// Name        : AlgDemo.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "common.h"

#define ARR_SIZE(arr) sizeof(arr) / sizeof(arr[0])

int main() {
	//TwoSum001::main();
	//ListAdd002::main();
	//StringLen003::main();
	//MedianSorted004::main();
	BinarySearchTree<int> bst;
	int data[] = { 7, 4, 9, 2, 5, 8, 11, 3, 12, 1 };
	for (int i = 0; i < ARR_SIZE(data); i++) {
		bst.add(data[i]);
	}
	return 0;
}
