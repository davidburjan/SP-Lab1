# SP-Lab1
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class Book {
public:
	string nameBook;
	vector <string> paragraphsList;
	vector <string> imagesList;
	vector <string> tablesList;

	void createNewParagraph(string newParagraph) {
		paragraphsList.push_back(newParagraph);
	}
	
	void createNewImage(string newImage) {
		imagesList.push_back(newImage);
	}

	void createNewTable(string newTable) {
		tablesList.push_back(newTable);
	}

	void print() {
		cout << nameBook << "\n";
		for (int i = 0; i < paragraphsList.size; i++) {
			cout<<
		}
	}
};

int main()
{
	Book discoTitanic;
	discoTitanic.nameBook = "Disco Titanic";
	discoTitanic.createNewParagraph("Paragraph 1");
	discoTitanic.createNewParagraph("Paragraph 2");
	discoTitanic.createNewParagraph("Paragraph 3");
	discoTitanic.createNewImage("Image 1");
	discoTitanic.createNewParagraph("Paragraph 4");
	discoTitanic.createNewTable("Table 1");
	discoTitanic.createNewParagraph("Paragraph 5");
	discoTitanic.print();


}
