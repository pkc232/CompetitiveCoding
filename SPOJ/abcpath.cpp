#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

char arr[52][52];
int h,w;
int px[3] = {-1,0,1};
int py[3] = {-1,0,1};

int feasible(int i,int j){
	return ((i>=1&&i<=h)&&(j>=1&&j<=w));
}

int maxlen[52][52];

int dfs(int r,int c,int l){

	if(maxlen[r][c]!=-1)
		return maxlen[r][c];

	char curr = arr[r][c];
	int nr,nc;
	char next;
	int mxl = l;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++){
			nr = r+px[i];
			nc = c+py[j];
			if(feasible(nr,nc)){
				next = arr[nr][nc];
				if(next==curr+1)
					mxl = max(mxl,dfs(nr,nc,l+1));
			}
		}

	return maxlen[r][c] = mxl;
}

int main(){
	ios_base::sync_with_stdio(false);

	
	char c;
	int cnt=1;
	while(1){
		// scanf("%d %d",&h,&w);
		cin>>h>>w;
		// cout<<h<<" "<<w<<endl;
		if(h==0&&w==0)
			return 0;

		for(int i=1;i<=h;i++)
			for(int j=1;j<=w;j++)
				cin>>arr[i][j];
		int l = 0;
		for(int i=1;i<=h;i++)
			for(int j=1;j<=w;j++){
				memset(maxlen,-1,sizeof(maxlen));{
				if(arr[i][j] == 'A'){
					l = max(l,1);
					l = max(l,dfs(i,j,1));
				}
				}
			}
		cout<<"Case "<<cnt<<": "<<l<<endl;
		cnt++;
	}
}