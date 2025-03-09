#include <iostream>
#include "linkedlist.h"
using namespace std;

// Problem statement - https://leetcode.com/problems/partition-list/description/

ListNode* partition(ListNode* head, int x)
{
    ListNode* dummy1 = new ListNode(0);
    ListNode* dummyTemp1 = dummy1;
    ListNode* dummy2 = new ListNode(0);
    ListNode* dummyTemp2 = dummy2;
    ListNode* temp = head;
    while(temp != NULL)
    {
        if(temp->val < x)
        {
            dummyTemp1->next = new ListNode(temp->val);
            dummyTemp1 = dummyTemp1->next;
        }
        else
        {
            dummyTemp2->next = new ListNode(temp->val);
            dummyTemp2 = dummyTemp2->next;
        }
        temp = temp->next;
    }
    dummyTemp1->next = dummy2->next;
    return dummy1->next;
}

int main()
{
    int arr[] = {1,4,3,2,5,2};
    int x = 3;
    ListNode* head = createLinkedList(arr, sizeof(arr)/sizeof(int));
    //display(head);

    ListNode* result = partition(head, x);
    display(result);
    return 0;
}
// Date: 09.3.25