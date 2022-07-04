/*
 * LevelOrderPrinter.h
 *
 *  Created on: 2022Äê7ÔÂ4ÈÕ
 *      Author: maochaoqun
 */

#ifndef PRINTER_LEVELORDERPRINTER_H_
#define PRINTER_LEVELORDERPRINTER_H_
#include "BinaryTreeInfo.h"
#include "Printer.h"

class LevelOrderPrinter : public Printer{
public:
	LevelOrderPrinter(BinaryTreeInfo tree) {
	super(tree);
	root = new Node(tree.root(), tree);
	maxWidth = root.width;
}
private:
    static int MIN_SPACE = 1;
	Node root;
	int minX;
	int maxWidth;
};



#endif /* PRINTER_LEVELORDERPRINTER_H_ */
