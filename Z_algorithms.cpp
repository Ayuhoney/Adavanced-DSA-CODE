#include<bits/stdc++.h>
using namespace std;

//O(n^2)
auto z_trival(string str){

    int len = str.length();
    vector<int>z(len);

    for(int i=1;i<len;i++){

        while(i+z[i] < len && str[z[i]] == str[z[i]+i]){
            z[i]++;
            //a -> 1
            //a -> 2
             //a-> 3  {abc}current prefix of backword 
        }
    }
    return z;
}
#define ll long long int

//z trival are used O(n^2) becoze we are check every patterm
// value for i and j

//O(n+n)
//O(n) for index like i -------->
//O(n) for range[L--R] becoz [L-R] not moving forword back they ----> O(n)
auto z_algo(string str){

    ll len= str.size();
    ll l{0},r{0};
    vector<ll>z(len);

    for(ll i=1;i<len;i++){

        if( i > r){ 
            // if i is out of bound then 
            // reset and Expend r length
            l =i,r =i;
            
            //calculate length 1++
            while( r < len && str[r] == str[r-l]){
                r++;
            }
            z[i]=r-l;
            r--; //reset length
        }
        else{

            ll index = i-l; // previous index find prefix

            //curr_index + previous_index <= right 
            //        index 
            //      L        R
            //in range mean we did previous calclulaled then uses it
            if(i+z[index] <= r){
                z[i] = z[index];
            }
            else{
                // left move forword index{i}
                //   i
                //   L  R
                 l=i;
                while(r < len && str[r] == str[r-l]){
                    r++;
                }
                z[i]=r-l;
                r--;
            }
        }
    }
    return z;
}
signed main(){

    string str;
    cin>>str;

    auto arr = z_trival(str);
    cout<<"TOC O(N^2)  : ";
    for(auto x : str){cout<<" "<<x<<" ";}
    cout<<endl;
    cout<<"Z-Trivial   : ";
    for(auto x : arr){
        cout<<"{"<<x<<"}";
    }
    cout<<endl;
    cout<<"TOC O(M+N)  :"<<endl;
    auto arr2 = z_algo(str);
    cout<<"Z-Algorithm : ";

    for(auto x : arr2){
        cout<<"{"<<x<<"}";
    }
}
