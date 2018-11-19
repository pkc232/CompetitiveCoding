#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

int n;
ll a[100007];
int dp[100007][3];
ll mx = INT_MAX;

ll minNo(int i,int w){
	int left = i, right = n-i+1;
	if(left>right)
		return 0;
	ll elem1,elem2;
	if(w)
	{
		elem1 = a[n-(i-1)+1];
		elem2 = a[i-1];
	}
	else
	{
		elem1 = a[i-1];
		elem2 = a[n-(i-1)+1];
	}
	ll ans = mx;
	int l0=-1,r0=-1,l1=-1,r1=-1;
	if(left%2){
		l0 = (a[left]>elem1);
		l1 = (a[right]>elem1);
	}
	else{
		l0 = (a[left]<elem1);
		l1 = (a[right]<elem1);
	}
	if(right%2){
		r0 = (a[right]>elem2);
		r1 = (a[left]>elem2);
	}
	else{
		r0 = (a[right]<elem2);
		r1 = (a[right]<elem2);
	}


	if(l0&&r0){
		if(left+1==right){
			if(a[left]>a[right])
				ans = min(ans,minNo(i+1,0));
		}
		else
			ans = min(ans,minNo(i+1,0));
	}


	if(l1&&r1){
		if(left+1==right){
			if(a[left]<a[right])
				ans=min(ans,1+minNo(i+1,1));
		}
		else
			ans = min(ans,1+minNo(i+1,0));
	}
	return ans;
}

ll minNo1(int i,int w){
	int left = i, right = n-i+1;
	if(left>right)
		return 0;
	ll elem1,elem2;
	if(w)
	{
		elem1 = a[n-(i-1)+1];
		elem2 = a[i-1];
	}
	else
	{
		elem1 = a[i-1];
		elem2 = a[n-(i-1)+1];
	}
	ll ans = mx;
	int l0=-1,r0=-1,l1=-1,r1=-1;
	if(left%2){
		l0 = (a[left]<elem1);
		l1 = (a[right]<elem1);
	}
	else{
		l0 = (a[left]>elem1);
		l1 = (a[right]>elem1);
	}
	if(right%2){
		r0 = (a[right]<elem2);
		r1 = (a[left]<elem2);
	}
	else{
		r0 = (a[right]>elem2);
		r1 = (a[right]>elem2);
	}


	if(l0&&r0){
		if(left+1==right){
			if(a[left]<a[right])
				ans = min(ans,minNo(i+1,0));
		}
		else
			ans = min(ans,minNo(i+1,0));
	}


	if(l1&&r1){
		if(left+1==right){
			if(a[left]>a[right])
				ans=min(ans,1+minNo(i+1,1));
		}
		else
			ans = min(ans,1+minNo(i+1,0));
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		a[0] = INT_MIN;
		if(n%2)
			a[n+1] = INT_MIN;
		else
			a[n+1] = INT_MAX;
		for(int i=0;i<=n+1;i++)
			cout<<a[i]<<" ";
		cout<<endl<<endl;
		ll ans1 = minNo(1,0);
		a[0]=-a[0];
		a[n+1]=-a[n+1];
		ll ans2 = minNo1(1,0);
		cout<<ans1<<" "<<ans2<<endl;
		cout<<min(ans1,ans2)<<endl;
	}

}