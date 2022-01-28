#include <iostream>
#include "text_editor.h"
int main() {
//test
	std::string str = "Hello. Is it good in winter in Moskow? Yes! Really? Sometimes.";
	IDivideMethod * user = new DivideByUserWidth(8);
	IDivideMethod * screen = new DivideByScreenWidth();
	IDivideMethod * sentence = new DivideBySentence();
	
	TextEditor te(str);
	te.setDivideMethod(user);
	te.printText();
	std::cout << "-------------------------------" << std::endl;
	te.setDivideMethod(screen);
	te.printText();
	std::cout << "-------------------------------" << std::endl;
	te.setDivideMethod(sentence);
	te.printText();
	
	delete user;
	delete screen;
	delete sentence;
	return 0;
}