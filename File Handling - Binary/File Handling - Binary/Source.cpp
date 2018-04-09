#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream fout("file.dat", ios::binary);
	char str[] = "Hello World";
	int x = 10;
	double y = 3.45148;
	fout.write(str, strlen(str));
	fout.write((char *)&x, sizeof(x));
	fout.write((char *)&y, sizeof(y));
	fout.close();

	char str2[9];
	int a;
	double b;
	ifstream fin("file.dat", ios::binary);
	if (fin.is_open()) {
		fin.read((char *) str2, strlen(str));
		cout << str2 << endl;
		fin.read((char *) &a, sizeof(x));
		cout << a << endl;
		fin.read((char *) &b, sizeof(y));
		cout << b << endl;
	}
	else {
		cout << "Error opening file.";
	}
	fin.close();
	return 0;
}