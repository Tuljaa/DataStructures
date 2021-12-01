#include<iostream>
#include<vector>
using namespace std;

  int removeDuplicates(vector<int>& nums) {
        int j=1,count=0,i=0;
        while(i<nums.size() && j<nums.size()){
            vector<int>::iterator it;
            if(nums.at(i)==nums.at(j)){
                it=nums.at(j);
                nums.erase(nums.at(j))
                j++;
                
            }else{
                i=j;
                j++;
                count++;
            }
        }
        return count;
    }

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    removeDuplicates(arr);
}