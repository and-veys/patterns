#include <vector>
#include <fstream>
class Data {
public:
	virtual void draw() = 0;
};
class Pixel : public Data {
public:
	int x;
	int y;
	std::string color;
	void draw(){
		std::cout << "("<< x << ", " << y << ", " << color << ") "; 
	}
	Pixel(int x, int y, std::string c) : x(x), y(y), color(c) {}
};

class Figure : public Data{
public:
   int x;
   int y;
   std::string figure;
   void draw(){
       std::cout << "("<< x << ", " << y << ", " << figure << ") ";
   }
   Figure(int x, int y, std::string f) : x(x), y(y), figure(f) {}
};


class Image {
protected:
	std::ifstream file;
	std::vector<Data*> buffer;
public:
	void openFile(const std::string& filename){ 
		file.open(filename, std::ios::binary);	
		std::cout << "Open file " << filename << std::endl;
	}
	void draw(){
		for (const auto it: buffer)
           it->draw();  
		std::cout << std::endl;
	}
	void finalDraw(){
       std::cout << "Drawing image complete" << std::endl;
	}
	~Image() { 
		std::cout << "Close file" << std::endl;
		file.close(); 
		for(auto it : buffer)
			delete it;
	}	
	virtual void readFile() = 0;	
};

class BitmapImage : public Image {     
public:
	BitmapImage(const std::string fl) {openFile(fl);}
	void readFile() override {
		std::cout << "Read bitmap file " << std::endl;
//Имитируем 
		buffer.push_back(new Pixel(5, 7, "red"));
		buffer.push_back(new Pixel(-9, 4, "green"));
		buffer.push_back(new Pixel(0, -5, "blue"));	
	}
};

class VectorImage : public Image {        
public:
	VectorImage(const std::string fl) {openFile(fl);}
    void readFile() override {
		std::cout << "Read vector file " << std::endl;
//Имитируем
		buffer.push_back(new Figure(52, 17, "LINE"));
		buffer.push_back(new Pixel(-92, -51, "CIRCLE"));
	}
};