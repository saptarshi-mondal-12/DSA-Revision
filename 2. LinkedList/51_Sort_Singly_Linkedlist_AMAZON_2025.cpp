#include<bits/stdc++.h>
using namespace std;


/* Q1. Sort singly - AMAZON 2025 MOST IMPORTANT

https://leetcode.com/problems/sort-list/description/

3-4 follow-up variations of the same problem:
    Q2. Add an option to sort in ascending or descending order
    Q3. Sort by the number of set bits
    Q4. In addition to the above, sort the list by the number of zeros

Each follow-up required separate coding + dry run + complexity analysis

Example: 4->2->1->3
Output: 1->2->3->4
*/

class ListNode{
    public:

    int data;
    ListNode* next;

    ListNode(int val){
        data=val;
        next=NULL;
    }
};

void display(ListNode* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}




// Q1. Q2. -------------------------------------------------
ListNode* sortList(ListNode*head, int order){
    vector<int>container;
    ListNode* temp=head;
    while(temp!=NULL){
        container.push_back(temp->data);
        temp=temp->next;
    }

    // order 1 means ascending order i.e increasing order
    if (order == 1){
        sort(container.begin(), container.end());
    }
    // order 2 means descending order i.e decreasing order
    else{
        sort(container.begin(), container.end(), greater<int>());

    }
    ListNode* ansNode = new ListNode(-1);
    ListNode* pt = ansNode;

    for(auto it: container){
        ListNode* newNode = new ListNode(it);
        pt->next=newNode;
        pt=pt->next;
    }
    pt->next=NULL;
    return ansNode->next;
}



// Q3. Sorting by number of setbit -------------------------
ListNode* sortBy_setBit(ListNode*head){
    vector<pair<int,int>>container;
    ListNode* temp=head;
    while(temp!=NULL){
        int n=temp->data;

        if (n == 0) {
            container.push_back({1, 0});
        }
        else{
            int ones = __builtin_popcount(n);
            container.push_back({ones, n});
        }
        temp=temp->next;
    }

    sort(container.begin(), container.end());

    // for(auto it: container){
    //     cout<<"n ="<<it.second<<" Set bits ="<<it.first<<endl;
    // }
    // cout<<endl;

    ListNode* ansNode = new ListNode(-1);
    ListNode* pt = ansNode;

    for(auto it: container){
        ListNode* newNode = new ListNode(it.second);
        pt->next=newNode;
        pt=pt->next;
    }
    pt->next=NULL;
    return ansNode->next;
}



// Q4. In addition to the above, sort the list by the number of zeros -----------
ListNode* sortBy_numberOfZeros(ListNode*head){
    // Time complexity: O(n) + O(N log N) + O(n)
    // Space complexity: O(n)

    vector<pair<int,int>>container;
    ListNode* temp=head;
    while(temp!=NULL){
        int n=temp->data;

        if (n == 0) {
            container.push_back({1, 0});
        }
        else{
            int ones = __builtin_popcount(n);
            int totalBits = 32 - __builtin_clz(n); // bits actually used to represent n
            int zeros = totalBits - ones;
            container.push_back({zeros, n});
        }
        temp=temp->next;
    }

    sort(container.begin(), container.end());

    // for(auto it: container){
    //     cout<<"n ="<<it.second<<" zeros ="<<it.first<<endl;
    // }
    // cout<<endl;


    ListNode* ansNode = new ListNode(-1);
    ListNode* pt = ansNode;

    for(auto it: container){
        ListNode* newNode = new ListNode(it.second);
        pt->next=newNode;
        pt=pt->next;
    }
    pt->next=NULL;
    return ansNode->next;
}





int main(){
    ListNode* head = new ListNode(4);
    head->next=new ListNode(2);
    head->next->next=new ListNode(1);
    head->next->next->next=new ListNode(3);
    head->next->next->next->next=new ListNode(5);

    // Q1. sort list only - ascending order
    // ListNode* ans = sortList(head);
    // display(ans);


    // Q2. Add an option to sort in ascending or descending order
    // 1 = ascending order , 2 = descending order;
    // ListNode* ans = sortList(head, 1);
    // display(ans);

    // Q3. Sort by the number of set bits
    // ListNode* ans = sortBy_setBit(head);
    // display(ans);

    // In addition to the above, sort the list by the number of zeros
    ListNode* ans = sortBy_numberOfZeros(head);
    display(ans);
    

}

