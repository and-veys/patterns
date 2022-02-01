#include <iostream>
#include "vacation.h"

int main() {

	Director dir;
	FirstDay d1_builder;
	SecondDay d2_builder;
	ThirdDay d3_builder;
	
	ScheduleDay * d1 = dir.createDay(&d1_builder);
	ScheduleDay * d2 = dir.createDay(&d2_builder);
	ScheduleDay * d3 = dir.createDay(&d3_builder);
	
	std::cout << "_____ First Day _____" << std::endl;
	d1->info();
	std::cout << "_____ Second Day _____" << std::endl;
	d2->info();
	std::cout << "_____ Third Day _____" << std::endl;
	d3->info();
	
	delete d1;
	delete d2;
	delete d3;
	
	return 0;
}