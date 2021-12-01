#include<iostream>
#include<vector>
using namespace std;

void swapp(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void insertHeap(vector<int> &A, int pos,int data){
    A[pos]=data;
    int parent=pos/2;
    for(int i=pos;i>1;){
        if(A[parent]<A[i]){
            swapp(A[parent],A[i]);
            parent=parent/2;
            i=i/2;
        }
        else{ break; }
    }
}

int deleteRootNode(vector<int> &A){
    int ans=A[1];
    A[1]=A[A.size()+1];
    A.pop_back();

    for(int i=1;i<A.size();){
        int R=2*i+1;
        int L=2*i;
        if(A[R]>A[L]){ swapp(A[R],A[i]); i=2*i+1; }
        else if(A[R]<A[L]) { swapp(A[L],A[i]); i=2*i; }
        else{ break; }
    }
    return ans;
}

void printArray(vector<int> arr, int n){
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<"      "<<i<<endl;
    }
}

int main(){

    int n;
    cin>>n;
    vector<int> A(n+1);
    for(int i=1;i<=n;i++){
        int data;
        cin>>data;
        insertHeap(A,i,data);
    }
    cout<<"Heap : "<<endl;
     printArray(A,n);
    cout<<"Sorted Array"<<endl;
    for(int i=1;i<=n;i++){
        cout<<deleteRootNode(A)<<endl;
    }
    printArray(A,n);
    return 0;
}