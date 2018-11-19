#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
using namespace std;

//wont work for 2 2 2 4 5 5 


int main(int argc, char const *argv[])
{
	int n;
	cin>>n;



	ll s1=0,s2=0;

	vector<int> v;
	int c,p;
	for(int i=0;i<n;i++){
		cin>>c>>p;
		for(int j=0;j<c;j++)
			v.pb(p);
	}

	sort(v.begin(), v.end());

	int i=v.size()-1;

	while(i>=0){
		if(s1<=s2)
			s1+=v[i];
		else
			s2+=v[i];
		i--;
	}

	cout<<abs(s1-s2)<<endl;

	return 0;
}