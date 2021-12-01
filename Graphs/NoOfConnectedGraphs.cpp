#include<iostream>
#include<vector>
using namespace std;
// Using DFS
int NoOfConnGraphs(int src,vector<bool> &visited, vector<vector<int> > AdjMat,int &count){
    visited[src]=true;
    for(int i=0;i<AdjMat.size();i++){
        if(AdjMat[src][i]==1 && visited[i]==false) {
            NoOfConnGraphs(i,visited,AdjMat,count);
        }
    }
    for(int i=0;i<visited.size();i++){
        if(visited[i]==false){
            NoOfConnGraphs(i,visited,AdjMat,++count);
        }
    }
    return count;
}

int main(){

    int n,e;
    cin>>n>>e;
    vector<vector<int> > AdjMat(n, vector<int>(n,0));
    vector<bool> visited(n, false);
    int count=0;
    for(int i=0;i<e;i++){
        int sv,ev;
        cin>>sv>>ev;
        AdjMat[sv][ev]=1;
        AdjMat[sv][ev]=1;
    }
    cout << NoOfConnGraphs(0,visited, AdjMat,count)<<endl;
    return 0;
}