
#include "cafe.h"

int main() {
	std::vector<Meal *> menu;
	menu.push_back(new JamPancake());
	menu.push_back(new BerryScream());
	menu.push_back(new TuttiFruity());
	menu.push_back(new Pistachio());
	menu.push_back(new Breakfast());
	menu.push_back(new Lunch());
	menu.push_back(new Dinner());
	int i=1;
	for(auto it : menu) {
		std::cout << i << ".";
		it->info();
		++i;
	}
	
	for(auto it : menu)
		delete it;
	
	return 0;
}