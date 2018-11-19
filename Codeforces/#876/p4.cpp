#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(false)
using namespace std;

ll p[300007];


int main(int argc, char const *argv[])
{
	fast;

	int n;
	cin>>n;
	int arr[n+2];

	for(int i=1;i<=n;i++){
		cin>>p[i];
		arr[i]=0;
	}

	int pointer = n,j;

	cout<<1<<" ";
	for(int i=1;i<=n;i++){
		arr[p[i]]=1;
		if(p[i]==pointer)
		{
			for(j=pointer;j>=1;j--)
			{
				if(arr[j]==0){
					pointer = j;
					break;
				}
			}
			if(j==0){
				cout<<1<<" ";
				break;
			}
		}

		cout<<i-(n-pointer)+1<<" ";
	}
	cout<<endl;
	return 0;
}