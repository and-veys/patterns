

#include "player.h"

int main() {
	Player pl(100.0, 50, "player_1");
	pl.changeHp(-2.2); 
	pl.changeSpeed(5);	
	pl.print();
	pl.undo();
	pl.print(); 

	return 0;
}