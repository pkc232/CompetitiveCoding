#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define MAXN 65536
#define MAXLG 17
using namespace std;


int N;


struct entry{
	int nr[2];
	int p;
}L[MAXN];

int P[MAXLG][MAXLG];

int stp,cnt;

int cmp(struct entry a,struct entry b){
	if(a.nr[0]==b.nr[0])
		return a.nr[1]<b.nr[1];
	else
		return (a.nr[0]<b.nr[0]);
}

int lcp(int x, int y)
{
 int k, ret = 0; 

 if (x == y) 
    return N - x;
 
 for (k = stp - 1; k >= 0 && x < N && y < N; k --)
            if (P[k][x] == P[k][y])
                x += 1 << k, y += 1 << k, ret += 1 << k; 

return ret;
} 

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	string s;
	cin>>s;
	int i;
	N=(int)s.size();
	for(i=0;i<N;i++)
		P[0][i]=s[i]-'a';

	for(stp=1, cnt = 1; cnt < N; stp++, cnt *= 2)
    {
        for(i=0; i < N; i++)
        {
            L[i].nr[0]=P[stp- 1][i];
            L[i].nr[1]=i +cnt <N? P[stp -1][i+ cnt]:-1;
            L[i].p= i;
        }
        sort(L, L+N, cmp);
        for(i=0; i < N; i++)
            P[stp][L[i].p] =i> 0 && L[i].nr[0]==L[i-1].nr[0] && L[i].nr[1] == L[i- 1].nr[1] ? P[stp][L[i-1].p] : i;
    }
    cout<<"Computed\n";
    for(i=0;i<N;i++)
    {
    	cout<<P[stp-1][i]<<endl;
    }

     return 0;


}