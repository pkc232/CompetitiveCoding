#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;


int arr[200005];
int cnt[1000007];
ll sum=0;
ll ans[200003];
vector<pair<pair<int,int>,int > >v;

void add(int pos){
	sum-=((cnt[arr[pos]])*(cnt[arr[pos]])*arr[pos]);
	cnt[arr[pos]]++;
	sum+=((cnt[arr[pos]])*(cnt[arr[pos]])*arr[pos]);
}

void remove(int pos){
	sum-=((cnt[arr[pos]])*(cnt[arr[pos]])*arr[pos]);
	cnt[arr[pos]]--;
	sum+=((cnt[arr[pos]])*(cnt[arr[pos]])*arr[pos]);	
}

int sqn;
bool comp(pair<pair<int,int>,int> &p1,pair<pair<int,int>,int> &p2){
	int x=p1.first.first/sqn,y=p2.first.first/sqn;
	if(x==y){
		return p1.first.second<p2.first.second;
	}
	else
	return x<y;
}

int main(){
	arr[0]=0;
	int n,t;
	cin>>n>>t;

	sqn=sqrt(n);
	for(int i=1;i<=n;i++)
		scanf("%d",&(arr[i]));

	memset(cnt,0,sizeof(cnt));


	

	int l,r;
	int cur=0;
	while(cur<t){
		scanf("%d %d",&l,&r);
		v.pb(mp(mp(l,r),++cur));
	} 

	sort(v.begin(), v.end(),comp);
	

	int currentL=0;
	int currentR=0;

	for(int i=0;i<v.size();i++){
		l=v[i].ff.ff;
		r=v[i].ff.ss;
		// cout<<l<<" "<<r<<" "<<sum<<endl;
		while(currentL>l){
			currentL--;
			add(currentL);
		}

		while(currentR<r){
			currentR++;
			add(currentR);
		}

		while(currentL<l){
			remove(currentL);
			currentL++;
		}

		while(currentR>r){
			remove(currentR);
			currentR--;
		}
		ans[v[i].ss]=sum;
	}

	for(int i=1;i<=t;i++){
		printf("%lld\n",ans[i] );
	}



}