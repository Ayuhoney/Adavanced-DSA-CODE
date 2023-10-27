#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    vector<Node*>child;
    Node(int x ) : data(x){

    }
};

class MwayTree{
    public:
    
    Node* root;
    int m;
    MwayTree(int x ) : m(x),root(nullptr){

    }

    void insert(int data){

        if(!root) root = new Node(data);
        else insertRecursive(root,data);
    }

    void insertRecursive(Node* currNode, int data){

        if(currNode->child.size() < m){
            currNode->child.push_back(new Node(data));

        }else{
            for(auto subChild : currNode->child){
                insertRecursive(subChild,data);
            }
        }
    }
    bool deleteNode(int data){
        if(root){
            if(root->data == data){
                delete root;
                root= nullptr;
                return true;
            }
            else{
                return deleteRecursive(root,data);
            }
        }
        return false;
    }
    bool deleteRecursive(Node* currNode , int data){

        for(auto it = currNode->child.begin() ; it != currNode->child.end();it++){

            if((*it)->data == data){
                delete(*it);
                currNode->child.erase(it);
                return true;
            }else{
                if(deleteRecursive(*it,data)){
                    return true;
               }
            }
        }
        return false;
    }
    void print(){
        if(root){
            printRecursive(root,0);
        }else cout<<"Error";
    }
    void printRecursive(Node* currNode , int depth){

        for(int i=0;i<depth;i++){
            cout<<" ";
        }
        cout<<currNode->data<<endl;
        for(auto subChild : currNode->child){
            printRecursive(subChild,depth+1);
        }
    }
};
int main() {
    MwayTree tree(3); 

    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);
    tree.insert(8);
    
    cout<<"Before delete print"<<endl;
    tree.print();
    int valueToDelete = 2;
    if (tree.deleteNode(valueToDelete)) {
        std::cout << "Deleted  " << valueToDelete << std::endl;
    }
    cout<<"After Deletion Print"<<endl;
    tree.print();

    return 0;
}
