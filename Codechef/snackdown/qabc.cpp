#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

int A[100005];
int B[100005];

int main(){
	ios_base::sync_with_stdio(false);

	int t,n;
	cin>>t;

	while(t--){
		cin>>n;

		for(int i=1;i<=n;i++)
			cin>>A[i];

		for(int i=1;i<=n;i++)
			cin>>B[i];

		int ind=1;
		int fl=0,c;
		while(ind<=n-2){
			if(A[ind]>B[ind])
			{
				fl=1;
				break;
			}
			c=B[ind]-A[ind];
			A[ind+1] += 2*c;
			A[ind+2] += 3*c;
			ind++;
		}
		if(A[n-1]!=B[n-1])
			fl=1;
		if(A[n]!=B[n])
			fl=1;

		if(fl)
			cout<<"NIE\n";
		else
			cout<<"TAK\n";

	}
}