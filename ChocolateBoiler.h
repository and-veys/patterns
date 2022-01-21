class ChocolateBoiler{
private:
	bool _empty;
	bool _boiled;
	ChocolateBoiler(){
		_empty = true;
		_boiled = false;
	}
	ChocolateBoiler(ChocolateBoiler& other) = delete;
    void operator= (ChocolateBoiler&) = delete;
public:
	static ChocolateBoiler& getInstance() {
		static ChocolateBoiler instance;
		return instance;
	}
	bool isEmpty() const{
		return _empty;
	}
	bool isBoiled() const{
		return _boiled;
	}
	void fill(){
       if (isEmpty()){
           _empty = false;
           _boiled = false;
		}
	}
	void drain(){
		if (!isEmpty() && isBoiled()){
			_empty = true;
		}
	}
	void boil(){
		if (!isEmpty() && !isBoiled()){
			_boiled = true;
		}
	}
};
/*
class ChocolateBoiler{
private:
	bool _empty;
	bool _boiled;
public:
	ChocolateBoiler(){
		_empty = true;
		_boiled = false;
	}
	bool isEmpty() const{
		return _empty;
	}
	bool isBoiled() const{
		return _boiled;
	}
	void fill(){
       if (isEmpty()){
           _empty = false;
           _boiled = false;
       }
	}
	void drain(){
		if (!isEmpty() && isBoiled()){
			_empty = true;
		}
	}
	void boil(){
		if (!isEmpty() && !isBoiled()){
			_boiled = true;
		}
	}
};
*/