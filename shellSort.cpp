#include<bits/stdc++.h>
using namespace std;


void shellSort(int arr[],int n){
    
    for(int gap=n/2; gap>0; gap/=2){
        for(int j=gap; j<n;j++){
            
            int temp = arr[j];
            int i=0;
            for(i=j; (i >= gap) && (arr[i-gap] > temp); i-=gap){
                arr[i] = arr[i-gap];
            }
            arr[i]=temp;
        }
     }
}
int main(){
    
    int n;
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    shellSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}