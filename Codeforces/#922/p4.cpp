#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define MOD 1000000007
#define mp make_pair
#define inf 999999
using namespace std;


int hs(string &s){
	int l=s.length();
	ll h=0,st=0;

	for(int i=0;i<l;i++){
		h+=(s[i]=='h');
		st+=(s[i]=='s');
	}
	if(h==0)
		return -inf;
	else if(st==0)
		return inf;
	else if()
	return (h-st);
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);

	int n;
	cin>>n;


	vector<string> v(n);
	vector<pair<ll,int> > arr;

	for(int i=0;i<n;i++){
		cin>>v[i];
		arr.pb(mp(hs(v[i]),i));
	}

	sort(arr.begin(), arr.end());

	ll s=0,cnt=0,l;
	string str;
	for(int i=0;i<n;i++){
		str=v[arr[i].second];
		l=str.length();
		for(int j=0;j<l;j++){
			if(str[i]=='s')
				s++;
			else
				cnt+=(s);
		}
	}

	cout<<cnt<<endl;
	return 0;
}