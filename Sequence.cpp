#include"Sequence.h"
#include<vector>
#include<algorithm>
Sequence::Sequence(string filename)
{
	ifile.open(filename);
	string tmp;
        getline(ifile,sequence);
        while(getline(ifile,tmp) )
        {
                sequence+=tmp;

        }

}

int Sequence::length()
{
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
	int site=0;
	for(int i=1;i<sequence.length();i++)
	{
		if(sequence[i]==tmpchar&&sequence[i+length]==tmpchar) tmplength++;
		else
		{
			if(tmplength>length)
			{
				length=tmplength;
				longest=tmpchar;
				site=i;
			}
			tmpchar=sequence[i];
			tmplength=1;
		}
	
	}
	
	
	return sequence.substr(site-length,length);
}



string Sequence::longestRepeated()
{
	vector<string> vs(sequence.length());
        for(int i = 0;i<sequence.length();i++)
 	{
        vs[i] = sequence.substr(sequence.length()-i-1,500);
	}
        sort(vs.begin(),vs.end());
	int maxLen = 0;
        string ret;
        for(int i = 0;i<vs.size()-1;i++){
        string cur = vs[i];
        string next = vs[i+1];

        int tmplen = 0;
        for(int j = 0;j<min(cur.length(),next.length());j++)
	{
	            if(cur[j]!=next[j]){ tmplen = 0;break;}
    	        else if(cur[j]==next[j]){tmplen++;
        }
       
            if(tmplen>maxLen)
		{
                maxLen =tmplen;
                ret = next.substr(0,maxLen);
                }
        }
    }
	return ret;
	


}



