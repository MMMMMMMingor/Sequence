#include"Sequence.h"
Sequence::Sequence(string filename)
{
	ifile.open(filename);
}
int Sequence::length()
{
	string tmp;
	getline(ifile,sequence);
	while(getline(ifile,tmp) )
        {
		sequence+=tmp;

	}

	return sequence.length();

}


int Sequence::numberOf(char base)
{
	int number=0;
	for(int i=0;i<sequence.length();i++)
	{
		if(sequence[i]==base) number++;
	}
	return number;
}


string Sequence::longestConsecutive()
{
	char tmpchar=sequence[0];
	char longest=sequence[0];
	int tmplength=1;
	int length=1;
	for(int i=1;i<sequence.length();i++)
	{
		if(sequence[i]==tmpchar) tmplength++;
		else
		{
			if(tmplength>length)
			{
				length=tmplength;
				longest=tmpchar;
			}
			tmpchar=sequence[i];
			tmplength=1;
		}
	
	}
	
	string longestConse;
	string tmpstring="a";
	tmpstring[0]=longest;
	longestConse[0]=longest;
	for(int i=0;i<length;i++)	
	{
		longestConse+=tmpstring;
	}

	return longestConse;
}

string Sequence::longestRepeated()
{



}
