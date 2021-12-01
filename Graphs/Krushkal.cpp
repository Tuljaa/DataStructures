#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Find cost of Min Spanning Treee Using Krushkal's algo:
class Edge {
   public :
    int src;
    int dest;
    int wt;

    Edge(int s,int d,int wtt){
        this->src=s;
        this->dest=d;
        this->wt=wtt;
    }
};

bool checkCycle(Edge *minSrc, vector<int> &parent){
    if(parent[minSrc->src]!=parent[minSrc->dest]){
        parent[minSrc->dest]=parent[minSrc->src];
        return true;
    }
    return false;
}

bool compareInterval(Edge *i1, Edge* i2) {  return (i1->wt<i2->wt); }

int main(){

    int n,e;
    cin>>n>>e;

    vector<Edge *> graph;
    for(int i=0;i<e;i++){
        int src,dest,wt;
        cin>>src>>dest>>wt;
       // Edge E;
       // new operator allocates memory address and returns address so Edge *E is accepted
       // to access properties of a pointer pointing to Object use -> so E->wt
        Edge *E=new Edge(src,dest,wt);
        graph.push_back(E);
    }

    sort(graph.begin(),graph.end(),compareInterval);

    vector<int> parent(e);

    for(int i=0;i<=graph.size();i++){
        parent[i]=i;
    }
  
    
    vector<Edge*> result;
    for(int i=0;i<graph.size();i++){
        if(checkCycle(graph[i],parent)){
            result.push_back(graph[i]);
        }
    }
    cout<< "Edges of MST are : "<<endl;
    int sum=0;

    for(int i=0;i<result.size();i++){
        cout<<result[i]->src<<" -- "<<result[i]->dest<<endl;
        sum+=result[i]->wt;
    }
    cout<<"Total SUM is : "<<sum<<endl;
    
    return 0;
}

/* 
------TC 01:
4
5
0 1 3
0 2 0
0 3 2
1 3 4
2 3 1
*/