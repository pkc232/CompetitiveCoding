#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;
ll arr[100007];
ll b[100007];
ll maxS;
int n;
map<ll,vector<int> > indices;

int overlap(int k, int i1, int i2){
	i1=min(i1,i2);
	i2=max(i1,i2);
	if(min(n,i1+k)>=max(i2-k,1))
		return 1;
	else
		return 0;	
}

int isPossib(int k){
	memset(b,0,sizeof(b));
	auto it = indices.begin();
	ll lowest = 1;
	cout<<"K is "<<k<<endl;
	while(it!=indices.end()){
		ll elem = it->first;
		// cout<<"Current element "<<elem<<endl;

		vector<int> ind = it->second;
		unordered_set<ll> isPresent;
		for(int i=0;i<ind.size();i++){
			isPresent.insert(ind[i]);
		}
		for(int i=0;i<ind.size();i++){
			
			int lo = max(1,ind[i]-k);
			int hi = min(n,ind[i]+k);
			ll mx = 0;

			for(int j=lo;j<=hi;j++){
				if(isPresent.find(j)==isPresent.end())
					mx = max(mx,b[j]);
			}
			b[ind[i]] = mx+1;
			// cout<<ind[i]<<" "<<b[ind[i]]<<endl;
		}

		stack<int> s;
		int i=0;
		while(i<ind.size()){
			if(s.empty())
				s.push(ind[i]);
			else{
			int index = s.top();
			if(overlap(k,ind[i],index)){
				s.push(ind[i]);
			}
			else
			{
				vector<int> temp;
				ll mx = 0;
				while(!s.empty()){
					index = s.top();
					s.pop();
					mx = max(mx,b[index]);
					temp.pb(index);
				}
				for(int j=0;j<temp.size();j++)
					b[temp[j]] = mx;
			}	
			}
			
			i++;
		}
		{
		ll mx = 0;
		int index;
		vector<int> temp;
		while(!s.empty()){
			index = s.top();
			s.pop();
			mx = max(mx,b[index]);
			temp.pb(index);
		}
		for(int j=0;j<temp.size();j++)
					b[temp[j]] = mx;
			}
		it++;
	}
	ll s =0;
	for(int i=1;i<=n;i++)
		s+=b[i];

	

	for(int i=1;i<=n;i++)
		cout<<b[i]<<" ";
	cout<<endl<<endl;
	return s<=maxS;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>maxS;
		ll ans = 0;
		indices.clear();
		for(int i=1;i<=n;i++){
			cin>>arr[i];
			indices[arr[i]].pb(i);
		}
		ll lo =1,hi=n,mid;

		while(lo<=hi){
			mid = lo + (hi-lo)/2;
			if(isPossib(mid))
			{
				ans=max(ans,mid);
				lo=mid+1;
			}
			else
			{
				hi=mid-1;
			}
		}
		cout<<ans+1<<endl;
	}
}