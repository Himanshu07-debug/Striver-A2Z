// In Postorder Traversal, The order is [ left right root ]

// Here you will observe that ki kisi bhi 3 node ke liye, root sabse last hai

// Apni Condition -> Humne single stack se try kiye nhi hua becz when the in 3 node, curr becomes parent, it again
//                  start inserting the child nodes which are already processed


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

// USING TWO STACK :

// INTUITION -> 

// Insertion in Stack 1 -> [ root left right ]
// Removal in Stack 1 ->   [ root right left ]  ( Each time curr ko S2 me daalne ke baad S1 me curr ke child daalenge )
// Insertion in Stack 2 -> [ root right left ]
// Removal in Stack 2   -> [ left right root ]  ( POST ORDER TRAVERSAL )

// S2 is only for printing the postOrder Traversal

// TIME -> O(N)
// SPACE -> O(N) + O(N)


vector<int> iterativePostOrderTraversal(node* root){

    vector<int> postOrder;

    if(root == NULL){
        return postOrder;
    }

    stack<node*>s1;
    stack<node*>s2;

    s1.push(root);

    while(s1.size()){

        node* curr = s1.top();
        s1.pop();

        s2.push(curr);

        if(curr->left!=NULL){
            s1.push(curr->left);
        }

        if(curr->right!=NULL){
            s1.push(curr->right);
        }

    }

    while(s2.size()){

        node* curr = s2.top();
        s2.pop();
        postOrder.push_back(curr->data);

    }
    
    return postOrder;

}

// USING SINGLE STACK -> 


// Just think what we have to do -> Humko as left to left possible node pe jana hai, now ab leftmost node pe left 
// child nhi honga, so we are sure humko right child jana hai, firse uske leftmost me jana hai iff possible


// TIME -> O(2*N) [ If Skew tree tilted at right side rhi to andar wala while loop bhi O(N) chalega ]
// SPACE -> O(N)

vector<int> IterativePostOrderTraversal(node* root){

    vector<int> postOrder;

    if(root == NULL){
        return postOrder;
    }

    stack<node*>s;

    node* curr=root;
    
    while(curr!=NULL || !s.empty()){

        if(curr!=NULL){
            s.push(curr);
            curr=curr->left;
        }
        else{
            
            // We are ensured that ki left child NULL hai becz LEFTMOST 
            node * temp = s.top() -> right;

            // if no right child
            if (temp == NULL) {

                // latest added parent ko select kro
                temp = s.top();
                s.pop();
                postOrder.push_back(temp -> data);

                // latest parent ka agar parent hai s.top() tab tak hi LOOP chalayenge [ temp = s.top()->right ]
                while (!s.empty() && temp == s.top()->right) {
                    temp = s.top();
                    s.pop();
                    postOrder.push_back(temp -> data);
                }

            } 
            // set curr to right child
            else{
                curr = temp;
            } 
        }
    }

    return postOrder;

}



int main() {

  struct node * root = new node(1);
  root -> left = new node(2);
  root -> right = new node(3);
  root -> left -> left = new node(4);
  root -> left -> right = new node(5);
  root -> left -> right -> left = new node(8);
  root -> right -> left = new node(6);
  root -> right -> right = new node(7);
  root -> right -> right -> left = new node(9);
  root -> right -> right -> right = new node(10);

  vector < int > postOrder;
  postOrder = IterativePostOrderTraversal(root);

  cout << "The postOrder Traversal is : ";
  for (int i = 0; i < postOrder.size(); i++) {
    cout << postOrder[i] << " ";
  }
  return 0;
}