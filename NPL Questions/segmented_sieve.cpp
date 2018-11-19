    #include <bits/stdc++.h>
    #define ll long long int
    #define pb push_back
    #define MAX 46656
    #define LMT 216
    #define LEN 4830
    #define RNG 100032
    #define large 1000000007

    using namespace std;


    ll base[MAX/64], segment[RNG/64], primes[LEN];

    #define sq(x) ((x)*(x))
    #define mset(x,v) memset(x,v,sizeof(x))
    #define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
    #define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))

    vector<ll> primeNos;
    /* Generates all the necessary prime numbers and marks them in base[]*/
    void sieve()
    {
        ll i, j, k;
        for(i=3; i<LMT; i+=2)
            if(!chkC(base, i))
                for(j=i*i, k=i<<1; j<MAX; j+=k)
                    setC(base, j);
        for(i=3, j=0; i<MAX; i+=2)
            if(!chkC(base, i))
                primes[j++] = i;
    }

    /* Returns the prime-count within range [a,b] and marks them in segment[] */
    ll segmented_sieve(ll a, ll b)
    {
        ll i, j, k, cnt = (a<=2 && 2<=b)? 1 : 0;
        if(b<2) return 0;
        if(a<3) a = 3;
        if(a%2==0) a++;
        memset(segment,0,sizeof segment);
        for(i=0; sq(primes[i])<=b; i++)
        {
            j = primes[i] * ( (a+primes[i]-1) / primes[i] );
            if(j%2==0) j += primes[i];
            for(k=primes[i]<<1; j<=b; j+=k)
                if(j!=primes[i])
                    setC(segment, (j-a));
        }
        for(i=0; i<=b-a; i+=2)
            if(!chkC(segment, i)){
                cnt++;
                primeNos.pb(a+i);
            }
        return cnt;
    }
    ll bsearch(ll p){
        ll lo=0,hi=primeNos.size(),mid;
        ll ans=large,num;
        while(lo<=hi){
            mid = lo+(hi-lo)/2;
            num = primeNos[mid];
            if(num<p){
                lo=mid+1;
            }
            else
            {
                ans=min(ans,num);
                hi=mid-1;
            }
        }
        if(ans<large)
        return ans;
        else
            return -1;
    }


    int main(int argc, char const *argv[])
    {
        // ifstream fin;
        // fin.open("input_segmented_4.txt");
        // ofstream fout;
        // fout.open("output_segmented_4.txt");
        ios_base::sync_with_stdio(false);
        ll T;
        cin>>T;
        while(T--){
            ll l,r,Q,p;
            cin>>l>>r>>Q;
            primeNos.clear();
            sieve();
            segmented_sieve(l,r);
            // cout<<"Hello\n";
            // for(int i=0;i<primeNos.size();i++)
            //     cout<<primeNos[i]<<" ";
            // cout<<endl;
            while(Q--){
                cin>>p;
                cout<<bsearch(p)<<endl;
            }

        }
        return 0;
    }