#include <iostream>
#include <cassert>

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

// 使用双指针, 对链表只遍历了一遍
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        assert(n>=0);
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* p = dummyHead;
        ListNode* q = dummyHead;
        //将q指针向后移动n+1次
        //n最多为链表节点的总数
        for( int i = 0 ; i < n + 1 ; i ++ ){
            //保证每一次新遍历的q不为空！
            assert(q);
            q = q->next;
        }
        //此时q就是待删除节点的前一个位置！
        while( q ){
            p = p->next;
            q = q->next;
        }

        ListNode* delNode = p->next;
        p->next = delNode->next;
        delete delNode;

        ListNode* retNode = dummyHead->next;
        delete dummyHead;

        return retNode;
    }
};

int main() {

    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(int);

    ListNode* head = createLinkedList(arr, n);
    printLinkedList(head);

    head = Solution().removeNthFromEnd(head, 2);
    printLinkedList(head);

    deleteLinkedList(head);

    return 0;
}