#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

Node *insert(){
    int data;
    cin>>data;
    Node *head=new Node(data);
    if(data==-1){
        return head;
    }

    int right,left;
    cin>>left>>right;
    while(1){
        if(left!=-1){
        Node *LeftChild =new Node(left);
        head->left=LeftChild;
    }
        if(right!=-1){
        Node *RightChild= new Node(right);
        head->right=RightChild;
        }
    }
}

int main(){
    Node *root=insert();

    return 0;
}