#include <bits/stdc++.h>
using namespace std;

bool present(int num){
	while(num){
		if((num%10)==7)
			return 1;
		num/=10;
	}
	return 0;
}

int main(){
	int x,hh,mm;
	cin>>x>>hh>>mm;
	int c=0;
	while(1){
		if(present(hh)|present(mm))
			break;
		mm-=x;
		c++;
		if(mm<0){
			hh--;
			mm+=60;
		}
		if(hh<0){
			hh+=24;
		}
	}

	cout<<c<<endl;

}