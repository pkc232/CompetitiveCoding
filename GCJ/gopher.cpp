#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

int done[1003][1003];

int hogya(int x,int y){
	int c=0;
	c+=done[x][y];
	c+=done[x][y-1];
	c+=done[x][y+1];
	c+=done[x-1][y];
	c+=done[x-1][y-1];
	c+=done[x-1][y+1];
	c+=done[x+1][y];
	c+=done[x+1][y-1];
	c+=done[x+1][y+1];

	return (c==9);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int a,x,y,p,q;
		cin>>a;
		int cnt=1000;
		memset(done,0,sizeof(done));
		x=500,y=500;
		while(cnt--){
			cout<<x<<" "<<y<<endl;
			cin>>p>>q;

			if(p==0&&q==0)
				break;
			done[p][q]=1;

			if(hogya(x,y)){
				if(x<999)
					x++;
				else
					y++;
			}
		}	
	}
}