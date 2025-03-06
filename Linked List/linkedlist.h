#include <iostream>
using namespace std;

struct ListNode
{
    int value;
    ListNode* next;

    ListNode(int x)
    {
        value = x;
        next = NULL;
    }
};

ListNode* createLinkedList(int arr[], int size)
{
    if(size == 0)
    {
        return NULL;
    }

    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for(int i = 1; i < size; i++)
    {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

void display(ListNode* head)
{
    ListNode* current = head;
    while ( current != NULL)
    {
        cout<<current->value<<" -> ";
        current = current->next;
    }
    cout<<"NULL"<<endl;
}
// Date: 06.3.25
