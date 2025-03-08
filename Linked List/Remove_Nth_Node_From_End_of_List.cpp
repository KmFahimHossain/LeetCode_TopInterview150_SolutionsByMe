#include <iostream>
#include "linkedlist.h"
using namespace std;

// Problem statement - https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    int i = 0;
    ListNode* current = head;
    while(current != NULL)
    {
        current = current->next;
        i++;
    }

    current = head;
    while( i != n + 1)
    {
        current = current->next;
        i--;
        if( i == 0)
        {
            return head->next;
        }
    }
    current->next = current->next->next;
    return head;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = 2;
    ListNode* head = createLinkedList(arr, sizeof(arr)/sizeof(int));
    //display(head);

    ListNode* result = removeNthFromEnd(head, n);
    display(result);
    return 0;
}
// Date: 08.3.25