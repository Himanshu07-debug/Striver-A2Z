#include<bits/stdc++.h>
using namespace std;

struct node {
    
    int data;
    node* next;

    node(int x){
        data=x;
        next = NULL;
    }

};

// INSERTION AT FIRST

node* insertAtFirst(node *head, int x){

    node* temp = new node(x);
    temp->next = head;

    return temp;

}


// PRINT LINKED LIST

void printLinkedList(node* head){

    node* curr = head;

    while(curr!=NULL){
        cout<<(curr->data)<<" ";
        curr = curr->next;
    }
    cout<<"\n";

}

int main(){

    node* head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);
    
    head = insertAtFirst(head,5);
    printLinkedList(head);

}