#include <iostream>

#include "iot.h"
int main() {
	Coffee cf;
	TeaPot tp;
	Alarm al;
	Calendar cl;
	
	Mediator md;
	md.add(&cf);
	md.add(&tp);
	md.add(&al);
	md.add(&cl);
	
	md.getUp();
	
	return 0;
}