#include <iostream>
#include "linkedlist.h"
using namespace std;

// Problem statement - https://leetcode.com/problems/add-two-numbers/description/

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    int sum = 0;
    int carry = 0;
    ListNode* current = new ListNode(0);
    ListNode* result = current;

    while(l1 != NULL && l2 != NULL)
    {
        sum = l1->value + l2->value + carry;
        l1 = l1->next;
        l2 = l2->next;
        carry = sum>=10;
        sum = sum%10;
        current->next = new ListNode(sum);  
        current = current->next;
    }

    while(l1 != NULL)
    {
        sum = l1->value + carry;
        l1 = l1->next;
        carry = sum>=10;
        sum = sum%10;
        current->next = new ListNode(sum);  
        current = current->next;
    }

    while(l2 != NULL)
    {
        sum = l2->value + carry;
        l2 = l2->next;
        carry = sum>=10;
        sum = sum%10;
        current->next = new ListNode(sum);  
        current = current->next;
    }

    if(carry > 0)
    {
        current->next = new ListNode(carry);  
    }
    return result->next;
}

int main()
{
    int arr1[] = {9,2,9,9,9,9,9};
    int arr2[] = {9,1,2,9};
    ListNode* l1 = createLinkedList(arr1, sizeof(arr1)/sizeof(int));
    ListNode* l2 = createLinkedList(arr2, sizeof(arr2)/sizeof(int));
    // display(l1);
    // display(l2);
    ListNode* l3 = addTwoNumbers(l1, l2);
    display(l3);
    return 0;
}
// Date: 06.3.25