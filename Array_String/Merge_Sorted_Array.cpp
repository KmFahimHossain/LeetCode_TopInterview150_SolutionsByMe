#include <iostream>
using namespace std;

// Problem statement - https://leetcode.com/problems/merge-sorted-array/description/

void solution(int* nums1, int* nums2, int m , int n)
{
    int i = m-1;
    int j = n-1;
    int k = m + n -1;
    while(j>=0)
    {
        if(i<0)
        {
            while(j>=0)
            {
                nums1[k] = nums2[j];
                j--; 
                k--;
            }
        }

        else if (nums1[i] >= nums2[j])
        {
            nums1[k] = nums1[i];
            i--;
            k--;
            if (i == -1)
            {
                while(j>=0)
                {
                    nums1[k] = nums2[j];
                    j--; 
                    k--;
                }
            }
        }

        else
        {
            nums1[k] = nums2[j];
            j--; 
            k--;
        }
    }
}

int main()
{
    int num1[] = {0,1,2,5,6,6,8,11,0,0,0,0,0,0};
    int num2[] = {-1,0,5,5,88,99};
    int m = 8;
    int n = 6;

    solution(num1,num2,m,n);

    for ( int i = 0; i < m+n ; i++)
    {
        cout<<num1[i]<<" ";
    }

    return 0;
}

// Date: 21.1.25
