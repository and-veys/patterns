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
class PizzaFactory{
	public:
		virtual Pizza * createPizza()=0;	
		virtual ~PizzaFactory(){}
};
class CheesePizzaFactory : public PizzaFactory {
	public:
		Pizza * createPizza() override {return new CheesePizza();}
};
class GreekPizzaFactory : public PizzaFactory {
	public:
		Pizza * createPizza() override {return new GreekPizza();}
};
class PepperoniPizzaFactory : public PizzaFactory {
	public:
		Pizza * createPizza() override {return new PepperoniPizza();}
};


Pizza* orderPizza(PizzaFactory * pizzaFactory){
   return pizzaFactory->createPizza();
}










Pizza* orderPizza(std::string type){
   Pizza* pizza = nullptr;
   if (type == "cheese"){
       pizza = new CheesePizza;
   }
   else if (type == "greek"){
       pizza = new GreekPizza;
   }
   else if (type == "pepperoni"){
       pizza = new PepperoniPizza;
   }
   return pizza;
}