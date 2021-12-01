#include<iostream>
#include<vector>
using namespace std;

void PrintDFS(int src, vector<vector<int> > AdjMat, vector<bool> &visited){
   visited[src]=true;
   cout<<src<<endl;
   for(int i=0;i<AdjMat.size();i++){
      if(AdjMat[src][i]==1 && visited[i]==false){
         PrintDFS(i,AdjMat,visited);
      }
   }
}


int main(){
   int n,e;
   cin>>n>>e;
   vector<vector<int> > AdjMat(n, vector<int>(n,0) );
   vector<bool> visited(n,false);
   for(int i=0;i<n;i++){
      int sv,ev;
      cin>>sv>>ev;
      AdjMat[sv][ev]=1;
      AdjMat[ev][sv]=1;
   }
   PrintDFS(0,AdjMat,visited);
   return 0;
}