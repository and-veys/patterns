class Device{
public:
   std::string type;
   Device(const std::string &type) : type(type) {}
   virtual void On(){
       std::cout << type <<" is on" << std::endl;
   }
   virtual void Off(){
       std::cout << type <<" is off" << std::endl;
   }
};

class MediaPlayer: public Device{
private:
   std::string currentMovie;
public:
   MediaPlayer(const std::string &type) : Device(type) {}
   void play(std::string newMovie) {
       currentMovie = newMovie;
       std::cout << "Movie " << currentMovie << " started" << std::endl;
   }
};

class Amplifier: public Device{
   Device* streamingPLayer;
   int volume;
public:
   Amplifier(const std::string &type) : Device(type), volume(0) {}
   void setStreamingPlayer(Device* d){
       streamingPLayer = d;
       std::cout << "Streaming player is " << d->type << std::endl;
   }
   void setSurroundSound(){
       std::cout << "Surround Sound Mode" << std::endl;
   };
   void setVolume(int v){
       volume = v;
   }

};

class Projector: public Device{
private:
   Amplifier* _amplifier;
   Device* _input;
public:
   Projector(const std::string &type) : Device(type) {}

   void setInput(Device* d){
       _input = d;
       std::cout << "Projector input is " << d->type << std::endl;
   }
   void wideScreenMode(){
       std::cout << "Wide Screen Mode" << std::endl;
   };
};

class Tuner{
private:
   Amplifier* _amplifier;
public:
   void on(){
       std::cout << "Tuner on" << std::endl;
   }

   void off(){
       std::cout << "Tuner off" << std::endl;
   }
};

class Popper: public Device{
public:
   Popper(const std::string &type) : Device(type) {}

   void pop(){
       std::cout << "Popcorn will be ready soon" << std::endl;
   }
};

class Lights: public Device{
private:
   int currentLight;
public:
   Lights(const std::string &type) : Device(type), currentLight(100) {}
   void dim(int light){
       currentLight = light;
   }
};

class Screen: public Device{
public:
   Screen(const std::string &type) : Device(type) {}
   void down(){
       std::cout << "Screen is down" << std::endl;
   };
   void up(){
       std::cout << "Screen is up" << std::endl;
   };
};
