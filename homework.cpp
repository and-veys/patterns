#include <iostream>
#include "2d_picture.h"

int main() {
	Image * img = new BitmapImage("image.bmp");
	img->readFile();
	img->draw();
	img->finalDraw();
	delete img;
	std::cout << "--------------" << std::endl;
	img = new VectorImage("image.dwg");
	img->readFile();
	img->draw();
	img->finalDraw();	
	delete img;
	
	return 0;
}