#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
// #define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define pii pair<int,int>
using namespace std;

#define NOV 4000000

unordered_map<string,int> mp;
vector<set<int> >gr(NOV);
int cnt = 2;
int stringlen = 10;

void preprocess(string s){
	string temp;
	cout<<"For "<<s<<" "<<mp[s]<<endl;
	for(int i=2;i<=stringlen;i++){
		for(int j=0;j+i<=stringlen;j++){
			temp = s;
			reverse(temp.begin()+j, temp.begin()+j+i);
			// cout<<" reversed "<<temp<<endl;
			// return;
			if(mp.find(temp)==mp.end()){
				mp[temp] = cnt++;
				preprocess(temp);
			}
			// gr[mp[s]].insert(mp[temp]);
		}
	}
}

int bfs(int s,int t){
	int dis[NOV];
	memset(dis,-1,sizeof(dis));

	queue<int> Q;
	Q.push(s);
	dis[s] = 0;
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		for(auto vit = gr[u].begin();vit!=gr[u].end();vit++){
			int v = *vit;
			if(dis[v] == -1){
				dis[v] = dis[u] + 1;
				Q.push(v);
			}
		}
		if(dis[t] != -1)
			return dis[t];
	}
	return dis[t];
}



int main(){
	ios_base::sync_with_stdio(false);

	string base = "abcdefghi";
	stringlen = base.length();
	mp[base] = 1;
	preprocess(base);
	cout<<"DOne\n";
	string x,y;

	while(1){
		cin>>x>>y;
		if(x=="*")
			break;
		cout<<bfs(mp[x],mp[y])<<endl;
	}

}