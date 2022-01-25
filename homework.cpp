#include <iostream>
#include "garland.h"
#include <time.h>

int main() {
//test	
	srand(time(0));
	size_t lights_count = 21;
	int action_count = 10;
	Garland garland(lights_count);
	Invoker inv(&garland);
	for(int i=0; i<action_count; ++i)
		inv.setCommand(rand()%lights_count, (bool)(rand()%2));
	
	garland.show();
	inv.showReverse();
	std::cout << "---------------------------------" << std::endl;
	garland.show();
	inv.showForward();
		
	return 0;
}