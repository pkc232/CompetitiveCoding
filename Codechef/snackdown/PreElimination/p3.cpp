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

char arr[NOV];

int main(){
	ios_base::sync_with_stdio(false);

	int t,n;
	cin>>t;

	while(t--){
		cin>>n;
		char x;

		ll hashcnt = 0, indexsum = 0, finans =0 ;
 		for(ll i=1;i<=n;i++){
			cin>>arr[i];
			if(arr[i]=='#'){
				hashcnt++;
				indexsum += i;
			} 	
		}
		finans = indexsum - (hashcnt*(hashcnt+1))/2;
		ll ptr =1;
		
		while(ptr<=n && arr[ptr]=='#')
			ptr++;

		ll def = 0;

		while( ptr<=n )
		{
			if( arr[ptr]=='#' )
			{
				finans += 2*def;
				def++;
				ptr++;
			}
			else
			{
				def = max(0ll, def-1);
				ptr++;
			}
		}

		if( def > 0 )
			cout<<"-1\n";
		else
			cout<<finans<<endl;
	}

	return 0;
}