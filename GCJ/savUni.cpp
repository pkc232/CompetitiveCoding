#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;
ll d;
string p;
int l;
ll curp = 1;
int lfnc(){
	int pos=-1;
	curp=1;
	for(int i=0;i<l-1;i++){
		if((p[i]=='C')&&(p[i+1]=='S')){
			pos=max(pos,i);
		}
		if(p[i]=='C'){
			int fl=0;
			for(int j=i+1;j<l;j++){
				if(p[j]=='S'){
					fl=1;break;
				}
			}
			if(fl)
				curp*=2;
		}

	}
	return pos;
}

int main(){
	int t;
	cin>>t;

	
	for(int ti=1;ti<=t;ti++){
		cin>>d>>p;
		ll tot=0,cur=1;
		l = p.length();
		int i,j;
		cout<<"Case #"<<ti<<":"<<" ";
		for(i=0;i<l;i++)
		{
			if(p[i]=='S')
				tot+=cur;
			else
				cur*=2;
		}
		ll swc=0;
		
		int pos;
		while(tot>d){
		// cout<<"Now "<<tot<<endl;
		pos = lfnc();
		if(pos==-1)
			goto impos;
		swap(p[pos],p[pos+1]);
		swc++;
		// cout<<pos<<" "<<curp<<endl;
		tot-=curp;
		tot+=(curp/2);
		}

		cout<<swc<<endl;
		continue;

		impos:
		cout<<"IMPOSSIBLE"<<endl;

	}

}