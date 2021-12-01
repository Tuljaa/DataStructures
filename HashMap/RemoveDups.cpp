#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> removeDups(vector<int> arr){
    vector<int>ans;
    unordered_map<int,bool> myMap;
    for(int i=0;i<arr.size();i++){
        if(myMap.count(arr[i])==0){
            ans.push_back(arr[i]);
            myMap[arr[i]]=true;
        }
    }
    return ans;
}

vector<int> myRemoveDups(vector<int> arr){
    vector<int> ans;
    unordered_map<int,int> myMap(0);
    for(int i=0;i<arr.size();i++){
       // myMap.insert(arr.at(i),arr.at(i)++);
       cout<<"In My Map : "<<myMap[i]<<endl;
       myMap[arr[i]]=myMap[arr[i]]+1;
    }
    for(int i=0;i<myMap.size();i++){
        if(myMap.at(arr[i])!=0){
            cout<<"ANS : "<<myMap.at(arr[i])<<myMap[i]<<endl;
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

int main(){
    vector<int> arr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        arr.push_back(data);
    }
    vector<int> ans=removeDups(arr);

    cout<<"Elements removing Duplications : "<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }

     vector<int> ans1=myRemoveDups(arr);

    cout<<"Elements removing Duplications from myremoveDups Func: "<<endl;
    for(int i=0;i<ans1.size();i++){
        cout<<ans1[i]<<endl;
    }
}