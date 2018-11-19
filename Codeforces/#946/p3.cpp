#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;
int dp[100007][30];
string a,b;
int l;

int possib(int i,int j){
	if(j==26)
		return 1;
	if(i==l)
		return 0;

	if(dp[i][j]!=-1)
		return dp[i][j];

	int ans=0;
	if((a[i]==b[j])||((char)(a[i]+1))==b[j]){
		ans = possib(i+1,j+1);
		ans|= possib(i+1,j);
	}
	else
		ans|=possib(i+1,j);

	return dp[i][j]=ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>a;

	int i=0,l=a.length();

	string ans="";
	char c='a';
	while(i<l){
		if(a[i]<=c&&c<='z'){
			ans+=c;
			c++;
			i++;
		}
		else
		{
			ans+=a[i];
			i++;
		}

	}

	if(c>'z')
		cout<<ans<<endl;
	else
		cout<<-1<<endl;




}