#include <bits/stdc++.h>
#define pb push_back
using namespace std;
 
string s1,s2;
int l1,l2;
 
int dp[5005][5005][2];
 
 
int findDiff(string &s,int i,int len,char prev){
	int c=0;
	for(int j=i;j<len;j++){
		if(s[j]!=prev){
			c++;
		}
		prev=s[j];
	}
	return c;
 
}
int getMin(int i,int j,int c){
	if(dp[i][j][c]!=-1)
		return dp[i][j][c];
 
	if(i==l1){
		if(c==0){
			return findDiff(s2,j,l2,s1[i-1]);
		}
		else
		{
			return findDiff(s2,j,l2,s2[j-1]);	
		}
	}
 
	if(j==l2){
		if(c==0){
			return findDiff(s1,i,l1,s1[i-1]);
		}
		else
		{
			return findDiff(s1,i,l1,s2[j-1]);	
		}
	}
	int ans=INT_MAX;
	if(c==0){
		if(s2[j]!=s1[i-1]){
			ans=min(ans,1+getMin(i,j+1,1));
		}
		else if(s2[j]==s1[i-1])
		{
			ans=min(ans,getMin(i,j+1,1));
		}	
		if(s1[i]!=s1[i-1])
			ans=min(ans,1+getMin(i+1,j,0));
		else if(s1[i]==s1[i-1])
		{
			ans=min(ans,getMin(i+1,j,0));
		}
	}
	else
	{
		if(s2[j]!=s2[j-1]){
			ans=min(ans,1+getMin(i,j+1,1));
		}
		else if(s2[j]==s2[j-1])
		{
			ans=min(ans,getMin(i,j+1,1));
		}
		if(s1[i]!=s2[j-1])
			ans=min(ans,1+getMin(i+1,j,0));
		else if(s1[i]==s2[j-1])
		
		{
			ans=min(ans,getMin(i+1,j,0));
		}
	}
	return dp[i][j][c]=ans;
}
 
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		
		cin>>s1>>s2;
		l1=s1.length();
		l2=s2.length();
		memset(dp,-1,sizeof(dp));
 
		// cout<<findDiff(s1,1,l1,'a')<<endl;
		cout<<1+min(getMin(0,1,1),getMin(1,0,0))<<endl;
	}
}