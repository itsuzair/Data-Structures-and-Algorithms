#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {

	ifstream fin;
	fin.open("file.txt", ios::in);
	int id, typ, ram, storage;
	char delimter = ',';

	while (fin >> id  >> delimter >> typ >> delimter >> ram >> delimter >> storage && delimter == ',') {
		//line by line vars set hote jaenge..
		//har line k lie jo kch b karna he is loop me krlo

		//Determine type(agr file me type 1 he to wo mobile k lie, 1 he to pc
		char *type;
		if (typ == 1) {
			type = "Mobile";
		} else {
			type = "PC";
		}

		//Test cout
		cout << "ID and type : " << id  << " " << type << endl;
	};
	return 0;
}