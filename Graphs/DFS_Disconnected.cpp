#include<iostream>
#include<vector>

using namespace std;

void printDfsOfDisconnectedGraphs(int src, vector<vector<int> > AdjMat, vector<bool> &visited){
    visited[src]=true;
    cout<<src<<endl;
    for(int i=0;i<AdjMat.size();i++){
            if(AdjMat[src][i]==1 && visited[i]==false){
                 printDfsOfDisconnectedGraphs(i,AdjMat,visited);
            }
    }
    for(int i=0;i<visited.size();i++){
        if(visited[i]==false){
            printDfsOfDisconnectedGraphs(i,AdjMat,visited);
        }
    }
}

int main(){

    int n,e;
    cin>>n>>e;
    vector<vector<int> > AdjMatrix(n, vector<int> (n,0) );
    vector<bool> visited(n,false);
    for(int i=0;i<e;i++){
        int sv,ev;
        cin>>sv>>ev;
        AdjMatrix[sv][ev]=1;
        AdjMatrix[ev][sv]=1;
    }
    printDfsOfDisconnectedGraphs(0,AdjMatrix,visited);
    return 0;
}