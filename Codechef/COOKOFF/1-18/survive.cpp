#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,k,s;
		cin>>n>>k>>s;

		int count=0, days=0, shop=0;
		int i=1;
		while(i<=s){
			if(i%7)
				days++;
			count-=k;
			while(count<0)
			{
				if(days)
				{
					days--;
					count+=n;
					shop++;
				}
				else
					break;
			}
			if(count<0)
				goto no;
			i++;
		}
		cout<<shop<<endl;
		continue;
		no:
			cout<<"-1"<<endl;
	}
}