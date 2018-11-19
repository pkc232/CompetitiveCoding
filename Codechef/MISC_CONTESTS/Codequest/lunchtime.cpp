#include<bits/stdc++.h>
using namespace std;
char ans[1002][1002];
int vis[1001][1001];
void fun(int n,int m,int i,int j,int curr_time,int x)
{
    if(curr_time>x || i<0 || j<0 || i>=n || j>=m )
    return;
    if(vis[i][j])
        return;
    if(ans[i][j]=='B')
    return;
    ans[i][j]='Y';
    vis[i][j]=1;
    fun(n,m,i-1,j,curr_time+1,x);
    fun(n,m,i,j-1,curr_time+1,x);
    fun(n,m,i+1,j,curr_time+1,x);
    fun(n,m,i,j+1,curr_time+1,x);
}
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        memset(ans,'N',sizeof(ans));
        cin>>n>>m;
        int a[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
                if(a[i][j]==-1)
                ans[i][j]='B';
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]>0)
                {
                    ans[i][j]='Y';
                    memset(vis,0,sizeof(vis));
                    fun(n,m,i,j,0,a[i][j]);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            cout<<ans[i][j];
            cout<<"\n";
        }
    }
}
