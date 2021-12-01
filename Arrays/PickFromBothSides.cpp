#include<iostream>
#include<vector>
using namespace std;

int Solution(vector<int> &A, int B) {
   int ans=0;
   int p1=0,p2=A.size()-1;
   while(B>0 && p1<p2){
       p1=p1+A[p1];
       p2=p2+A[p2];
       if(ans < p1+p2 ){
           ans=p1+p2;
       }
       B=B+2;
       p1--;
       p2++;
   }
        
    return ans;
}
int main(){

    int n,b;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cin>>b;
    cout<<Solution(arr,b)<<endl;
    return 0;
}