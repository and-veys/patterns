#include <iostream>
#include "monster.h"

int main() {
	Monster * m1 = new Monster(100, 9, 7, "Baba Yaga");
	Monster * m2 = m1->clone();
	m2->doubleParameters();
	
	m1->info();
	m2->info();
	
	delete m1;
	delete m2;
	
	return 0;
}