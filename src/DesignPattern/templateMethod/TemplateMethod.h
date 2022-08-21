/*
 * TemplateMethod.h
 *
 *  Created on: 2022年8月21日
 *      Author: pirate
 */

#ifndef DESIGNPATTERN_TEMPLATEMETHOD_TEMPLATEMETHOD_H_
#define DESIGNPATTERN_TEMPLATEMETHOD_TEMPLATEMETHOD_H_

#include <iostream>
using namespace std;

class TemplateMethod{
public:
	//稳定的template method
	void run(){
		step1();

		if(step2()){
			step3();
		}

		for(int i = 0; i<5 ;i++){
			step4();
		}

		step5();
	}
protected:
	void step1(){
		cout << "step1" <<endl;
	};
	void step3(){
		cout << "step3" <<endl;
	};
	void step5(){
		cout << "step5" <<endl;
	};

	virtual bool step2() = 0;//变化
	virtual bool step4() = 0;//变化
private:
};



#endif /* DESIGNPATTERN_TEMPLATEMETHOD_TEMPLATEMETHOD_H_ */
