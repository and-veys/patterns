class Pizza{
public:
	void prepare() { 
		bake();
		cut();
		box();
	};
	virtual void bake() {};
	virtual void cut() {};
	virtual void box() {};
};
//выпекать, резать и упаковывать можно по-разному, в зависимости от пиццы
class CheesePizza:public Pizza{
	public:
	   void bake() override { std::cout << "CheesePizza is baking." << std::endl; }
	   void cut() override { std::cout << "CheesePizza is cuting." << std::endl; };
	   void box() override {std::cout << "CheesePizza is boxing." << std::endl; };
};
class GreekPizza:public Pizza{
	public:
	   void bake() override { std::cout << "GreekPizza is baking." << std::endl; }
	   void cut() override { std::cout << "GreekPizza is cuting." << std::endl; };
	   void box() override {std::cout << "GreekPizza is boxing." << std::endl; };
};
class PepperoniPizza:public Pizza{
	public:
	   void bake() override { std::cout << "PepperoniPizza is baking." << std::endl; }
	   void cut() override { std::cout << "PepperoniPizza is cuting." << std::endl; };
	   void box() override {std::cout << "PepperoniPizza is boxing." << std::endl; };
};
Pizza* orderPizza(Pizza * pizza){
   pizza->prepare();
   return pizza;
}

