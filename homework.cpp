#include <iostream>
#include "text_view.h"
int main() {
//test
	Figure fig(15, 25);	
	TextView txt(new Text("one two three", 15));
	
	fig.paint();
	txt.paint();
	std::cout << "-----------------------------------------" << std::endl;
	fig.flip();
	txt.flip();
	fig.paint();
	txt.paint();
	
	
	return 0;
}