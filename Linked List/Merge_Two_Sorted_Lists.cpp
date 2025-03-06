#include <iostream>
#include "linkedlist.h"
using namespace std;

// Problem statement - https://leetcode.com/problems/merge-two-sorted-lists/description/

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    ListNode* current = new ListNode(0);
    ListNode* result = current;

    while (list1 != NULL && list2 != NULL) 
    {
        if(list1->val <= list2->val)
        {
            current->next = new ListNode(list1->val);
            list1 = list1->next;
        }
        else
        {
            current->next = new ListNode(list2->val);
            list2 = list2->next;
        }
        current = current->next;
    }

    if (list1 != NULL) 
    {
        current->next = list1;
    }

    else if (list2 != NULL) 
    {
        current->next = list2;
    }
    return result->next;
}

int main()
{
    int arr1[] = {1,2,3,3,4,11};
    int arr2[] = {1,3,4};
    ListNode* list1 = createLinkedList(arr1, sizeof(arr1)/sizeof(int));
    ListNode* list2 = createLinkedList(arr2, sizeof(arr2)/sizeof(int));
    // display(list1);
    // display(list2);
    ListNode* l3 = mergeTwoLists(list1, list2);
    display(l3);
    return 0;
}
// Date: 06.3.25