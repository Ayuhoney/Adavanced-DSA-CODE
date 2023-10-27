#include<bits/stdc++.h>
using namespace std;

void DMAFirst(int& m,int& n,int& c){

    int* arr = new int[m*n];

    for(int i{0};i<m;i++){
        for(int j{0};j<n;j++){

            *(arr+i*n+j)=++c;
        }
    }
    for(int i{0};i<m;i++){
        for(int j{0};j<n;j++){
            cout<<*(arr+i*n+j)<<" ";
        }
        cout<<endl;
    }
}
void DMASecond(int& m,int& n,int& c){

    int** arr = new int*[m];

    for(int i{0};i<m;i++){
        arr[i] = new int[n];
    }
    for(int i{0};i<n;i++){
        for(int j{0};j<m;j++){
            arr[i][j] =++c;
        }
    }
    for(int i{0};i<n;i++){
      for(int j{0};j<m;j++){
          cout<<arr[i][j]<<" ";
     }
      cout<<endl;
    }
}
signed main(){

    int m{0},n{0},c{0};
    cin>>m>>n;

    DMAFirst(m,n,c);
    DMASecond(m,n,c);

}