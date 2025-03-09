#include <iostream>
#include "linkedlist.h"
using namespace std;

// Problem statement - https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/

ListNode* deleteDuplicates(ListNode* head)
{
    if(head == NULL)
    {
        return head;
    }

    ListNode* prev = new ListNode(0);
    prev->next = head;
    ListNode* current = head;
    head = prev;
    int skip = 0;
    while(current->next != NULL)
    {
        while(current->val == current->next->val)
        {
            skip = 1;
            current->next = current->next->next;
            if(current->next == NULL)
            {
                prev->next = NULL;
                return head->next;
            }
        }

        if(skip == 1)
        {
            skip = 0;
            prev->next = current->next;
            current = current->next;
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
    return head->next;
}

int main()
{
    int arr[] = {1,1,1,1,2,3,3,3,3,3,3,4,4,5,6,6,6,6,7,8,9,9,9,9};
    ListNode* head = createLinkedList(arr, sizeof(arr)/sizeof(int));
    //display(head);

    ListNode* result = deleteDuplicates(head);
    display(result);
    return 0;
}
// Date: 09.3.25