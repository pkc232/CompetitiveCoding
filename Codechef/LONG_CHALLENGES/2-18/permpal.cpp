#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
using namespace std;


int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int l=s.length();
		vector<pair<char,int> > v;
		for(int i=0;i<l;i++)
		{
			v.pb(mp(s[i],i+1));
		}
		sort(v.begin(), v.end());

		vector<int> ans(l);
		int i=0,j=l-1,ind=0;
		int wrngind = -1;
		while(i<j){
			if(v[ind].first==v[ind+1].first){
				ans[i]=v[ind].second;
				ans[j]=v[ind+1].second;
				ind+=2;
				i++;
				j--;
			}
			else{
				if(wrngind!=-1)
					goto no;
				wrngind = ind;

			}
		}

		if(i==j){
			if(wrngind==-1)
			ans[i]=v[ind].second;
			else
				ans[i]=v[wrngind].second;
		}


		yes:
		for(i=0;i<l;i++)
			cout<<ans[i]<<" ";
		cout<<endl;
		continue;
		no:
		cout<<-1<<endl;

	}
	return 0;
}



