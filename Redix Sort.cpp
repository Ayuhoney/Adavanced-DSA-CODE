 #include<bits/stdc++.h>
using namespace std;


int getmax(int arr[],int n){

    int maxi = arr[0];
    for(int i=1;i<n;i++){

        if(arr[i] > maxi){
            maxi =arr[i];
        }
    }
    return maxi;
}

void coutSort(int arr[],int n,int div){

    int temp[n];
    int count[10]={0};

    for(int i=0;i<n;i++)
        count[(arr[i]/div)%10]++;
    
    for(int i=1;i<n;i++)
        count[i]+=count[i-1];
    
    for(int i=n-1;i>=0;i--){                    //Convert indexex
        temp[count[(arr[i]/div)%10]-1]=arr[i]; //-1 arr{1}-> arr{0}
        count[(arr[i]/div)%10]--;
    }

    for(int i=0;i<n;i++)
     arr[i]=temp[i];
}
void redix(int arr[],int n){

    int  m = getmax(arr,n);

    for(int div=1; m/div > 0 ; div*=10){
        coutSort(arr,n,div);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Unsorted Array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    redix(arr,n);
    cout<<"Sorted Array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return -1;
}