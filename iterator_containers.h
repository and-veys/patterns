#include <vector>
#include <deque>
#include <list>
#include <array>

class Data {
public:
	virtual void print()=0;
};

class DataInt : public Data {
private:
	int data;
public:
	DataInt(int dt):data(dt){}
	void print() override { std::cout << data << " "; }
};

class DataDouble : public Data {
private:
	double data;
public:
	DataDouble(double dt):data(dt){}
	void print() override { std::cout << data << " "; }
};

class DataString : public Data {
private:
	std::string data;
public:
	DataString(std::string dt):data(dt){}
	void print() override { std::cout << data << " "; }
};

class DataPerson : public Data {
private:	
	std::string name;
	size_t age;
public:
	DataPerson(std::string nm, size_t a):name(nm), age(a){}
	void print() override { std::cout << name << " is " << age << " years old. "; }
};
//-----------------------------------------------------------------------------------------------------------
class IIterator {
public:
	virtual bool hasNext() = 0;
	virtual bool hasPrev() = 0;
    virtual Data * getNext() = 0;
	virtual Data * getPrev() = 0;
	
};

class ArrayIterator : public IIterator {
private:
	std::array<Data *, 100> data;
	size_t position;
public:
	ArrayIterator(std::array<Data *, 100> & dt) : data(dt), position(0) {}
	bool hasNext() override { return (position < data.size() && data[position] != nullptr); }
	bool hasPrev() override { return (position != 0); }
	Data * getNext() override { 
		if(hasNext()) 
			return data[position++]; 
		return nullptr;
	}
	Data * getPrev() override { 
		if(hasPrev()) 
			return data[--position]; 
		return nullptr;
	}
};
class ListIterator : public IIterator  {
private:
	std::list<Data *> data;
	size_t position;
public:
	ListIterator(std::list<Data *> & dt) : data(dt), position(0) {}
	bool hasNext() override { return (position < data.size()); }
	bool hasPrev() override { return (position != 0); }
	Data * getNext() override { 
		if(hasNext()) 
			return *(std::next(data.begin(), position++)); 
		return nullptr;
	}
	Data * getPrev() override { 
		if(hasPrev()) 
			return *(std::next(data.begin(), --position));  
		return nullptr;
	}
};
class VectorIterator : public IIterator  {
private:
	std::vector<Data *> data;
	size_t position;
public:
	VectorIterator(std::vector<Data *> & dt) : data(dt), position(0) {}
	bool hasNext() override { return (position < data.size()); }
	bool hasPrev() override { return (position != 0); }
	Data * getNext() override { 
		if(hasNext()) 
			return *(std::next(data.begin(), position++)); 
		return nullptr;
	}
	Data * getPrev() override { 
		if(hasPrev()) 
			return *(std::next(data.begin(), --position));  
		return nullptr;
	}
};
class DequeIterator : public IIterator  {
private:
	std::deque<Data *> data;
	size_t position;
public:
	DequeIterator(std::deque<Data *> & dt) : data(dt), position(0) {}
	bool hasNext() override { return (position < data.size()); }
	bool hasPrev() override { return (position != 0); }
	Data * getNext() override { 
		if(hasNext()) 
			return *(std::next(data.begin(), position++)); 
		return nullptr;
	}
	Data * getPrev() override { 
		if(hasPrev()) 
			return *(std::next(data.begin(), --position));  
		return nullptr;
	}
};
//-----------------------------------------------------------------------------------------------------------

class ArrayContainer {
private:
	std::array<Data *, 100> data;
	size_t size;
public:
	ArrayContainer() : size(0) {
		for(int i=0; i<data.size(); ++i) data[i] = nullptr;
	}
	~ArrayContainer(){
		for(int i=0; i<size; ++i) delete data[i];
	}
	bool addData(Data * dt){
		if(size == data.size()) return false;
		data[size] = dt;
		++size;
		return true;
	}
	IIterator * createIterator() { return new ArrayIterator(data); }
};
class ListContainer {
private:
	std::list<Data *> data;
public:
	ListContainer() {}
	~ListContainer(){
		for(int i=0; i<data.size(); ++i) delete *(std::next(data.begin(), i));
	}
	void addData(Data * dt){
		data.push_back(dt);
	}
	IIterator * createIterator() { return new ListIterator(data); }
};
class VectorContainer {
private:
	std::vector<Data *> data;
public:
	VectorContainer() {}
	~VectorContainer(){
		for(int i=0; i<data.size(); ++i) delete *(std::next(data.begin(), i));
	}
	void addData(Data * dt){
		data.push_back(dt);
	}
	IIterator * createIterator() { return new VectorIterator(data); }
};
class DequeContainer {
private:
	std::deque<Data *> data;
public:
	DequeContainer() {}
	~DequeContainer(){
		for(int i=0; i<data.size(); ++i) delete *(std::next(data.begin(), i));
	}
	void addData(Data * dt){
		data.push_back(dt);
	}
	IIterator * createIterator() { return new DequeIterator(data); }	
};


