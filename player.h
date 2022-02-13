
#include <iostream>
#include <fstream>
#include <vector>
#pragma once


template<class T>
class SmartPointer {
private:
	T* ptr;
public:
	SmartPointer(T* p = nullptr) : ptr(p) {}
	~SmartPointer() { delete ptr; }		
	T& operator*() { return *ptr; }
	T* operator->() { return ptr; }
	void operator=(T* p) {
		delete ptr;
		ptr = p;
	}
};


class Data{
public:
	Data(float h, int sp):hp(h), speed(sp) {}
	float hp;
	int speed;
};

class Player{
private:
   float hp;
   int speed;
   std::string name;
   class Memento;
   SmartPointer<Memento> mem;
public:
	Player(float hp, int speed, const std::string &name);
	~Player();
	void undo();
	void add();
	
	
	void changeSpeed(int change){
		add();
		speed += change;
	}
	void changeHp(float change){
		add();
		hp += change;
	}	
	void print(){ std::cout << "HP = " << hp << "; SPEED = " << speed << std::endl;}
	void setSpeed(int sp) { speed = sp; }
	void setHp(float h) { hp = h; }
	float getHp() const { return hp; }
	int getSpeed() const { return speed; }
	const std::string &getName() const { return name; }
};
