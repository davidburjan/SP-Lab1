#include<iostream>
#include<strings.h>
#include<vector>
using namespace std;

class Subchapter{
public:
    string subchapter_name;
    vector<string> paragraphs;
    vector<string> tables;
    vector<string> images;

    void add_subchapter_name(string a){
        subchapter_name=a;
    }
};

class Chapter{
public:

    string chapter_name;
    vector<Subchapter> subchapters;

    void add_chapter_name(string a){
        chapter_name=a;
    }

    void add_new_subchapter(Subchapter a){
        subchapters.push_back(a);
    };
    
};

class Book{
public:
    string book_name;
    string book_author;

    void add_book_name(string a){
        book_name = a;
    };

    void add_author_name(string a){
        book_author = a;
    };

    vector<Chapter> chapters;
    void add_new_chapter(Chapter a){
        chapters.push_back(a);
    }

    void createNewTable(string a, int nrSubchapter, int nrChapter){
        chapters[nrChapter-1].subchapters[nrSubchapter-1].tables.push_back(a);
    }

    void createNewParagraph(string a, int nrSubchapter, int nrChapter){
        chapters[nrChapter-1].subchapters[nrSubchapter-1].paragraphs.push_back(a);
    }

    void createNewImage(string a, int nrSubchapter, int nrChapter){
        chapters[nrChapter-1].subchapters[nrSubchapter-1].images.push_back(a);
    }

    void printAll(){
        cout<<book_name<<" by "<<book_author<<"\n";

        for( int i=0; i<chapters.size(); i++){
            cout<<"Chapter: "<<chapters[i].chapter_name<<"\n";

            for( int j=0; j<chapters[i].subchapters.size(); j++){
                cout<<"Subchapter: "<<chapters[i].subchapters[j].subchapter_name<<"\n";

                for( int g=0; g<chapters[i].subchapters[j].paragraphs.size(); g++){
                    cout<<"Paragraph: "<<chapters[i].subchapters[j].paragraphs[g]<<"\n";
                }

                for( int g=0; g<chapters[i].subchapters[j].images.size(); g++){
                    cout<<"Image with name: "<<chapters[i].subchapters[j].images[g]<<"\n";
                }

                for( int g=0; g<chapters[i].subchapters[j].tables.size(); g++){
                    cout<<"Table with title: "<<chapters[i].subchapters[j].tables[g]<<"\n";
                }

            }
        }        
    }
};

int main(){

    Book discoTitanic;
    discoTitanic.add_book_name("Disco Titanic");
    discoTitanic.add_author_name("Radu Pavel Gheo");
    
    Chapter chp_1;
    chp_1.add_chapter_name("Capitolul 1");
    discoTitanic.add_new_chapter(chp_1);

    Subchapter schp_1_1;
    schp_1_1.add_subchapter_name("Subcapitolu 1.1");
    discoTitanic.chapters[0].add_new_subchapter(schp_1_1);

    discoTitanic.createNewParagraph("Paragraph 1",1,1);
    discoTitanic.createNewParagraph("Paragraph 2",1,1);
    discoTitanic.createNewParagraph("Paragraph 3",1,1);
    discoTitanic.createNewImage("Image 1",1,1);
    discoTitanic.createNewParagraph("Paragraph 4",1,1);
    discoTitanic.createNewTable("Table 1",1,1);
    discoTitanic.createNewParagraph("Paragraph 5",1,1);

    discoTitanic.printAll();
    
};

