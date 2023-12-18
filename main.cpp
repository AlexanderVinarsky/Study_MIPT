#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

// Класс абстрактный элемент
class AbstractElement {
public:
    string txt;
    virtual string getType() {return "AbstractElement";};
};

// Класс картинка, которая является элементом
class Image: public AbstractElement {
public:
    explicit Image(string txt) {
        this->txt = txt;
    }

    string getType() {
        return type;
    }
private:
    string type = "Image";
};

// Класс текста, которая является элементом
class Text: public AbstractElement {
public:
    explicit Text(string txt, bool isBold = false) {
        this->isBold = isBold;
        this->txt = txt;
    }

    string getType() {
        return type;
    }
private:
    string type = "Text";
    bool isBold;
};

// Класс главы
class Chapter {
public:
    vector <AbstractElement*> elements;
    Chapter(string caption) {
        this->caption = caption;
    }
    void add(AbstractElement* element) {
        elements.push_back(element);
    }

    string caption;
};

// Класс абстрактного отчёта
class AbstractReport{
protected:
    vector<Chapter> chapters;
public:
    void add(Chapter chapter) {
        chapters.push_back(chapter);
    }
};

// Класс MarkDown отчёта, наследник абстрактного
class MDReport: public AbstractReport {
public:
    MDReport() {
        this->chapters = *new vector<Chapter>;
    }

    string getResult(){
        string res = "";
        for (int i = 0; i<chapters.size(); i++) {
            res += "#" + chapters[i].caption + "\n";
            for (int j = 0; j<chapters[i].elements.size(); j++) {
                //cout << chapters[i].elements[j]->txt;
                if (chapters[i].elements[j]->getType() == "Text") {
                    res+= chapters[i].elements[j]->txt + "\n";
                }
                else {
                    res += "![Alt text](" + chapters[i].elements[j]->txt + ")\n";
                }

            }
            res+="\n";
        } return res;
    }
};

// Класс RST отчёта, наследник абстрактного
class RSTReport: public AbstractReport {
public:
    RSTReport() {
        this->chapters = *new vector<Chapter>;
    }

    string getResult(){
        string res = "";
        for (int i = 0; i<chapters.size(); i++) {
            res += "#" + chapters[i].caption + "\n";
            for (int j = 0; j<chapters[i].elements.size(); j++) {
                //cout << chapters[i].elements[j]->txt;
                if (chapters[i].elements[j]->getType() == "Text") {
                    res+= chapters[i].elements[j]->txt + "\n";
                }
                else {
                    res += ".. image::" + chapters[i].elements[j]->txt + "\n";
                }

            }
            res+="\n";
        } return res;
    }
};

//Класс Абстрактная Фабрика - паттерн программирования
class AbstractFactory {
protected:
    string txt = "";
};

//Класс MarkDown Фабрики, наследник абстрактной фабрики
class MDFactory : public AbstractFactory {
public:
    MDReport make_report() {
        return MDReport();
    }
};

//Класс RST Фабрики, наследник абстрактной фабрики
class RSTFactory : public AbstractFactory {
public:
    RSTReport make_report() {
        return RSTReport();
    }
};

int main() {
    auto F = MDFactory(); //Заменить на auto F = RSTFactory(); и работает так же, но выдаёт файл для RST
    auto R = F.make_report();
    Chapter C1 = Chapter("Introduction");
    Chapter C2 = Chapter("Part 1");
    Text T1 = Text("Blah Blah Blah Blah Blah Blah Blah.", false);
    Image T2 = Image("Oink oink oink");
    C1.add(&T1);
    C1.add(&T2);
    C2.add(&T1);
    C2.add(&T2);
    R.add(C1);
    R.add(C2);
    cout << R.getResult();
}