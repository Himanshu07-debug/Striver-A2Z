#include<bits/stdc++.h>
using namespace std;

struct node{

    int data;
    node* left;
    node* right;

    node(int x){
        data = x;
        left=NULL;
        right=NULL;
    }

};


// ITERATIVE INORDER TRAVERSAL

vector<int> iterativeInorderTravesal(node* root){

    vector<int> inOrder;

    if(root==NULL){
        return inOrder;
    }

    stack<node*>s;

    node* curr = root;

    while(curr!=NULL || s.size()){

        while(curr!=NULL){

            s.push(curr);

            curr = curr->left;

        }

        curr = s.top();

        inOrder.push_back(curr->data);

        curr = curr->right;

    }

    return inOrder;

}

// AUX SPACE -> O(N)


int main(){

    node * root = new node(1);
    root -> left = new node(2);
    root -> right = new node(3);
    root -> left -> left = new node(4);
    root -> left -> right = new node(5);
    root -> left -> right -> left = new node(8);
    root -> right -> left = new node(6);
    root -> right -> right = new node(7);
    root -> right -> right -> left = new node(9);
    root -> right -> right -> right = new node(10);

    vector<int> inOrder = iterativeInorderTravesal(root);

    for(int x:inOrder){
        cout<<x<<" ";
    }
    
    return 0;

}