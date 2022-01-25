#include <iostream>
#include "coffee.h"

int main() {
//test
	Beverage * main_coffee = new DarkRoast();
	CoffeeDecorator * wch = new WithChocolate();
	CoffeeDecorator * wos = new WithoutSugar();
	CoffeeDecorator * wwc = new WithWhippedCream();

	MakeCoffee coffee(main_coffee);
	coffee.addExtra(wch);
	coffee.addExtra(wos);
	coffee.addExtra(wwc);
	std::cout << coffee.getDescription() << " - cost is " << coffee.cost() << std::endl;
	delete main_coffee;
	delete wch;
	delete wos;
	delete wwc;
	return 0;
}