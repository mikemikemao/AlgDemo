/*
 * TemplateMethod.h
 *
 *  Created on: 2022��8��21��
 *      Author: pirate
 */

#ifndef DESIGNPATTERN_TEMPLATEMETHOD_TEMPLATEMETHOD_H_
#define DESIGNPATTERN_TEMPLATEMETHOD_TEMPLATEMETHOD_H_

#include <iostream>
using namespace std;

class TemplateMethod{
public:
	//�ȶ���template method
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

	virtual bool step2() = 0;//�仯
	virtual bool step4() = 0;//�仯
private:
};



#endif /* DESIGNPATTERN_TEMPLATEMETHOD_TEMPLATEMETHOD_H_ */
