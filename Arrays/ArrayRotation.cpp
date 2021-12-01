#include<iostream>

using namespace std;

int * RotatedArray(int arr[] , int k,int size){
    int *localArr= new int[size];
    int j=0;
    for(int i=k;i<size;){
        localArr[j++]=arr[i++];
    }
    for(int i=0;i<k;i++){
        localArr[j++]=arr[i];
    }
    return localArr;
}

void RotatedArrayApproach2(int arr[],int k,int size){
   // static int localArr[size]   shows an error as size of arr is not static;
    for(int i=0;i<k;i++){
         int j=0;
         int key=arr[j];
        for(;j<=size-1;j++){
            arr[j]=arr[j+1];
        }
       arr[j-1]=key;
    }
}

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int *RotatedArr = RotatedArray(arr,k,n);
    for(int i=0;i<n;i++){
        cout<<RotatedArr[i]<<" ";
    }
    delete [] RotatedArr;
    RotatedArrayApproach2(arr,k,n);
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}