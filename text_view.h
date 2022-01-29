class IShape{
public:
   virtual void scale(double scale_percentage) = 0;	// Масштабируем фигуру
   virtual void rotate(double angle) = 0;          	// Поворачиваем фигуру
   virtual void flip() = 0;                        	// Отражаем фигуру
   virtual void paint() = 0;
};

class Figure: IShape{
private:
   int width;
   int height;
   double angle;
   bool isFlipped;
public:
   Figure(int width, int height) : width(width), height(height), angle(0.0), isFlipped(false) {}

   void scale(double scale_percentage) override {
       width *= scale_percentage;
       height *= scale_percentage;
   }

   void rotate(double angle) override {
       angle += angle;
   }

   void flip() override {
       isFlipped = !isFlipped;
   }
   
   void paint() override {std::cout << (isFlipped ? "" : "Not ") << "Reflection" << std::endl;}
};

class IText{
public:
   virtual void newSize(int size) = 0;   		// Изменяем размер шрифта текста
   virtual void rotate(double angle) = 0;   	// Поворачиваем текст
   virtual void reverse() = 0;              	// Изменяем направление текста
};

class Text: IText{
private:
   int size;
   double angle;
   bool isReversed;
   std::string text;
public:
   Text(const std::string text, int size) : text(text), size(size), angle(0.0), isReversed(false) {}		

   void newSize(int newSize) override {
       size = newSize;
   }

   void rotate(double newAngle) override {
       angle = newAngle;
   }

   void reverse() override {
       for (int i = 0; i < text.size()/2; ++i) {
           char c = text[i];
           text[i] = text[text.size() - 1 - i];
           text[text.size() - 1 - i] = c;
       }
	   isReversed = !isReversed;
   }
   void paint() {std::cout << text << std::endl;}
};


class TextView : public IShape {
private:
	Text * text;
public:
	TextView(Text * txt):text(txt){}
	~TextView(){delete text; }
	void scale(double scale_percentage) override { text->newSize((int) scale_percentage); }
	void rotate(double angle) override { text->rotate(angle); }          	
	void flip()override { text->reverse(); } 
	void paint() override {text->paint();}
};







