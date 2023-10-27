#include<bits/stdc++.h>
using namespace std;


string transform(string s){
    
    string temp = "#";
    for(auto ch : s){
        temp+=ch;
        temp+="#";
    }
    return temp;
}

string LongestPalin(string s){

    string t = transform(s);

    int n = t.size();
    int  len = t.size();
    int l{0},r{0};

    int centre;
    int maxLen=0;
    vector<int>pi(n);
    pi[0]=0;

    for(int i=1;i<n;i++){
      int k;

        if( i > r){   //expend arround the ith index to compute p[i] from starting 
          k=0;
        }else{
            int  j = l + (r-i);
            if(j-pi[j] > l){  //range me hain p[i] = p[j]
                pi[i]=pi[j];
                continue;
                    
            }else if((l-j) >= (r-i)){ // boundry cross kr rha h
            
              // {r-i} is mirror image range of {j-l} Pi[j]
             // pi[j] <= p[i]  --> pi[j]{ r-i } <= pi[i]{l-j}
                k = r-i; // tb tk expend krte raho
            }
        }    // left    //right
        while(i-k >=0 && (i+k) < n && t[i-k] == t[i+k]){
            k++;
        }
        k--; //come again original position
        pi[i]=k;

        if(pi[i] > maxLen){
            maxLen = pi[i];
            centre = i/2;
        }
        if(i+k > r){
            l = l-k; //new l 
            r = l+k; //new r
        }
    }   
       //start = centre-(maxLen/2)
    return s.substr(centre-(maxLen/2),maxLen);
}
int main(){

    string str="babad";
    cout<<LongestPalin(str)<<endl;

    return 0;
}
// this algo is also same As previous bt in their we used left & right 
