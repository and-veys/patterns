#include <map>
#include <ctime>
#include <iostream>

class ISellSystem{
public:
   virtual void changePrice(std::string, float) = 0;
   virtual void sellProduct(std::string) = 0;
   virtual void addProduct(std::string, size_t) = 0;
};
class Automaton : public ISellSystem {
private:
   std::string location;
   double recieved_money;
   double spent_money;
   std::map <std::string, float> goods_price;
   std::map <std::string, float> goods_count;

public:
   Automaton(const std::string &location, double recievedMoney) : location(location), recieved_money(recievedMoney) {
       spent_money = 0.0;
   }
   void changePrice(std::string name, float newPrice) override {
       goods_price[name] = newPrice;
   }
   void sellProduct(std::string name) override {
       if(goods_count[name] > 0){
           recieved_money += goods_price[name];
		   --goods_count[name];
       }
       else{
           std::cerr << "Not enough goods" << std::endl;
       }
   }
   void addProduct(std::string name, size_t count) override {
       goods_count[name] += count;
   }
   double allMoneyReport() const{
       return recieved_money - spent_money;
   }
   const std::string& getLocationReport() const {
       return location;
   }
   void goodsCountReport() const{
       for (auto& [product,count]: goods_count){
           std::cout << product << ": " << count << std::endl;
       }
   };
   void goodsPriceReport() const{
	   
       for (auto& [product,price]: goods_price){
           std::cout << product << ": " << price << std::endl;
       }
   };
};
class ProxyAutomaton : public ISellSystem {
private:
	time_t _last_update;
	size_t _delta_update;
	Automaton * _report;
	Automaton * _main;
	void updateReport() {
		time_t cur = time(NULL);
		if((cur - _last_update) > _delta_update) {
			_last_update = cur;
			if(_report != nullptr) 
				delete _report;
			_report = new Automaton(*_main);
		}
	}
	void PrintTimeReport() {
		std::cout << "...Report as of "  << ctime(&_last_update); 
	}
public:
	ProxyAutomaton(Automaton * am, size_t dt = 3600): _last_update(0), _report(nullptr), _delta_update(dt), _main(am) {		
		updateReport();
	}
	~ProxyAutomaton() {
		delete _report;
	}
	void changePrice(std::string name, float newPrice) override {
		_main->changePrice(name, newPrice);
	}
	void sellProduct(std::string name) override {
		_main->sellProduct(name);
	}
	void addProduct(std::string name, size_t count) override {
		_main->addProduct(name, count);
	}
	double allMoneyReport() {
		updateReport();
		PrintTimeReport(); 
		return _report->allMoneyReport(); 
   }
   const std::string& getLocationReport() {
		updateReport();
		PrintTimeReport(); 
		return _report->getLocationReport();
   }
   void goodsCountReport(){
	   updateReport();
	   PrintTimeReport(); 
	   _report->goodsCountReport();
   };
   void goodsPriceReport(){
		updateReport();
		PrintTimeReport(); 
		_report->goodsPriceReport();
   };	
};	