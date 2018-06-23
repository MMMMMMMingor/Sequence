#include"Sequence.h"
int main()
{
	Sequence sequence("./dna.txt");
 	cout<<"The sequence length:"<<sequence.length()<<endl;	
	cout<<"The number of A:"<<sequence.numberOf('A')<<endl;
	cout<<"The number of T:"<<sequence.numberOf('T')<<endl;
	cout<<"The number of C:"<<sequence.numberOf('C')<<endl;
        cout<<"The number of G:"<<sequence.numberOf('G')<<endl;	
	cout<<"The longest sequence:"<<sequence.longestConsecutive()<<endl;


	return 0;	

}
