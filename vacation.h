#include <vector>
class Events{
public:
   virtual void getEvent() = 0;
   virtual ~Events() {};
};

class Hotel: public Events{
public:
   void getEvent() { std::cout << "Booking Hotel" << std::endl; }
};

class Park: public Events{
   void getEvent() { std::cout << "Park visiting" << std::endl; }
};

class Food: public Events{
protected:
	std::string _type;
public:
	Food(std::string tp):_type(tp){}
	virtual void getEvent() = 0;
	virtual ~Food() {};
};

class Dinner: public Food{
public:
   Dinner() : Food("dinner") {}
   void getEvent(){ std::cout << "Food: " << _type << std::endl; }
};

class Lunch: public Food{
public:
   Lunch() : Food("lunch") {}
   void getEvent(){ std::cout << "Food: " << _type << std::endl; }
};

class Breakfast: public Food{
public:
   Breakfast() : Food("breakfast") {}
   void getEvent(){ std::cout << "Food: " << _type << std::endl; }
};

class Special: public Events{
protected:
	std::string _type;
public:
	Special(std::string tp):_type(tp){}
	virtual ~Special() {};
};

class Skating:public Special{
public:
   Skating() : Special("skating") {}
   void getEvent(){ std::cout << "Special: " << _type << std::endl; }
};

class Circus:public Special{
public:
   Circus() : Special("circus") {}
   void getEvent(){ std::cout << "Special: " << _type << std::endl; }
};

class ScheduleDay {
private:
	std::vector<Events *> events;
public:
	void info(){
		for(auto item : events)
			item->getEvent();
	};	
	~ScheduleDay() {
		for(auto item : events)
			delete item;
	}
	void add(Events * ev) { events.push_back(ev); }
};
class BuilderDay {
protected:
	ScheduleDay * _day;
public:	
	
	virtual ~BuilderDay(){}
	virtual void addHotel(){}
	virtual void addPark(){}
	virtual void addBreakfast(){}
	virtual void addLunch(){}
	virtual void addDinner(){}
	virtual void addSkating(){}
	virtual void addCircus(){}	
	virtual void createDay(){ _day = new ScheduleDay; }
	virtual ScheduleDay * getDay(){return _day;}

};
class Director {
public:
	ScheduleDay * createDay(BuilderDay * bd) {
		bd->createDay();
		bd->addHotel();
		bd->addPark();
		bd->addBreakfast();
		bd->addLunch();
		bd->addDinner();
		bd->addSkating();
		bd->addCircus();	
		return bd->getDay();
	}
};
class FirstDay : public BuilderDay{
public:
	virtual void addHotel(){_day->add(new Hotel);}
	virtual void addPark(){_day->add(new Park);}
	virtual void addDinner(){_day->add(new Dinner);}
};
class SecondDay : public BuilderDay{
public:
	virtual void addHotel(){_day->add(new Hotel);}
	virtual void addPark(){_day->add(new Park);}
	virtual void addBreakfast(){_day->add(new Breakfast);}
	virtual void addDinner(){_day->add(new Dinner);}
	virtual void addSkating(){_day->add(new Skating);}
};
class ThirdDay : public BuilderDay{
public:
	virtual void addPark(){_day->add(new Park);}
	virtual void addBreakfast(){_day->add(new Breakfast);}
	virtual void addLunch(){_day->add(new Lunch);}
	virtual void addCircus(){_day->add(new Circus);}
};

 


