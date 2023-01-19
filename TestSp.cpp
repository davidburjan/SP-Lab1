#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

class Directory;

class Visitor{
public:
    virtual void VisitDirectory(const Directory *dir) const =0;
};

class Txt{
public:
    string txt_name;
    
    Txt(string a){
        txt_name=a;
    }
    
};

class Mp3{
public:
    string mp3_name;

    Mp3(string a){
        mp3_name=a;
    }

};

class Svg{
public:
    string svg_name;

    Svg(string a){
        svg_name=a;
    }
    
};

class Directory{
public:
    string directory_name;

    vector<Mp3 *> mp3s;
    vector<Svg *> svgs;
    vector<Txt *> txts;
    vector<Directory *> directories; 

    Directory(string a){
        directory_name=a;
    }
    
    void addContent(Mp3 *a){
        mp3s.push_back(a);
    }
    
    void addContent(Svg *a){
        svgs.push_back(a);
    }
    
    void addContent(Txt *a){
        txts.push_back(a);
    }
    
    void addContent(Directory *a){
        directories.push_back(a);
    }
    
    void printMp3s(){
        for(int i=0; i<mp3s.size(); i++){
            cout<<"Mp3 with name: "<<mp3s[i]->mp3_name<<"\n";
        }
        for(int i=0; i<svgs.size(); i++){
            cout<<"Svg with name: "<<svgs[i]->svg_name<<"\n";
        }
        for(int i=0; i<txts.size(); i++){
            cout<<"Txt with name: "<<txts[i]->txt_name<<"\n";
        }
    }
    
    void print(){
        cout<<directory_name<<"\n";
        printMp3s();
        for(int i=0; i<directories.size(); i++){
            directories[i]->print();
        }
    }
    
    virtual void Accept(Visitor* visitor){
        visitor->VisitDirectory(this);
    }
};

class Visitor1: public Visitor{
public:

    int nrTxt=0;
    void countTxt(*dir){
        nrTxt=nrTxt+dir.txts.size();
    }
        
    virtual void VisitDirectory(const Directory *dir) const override{
        countTxt(dir);
        for(int i=0; i<dir.directories.size(); i++){
            countTxt();
        }
    }
};

int main(){
    Directory d1("Directory 1");
    Mp3 mp1("Mp3 1");
    d1.addContent(&mp1);
    Directory d2("Directory 2");
    d1.addContent(&d2);
    Txt t1("Text 1");
    d2.addContent(&t1);
    Txt t2("Text 2");
    d1.addContent(&t2);
    d1.print();
    
    Visitor1 v1;
    d1.Accept(&v1);
};
