
class DrawingImplementor {
public:
    virtual void drawSquare(double) = 0; 
    virtual ~DrawingImplementor() {
    }
};

class PaintBrush : public DrawingImplementor {
public:
	void drawSquare(double w) { std::cout << "Brush width " << w << std::endl; }
};
class PaintPen : public DrawingImplementor {
public:
	void drawSquare(double w) { std::cout << "Pen width " << w << std::endl; }
};

class Shape {
protected:
	DrawingImplementor * imp;
public:
    virtual void draw() = 0; 						// low-level
    virtual void resize(double){}; 					// high-level
    virtual ~Shape() {}
};

class Square : public Shape {
protected:
	DrawingImplementor * imp;
public:
	Square(DrawingImplementor * i):imp(i){};
	void draw() override {imp->drawSquare(1);}	
};

class SquareWidth : public Square {
private:
	double width;
public:
	SquareWidth(DrawingImplementor * i):Square(i){}
	void resize(double p) {width = p; }
	void draw() override {imp->drawSquare(width);}	
};