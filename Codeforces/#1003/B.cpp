#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

string bf = "",af="";
string s = "0";
int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	int a,b,x;
	cin>>a>>b>>x;
	int na=a,nb=b,nx=x;

	
	int cur=1;
	int zr=1,on=0;
	while(x){
		s+='0'+cur;
		on+=cur;
		zr+=1-cur;
		x--;
		cur=1-cur;
	}
	a-=zr;b-=on;
	// cout<<a<<endl;
	if(a<0){
		// cout<<"fsd\n";
		s="1";
		a=na,b=nb,x=nx;
		int cur=0;
	int zr=0,on=1;
	while(x){
		s+='0'+cur;
		on+=cur;
		zr+=1-cur;
		x--;
		cur=1-cur;
	}
	// cout<<s<<endl;
	a-=zr,b-=on;
	}
	while(a--){
		bf+='0';
	}
	while(b--){
		af+='1';
	}
	cout<<bf+s+af<<endl;

}