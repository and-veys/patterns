#include <iostream>
#include "home_cinema.h"

class HomeCinemaFacade{
private:
	enum State{ON, OFF};
	int _state;
	MediaPlayer* mp;
	Popper* popper;
	Lights* light;
	Projector* projector;
	Screen* screen;
	Amplifier* amp;
public:
	HomeCinemaFacade() : _state(OFF){
	mp = new MediaPlayer("media player");
	popper = new Popper("popper");
	light = new Lights("light");
	projector = new Projector("projector");
	screen = new Screen("screen");
	amp = new Amplifier("Amplifier");	
	}
	~HomeCinemaFacade() {
		delete mp;
		delete popper;
		delete light;
		delete projector;
		delete screen;
		delete amp;
	}
	
	void on(){
		if(_state == ON) { 
			std::cout << "HomeCinema is alredy ON" << std::endl;
			return;
		}
		popper->On();                    	// Включаем попкорн машину
		popper->pop();                   	// Готовим попкорн  
		light->dim(0);              		// Глушим свет
		screen->down();                  	// Опускаем экран  
		projector->On();                 	// Включаем проектор
		projector->setInput(mp);       		// Выбираем вход проектора
		projector->wideScreenMode();     	// Широкоэкранный режим  
		amp->On();                       	// Включаем усилитель
		amp->setStreamingPlayer(mp);   		// Выбираем куда отправлять звук
		amp->setSurroundSound();         	// Режим объемного звука
		amp->setVolume(5);             		// Средняя громкость  
		mp->On();                       	// Включаем медиаплеер
		mp->play("Star Wars"); 				// Наконец смотрим фильм			
		_state = ON;		
	}	
	void off(){
		if(_state == OFF) { 
			std::cout << "HomeCinema is alredy OFF" << std::endl;
			return;
		}
		light->dim(100);              		// Зажигаем свет
		popper->Off();                   	// Выключаем попкорн		
		screen->up();                  		// Поднимаем экран  
		projector->Off();                	// Выключаем проектор
		amp->Off();                      	// Выключаем усилитель 
		mp->Off();                       	// Выключаем медиаплеер	
		_state = OFF;
	}
};

int main() {
	
	HomeCinemaFacade hc;
	hc.on();
	std::cout << "---------------------------------------" << std::endl;
	hc.off();
	return 0;
}