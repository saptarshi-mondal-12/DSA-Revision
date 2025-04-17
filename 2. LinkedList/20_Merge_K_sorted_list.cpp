
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};

node* display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

node* insertAtTail(node* &head, int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return head;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    return head;
}

node* merge(node* &l1, vector<int>l2){
    node* n=new node(0);
    node* temp=n;

    int i=0;

    while(l1!=NULL && i<l2.size()){
        if (l1->data <= l2[i]){
            temp->next=l1;
            l1=l1->next;
            temp=temp->next;
        }else{
            node* curr=new node(l2[i]);
            temp->next=curr;
            temp=temp->next;
            i++;
        }
    }

    if(l1!=NULL){
        temp->next=l1;
    }
    while (i<l2.size()){
        node* curr=new node(l2[i]);
        temp->next=curr;
        temp=temp->next;
        i++;
    }
    temp->next=NULL;
    return n->next;


}

node* merge_K(vector<vector<int>>v){
    // Time complexity - O(k*n)
    // space complexity - O(1)
    
    node* result=new node(0);
    for(int i=0;i<v.size();i++){
        result->next=merge(result->next,v[i]);
    }
    result=result->next;
    return result;
}

int main(){

    vector<vector<int>>v={{1,4,5},{2,6,10},{3,7,8,9}};

    // node - in question vector pass in linkList node so perforn simple linedilist operation

    node* head=merge_K(v);
    display(head);   

}
