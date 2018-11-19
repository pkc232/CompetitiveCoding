#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

// Structure to store information of a suffix
struct suffix
{
    int index; // To store original index
    int rank[2]; // To store ranks and next rank pair
};

struct node{
	std::vector<pair<int,int> > v;
};

node tree[300007];
int arr[100007];
char txt[100007];
node merge(node &n1,node &n2){
	node n;
	std::vector<pair<int,int> > v1=n1.v;
	std::vector<pair<int,int> > v2=n2.v;
	int i=0,j=0;
	int l1=v1.size(),l2=v2.size();
	std::vector<pair<int,int> > va;
	while(i<l1&&j<l2){
		if(v1[i].ss<=v2[j].ss){
			va.pb(v1[i]);
			i++;
		}
		else
		{
			va.pb(v2[j]);
			j++;
		}
	}
	while(i<l1){
		va.pb(v1[i]);
		i++;
	}
	while(j<l2){
		va.pb(v2[j]);
		j++;
	}

	n.v=va;
	return n;
}

void constructTree(int cur,int l,int r){
	if(l==r)
	{
		tree[cur].v.pb(mp(arr[l],l));
		return;
	}

	int mid = l+(r-l)/2;
	constructTree(2*cur,l,mid);
	constructTree(2*cur+1,mid+1,r);

	tree[cur]=merge(tree[2*cur],tree[2*cur+1]);
}

int query(int cur,int l,int r,int st,int e,int k){
	
	if(k<=0)
		return 0;
	if(l>r)
		return 0;
	if(st>r||e<l)
		return 0;
	if(st<=l&&e>=r){
		// cout<<"k hai "<<k<<endl;
		cout<<"hai "<<tree[cur].v[k-1].ff<<endl;
		return tree[cur].v[k-1].ff;
	}

	int mid = l+(r-l)/2;
	int x1=0,x2=0;
	cout<<l<<" "<<r<<" "<<cur<<" "<<mid<<" hai"<<endl;
	if(k<=(mid-l)){
	x1 = query(2*cur,l,mid,st,e,k);
	cout<<"k is less"<<x1<<endl;
	}
	else{
	x2 = query(2*cur+1,mid+1,r,st,e,k-(mid-l)+1);
	cout<<"k is more"<<x2<<endl;
	}
	// cout<<x1<<" "<<x2<<endl;
	
	return max(x1,x2);
}

 
// A comparison function used by sort() to compare two suffixes
// Compares two pairs, returns 1 if first pair is smaller
int cmp(struct suffix a, struct suffix b)
{
    return (a.rank[0] == b.rank[0])? (a.rank[1] < b.rank[1] ?1: 0):
               (a.rank[0] < b.rank[0] ?1: 0);
}
 
// This is the main function that takes a string 'txt' of size n as an
// argument, builds and return the suffix array for the given string
int *buildSuffixArray(char *txt, int n)
{
    // A structure to store suffixes and their indexes
    struct suffix suffixes[n];
 
    // Store suffixes and their indexes in an array of structures.
    // The structure is needed to sort the suffixes alphabatically
    // and maintain their old indexes while sorting
    for (int i = 0; i < n; i++)
    {
        suffixes[i].index = i;
        suffixes[i].rank[0] = txt[i] - 'a';
        suffixes[i].rank[1] = ((i+1) < n)? (txt[i + 1] - 'a'): -1;
    }
 
    // Sort the suffixes using the comparison function
    // defined above.
    sort(suffixes, suffixes+n, cmp);
 
    // At his point, all suffixes are sorted according to first
    // 2 characters.  Let us sort suffixes according to first 4
    // characters, then first 8 and so on
    int ind[n];  // This array is needed to get the index in suffixes[]
                 // from original index.  This mapping is needed to get
                 // next suffix.
    for (int k = 4; k < 2*n; k = k*2)
    {
        // Assigning rank and index values to first suffix
        int rank = 0;
        int prev_rank = suffixes[0].rank[0];
        suffixes[0].rank[0] = rank;
        ind[suffixes[0].index] = 0;
 
        // Assigning rank to suffixes
        for (int i = 1; i < n; i++)
        {
            // If first rank and next ranks are same as that of previous
            // suffix in array, assign the same new rank to this suffix
            if (suffixes[i].rank[0] == prev_rank &&
                    suffixes[i].rank[1] == suffixes[i-1].rank[1])
            {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = rank;
            }
            else // Otherwise increment rank and assign
            {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = ++rank;
            }
            ind[suffixes[i].index] = i;
        }
 
        // Assign next rank to every suffix
        for (int i = 0; i < n; i++)
        {
            int nextindex = suffixes[i].index + k/2;
            suffixes[i].rank[1] = (nextindex < n)?
                                  suffixes[ind[nextindex]].rank[0]: -1;
        }
 
        // Sort the suffixes according to first k characters
        sort(suffixes, suffixes+n, cmp);
    }
 
    // Store indexes of all sorted suffixes in the suffix array
    int *suffixArr = new int[n];
    for (int i = 0; i < n; i++)
        suffixArr[i] = suffixes[i].index;
 
    // Return the suffix array
    return  suffixArr;
}
 
// A utility function to print an array of given size
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int q;
	cin>>txt;
	cin>>q;
    int n = strlen(txt);
    int *suffixArr = buildSuffixArray(txt,  n);
    // cout << "Following is suffix array for " << txt << endl;
    // printArr(suffixArr, n);

    for(int i=1;i<=n;i++)
    	arr[i]=suffixArr[i-1]+1;

    constructTree(1,1,n);

    for(int i=1;i<=n;i++){
    	cout<<"For node "<<i<<endl;
    	for(int j=0;j<tree[i].v.size();j++)
    		cout<<tree[i].v[j].ff<<" "<<tree[i].v[j].ss<<endl;
    }
    int l,r,k;
    while(q--){
    	cin>>l>>r>>k;
    	cout<<query(1,1,n,l,r,k)<<endl;

    }
}