#include <iostream>
#include <vector>
#include "linkedlist.h"
using namespace std;

// Problem statement - https://leetcode.com/problems/reverse-nodes-in-k-group/description/

ListNode *reverseKGroup(ListNode *head, int k)
{
    vector<ListNode *> nodes;
    while (head != NULL)
    {
        nodes.push_back(head);
        head = head->next;
    }
    nodes.push_back(head);

    int x = ((nodes.size() - 1) / k) * k;
    for (int i = 0; i < x; i++)
    {
        if (i % k != 0)
        {
            nodes[i]->next = nodes[i - 1];
        }
        else if (i < x - k)
        {
            nodes[i]->next = nodes[i + 2 * k - 1];
        }
        else
        {
            nodes[i]->next = nodes[i + k];
        }
    }
    return nodes[k - 1];
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 14, 15};
    int k = 4;
    ListNode *head = createLinkedList(arr, sizeof(arr) / sizeof(int));
    // display(head);

    ListNode *result = reverseKGroup(head, k);
    display(result);
    return 0;
}
// Date: 13.3.25