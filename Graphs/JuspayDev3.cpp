
#include<iostream>
#include<vector>
using namespace std;

class Edge{
    public:
    int src,dest,wt;
    Edge(int src,int dest,int wt){
        this->src=src;
        this->dest=dest;
        this->wt=wt;
    }
};

vector<int> findFollowers(int src,int dest, vector<vector<int> > AdjMat){

    vector<int> ans;
    for(int i=0;i<AdjMat.size();i++){
        if(AdjMat[src][i]==1){
                ans.push_back(i);
            }
    }
            
       return ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int> > AdjMat(1000, vector<int>(1000,0));

    for(int i=0;i<n;i++){
        int nodes;
        cin>>nodes;
        AdjMat[nodes][nodes]=1;
    }

    int e;
    cin>>e;
   
    for(int i=0;i<e;i++){
        int src,dest;
        cin>>src>>dest;
        AdjMat[src][dest]=1;
    }
  
    int srcPoint,destPoint;
    cin>>srcPoint>>destPoint;
    
    vector<int> ans= findFollowers(srcPoint,destPoint,AdjMat);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }

    return 0;
}
