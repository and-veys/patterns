#include <iostream>
#include <thread>
#include "ChocolateBoiler.h"

void print(std::string pr, ChocolateBoiler* chb) {
	std::cout << pr << ": boiled(" << chb->isBoiled() << ") empty(" << chb->isEmpty() << ") *(" << chb << ")" << std::endl;
}

void fun_1() {
	ChocolateBoiler* chb = &ChocolateBoiler::getInstance();
	chb->boil();
	print("th_1", chb);
}
void fun_2() {
	ChocolateBoiler* chb = &ChocolateBoiler::getInstance();
	print("th_2", chb);
}

int main() {
// test #1
	ChocolateBoiler* chb_1 = &ChocolateBoiler::getInstance();
	ChocolateBoiler* chb_2 = &ChocolateBoiler::getInstance();
	if(chb_1 == chb_2)
		std::cout << "one and the same" << std::endl;
	else
		std::cout << "different" << std::endl;
// test #2
	chb_2->fill();
	print("chb_1", chb_1);
	print("chb_2", chb_2);
// test #3
	std::thread th1(fun_1);
	std::thread th2(fun_2);
	th1.join();
	th2.join();
// Я правильно понял, что при получении экземпляра через ссылку, mutex не нужен ??
	return 0;
}