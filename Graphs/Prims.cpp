#include<iostream>
#include<vector>

using namespace std;

int checkUpdate(int src,vector<vector<int> > graph,vector<int> &weight, vector<int> &parent, vector<bool> &visited){
    
    visited.at(src)=true;
    
    for(int i=0;i<graph.size();i++){
        if(graph[src][i]!=0 && visited.at(i)==false){
            weight[i]=graph[src][i];
            parent[i]=src;
        }
    }
    return weight[src];
}

int findMinWeight(int src,vector<int> weight,vector<bool> visited){

    int min=INT_MAX;
    
    for(int i=0;i<weight.size();i++){
        if(weight[i]<min && visited[i]==false ){
            min=i;
        }
    }
    return min;
}

bool comp(vector<int> A, vector<int> B){
    for(int i=0;i<A.size();i++){  cout<<"IN COMP"<<A[i]<<B[i]<<i<<endl; }
  
    return A[2]>B[2];
}

int main(){

    int n,e;
    cin>>n>>e;
    vector<vector<int> > AdjMat(n, vector<int>(n,0));
    vector<int> parent(n,-1);
    vector<bool> visited(n,false);
    vector<int> weight(n,INT_MAX);
    for(int i=0;i<e;i++){
        int sv,ev,wt;
        cin>>sv>>ev>>wt;
        AdjMat[sv][ev]=wt;
       // AdjMat[ev][sv]=wt;
    }

    weight.at(0)=0;
    int sum=0;
    
    for(int i=0;i<AdjMat.size();i++){
       int src=findMinWeight(i,weight,visited);
       cout<<"SRC IS : "<<src<<endl;
       if(src!=INT_MAX){
           sum+=checkUpdate(src,AdjMat,weight,parent,visited);
       }
    }
    cout<<"MST Sum is : "<<sum<<endl;
     cout<<"Ele at 00 : "<<AdjMat[0][1]<<endl;

    sort(AdjMat.begin(),AdjMat.end(),comp);
    

   

    return 0;
}
/* 
------TC01-----
5
7
0 1 4
0 2 8
1 2 2
1 3 6
2 3 3
2 4 9
3 4 5
*/