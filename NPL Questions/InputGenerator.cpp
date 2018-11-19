#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main()
{
	ofstream fout; fout.open("Input3.txt");
	int T;
	cout<<"Number of Test Cases : "; 
	cin>>T;
	cout<<endl;
	fout<<T<<endl;
	srand(time(NULL));
	for(int i=1;i<=T;i++){
		int N;
		cout<<"Test Case "<<i<<endl;
		cout<<"Number of Boxes : "; 
		N = rand()%100000+1; cout<<N<<endl;
		fout<<N<<endl;
		for(int j=0;j<N;j++)
		{
			int c = rand()%1000000000+1;
			fout<<c<<" ";
		}
		fout<<endl;
	}
	
}
