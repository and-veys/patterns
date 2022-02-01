#include <iostream>
#include "graphic_editor.h"
int main() {
//test
	PaintPen pp;
	PaintBrush pb;
	
	Square sq(&pp);
	sq.draw();
	SquareWidth sqW(&pb);
	sqW.resize(5);
	sqW.draw();

	return 0;
}