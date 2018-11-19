#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
using namespace std;

ll matrix[1005][1005];
int ansi,ansj;
int row_ord[1005],col_ord[1005];
ll n,k,v;
int comparator(ll elem, int row, int col){
	// cout<<"checking for "<<elem<<" "<<row<<" "<<col<<endl;
	int ord = col_ord[col];
	if(ord){
		if(row<col){
			if(col>1){
				if(elem<matrix[col-1][col])
					return 1;	
			}
			if(elem<matrix[col][col])
				return 1;
			else
				return 0;
		}
		else{
			if(elem>matrix[col][col])
				return -1;
			else
				return 0;

		}
	}
	else
	{
		if(row>col){
			if(elem<matrix[col][col])
				return 1;
			else
				return 0;
		}
		else{
			if(elem>matrix[col][col])
				return -1;
			else
				return 0;

		}
	}
}

int present(int row, int col){
	return matrix[row][col]!=-1;
}

int bsearch(ll elem, int row,int ord,ll lo,ll hi){

	// cout<<"Current row1"<<row<<endl;
	if(lo>hi)
		return 0;
	int col;
	if(lo==hi){
		col=lo;
		if(!present(row,col)){
			int x = comparator(elem,row,col);
			if(x==0)
			{
				cout<<1<<" "<<row<<" "<<col<<endl;
				cin>>matrix[row][col];
			}
			else
				return 0;
		}
		ansi=row;
		ansj=lo;
		return matrix[row][lo]==elem;
	}
	// cout<<"Current row2"<<row<<endl;
	int mid = lo+(hi-lo)/2;
	col=mid;
	ll curel;
	if(matrix[row][col]!=-1){
		curel = matrix[row][col];
		if(curel==elem){
			ansi=row;
			ansj=mid;
			return 1;
		}
		else{
		if(elem<curel){
			if(ord==0){
				return bsearch(elem,row,ord,lo,mid-1);
			}
			else
			{
				return bsearch(elem,row,ord,mid+1,hi);	
			}
		}
		else
		{
			if(ord==1){
				return bsearch(elem,row,ord,lo,mid-1);
			}
			else
			{
				return bsearch(elem,row,ord,mid+1,hi);	
			}	
		}
	}
	}


	// cout<<"Current row3"<<row<<endl;
	int x = comparator(elem,row,col);
	// cout<<" elem:"<<elem<<" row:"<<row<<" col:"<<col<<" comp:"<<x<<endl;
	if(x==1){
		if(ord==0)
			return bsearch(elem,row,ord,lo,mid-1);
		else
			return bsearch(elem,row,ord,mid+1,hi);
	}
	else if(x==-1){
		if(ord==0)
			return bsearch(elem,row,ord,mid+1,col);
		else
			return bsearch(elem,row,ord,lo,mid-1);
	}

	else{
	if(matrix[row][mid]==-1){
		cout<<1<<" "<<row<<" "<<mid<<endl;
		cin>>curel;
	}
	else
	{
		curel=matrix[row][mid];
	}
	if(curel==elem){
		ansi=row;
		ansj=mid;
		return 1;
	}
	else{
		if(elem<curel){
			if(ord==0){
				return bsearch(elem,row,ord,lo,mid-1);
			}
			else
			{
				return bsearch(elem,row,ord,mid+1,hi);	
			}
		}
		else
		{
			if(ord==1){
				return bsearch(elem,row,ord,lo,mid-1);
			}
			else
			{
				return bsearch(elem,row,ord,mid+1,hi);	
			}	
		}
	}		
	}
	

}

void constructMatrix(){
	int row=1,col=1;
	while(row<=n){
		if(col>n)
			break;
		cout<<1<<" "<<row<<" "<<col<<endl;
		cin>>matrix[row][col];
		col++;
		if(col>n)
			break;
		cout<<1<<" "<<row<<" "<<col<<endl;
		cin>>matrix[row][col];
		row++;
	}
	if(row>1){
		cout<<1<<" "<<2<<" "<<1<<endl;
		cin>>matrix[2][1];
		col_ord[1]=(matrix[1][1]>matrix[2][1]);
	}
	if(matrix[n][n-1]==-1)
	{
		cout<<1<<" "<<n<<" "<<n-1<<endl;
		cin>>matrix[n][n-1];
		row_ord[n]=(matrix[n][n-1]>matrix[n][n]);
	}
	for(int i=1;i<n;i++){
		row_ord[i]=(matrix[i][i]>matrix[i][i+1]);
	}
	for(int j=2;j<=n;j++){
		col_ord[j]=(matrix[j][j-1]>matrix[j][j]);
	}

}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin>>n>>k>>v;
	// int rows[n+7],cols[n+7];
	// memset(rows,0,sizeof(rows));
	// memset(cols,0,sizeof(cols));
	ll a,b,c,ord;
	
	memset(matrix,-1,sizeof(matrix));
	constructMatrix();

	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=n;j++){
	// 		cout<<matrix[i][j]<<" ";
	// 		if(matrix[i][j]==v)
	// 		{
	// 			cout<<2<<" "<<i<<" "<<j<<endl;
	// 			return 0;
	// 		}
	// 	}
	// 	cout<<endl;
	// }

	// while(1){
	// 	cout<<"Compare\n";
	// 	int row,col,x;
	// 	cin>>row>>col>>x;
	// 	cout<<"COmpa :"<<comparator(x,row,col)<<endl;
	// }

	for(int i=1;i<=n;i++){
		// cout<<"searching in "<<i<<endl;
		int x = bsearch(v,i,row_ord[i],1,n);
		if(x){
			cout<<2<<" "<<ansi<<" "<<ansj<<endl;
			return 0;
		}

	}
	// for(int i=1;i<=n;i++){
		
	// 	c = bsearch(v,i,ord,1,n);
	// 	if(c==1){
	// 		cout<<2<<" "<<ansi<<" "<<ansj<<endl;
	// 		return 0;
	// 	}	 
	// }
	cout<<2<<" "<<-1<<" "<<-1<<endl;
}