/*
 * TemplateMethodImp.h
 *
 *  Created on: 2022Äê8ÔÂ21ÈÕ
 *      Author: pirate
 */

#ifndef DESIGNPATTERN_TEMPLATEMETHOD_TEMPLATEMETHODIMP_H_
#define DESIGNPATTERN_TEMPLATEMETHOD_TEMPLATEMETHODIMP_H_

#include "TemplateMethod.h"

class TemplateMethodImp : public TemplateMethod{
public:
	virtual bool step2(){
		cout << "step2" << endl;
		return true;
	}

	virtual bool step4(){
			cout << "step4" << endl;
			return true;
		}
};


#endif /* DESIGNPATTERN_TEMPLATEMETHOD_TEMPLATEMETHODIMP_H_ */
