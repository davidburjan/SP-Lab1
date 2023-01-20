#include<iostream>
#include<string.h>
#include<vector>
#include<Windows.h>
#include<iomanip>
#include<fstream>


using namespace std;

class Table {
public:
    Table(string a) {
        content = a;
    }
    string content;
};

int AlignLeft() {
    return 0;
};

int AlignCenter() {
    return 1;
};

int AlignRight() {
    return 2;
};

class Paragraph {
public:
    Paragraph(string a) {
        content = a;
    }

    //0 = alignment left ---- 1 = alignment center ---- 2 = alignment right
    int alignment = 0;
    string content;

    void setAlignStrategy(int a) {
        if (a == 0) {
            alignment = 0;
        }
        if (a == 1) {
            alignment = 1;
        }
        if (a == 2) {
            alignment = 2;
        }
    }

    void printParagraph() {

        if (alignment == 0) {
            cout << setw(40) << left << content;
        }
        if (alignment == 1) {
            cout << setw((40 - content.length()) / 2 + content.length()) << right << content;
        }
        if (alignment == 2) {
            cout << setw(40) << right << content;
        }
    }

};

class ProxyImage {
public:
    ProxyImage(string a) {
        content = a;

    }

    string content;
    int dim = rand() % 100;
};

class Image {
public:
    Image(string a) {
        content = a;
    }

    Image(ProxyImage* a) {
        content = a->content;
        dim = a->dim;
        Sleep(dim * 100);
    }

    string content;
    int dim;
};

class Section {
public:
    string section_name;
    vector<Paragraph*> paragraphs;
    vector<Section*> sections;
    vector<ProxyImage*> images;
    vector<Table*> tables;

    Section(string a) {
        section_name = a;
    }

    void addContent(Paragraph* a) {
        paragraphs.push_back(a);
    }

    void addContent(Section* a) {
        sections.push_back(a);
    }

    void addContent(ProxyImage* a) {
        images.push_back(a);
    }

    void addContent(Image* a) {
        ProxyImage imgg(a->content);
        images.push_back(&imgg);
    }

    void addContent(Table* a) {
        tables.push_back(a);
    }

    void printSectionParagraphs() {
        for (int i = 0; i < paragraphs.size(); i++) {
            paragraphs[i]->printParagraph();
            cout << "\n";
        }
        for (int i = 0; i < images.size(); i++) {
            Image thisImg(images[i]);
            cout << "Image with name: " << thisImg.content << "\n";
        }
    }

    void printSection() {
        cout << section_name << "\n";
        printSectionParagraphs();
        for (int i = 0; i < sections.size(); i++) {
            sections[i]->printSection();
        }
    }

};

class Author {
public:
    string author_name;

    Author(string name) {
        author_name = name;
    }
};

class Book {
public:
    string book_name;
    vector<Author*> authors;
    vector<Section*> sections;
    vector<Paragraph*> paragraphs;

    Book(string name) {
        book_name = name;
    }

    void addAuthor(Author* a) {
        authors.push_back(a);
    }

    void addContent(Section* a) {
        sections.push_back(a);
    }

    void addContent(Paragraph* a) {
        paragraphs.push_back(a);
    }

    void printAuthors() {
        for (int i = 0; i < authors.size(); i++) {
            cout << "Author: " << authors[i]->author_name << "\n";
        }
        cout << "\n";
    }

    void printParagraphs() {
        for (int i = 0; i < paragraphs.size(); i++) {
            cout << "Paragraph: ";
            paragraphs[i]->printParagraph();
            cout << "\n";
        }
    }

    void print() {
        cout << "Book: " << book_name << "\n" << "\n" << "Authors:" << "\n";
        printAuthors();
        printParagraphs();

        for (int i = 0; i < sections.size(); i++) {
            sections[i]->printSection();
        }
    }
};

int main() {
    Section cap1("Capitolul 1");
    Paragraph p1("Paragraph 1");
    cap1.addContent(&p1);
    Paragraph p2("Paragraph 2");
    cap1.addContent(&p2);
    Paragraph p3("Paragraph 3");
    cap1.addContent(&p3);
    Paragraph p4("Paragraph 4");
    cap1.addContent(&p4);

    cout<<"Printing without Alignment";
    cap1.printSection();

    p1.setAlignStrategy(AlignCenter());
    p2.setAlignStrategy(AlignRight());
    p3.setAlignStrategy(AlignLeft());


    cout<<"Printing with Alignment";
    cap1.printSection();

};