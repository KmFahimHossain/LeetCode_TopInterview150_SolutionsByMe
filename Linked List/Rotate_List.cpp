#include <iostream>
#include "linkedlist.h"
using namespace std;

// Problem statement - https://leetcode.com/problems/rotate-list/description/

ListNode* rotateRight(ListNode* head, int k)
{
    if(head == NULL)
    {
        return head;
    }

    int size = 0;
    ListNode* temp1 = head;
    ListNode* temp2 = head;
    while(temp1->next != NULL)
    {
        temp1 = temp1->next;
        size++;
    }
    temp1->next = head;
    size++;
    k = k%size;

    for(int i = 0; i < size - k - 1; i++)
    {
        temp2 = temp2->next;
    }
    head = temp2->next;
    temp2->next = NULL;
    return head;
}

int main()
{
    int arr[] = {1,2,3,4,5,6};
    int k = 2;
    ListNode* head = createLinkedList(arr, sizeof(arr)/sizeof(int));
    //display(head);

    ListNode* result = rotateRight(head,k);
    display(result);
    return 0;
}
// Date: 09.3.25