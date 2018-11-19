#include <bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define pb push_back
using namespace std;

int l1,l2;
string s1,s2;
int k;
bool check(int ind){
	int i=0,c=0;

	while(i<l2){
		if(s1[ind]!=s2[i])
			c++;
		i++;
		ind++;
	}
	return c<=k;
}


int main(int argc, char const *argv[])
{
	
	int t;
	cin>>t;
	while(t--){
		cin>>s1>>s2;
		cin>>k;
		int m = s2.length();
		k=m-k;
		l1=s1.length();
		l2=s2.length();
		bool ans=0;
		for(int i=0;i<=l1-l2;i++){
			ans|=check(i);
	
		}
			if(ans)
				cout<<"Yes\n";
			else
				cout<<"No\n";
	}

	return 0;
}