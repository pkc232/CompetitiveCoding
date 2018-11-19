//Binary exponentiation

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

// Hashing strings

void precomputePower(){
    const ll p = 31;
    powers_p[0] = 1;
    for(int i=1;i<=1000000;i++){
        powers_p[i] = ((powers_p[i-1]*p)%MOD);
    }
}

ll inv(ll a, ll b){
 return 1<a ? b - inv(b%a,a)*b/a : 1;
}

void generateHashes(){
    ll firstHash = 0;
    for(int i=0;i<k;i++){
        firstHash = ((firstHash + (s[i]-'a'+1)*powers_p[i])%MOD);
    }
    ll p = 31;
    ll invrs = inv(p,MOD);
    int dbl =totstring.length();
    for(int i=1;i<len;i++){
        // cout<<"current firsthash"<<firstHash<<endl;
        firstHash = ((firstHash - (totstring[i-1]-'a'+1) + MOD)%MOD);
        firstHash = ((firstHash*invrs+MOD)%MOD);
        firstHash = ((firstHash + (totstring[i+k-1]-'a'+1)*powers_p[k-1])%MOD);
        // cout<<i<<" "<<firstHash<<endl;
        



        //To DO
    }

}

ll hashval(string st){
    ll firstHash = 0;
    for(int i=0;i<k;i++){
        firstHash = ((firstHash + (st[i]-'a'+1)*powers_p[i])%MOD);
    }
    return firstHash;
}

//Hashing a vector containing values <=10^6 From CF 154C
//	http://codeforces.com/problemset/problem/154/C

ll gen(ll i) {
    return 9237477 * i * i * i * i * i + 2347189 * i * i * i * i + 8717127 * i * i * i + 128615331 * i * i + 9981717 * i + 13;
}

ll hash_and_store(vector<ll> &v){
	
	ll s = 0;
	for(ll i:v)
		s += gen(i);
	return s;
}

//Modular inverse
ll inv(ll a, ll b){
 return 1<a ? b - inv(b%a,a)*b/a : 1;
}

//Extended Euclid and diophantine equation

int gcd(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}


//Fibonnacci in logn

pair<int, int> fib (int n) {
    if (n == 0)
        return {0, 1};

    auto p = fib(n >> 1);
    int c = p.first * (2 * p.second - p.first);
    int d = p.first * p.first + p.second * p.second;
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}

//Sieve
int isPrime[NOV];

void sieve(){
    isPrime[1] = 0;
    for(ll i=2;i<=1e6;i++){
        if(isPrime[i]==-1){
            isPrime[i]=1;
            for(ll j=i*2;j<=1e6;j+=i)
                isPrime[j]=0;
        }
    }
}