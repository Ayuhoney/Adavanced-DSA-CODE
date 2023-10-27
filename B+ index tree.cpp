#include<bits/stdc++.h>
using namespace std;

int a[10000];
int bit[10000]={0};

void build(int i,int inc,int N){

    while(i <= N){
        bit[i]+=inc;
        i+=(i&(-i)); // O(logn)
    }
}
int query(int i){
    
    int ans=0;
    while(i > 0){
        ans +=bit[i];
        i -=(i&(-i)); //O(logn)
    }
    return ans;
}
int main(){

    int n;
    cin>>n;

    for(int i=1;i<=n;i++){   
        cin>>a[i];
        build(i,a[i],n); //O(nlogn)
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<query(r)-query(l-1)<<endl;
    }
    return -1;
}
