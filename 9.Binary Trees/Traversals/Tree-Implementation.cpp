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

// INORDER TRAVERSAL

void inorder(node* root){

    if(root!=NULL){

        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);

    }

}

// PREORDER TRAVERSAL

void preorder(node* root){

    if(root!=NULL){

        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);

    }

}

// POSTORDER TRAVERSAL

void postorder(node* root){

    if(root!=NULL){

        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";

    }

}


// LEVEL ORDER TRAVERSAL

void BFS(node* root){

    queue<node*> q;

    q.push(root);

    while(q.size()){

        node* curr = q.front();
        q.pop();

        cout<<curr->data << " ";

        if(curr->left!= NULL){
            q.push(curr->left);
        }

        if(curr->right!=NULL){
            q.push(curr->right);
        }

    }

}



int main(){

    node* root = new node(10);
    node* temp1 = new node(20);
    node* temp2 = new node(30);

    root->left = temp1;
    root->right = temp2;

    // Traversals:

    cout<<"Inorder Traversal : \n";
    inorder(root);

    cout<<"\nPreorder Traversal : \n";
    preorder(root);

    cout<<"\nPostorder Traversal : \n";
    postorder(root);
    
    cout<<"\nLevel Order Traversal : \n";
    BFS(root);

    return 0;
}