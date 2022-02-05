#include <iostream>
#include "news.h"
int main() {
	Herald herald;
	Doctor dc(&herald);
	Blacksmith bl(&herald);
	Child ch(&herald);
	
	herald.notify(10, "Hello");
	herald.getAnswer();
	std::cout << "-------------------" << std::endl;
	herald.notify(80, "One-Two-Three");
	herald.getAnswer();
	std::cout << "-------------------" << std::endl;
	herald.remove(&dc);
	herald.notify(50, "Bye");
	herald.getAnswer();

	return 0;
}