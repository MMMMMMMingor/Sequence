#include"Sequence.h"
#include<vector>
#include<algorithm>
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
	string s=sequence;
	vector<string> vs(s.length());
    for(int i = 0;i<s.length();i++)
	{
       vs[i] = s.substr(s.length()-i-1,160);
	}
    sort(vs.begin(),vs.end());
	int maxLen = 0;
    string ret;
    for(int i = 0;i<vs.size()-1;i++){
        string cur = vs[i];
        string suf = vs[i+1];

        int tlen = 0;
        for(int j = 0;j<min(cur.length(),suf.length());j++){
            if(cur[j]!=suf[j]){
                tlen = 0;
                break;
            }
            else if(cur[j]==suf[j]){
                tlen++;
            }
       
            if(tlen>maxLen){
                maxLen =tlen;
                ret = suf.substr(0,maxLen);
            }
        }
    }
	return ret;
	


}



