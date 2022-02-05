#include <iostream>
#include "menu.h"

int main() {
	Client cl;
	std::vector<Menu *> vec;
	vec.push_back(new MenuItem("Borsch", "Beetroot soup", 3.25));
	vec.push_back(new Ingredient("Beetroot", 50, 50.0, 5.2, 1.8, 5.1));
	vec.push_back(new Ingredient("Beef", 10, 250.0, 25.4, 13.2, 7.2));
	
	for(Menu * m : vec) {
		m->info(&cl);
		std::cout << "--------------------------" << std::endl;
	}
	
	for(Menu * m : vec)
		delete m;	
	return 0;
}