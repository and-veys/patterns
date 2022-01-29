#include <iostream>
#include "iterator_containers.h"

int main() {
//test	
	ArrayContainer a;	
		a.addData(new DataInt(5));
		a.addData(new DataInt(8));
		a.addData(new DataInt(-4));
	ListContainer l;
		l.addData(new DataDouble(5.5));
		l.addData(new DataDouble(8.8));
		l.addData(new DataDouble(-4.4));
	VectorContainer v;
		v.addData(new DataString("one"));
		v.addData(new DataString("two"));
		v.addData(new DataString("three"));
	DequeContainer d;
		d.addData(new DataPerson("Andrey", 22));
		d.addData(new DataPerson("Alexey", 17));
		d.addData(new DataPerson("Sergey", 18));
	
	IIterator * arr = a.createIterator();
	IIterator * lst = l.createIterator();
	IIterator * vec = v.createIterator();
	IIterator * deq = d.createIterator();
	
	while(arr->hasNext()) 
		arr->getNext()->print();
	std::cout << std::endl;
	while(lst->hasNext()) 
		lst->getNext()->print();
	std::cout << std::endl;
	while(vec->hasNext()) 
		vec->getNext()->print();
	std::cout << std::endl;
	while(deq->hasNext()) 
		deq->getNext()->print();	
	std::cout << std::endl << "-----------------------------" << std::endl;
	while(arr->hasPrev())
		arr->getPrev()->print();
	std::cout << std::endl;
	while(lst->hasPrev())
		lst->getPrev()->print();
	std::cout << std::endl;
	while(vec->hasPrev())
		vec->getPrev()->print();
	std::cout << std::endl;
	while(deq->hasPrev())
		deq->getPrev()->print();
	
	delete arr;
	delete lst;
	delete vec;
	delete deq;
	
	return 0;
}