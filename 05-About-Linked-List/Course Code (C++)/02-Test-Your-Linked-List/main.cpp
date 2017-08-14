#include <iostream>
#include <cassert>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

/// LinkedList Test Helper Functions
ListNode* createLinkedList(int arr[], int n){

    if( n == 0 )
        return NULL;
    //创建链表的过程中，我们需要不断的向头指针的
    //下一个指针创建新节点，但是头指针是第一个节点，
    //不是通过上一个节点的next指针而创建的
    ListNode* head = new ListNode(arr[0]);
    ListNode* curNode = head;
    for( int i = 1 ; i < n ; i ++ ){
        curNode->next = new ListNode(arr[i]);
        curNode = curNode->next;
    }

    return head;
}

void printLinkedList(ListNode* head){

    ListNode* curNode = head;
    while( curNode != NULL ){
        cout << curNode->val << " -> ";
        curNode = curNode->next;
    }

    cout<<"NULL"<<endl;

    return;
}

void deleteLinkedList(ListNode* head){

    ListNode* curNode = head;
    while( curNode != NULL ){
        ListNode* delNode = curNode;
        curNode = curNode->next;
        delete delNode;
    }

    return;
}

ListNode *findInvertedNode(ListNode *head, int k)
{
    assert(k>0);
    //ListNode* dummyHead = new ListNode(0);
    ListNode *first;
    ListNode *second;
    //dummyHead->next = head;
    first = second = head;
    for(int i=0; i<k; i++)
    {
        second = second->next;
    }
    while(second != NULL)
    {
        first = first->next;
        second = second->next;
    }
    return first;
}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* pre = NULL;
        ListNode* cur = head;
        while( cur != NULL ){
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }
};

int main(){

    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(int);

    ListNode* head = createLinkedList(arr, n);
    printLinkedList(head);

    ListNode*p = findInvertedNode(head,4);
    cout << p->val <<endl;

    ListNode* head2 = Solution().reverseList(head);
    printLinkedList(head2);

    ListNode*p2 = findInvertedNode(head2,4);
    cout << p2->val <<endl;
    deleteLinkedList(head2);

    return 0;
}