#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

vector<pair<int,int> >d;
int cont[100007];

int main(){
	ios_base::sync_with_stdio(false);
	int n,k,x,u,v;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x;
		d.pb(mp(x,i));
	}
	sort(d.begin(), d.end());

	if((d[1].ff == 0) || (d[0].ff != 0))
	{
		cout<<-1<<endl;
		return 0;
	}
	// for(int i=0;i<n;i++)
	// {
	// 	cout<<d[i].ff<<" "<<d[i].ss<<endl;
	// }
	int cur = 0;
	queue<int> Q1,Q2;
	Q1.push(d[0].ss);
	int i = 1;
	stack<int> s;
	vector<pair<int,int> > ans;
	while(1){
		while(i<n){
			if(d[i].ff==cur+1)
			{
				// cout<<"pushing "<<d[i].ss<<endl;
				s.push(d[i].ss);
				i++;
			}
			else
				break;
		}
		if(s.empty())
		{
			cout<<-1<<endl;
			return 0;
		}
		while(!s.empty()){
			u = s.top();
			s.pop();
			v = Q1.front();
			Q1.pop();
			ans.pb(mp(u,v));
			cont[v]++;
			// cout<<"making "<<u<<" "<<v<<" "<<cont[v]<<endl;
			if(cont[v]>k)
			{
				cout<<-1<<endl;
				return 0;
			}
			Q1.push(v);
			Q2.push(u);
			cont[u] = 1;
		}
		cur++;
		Q1=Q2;
		Q2 = queue<int>();
		if(i==n)
			break;
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
		cout<<ans[i].ff<<" "<<ans[i].ss<<endl;

}