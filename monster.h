class Monster{
private:
   int hp;
   int atk;
   int def;
   std::string type;
public:
   Monster(int hp, int atk, int def, const std::string &type) : hp(hp), atk(atk), def(def), type(type) {}

   void changeHp(int change){
       hp += change;
   }

   void changeAtk(int change){
       atk += change;
   }

   void changeDef(int change){
       def += change;
   }

   int getHp() const {
       return hp;
   }

   int getAtk() const {
       return atk;
   }

   int getDef() const {
       return def;
   }
   
   Monster * clone() const { return new Monster(this); }
   Monster(const Monster * mn) {
		hp = mn->hp;
		atk = mn->atk;
		def = mn->def;
		type = mn->type;
   }
   void doubleParameters() {
		hp *= 2;
		atk *= 2;
		def *= 2;
   }
   void info() { 
		std::cout 	<< "Monster: " << type
					<< " (atk: " << atk 
					<< ", def: " << def
					<< ", hp: " << hp
					<< ")" << std::endl;
   }
};