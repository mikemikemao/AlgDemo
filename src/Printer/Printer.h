/*
 * Printer.h
 *
 *  Created on: 2022年7月4日
 *      Author: maochaoqun
 */

#ifndef PRINTER_PRINTER_H_
#define PRINTER_PRINTER_H_

#include "BinaryTreeInfo.h"

class Printer {
public:
	Printer(BinaryTreeInfo tree) {
		this.tree = tree;
	}
	virtual string printString()=0;
	virtual void println() {
	}
	virtual void print() {
	}

protected:
	BinaryTreeInfo tree;

};

#endif /* PRINTER_PRINTER_H_ */
