#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define pii pair<int,int>
#define large_int 2139062143
#define large_long_long_int 9187201950435737471
using namespace std;

#define NOV 100005


int main(){
	ios_base::sync_with_stdio(false);


	int t,l;
	cin>>t;
	string s;
	while(t--){
		cin>>s;
		s += s[0];
		l = s.length();
		int lo= -1 ,hi = -1;
		for(int i=0;i<l-1;i++){
			if(s[i]==s[i+1]){
				lo = i+1;
				break;
			}
		}
		if(lo==-1)
		{
			cout<<"yes\n";
			continue;
		}
		else
		{
			hi = lo+1;
			while(hi<l){
				if(s[hi]==s[hi-1]){
					break;
				}
				hi++;
			}
			// cout<<"lo: "<<lo<<" hi:"<<hi<<endl;
			reverse(s.begin()+lo,s.begin()+hi);
			// cout<<"New "<<s<<endl;
			int fl = 0;
			for(int i=0;i<l-1;i++){
				if(s[i]==s[i+1])
				{
					fl=1;
					break;
				}
			}
			if(fl)
				cout<<"no\n";
			else
				cout<<"yes\n";
		}
	}
}