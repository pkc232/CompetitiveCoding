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

int arr[NOV];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;

	for(int i=1;i<=n;i++)
		cin>>arr[i];

	int curr = arr[1];
	int ptr = 2,nptr;
	int fc = 0;
	while(ptr<n){
		
		if(arr[ptr]==curr){
			fc = 1;
			nptr = ptr;
			while(arr[nptr]==curr){
				fc++;
				nptr++;
				if(nptr>n)
					break;
				else if(fc==5)
					break;
			}
		}
	}
}