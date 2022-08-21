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

//#define LEETCODE
//#define ALG_THEORY
//#define DESIGN_PATTERN

int main() {
#ifdef LEETCODE
	LeetcodeTest::MedianSorted004Test();
#endif
#ifdef ALG_THEORY
	AlgTest::main();
#endif

#ifdef DESIGN_PATTERN
	DesignPatternTest::TemplateMethodTest();
#endif
	return 0;
}
