int arr[10005];
    
int root(int x){
    while(x!=arr[x]){
        arr[x] == arr[arr[x]];
        x = arr[x];
    }
    return arr[x];
}

void Union(int a, int b){
    int ra = root(a), rb = root(b);
    arr[ra] = rb;
}

int Find(int a, int b){
    return root(a) == root(b);

}