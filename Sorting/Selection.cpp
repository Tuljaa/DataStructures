#include<iostream>
using namespace std;

int findMin(int arr[],int low,int high){
    int min=arr[low],pos=low;
    for(int i=low;i<=high;i++){
        if(arr[i]<=min){
            min=arr[i];
            pos=i;
        }
    }
    return pos;
}

void selection(int arr[],int n){
    for(int i=0;i<n;i++){
        int minPos=findMin(arr,i,n-1);
        //swap;
         if(i != minPos) {
             int temp=arr[i];
            arr[i]=arr[minPos];
            arr[minPos]=temp;
         }
        
    }
}

void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}

int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    selection(arr,n);
    printArray(arr,n);
    return 0;
}