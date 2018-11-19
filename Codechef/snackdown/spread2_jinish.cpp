#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        
        for( int i=0; i<n; i++ )
            cin>>a[i];
        
        int days = 0;
        int curinc = 1, newinc;
        int ptr = 1;
        
        for( days=1; days<n; days++ )
        {
            newinc = curinc;
            for( int i=0; i<curinc && ptr<n; i++, ptr++ )
                newinc += a[ptr];
            curinc = newinc;
            
            if( ptr==n )
                break;
        }
        
        cout<<days<<endl;
    }
    
    return 0;
}