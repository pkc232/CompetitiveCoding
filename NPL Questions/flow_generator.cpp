#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

ll randomNumber(){
	ll x1 = rand()%100 +1;
	ll x2 = rand()%100 +1;
	ll x3 = rand()%1000 +1;
	return x1*x2*x3;
}

int main(){
	ofstream fout;
	fout.open("flow_ip3.txt");
	int t =1;
	fout<<t<<endl;
	srand(time(NULL));
	while(t--){
		int n = 2200,k=1200;
		fout<<n<<" "<<k<<endl;
		ll num1,num2;
		for(int i=1;i<=n;i++){
			num1 = randomNumber();
			fout<<num1<<" ";
		}
		fout<<endl;
		for(int i=1;i<=n;i++){
			num1 = randomNumber();
			fout<<num1<<" ";
		}
		fout<<endl;
			
	}
}