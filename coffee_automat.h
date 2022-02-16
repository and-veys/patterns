class CoffeeAutomat;

class State{
private:
    std::string info;
public:
    State(const std::string &inf) : info(inf) {}
    const std::string &getInfo() const { return info; }
    virtual void next(CoffeeAutomat*) = 0;
};

class NotCoin : public State {
public:
	NotCoin() : State("not coin") {}
	void next(CoffeeAutomat* am) override;
};

class WaitCoin : public State {
public:
	WaitCoin() : State("insert coin") {}
	void next(CoffeeAutomat* am) override;
};

class TakeCoffee : public State {
public:
	TakeCoffee() : State("take a coffee") {}
	void next(CoffeeAutomat* am) override;
};

class ReadyCoffee : public State {
public:
	ReadyCoffee() : State("coffee is ready"){}
	void next(CoffeeAutomat* am) override;
};

class OverCoffee : public State {
public:
	OverCoffee() : State("coffee is over") {}
	void next(CoffeeAutomat*) override;
};

class PushPay : public State {
public:
	PushPay() : State("push to pay") {}
	void next(CoffeeAutomat* am) override;
};

class CoffeeAutomat{
private:
	bool coin; 
	int amount;
    State* state;
public:
    CoffeeAutomat(int am) : state(nullptr), amount(am), coin(false) {
		setState(new WaitCoin()); 
	}
	void setState(State*  st) {
		delete state;
		state = st;
		std::cout << state->getInfo() << std::endl;
	}
	~CoffeeAutomat() { delete state; }
	void setCoin() { coin = true;}
	bool getCoin() { 
		if(coin) {
			coin = false;
			return true;
		}		
		return false;
	}
	bool getCoffee() { 
		--amount;
		return amount >= 0;
	}
	void next() { state->next(this); }
};

void NotCoin::next(CoffeeAutomat* am) {
	am->setState(new WaitCoin());
}

void WaitCoin::next(CoffeeAutomat* am) {
	if(am->getCoin()) 
		am->setState(new PushPay());
	else
		am->setState(new NotCoin());
}	

void TakeCoffee::next(CoffeeAutomat* am) {
	am->setState(new WaitCoin());
}

void ReadyCoffee::next(CoffeeAutomat* am) {
	am->setState(new TakeCoffee());
}

void OverCoffee::next(CoffeeAutomat* am)  {	
}

void PushPay::next(CoffeeAutomat* am) {
	if(am->getCoffee())
		am->setState(new ReadyCoffee());
	else
		am->setState(new OverCoffee());
}









