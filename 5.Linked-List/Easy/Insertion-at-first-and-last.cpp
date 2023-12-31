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

// INSERTION AT LAST

node* insertAtLast(node* head, int x){

    node* temp = new node(x);

    if(head==NULL){
        return temp;
    }

    node* curr= head;

    while(curr->next!=NULL){
        curr=curr->next;
    }

    curr->next=temp;

    return head;

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

    head = insertAtLast(head, 70);
    printLinkedList(head);

}