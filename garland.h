#include <vector>
class Light{
	private:
	   bool state;
	public:
	   Light():state(false){};
	   void On(){
		   if(!state){
			   state = true;
		   }
	   };	  
	   void Off(){
		   if(state){
			   state = false;
		   }
	   };
	   bool getState() const {
		   return state;
	   }
};

class Garland {
private:
	std::vector<Light *> lights;
public:
	Garland(size_t len) {		//len - количество лампочек в герлянде
		lights.resize(len);
		for(int i=0; i<len; ++i) lights[i] = new Light();			
	}
	~Garland() {
		for(Light * lg : lights) delete lg;
	}
	void show() {
		for(Light * lg : lights) std::cout << (lg->getState()?"0":"|");
		std::cout << std::endl;
	}
	Light * getLight(size_t ind) { return lights[ind]; }
};



class Command {
	protected:
		Light * light;
	public:
		Command(Light * lg):light(lg){}
		virtual ~Command() {}
		virtual bool Execute() = 0;
		virtual void UnExecute() = 0;
};

class OnLight : public Command {
public:
	OnLight(Light * lg):Command(lg){}
	bool Execute() override { 
		if(light->getState()) return false;
		light->On(); 
		return true;
	}
	void UnExecute() override { light-> Off(); }
};

class OffLight : public Command {
public:
	OffLight(Light * lg):Command(lg){}
	bool Execute() override {
		if(!light->getState()) return false;
		light->Off(); 
		return true;
	}
	void UnExecute() override { light-> On(); }
}; 



class Invoker {
private:
	std::vector<Command *> commands;
	Garland * garland;
public:
	Invoker(Garland * gr):garland(gr){}
	~Invoker(){
		for(Command * cm : commands) delete cm;
	}
	void setCommand(size_t ind, bool dt) {
		Light* lg = garland->getLight(ind);
		Command * cm;
		if(dt) 
			cm = new OnLight(lg);
		else 
			cm = new OffLight(lg);
		if(cm->Execute()) commands.push_back(cm);
		else delete cm;
	}
	void showForward() {
		for(int i = 0; i < commands.size(); ++i) {			
			commands[i]->Execute();
			garland->show();
		}
	}
	void showReverse() { 
		for(int i = commands.size()-1; i >= 0; --i) {
			commands[i]->UnExecute();
			garland->show();
		}
	}	
};
