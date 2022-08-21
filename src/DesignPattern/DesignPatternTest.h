/*
 * DesignPatternTest.h
 *
 *  Created on: 2022��8��21��
 *      Author: pirate
 */

#ifndef DESIGNPATTERN_DESIGNPATTERNTEST_H_
#define DESIGNPATTERN_DESIGNPATTERNTEST_H_

#include "templateMethod/TemplateMethodImp.h"

class DesignPatternTest{
public:
	static void TemplateMethodTest(){
		TemplateMethodImp templateMethodImp;
		templateMethodImp.run();
	}
};




#endif /* DESIGNPATTERN_DESIGNPATTERNTEST_H_ */
