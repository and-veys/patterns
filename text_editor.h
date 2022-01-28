#include <fstream>
#include <algorithm>

class IDivideMethod {
public:
	virtual std::string divide(std::string) = 0;
	virtual ~IDivideMethod(){}
};

class DivideByUserWidth : public IDivideMethod {
private:
	size_t _editorWidth;
public:	
	DivideByUserWidth(size_t w) : _editorWidth(w) {}
		std::string divide(std::string str) override {

			if(str.size() > _editorWidth)
				return str.substr(0, _editorWidth) + "\n" + divide(str.substr(_editorWidth));			
			return str;
		};
};

class DivideByScreenWidth : public DivideByUserWidth {
public:
	DivideByScreenWidth() : DivideByUserWidth(getScreenWidth()){}
private:
	size_t getScreenWidth() { return 15; }	//нужно реализовать правильно из условий ОС
};

class DivideBySentence : public IDivideMethod {
public:
	std::string divide(std::string str) override {
		auto it = find_if(str.begin(), str.end(), [](char ch){return ch=='.' || ch=='?' || ch=='!';});
		if(it < str.end()-1)
		{
			size_t _editorWidth = it - str.begin() + 2;
			return str.substr(0, _editorWidth) + "\n" + divide(str.substr(_editorWidth));
		}
		return str;
	};	
};

class ITextWork{
public:
	virtual void setDivideMethod(IDivideMethod * m) = 0;
	virtual void printText() = 0;	
	virtual ~ITextWork(){}
protected:
	virtual std::string divide() = 0;	
};

class TextEditor : public ITextWork {
private:
	std::string all_text;  
	IDivideMethod * _method;
	std::string divide() override { return _method->divide(all_text); }
public:
    TextEditor(){};
    TextEditor(const std::string &text) : all_text(text) {};
    TextEditor(std::ifstream& file) {
        std::string line;
        if (file.is_open()){
            while (getline(file, line))
                all_text+=line;
        }
    }
	void setDivideMethod(IDivideMethod * m) override {
		_method = m;
	}
    void printText() override {
        std::cout << divide() << std::endl;
    }    
};