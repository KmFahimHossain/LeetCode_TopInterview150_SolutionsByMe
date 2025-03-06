#include <iostream>
#include "linkedlist.h"
using namespace std;

// Problem statement - https://leetcode.com/problems/linked-list-cycle/description/

ListNode* createLinkedListWithCycle(int arr[], int size, int pos)
{
    if(size == 0)
    {
        return NULL;
    }

    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    ListNode* target = NULL;
    for(int i = 1; i < size; i++)
    {
        current->next = new ListNode(arr[i]);
        current = current->next;
        if(i==pos)
        {
            target = current;
        }
    }

    if(pos == 0)
    {
        current->next = head;
    }
    
    else if(target != NULL)
    {
        current->next = target;
    }
    return head;
}

bool hasCycle(ListNode *head)
{
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != NULL && fast->next != NULL) 
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) 
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int arr[] = {3,0,2,-4};
    int pos = 1;
    ListNode* head = createLinkedListWithCycle(arr, sizeof(arr)/sizeof(int), pos);
    //display(head);

    cout << hasCycle(head);
    return 0;
}
// Date: 06.3.25