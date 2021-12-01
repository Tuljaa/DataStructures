#include<iostream>
using namespace std;

int partition(int arr[],int low,int high){
    int i=low,j=high;
    int pivot=arr[low];
    while(i<j){
        while(arr[i]<=pivot){ i++; }
       // cout<<"Element at i : "<< i << "     "<<arr[i]<<endl;
        while(arr[j]>pivot){ j--; }
        if(i<j){
            int temp =arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
         
    }
        int temp = arr[j];
        arr[j]=pivot;
        arr[low]=temp;
    
   return j;
}

void quickSort(int arr[],int low,int high){
    if(low<high){
        int pos = partition(arr,low,high);
     
        quickSort(arr,low,pos-1);
        quickSort(arr,pos+1,high);
    }
        return;
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
    quickSort(arr,0,n-1);
    printArray(arr,n);
    return 0;
}