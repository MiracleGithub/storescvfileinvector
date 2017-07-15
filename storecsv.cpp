#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
void parse(string& somestring, vector< vector<string> > &attributetable)
{
	int attributeCount = 0;
	vector<string> vectorofstrings;
	while (somestring.length() != 0 && somestring.find(',') != string::npos)
	{
		size_t pos;
		string singleattribute;
		pos = somestring.find_first_of(',');
		singleattribute = somestring.substr(0, pos);
		vectorofstrings.push_back(singleattribute);
		somestring.erase(0, pos+1);
	}
	vectorofstrings.push_back(somestring);
	attributetable.push_back(vectorofstrings);
	vectorofstrings.clear();
}
int main()
{
   char inputFilename[] = "C:\\Users\\miracle\\Desktop\\xyz.csv";

   char outputFilename[] = "out11.csv";
   vector < vector<string> > datatable;
   ifstream inFile;
   ofstream outFile;
   string username;
   size_t i;
   inFile.open(inputFilename, ios::in);
   if (!inFile) {
     cerr << "Can't open input file " << inputFilename << endl;
     exit(1);
   }

   outFile.open(outputFilename, ios::out);
   if (!outFile) {
     cerr << "Can't open output file " << outputFilename << endl;
     exit(1);
   }
   while (getline(inFile,username)) {

    parse( username,datatable);

   }
   inFile.close();
   outFile.close();
   size_t inner, outer;
	for (outer = 0; outer < datatable.size()-1; outer++) {
		for (inner = 0; inner < datatable[outer].size()-1; inner++) {
			cout << datatable[outer][inner] << "\t";
		}
		cout << endl;
	}
	getchar();
   return 0;
}
