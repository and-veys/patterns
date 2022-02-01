#include <iostream>
#include "pizza_2.h"
#include <vector>

int main() {
//test
	std::vector<Pizza *> orders;
	CheesePizzaFactory cp;
	GreekPizzaFactory gp;
	PepperoniPizzaFactory pp;
	
	orders.push_back(orderPizza(&gp));
	orders.push_back(orderPizza(&pp));
	orders.push_back(orderPizza(&cp));
	
	for(auto item : orders){
		item->prepare();
		std::cout << "--------------------------------" << std::endl; 
	}
	
	return 0;
}