#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

ll arr[100007];


int allminus(pair<ll,ll> &p){
	for(int i=p.ff;i<=p.ss;i++)
		if(arr[i]!=-1)
			return 0;
	return 1;
}


int incrs(pair<ll,ll> &p){
	ll fl1=0;
	vector<ll> temp(p.ss-p.ff+3);
	int len=p.ss-p.ff+1;
	int i;
	for(i=p.ff;i<=p.ss;){
		if(arr[i]!=-1)
		{
			break;
		}
		i++;
	}
	// cout<<i<<endl;

	temp[i-p.ff+1]=arr[i];
	// cout<<arr[i]<<" fsd"<<endl;
	int left=i-p.ff,right=i+2-p.ff;
	while(left>=1)
	{
		temp[left]=temp[left+1]-1;
		left--;
	}
	while(right<=len){
		// cout<<right<<" "<<temp[right]<<" "<<temp[right-1]<<endl;
		temp[right]=temp[right-1]+1;
		right++;
	}
	// for(int i=1;i<=len;i++)
	// 	cout<<temp[i]<<" ";
	// cout<<endl;
	int c1=p.ff,c2=1;
	while(c1<=p.ss){
		if(arr[c1]==-1)
			continue;
		cout<<arr[c1]<<" "<<temp[c2]<<endl;
		if(temp[c2]!=arr[c1])
			return 0;
		c1++;
		c2++;
	}

	return 1;
}

int decrs(pair<ll,ll> &p){
	ll fl1=0;
	vector<ll> temp(p.ss-p.ff+3);
	int len=p.ss-p.ff+1;
	int i;
	for(i=p.ff;i<=p.ss;){
		if(arr[i]!=-1)
		{
			break;
		}
		i++;
	}
	// cout<<i<<endl;

	temp[i-p.ff+1]=arr[i];
	// cout<<arr[i]<<" fsd"<<endl;
	int left=i-p.ff,right=i+2-p.ff;
	while(left>=1)
	{
		temp[left]=temp[left+1]+1;
		left--;
	}
	while(right<=len){
		// cout<<right<<" "<<temp[right]<<" "<<temp[right-1]<<endl;
		temp[right]=temp[right-1]-1;
		right++;
	}
	for(int i=1;i<=len;i++)
		cout<<temp[i]<<" ";
	cout<<endl;

	int c1=p.ff,c2=1;
	while(c1<=p.ss){
		if(arr[c1]==-1)
			continue;
		cout<<arr[c1]<<" "<<temp[c2]<<endl;
		if(temp[c2]!=arr[c1])
			return 0;
		c1++;
		c2++;
	}
	return 1;
}

ll p = MOD;
ll power(ll x, ll y)
{
    ll res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}

int overlap(pair<ll,ll> &p1,pair<ll,ll> &p2){

	cout<<p1.ff<<" "<<p1.ss<<" "<<p2.ff<<" "<<p2.ss<<endl;
	// if(p1.ff>=p2.ff&&p1.ss<=p2.ss)
	// 	return 1;
	// if(p2.ff>=p1.ff&&p2.ss<=p1.ss)
	// 	return 1;
	if(p1.ff>=p2.ff&&p1.ff<=p2.ss)
		return 1;

	if(p2.ff>=p1.ff&&p2.ff<=p1.ss)
		return 1;

	return 0;
}

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);


	int t;
	cin>>t;
	ll n,m,k,l,r;
	char c;
	vector<pair<ll,ll> > v1,v2;
	vector<pair<ll,ll> > vi,vd;
	while(t--){
	ll minuscnt=0;
		cin>>n>>m>>k;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
			if(arr[i]==-1)
				minuscnt++;
		}
		v1.clear();
		v2.clear();
		vi.clear();
		vd.clear();


		while(m--){
			cin>>c>>l>>r;
			if(c=='I')
				v1.pb(mp(l,r));
			else
				v2.pb(mp(l,r));
		}

		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());

		ll left = 0,right=0;
		for(int i=0;i<v1.size();i++){
			if(v1[i].ff>right){
				vi.pb(mp(left,right));
				left=v1[i].ff;
				right=v1[i].ss;
			}
			else
			{
				right=max(right,v1[i].ss);
			}
		}
		vi.pb(mp(left,right));

		left=0,right=0;
		
		for(int i=0;i<v2.size();i++){
			if(v2[i].ff>right){
				vd.pb(mp(left,right));
				left=v2[i].ff;
				right=v2[i].ss;
			}
			else
			{
				right=max(right,v2[i].ss);
			}
		}
		vd.pb(mp(left,right));
		int i1=1,i2=1,fl=0;
		ll ans=1;
		while(i1<vi.size()&&i2<vd.size()){
			if(overlap(vi[i1],vd[i2]))
				goto no;
			if(vi[i1].ff<vd[i2].ff)
				i1++;
			else
				i2++;
		}

		i1=1;

		cout<<"Hello1\n";

		while(i1<vi.size()){
			if(allminus(vi[i1]))
			{
				int l=vi[i1].ss-vi[i1].ff+1;
				if(l>k)
					goto no;
				ans*=max(k-l+1,0ll);
				ans%=MOD;
			}
			else
			{
				if(!incrs(vi[i1]))
					goto no;
			}
			i1++;
		}
		cout<<"Hello2\n";
		i2=1;
		while(i2<vd.size()){
			if(allminus(vd[i2]))
			{
				int l=vd[i2].ss-vd[i2].ff+1;
				if(l>k)
					goto no;
				ans*=max(k-l+1,0ll);
				ans%=MOD;
			}
			else
			{
				if(!decrs(vd[i2]))
					goto no;
			}
			i2++;
		}
		cout<<"Hello1\n";
		ans*=power(k,minuscnt);
		ans%=MOD;
		cout<<ans<<endl;
		continue;
		no:
		cout<<"kko\n";
		cout<<0<<endl;
	}
}