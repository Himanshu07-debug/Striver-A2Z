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

// DELETION AT FIRST

node* deleteAtFirst(node* head){

    if(head==NULL){
        return NULL;
    }

    node* temp = head->next;

    delete head;

    return temp;

}

// DELETION AT LAST

node* deleteAtLast(node* head){

    if(head == NULL || head->next ==NULL){
        return NULL;
    }

    node* curr = head;

    while(curr->next->next != NULL){
        curr= curr->next;
    }

    node* temp = curr->next;

    curr->next = NULL;

    delete temp;

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

    head = deleteAtFirst(head);
    printLinkedList(head);

    head = deleteAtLast(head);
    printLinkedList(head);

}