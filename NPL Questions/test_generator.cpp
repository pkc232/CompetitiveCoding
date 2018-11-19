#include <bits/stdc++.h>
using namespace std;

int randomNumber(){
	int sign = rand()%2;
	int x1 = rand()%1000 +1;
	int x2 = rand()%1000 +1;
	int x3 = rand()%1000 +1;
	if(sign)
		return x1*x2*x3;
	else
		return -(x1*x2*x3);
}

int main(){
	ofstream fout;
	fout.open("input_restaurants_3.txt");
	int t =8;
	fout<<t<<endl;
	srand(time(NULL));
	while(t--){
		int n = 99999;
		fout<<n<<endl;
		int sign,num1,num2;
		for(int i=1;i<=n;i++){
			num1 = randomNumber();
			num2 = randomNumber();
			fout<<num1<<" "<<num2<<endl;
		}
	}
}