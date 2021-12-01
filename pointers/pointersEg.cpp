#include<iostream>

using namespace std;

int main(){
    
    int a=100;
    int *ptr=&a;
    cout<<*ptr <<endl;
    int **dptr=&ptr;
    cout<<**dptr<<endl;

   // -----------------Arrays---------------
   int arr[4]={100};
   cout<<arr<<endl;
   cout<<*arr<<endl;

   return 0;  
}