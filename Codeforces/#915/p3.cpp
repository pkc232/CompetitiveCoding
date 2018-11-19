#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
using namespace std;

int cnt[10];
string s1,s2;

int main(int argc, char const *argv[])
{
		
	cin>>s1>>s2;
	int l1=s1.length(),l2=s2.length();
	if(l1<l2){
		sort(s1.rbegin(),s1.rend());
		cout<<s1<<endl;
	}
	else
	{
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<l1;i++)
			cnt[s1[i]-'0']++;
		string ans="";
		int i,j;
		for(i=0;i<l2;i++){
			if(cnt[s2[i]-'0']){
				ans+=(char)(s2[i]);
				cnt[s2[i]-'0']--;
			}
			else
				break;
		}
		if(i==l2){
			cout<<ans<<endl;
		}
		else
		{
			if(i<l2){
				for(j=s2[i]-'0'-1;j>=0;j--){
					if(cnt[j]){
						ans+=(char)('0'+j);
						cnt[j]--;
						break;
					}
				}
				if(j<0){
					int ind=-1;
					i--;
					while(i>=0){
						cnt[s2[i]-'0']++;
						for(j=s2[i]-'0'-1;j>=0;j--){
							if(cnt[j])
							{
								ind=j;
								cnt[j]--;
								break;
							}
						}
						if(ind!=-1)
							break;
						i--;
					}
					string finans = ans.substr(0,i);
					finans+=(char)('0'+ind);
					string temp="";
					for(int p=0;p<10;p++){
						while(cnt[p]){
							temp+=(char)('0'+p);
							cnt[p]--;
						}
					}
					sort(temp.rbegin(),temp.rend());
					finans+=temp;
					cout<<finans<<endl;
				}
				else
				{
					string temp="";
					for(int p=0;p<10;p++){
						while(cnt[p]){
							temp+=(char)('0'+p);
							cnt[p]--;
						}
					}
					sort(temp.rbegin(),temp.rend());
					ans+=temp;
					cout<<ans<<endl;
				}

			}
		}
	}

	return 0;
}