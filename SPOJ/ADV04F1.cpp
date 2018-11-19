#include <bits/stdc++.h>
#include <time.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

map<vector<int>,int> dp;
int n = 8;

vector<int> isFeasibleLinear(vector<int> &v, int i){
	vector<int> rv(4);
	for(int j=0;j<4;j++)
	{
		if(i!=j)
			rv[j] = v[j];
	}
	int elem = v[i];
	if(i==3){
		if(v[3]>=n)
		{
			rv[3]=-1;
			return rv;
		}
		rv[3] = v[3]+1;
		return rv;
	}
	if(v[i]+1==v[i+1]){
		rv[i] = -1;
	}
	else
		rv[i] = v[i]+1;

	return rv;

}

int notPresent(std::vector<int> &v,int val){
	for(int i=0;i<4;i++){
		if(v[i]==val)
			return 0;
	}
	return 1;
}

vector<int> isFeasibleSwap(vector<int> &v,int i, int j){
	int e1 = v[i], e2 = v[j];
	vector<int> rv(4);
	for(int k=0;k<4;k++){
		if(k!=i)
			rv[k] = v[k];
	}
	int d;
	if(e1<e2){
		d = e2-e1;
		
		if(e2+d<=n&&notPresent(v,e2+d))
		{
			rv[i] = e2+d;
			sort(rv.begin(), rv.end());
			return rv;
		}
		else
		{
			rv[i] = -1;
			return rv;
		}
	}

	else
	{
		d = e1-e2;
		if(e1-d>=1&&notPresent(v,e1-d)){
			rv[i] = e1-d;
			sort(rv.begin(), rv.end());
			return rv;
		}
		else
		{
			rv[i] = -1;
			return rv;	
		}
	}
}

void printVector(std::vector<int> &v){
	for(int i=0;i<4;i++)
		cout<<v[i]<<" ";
	cout<<endl;
}

int cnt=0;
void getDist(vector<int> v, int d){
	if(dp.find(v)!=dp.end())
		return;
	// if(cnt>10)
	// 	return;
	// cnt++;

	// printVector(v);
	// cout<<"Dist "<<d<<endl;

	dp[v] = d;

	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(i==j)
				continue;
			vector<int> rv = isFeasibleSwap(v,i,j);
			if(rv[i]!=-1)
				getDist(rv,d+1);
		}
	}

	for(int i=0;i<4;i++){
		vector<int> rv = isFeasibleLinear(v,i);
		if(rv[i]!=-1)
			getDist(rv,d+1);
	}

	
}


int main(){
	ios_base::sync_with_stdio(false);
	std::vector<int> v(4);
	v[0] = 1;
	v[1] = 2;
	v[2] = 3;
	v[3] = 4;

	clock_t tStart = clock();
	getDist(v,0);

	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	cout<<"DOne\n";
	int t;
	cin>>t;
	vector<int> tv(4);
	while(t--){
		for(int i=0;i<4;i++)
			cin>>tv[i];
		cout<<dp[tv]<<endl;
	}
}