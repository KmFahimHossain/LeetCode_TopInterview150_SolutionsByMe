#include <iostream>
#include "linkedlist.h"
using namespace std;

// Problem statement - https://leetcode.com/problems/reverse-linked-list-ii/description/

ListNode* reverseBetween(ListNode* head, int left, int right) 
{
    if(left == right)
    {
        return head;
    }

    ListNode* prev = NULL;
    ListNode* current = head;
    ListNode* later = head->next;
    ListNode* beforeStart = NULL;
    ListNode* afterEnd = NULL;
    ListNode* start = NULL;
    ListNode* end = NULL;

    for(int i = 1; i <= right; i++)
    {
        if(i == left)
        {
            beforeStart = prev;
            start = current;
            current->next = prev;
        }
        else if( i > left  && i <= right )
        {
            current->next = prev;
            if( i == right)
            {
                end = current;
                afterEnd = later;
                break;
            }
        }
        prev = current;
        current = later;
        later = later->next;
    }

    start->next = afterEnd;
    if(beforeStart != NULL)
    {
        beforeStart->next = end;
    }
    else
    {
        head = end;
    }
    return head;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int left = 2;
    int right = 7;
    ListNode* head = createLinkedList(arr, sizeof(arr)/sizeof(int));
    //display(head);

    ListNode* result = reverseBetween(head, left, right);
    display(result);
    return 0;
}
// Date: 08.3.25