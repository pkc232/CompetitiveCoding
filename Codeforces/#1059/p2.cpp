#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;


int n,m;
char arr[1007][1007];
char temp[1007][1007];
int checkRow(int r,int c){
	for(int i=0;i<3;i++)
	{
		if(arr[r][c+i]=='.')
			return false;
	}
	return true;
}

int checkCol(int r,int c){
	for(int i=0;i<3;i++){
		if(arr[r+i][c]=='.')
			return false;
	}
	return true;
}

void colorRow(int r,int c){
	for(int i=0;i<3;i++)
		temp[r][c+i]='#';
}

void colorCol(int r,int c){
	for(int i=0;i<3;i++)
		temp[r+i][c]='#';
}


int same(){
	// for(int i=1;i<=n;i++)
	// 	{for(int j=1;j<=m;j++)
	// 				cout<<temp[i][j];
	// 				cout<<endl;}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(arr[i][j]!=temp[i][j])
				return false;
		}
		return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>n>>m;
	



	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>arr[i][j];

	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			temp[i][j]='.';

	

	for(int i=1;i<=n-2;i++){
		for(int j=1;j<=m-2;j++){
			int x = checkRow(i,j);
			// cout<<x<<endl;
			x &= checkRow(i+2,j);//cout<<x<<endl;
			x &= checkCol(i,j);//cout<<x<<endl;
			x &= checkCol(i,j+2);//cout<<x<<endl;
			if(x){
				colorRow(i,j);
				colorRow(i+2,j);
				colorCol(i,j);
				colorCol(i,j+2);
			}
		}
	}

	if(same())
		cout<<"YES\n";
	else
		cout<<"NO\n";


}