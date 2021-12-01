#include<iostream>

using namespace std;

void insertion(int arr[],int n){
    int i,j;
    for(i=1;i<n;i++){
        j=i-1;
        int key=arr[i];
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
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
    insertion(arr,n);
    printArray(arr,n);
    return 0;
}