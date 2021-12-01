#include<iostream>
#include<vector>
#include<queue>

using namespace std;
// No Of Connected Components also Calculated using Count
void printBFS(int src, vector<vector<int> > AdjMat, vector<bool> visited) {
   
    queue<int>q;
    int count=0;
    
    for(int i=0;i<visited.size();i++){
        
        if(visited[i]==false){
         count++;
         q.push(i);
        visited[i]=true;
        while(!q.empty()){
        int temp=q.front();
        q.pop();
        cout<<temp<<endl;
        for(int i=0;i<AdjMat.size();i++){
            if(AdjMat[temp][i]==1 && visited[i]==false){
                q.push(i);
                visited[i]=true;
            }
        }
        }
        }
    }

   cout<<"No Of Connected Graphs : "<<count<<endl;
  //  checkVisited(visited, AdjMat);

}
/*void checkVisited(vector<bool> visited, vector<vector<int> > AdjMat){
    for(int i=0;i<visited.size();i++){
        if(visited[i]==false){
            printBFS(i,AdjMat, visited);
        }
    }
} */

int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<int> > AdjMatrix(n, vector<int> (n, 0));
    vector<bool> visited(n,false);
    for(int i=0;i<e;i++){
        int sv,ev;
        cin>>sv>>ev;
        AdjMatrix[sv][ev]=1;
        AdjMatrix[ev][sv]=1;
    }
    printBFS(0, AdjMatrix, visited);

    return 0;
}