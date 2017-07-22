#include <iostream>

using namespace std;

///Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/// LinkedList Test Helper Functions
ListNode* createLinkedList(int arr[], int n){

    if( n == 0 )
        return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* curNode = head;
    for( int i = 1 ; i < n ; i ++ ){
        curNode->next = new ListNode(arr[i]);
        curNode = curNode->next;
    }

    return head;
}

void printLinkedList(ListNode* head){

    if( head == NULL ){
        cout<<"NULL"<<endl;
        return;
    }

    ListNode* curNode = head;
    while( curNode != NULL ){
        cout<<curNode->val;
        if( curNode->next != NULL )
            cout<<" -> ";
        curNode = curNode->next;
    }

    cout<<endl;

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

// 不使用虚拟头结点
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        //在循环过程中不断的访问head—>val,
        //要保证每次进入循环时head都不为空！
        while( head != NULL && head->val == val ){

            ListNode* node = head;
            head = head->next;
            delete node;
        }
        //执行完上面的操作之后，就会由一个新的head
        //此时也要保证head不为NULL
        if( head == NULL )
            return head;

        ListNode* cur = head;
        while( cur->next != NULL ){

            if( cur->next->val == val ){
                ListNode* delNode = cur->next;
                cur->next = delNode->next;
                delete delNode;
            }
            else
                cur = cur->next;
        }

        return head;
    }
};

int main() {

    int arr[] = {1, 2, 6, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(int);

    ListNode* head = createLinkedList(arr, n);
    printLinkedList(head);

    head = Solution().removeElements( head, 1);
    printLinkedList(head);

    deleteLinkedList( head );

    return 0;
}