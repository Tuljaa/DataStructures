#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// void PrintBFS(int src, vector<vector<int> > AdjMat){
    
//      vector<bool> visited(AdjMat.size(),false);

//     queue<int> q;
//     q.push(src);
//     visited[src]=true;
//     while(!q.empty()){
      
//         int temp=q.front();
//         q.pop();
//         cout<<temp<<endl;
//         for(int i=0;i<AdjMat.size(); i++){
//             if(AdjMat[temp][i]==1 && visited[i]==false){
//                 q.push(i);
//                 visited[i]=true;
//             }
//         }
//     }
// }
void PrintBFS(int src,vector<vector<int> > AdjMat){
    queue<int>q;
    q.push(src);
    vector<bool> visited(AdjMat.size(),false);
    visited[src]=true;
    while(!q.empty()){
        int temp=q.front();
        q.pop(); cout<<temp<<endl;
        for(int i=0;i<AdjMat.size();i++){
            if(AdjMat[temp][i]==1 && visited[i]==false){
                q.push(i);
                visited[i]=true;
            }
        }
    }
}
int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<int> > AdjMatrix(n, vector<int> (n,0));
    vector<bool> visited(n,false);
    for(int i=0;i<e;i++){
        int sv,ev;
        cin>>sv>>ev;
        AdjMatrix[sv][ev]=1;
        AdjMatrix[sv][ev]=1;
    }
    PrintBFS(0, AdjMatrix);
    return 0;
}
/*  TC 
8
9
0 4 
0 5
4 3
3 2
3 1
3 6
2 1
6 5
6 7
---------TC 2
6
8
1 2
1 3
2 4
2 5
3 5
4 5
4 6
5 6
*/