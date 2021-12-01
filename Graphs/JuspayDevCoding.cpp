
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

bool compare (Edge * E1, Edge *E2){
    return E1->wt<E2->wt;
}

int findMin(int srcPoint, int destPoint, vector<Edge *> graph){
    vector<Edge *> s;
    vector<Edge *> d;
    int min=0;
    for(int i=0;i<graph.size();i++){
        if(graph[i]->src==srcPoint && graph[i]->dest==destPoint){
            min=graph[i]->wt;
        }
        else if(graph[i]->src==srcPoint && graph[i]->dest!=destPoint){
            s.push_back(graph[i]);
        }
    }
    for(int i=0;i<graph.size();i++){
        if(graph[i]->dest==destPoint){
            d.push_back(graph[i]);
        }
    }
    sort(s.begin(),s.end(),compare);
    sort(d.begin(),d.end(),compare);
    

}

int main(){
    int n;
    cin>>n;
    vector<int> Nodes;

    for(int i=0;i<n;i++){
        int nodes;
        cin>>nodes;
        Nodes.push_back(nodes);
    }

    int e;
    cin>>e;
    vector<Edge*> graph;
    for(int i=0;i<e;i++){
        int src,dest,wt;
        cin>>src>>dest>>wt;
        Edge *E =new Edge(src,dest,wt);
        graph.push_back(E);
    }
   // sort(graph.begin(),graph.end(),compare);
    int srcPoint,destPoint;
    cin>>srcPoint>>destPoint;
    cout<<findMin(srcPoint,destPoint,graph);

    return 0;
}



/* for(int i=0;i<graph.size();i++){
        cout<<graph[i]->wt;
    } */