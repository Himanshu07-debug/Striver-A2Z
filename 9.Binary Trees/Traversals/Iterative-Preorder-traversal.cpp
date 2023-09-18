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



// ITERATIVE PREORDER

vector<int> iterativePreorderTraversal(node* root){

    vector <int> preOrder;

    if (root == NULL)
        return preOrder;

    stack<node*>s;

    s.push(root);

    while(s.size()){

        node* curr= s.top();

        s.pop();

        // cout<<curr->data<<" ";
        preOrder.push_back(curr->data);

        if(curr->right!=NULL){
            s.push(curr->right);
        }

        if(curr->left!= NULL){
            s.push(curr->left);
        }

    }

    return preOrder;

}

// --------->> AUX SPACE -> O(N)


// SPACE OPTIMIZED ITERATIVE PREORDER

void SpaceOptimizedIterativePreorderTraversal(node *root){

    if(root==NULL){
        return;
    }

    stack<node*>s;

    node* curr = root;

    while( curr!=NULL  && s.size() ){

        while(curr!=NULL){

            cout<<curr->data<<" ";

            if(curr->right!=NULL){
                s.push(curr->right);
            }

            curr = curr->left;

        }

        if(s.size()){

            curr = s.top();
            s.pop();

        }

    }

}

// AUX SPACE ---------->> O(H) [ height of the tree ]


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

    vector<int> preOrder = iterativePreorderTraversal(root);

    for(int x:preOrder){
        cout<<x<<" ";
    }

    return 0;
}