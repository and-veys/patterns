class Beverage {            // Абстрактный класс
	public:
		virtual std::string getDescription() const = 0;
		virtual double cost() const = 0;
};

class HouseBlend: public Beverage{   // Молотый
	public:
		std::string getDescription() const override { return "HouseBlend";}
		double cost() const override { return 5.5; }
};

class DarkRoast: public Beverage{  // Темной обжарки
	public:
		std::string getDescription() const override { return "DarkRoast";}
		double cost() const override { return 6.0; }
};
 
class Decaf: public Beverage{    // Без кофеина
	public:
		std::string getDescription() const override { return "Decaf";}
		double cost() const override { return 7.3; }
};

class Espresso: public Beverage{  // Эспрессо
	public:
		std::string getDescription() const override { return "Espresso";}
		double cost() const override { return 3.5; }
};



class CoffeeDecorator : public Beverage{		
	public:
		CoffeeDecorator(){}
		void setBeverage(Beverage * bv) { beverage = bv; }
	protected:
		Beverage * beverage;
};

class WithChocolate : public CoffeeDecorator {
	public:
		std::string getDescription() const override { return beverage->getDescription() + " with chocolate";}
		double cost() const override { return 0.2 + beverage->cost(); }
};
class WithWhippedCream : public CoffeeDecorator {
	public:
		std::string getDescription() const override { return beverage->getDescription() + " with whipped cream";}
		double cost() const override { return 0.4 + beverage->cost(); }
};
class WithCinnamon : public CoffeeDecorator { 
	public:
		std::string getDescription() const override { return beverage->getDescription() + " with cinnamon";}
		double cost() const override { return 0.3 + beverage->cost(); }
};
class WithoutSugar : public CoffeeDecorator {
	public:
		std::string getDescription() const override { return beverage->getDescription() + " without sugar";}
		double cost() const override { return -0.1 + beverage->cost(); }
};


class MakeCoffee{
	public:
		MakeCoffee(Beverage * bv):beverage(bv) {}
		Beverage * addExtra(CoffeeDecorator * cd){
			cd->setBeverage(beverage);
			beverage = cd;	
			return cd;
		}
		double cost() { return beverage->cost(); }
		std::string getDescription() { return beverage->getDescription(); }
	private:
		Beverage * beverage;	
};

