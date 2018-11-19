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

#define NOV 300005

int done[NOV];

int a[NOV];
int b[NOV];

int main(){
	ios_base::sync_with_stdio(false);

	int n;
	cin>>n;

	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];

	int curr = 1;
	int c = 0;
	for(int i=1;i<=n;i++){
		if(done[b[i]]){
			cout<<0<<" ";
			continue;
		}
		else
		{
			c = 0;
			while(curr<=n){
				done[a[curr]] = 1;
				c++;
				if(a[curr]==b[i])
					break;
				else
					curr++;
			}
			curr++;
			cout<<c<<" ";
		}
	}
	cout<<endl;

}