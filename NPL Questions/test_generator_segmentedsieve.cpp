#include <bits/stdc++.h>
using namespace std;


#define tp5 100000
int randomNumber(){
	int x1 = rand()%1000 +1;
	int x2 = rand()%1000 +1;
	int x3 = rand()%1000 +1;
	return x1*x2*x3;
}

int randomAround(){
	int num = rand()%tp5;
	return num;
}

int main(){
	ofstream fout;
	fout.open("input_segmented_4.txt");
	int t =5,l,r,Q,n;
	fout<<t<<endl;
	srand(time(NULL));
	while(t--){
		r = randomNumber();
		// cout<<r<<endl;
		if(r<=tp5){
			l=r;
			r+=tp5;
		}
		else
		{
			l=r-tp5;
		}
		Q=99999;
		fout<<l<<" "<<r<<" "<<Q<<endl;
		while(Q--){
			r=randomAround();
			fout<<l+r<<endl;
		}

	}
}