#include <iostream>
#include "pizza.h"

int main() {
//test
	Pizza * ready;
	ready = orderPizza(new CheesePizza);
	delete ready;
	std::cout << "--------------" << std::endl;
	ready = orderPizza(new GreekPizza);
	delete ready;
	std::cout << "--------------" << std::endl;
	ready = orderPizza(new PepperoniPizza);
	delete ready;
	return 0;
}