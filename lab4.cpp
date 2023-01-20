#include<iostream>
#include<strings.h>
#include<vector>
#include <Windows.h>
using namespace std;

class ProxyImage{
public:
    ProxyImage(string a){
        content=a;
    }

    string content;
    int dim=rand()%100;
};

class Image{
public:
    Image(ProxyImage *a){
        content=a->content;
        dim=a->dim;
        Sleep(dim*100);
    }

    string content;
    int dim;
};

class Section{
public:
    string section_name;
    vector<string> paragraphs;
    vector<Section *> sections;
    vector<ProxyImage *> images;

    Section(string a){
        section_name=a;
    }

    void addContent(string a){
        paragraphs.push_back(a);
    }

    void addContent(Section *a){
        sections.push_back(a);
    }

    void addContent(ProxyImage *a){
        images.push_back(a);
    }

    void printSectionParagraphs(){
        for(int i=0; i<paragraphs.size(); i++){
            cout<<"Paragraph: "<<paragraphs[i]<<"\n";
        }
        for(int i=0; i<images.size(); i++){
            Image thisImg(images[i]);
            cout<<"Image with name: "<<thisImg.content<<"\n";
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
    ProxyImage img1("Pamela Anderson");
    ProxyImage img2("Kim Kardashian");
    ProxyImage img3("Kirby Griffin");

    Section playboyS1("Front Cover");
    playboyS1.addContent(&img1);

    Section playboyS2("Summer Girls");
    playboyS2.addContent(&img2);
    playboyS2.addContent(&img3);

    Book playboy("Playboy");
    playboy.addContent(&playboyS1);
    playboy.addContent(&playboyS2);

    playboy.print();

    cout<<"\n"<<img1.dim<<"\n"<<img2.dim<<"\n"<<img3.dim;

};