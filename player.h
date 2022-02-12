#include <fstream>
#include <vector>


class Data{
public:
	Data(float h, int sp):hp(h), speed(sp) {}
	float hp;
	int speed;
};

class Memento {
private:
	std::string file_name;
	std::vector<Data *> data;
public:
	Memento(std::string nm):file_name(nm + ".sav"){}
	~Memento(){
		for(auto dt : data)
			delete dt;
	}
	void save() {
		std::ofstream out(file_name, std::ios::binary);
		if(out.is_open()) {
			int num = data.size();
			out.write(reinterpret_cast<char*>(&num), sizeof(num));			
			for(auto dt : data)	{		
				out.write(reinterpret_cast<char*>(&dt->hp), sizeof(dt->hp));
				out.write(reinterpret_cast<char*>(&dt->speed), sizeof(dt->speed));
			}
			out.close();
		}
	}
	void load() {
		std::ifstream in(file_name, std::ios::binary);
		if(in.is_open()) {
			int num;
			in.read(reinterpret_cast<char*>(&num), sizeof(num));
			for(int i=0; i< num; ++i) {
				float h;
				int sp;
				in.read(reinterpret_cast<char*>(&h), sizeof(h));
				in.read(reinterpret_cast<char*>(&sp), sizeof(sp));
				data.push_back(new Data(h, sp));				
			}
			in.close();
		}
	}
	void add(Data * dt) {
		data.push_back(dt);	
	}
	Data * undo() {
		if(data.size() != 0) {
			Data * temp = data.back();
			data.pop_back();
			return temp;
		}
		else
			return nullptr;			
	}
};

class Player{
private:
   float hp;
   int speed;
   std::string name;
   Memento * mem;
public:
	Player(float hp, int speed, const std::string &name) : hp(hp), speed(speed), name(name) {
		mem = new Memento(name);
		mem->load();
	}
	~Player(){ 
		add();
		mem->save();
		delete mem; 
	}
	void changeSpeed(int change){
		add();
		speed += change;
	}
	void changeHp(float change){
		add();
		hp += change;
	}
	void undo() { 
		Data * dt = mem->undo(); 
		if(dt == nullptr)
			std::cout << "no undo" << std::endl;
		else {
			hp = dt->hp;
			speed = dt->speed;
			delete dt;
		}		
	}
	void add() { mem->add(new Data(hp, speed)); }
	void print(){ std::cout << "HP = " << hp << "; SPEED = " << speed << std::endl;}
	void setSpeed(int sp) { speed = sp; }
	void setHp(float h) { hp = h; }
	float getHp() const { return hp; }
	int getSpeed() const { return speed; }
	const std::string &getName() const { return name; }
};
