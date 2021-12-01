
#include<iostream>
#include<vector>
using namespace std;

bool findpath(int src,int dest, vector<int> AdjMat){
    
            if(AdjMat[src]==dest  ){
                return true;
            }
       return false;

}

int main(){
    int n;
    cin>>n;
    vector<int> Nodes;
    vector<vector<int> > AdjMat(10000, vector<int>(10000,0));

    for(int i=0;i<n;i++){
        int nodes;
        cin>>nodes;
        Nodes.push_back(nodes);
      //  AdjMat[nodes][nodes]=1;
    }

    int e;
    cin>>e;
   
    for(int i=0;i<e;i++){
        int src,dest;
        cin>>src>>dest;
       // AdjMat[src][dest]=1;
       Nodes[src]=dest;
    }
  
    int srcPoint,destPoint;
    cin>>srcPoint>>destPoint;
    cout<<findpath(srcPoint,destPoint,Nodes);

    return 0;
}


