#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define pii pair<int,int>
#define large_int 2139062143
#define large_long_long_int 9187201950435737471
using namespace std;

#define NOV 100005

int check(double d)
{
	return ((d*d-4*d)>=0);
}

int main(){
	// ios_base::sync_with_stdio(false);

	int t;
	cin>>t;
	while(t--){
		double d;
		cin>>d;
		double a = 0, b = 0;
		if(d==0){
			printf("Y ");
			printf("%.8f %.8f\n",a,b);
			continue;
		}

		if(check(d)){
			double disc = d*d-4*d;
			disc = sqrt(disc);
			double a1 = (d+disc)/(2);
			double a2 = (d-disc)/(2);

			if(a1>1){
				b = a1;
				a = b/(b-1);
				// if(a+b==d&&(a*b)==d)
				{
					
				printf("Y ");
				printf("%.9f %.9f\n",a,b);
				continue;
				}
			}
			if(a2>1){
				b = a2;
				a = b/(b-1);
				// if(a+b==d&&(a*b)==d)
				{
					
				printf("Y ");
				printf("%.9f %.9f\n",a,b);
				continue;
				}
			}
		}

		printf("N\n");
	}
}