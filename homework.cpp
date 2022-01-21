#include "SellSystem.h"
#include <thread>
int main() {
//test
	Automaton am("Moscow", 1000);	
	am.changePrice("bread", 3);
	am.addProduct("bread", 20);
	ProxyAutomaton proxy(&am, 2);	
	proxy.changePrice("butter", 5);	
	proxy.addProduct("butter", 15);
	proxy.goodsCountReport();
	std::this_thread::sleep_for(std::chrono::seconds(3));
	proxy.goodsCountReport();	
	proxy.sellProduct("butter");
	proxy.sellProduct("bread");
	proxy.goodsCountReport();
	std::this_thread::sleep_for(std::chrono::seconds(3));
	proxy.goodsCountReport();	
	return 0;
}