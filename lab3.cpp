#include<iostream>
#include<strings.h>
#include<vector>
using namespace std;

class Image{
public:
    Image(string a){
        content=a;
    }

    string content;
};

class Section{
public:
    string section_name;
    vector<string> paragraphs;
    vector<Section *> sections;
    vector<Image> images;

    Section(string a){
        section_name=a;
    }

    void addContent(string a){
        paragraphs.push_back(a);
    }

    void addContent(Section *a){
        sections.push_back(a);
    }

    void addContent(Image a){
        images.push_back(a);
    }

    void printSectionParagraphs(){
        for(int i=0; i<paragraphs.size(); i++){
            cout<<"Paragraph: "<<paragraphs[i]<<"\n";
        }
        for(int i=0; i<images.size(); i++){
            cout<<"Image with name: "<<images[i].content<<"\n";
        }
    }

    void printSection(){
        cout<<section_name<<"\n";
        printSectionParagraphs();
        for(int i=0; i<sections.size(); i++){
            sections[i]->printSection();
        }
    }
};

class Author{
public:
    string author_name;

    Author(string name){
        author_name=name;
    }    
};

class Book{
public:
    string book_name;

    vector<Author*> authors;
    vector<Section*> sections;
    vector<string> paragraphs;

    Book(string name){
        book_name=name;
    }

    void addAuthor(Author *a){
        authors.push_back(a);
    }

    void addContent(Section *a){
        sections.push_back(a);
    }

    void addContent(string a){
        paragraphs.push_back(a);
    }

    void printAuthors(){
        for(int i=0; i<authors.size(); i++){
            cout<<"Author: "<<authors[i]->author_name<<"\n";
        }
        cout<<"\n";
    }

    void printParagraphs(){
        for(int i=0; i<paragraphs.size(); i++){
            cout<<"Paragraph: "<<paragraphs[i]<<"\n";
        }
    }

    void print(){
        cout<<"Book: "<<book_name<<"\n"<<"\n"<<"Authors:"<<"\n";
        printAuthors();
        printParagraphs();

        for(int i=0; i<sections.size(); i++){
            sections[i]->printSection();
        }
    }
};


int main(){

    Book noapteBuna("Noapte buna, copii!");
    Author prGheo("Radu Pavel Gheo");
    noapteBuna.addAuthor(&prGheo);

    Section cap1("Capitolul 1");
    Section cap2("Capitolul 2");
    Section cap11("Capitolul 1.1");
    Section cap111("Capitolul 1.1.1");
    Section cap1111("Subcapitolul 1.1.1.1");

    noapteBuna.addContent("Multumesc celor care ...");
    noapteBuna.addContent(&cap1);
    noapteBuna.addContent(&cap2);

    cap1.addContent("Moto capitol");
    cap1.addContent(&cap11);
    cap11.addContent("Text from subchapter 1.1");
    cap11.addContent(&cap111);
    cap111.addContent("Text from subchapter 1.1.1");
    cap111.addContent(&cap1111);
    cap1111.addContent(Image("Image subchapter 1.1.1.1"));
    cap1111.addContent(Image("Image 2 subchapter 1.1.1.1"));
    
    noapteBuna.print();
};