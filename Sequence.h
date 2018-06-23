#ifndef SEQUENCE_H
#define SEQUENCE_H
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;
class Sequence
 {
    public:
	Sequence(string);
	int length();
	int numberOf(char);
	string longestConsecutive();
	string longestRepeated();
    private:
	string sequence;
	ifstream ifile;	
 };



#endif
