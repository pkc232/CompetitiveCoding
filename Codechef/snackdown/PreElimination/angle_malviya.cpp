#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define eps 0.000000000001
#define pi 3.141592653589793

#define ll long long int
#define pb push_back
#define iosbase ios_base::sync_with_stdio(false)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define sc scanf
#define pr printf
#define ub upper_bound
#define lb lower_bound

ll a[1010];
vector<pair<ll,ll> > v;
ll t,n,p,q; 

ll validd(ll x,ll y,ll z)
{
	if(x>=y+z)
		return 0;
	if(y>=x+z)
		return 0;
	if(z>=x+y)
		return 0;
	if(x<=abs(y-z))
		return 0;
	if(y<=abs(x-z))
		return 0;
	if(z<=abs(x-y))
		return 0;
	return 1;
}

ll fun(ll x,ll y)
{
	ll ans=-1;
	ll l=0;
	ll r=n-1;
	while(l<=r)
	{
		ll mid=l+(r-l)/2;
		if(validd(a[x],a[y],a[mid]))
		{
			if( (a[x]*a[x]+a[y]*a[y]-a[mid]*a[mid]) * q >= p * (2*a[x]*a[y]) )
			{
				l=mid+1;
				if(mid!=x&&mid!=y)
					ans=mid;
			}
			else
			{
				r=mid-1;
			}
		}
		else
		{
			if(a[mid]>=a[x]+a[y])
				r=mid-1;
			else
				l=mid+1;
		}
	}
	return ans;
}

int main()
{
    scanf("%lld",&t);
    while(t--)
    {
    	v.clear();
    	scanf("%lld%lld%lld",&n,&p,&q);
    	for(ll i=0;i<n;++i)
    	{
    		scanf("%lld",&a[i]);
    		v.pb({a[i],i+1});
    	}

    	ll ax,ay,az;
    	ll ap,aq;
    	ax=ay=az=ap=aq=-1;

    	sort(v.begin(),v.end());

    	for(ll i=0;i<n;++i)
    		a[i]=v[i].first;

    	for(ll i=0;i<n;++i)
    	{
    		for(ll j=i+1;j<n;++j)
    		{
    			ll in=fun(i,j);
    			if(in!=-1)
    			{
    				if(ax==-1)
    				{
    					ax=in;
    					ay=i;
    					az=j;
    					ap=(a[i]*a[i]+a[j]*a[j]-a[in]*a[in]);
    					aq=(2*a[i]*a[j]);
    				}
    				else if( (a[i]*a[i]+a[j]*a[j]-a[in]*a[in])*aq < ap*(2*a[i]*a[j]) )
    				{
    					ax=in;
    					ay=i;
    					az=j;
    					ap=(a[i]*a[i]+a[j]*a[j]-a[in]*a[in]);
    					aq=(2*a[i]*a[j]);
    				}
    			}
    		}
    	}
    	if(ax==-1)
    		cout<<-1<<endl;
    	else
    		cout<<v[ax].second<<" "<<v[ay].second<<" "<<v[az].second<<endl;
    }
    return 0;
}
