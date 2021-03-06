Maximum Sum Path in Two Arrays
Last Updated: 16-03-2020
Given two sorted arrays, such that the arrays may have some common elements. Find the sum of the maximum sum path to reach from the beginning of any array to end of any of the two arrays. We can switch from one array to another array only at common elements.
Note: The common elements do not have to be at the same indexes.

Expected Time Complexity: O(m+n), where m is the number of elements in ar1[] and n is the number of elements in ar2[].

Examples:

Input: ar1[] = {2, 3, 7, 10, 12}
       ar2[] = {1, 5, 7, 8}
Output: 35

Explanation: 35 is sum of 1 + 5 + 7 + 10 + 12.
We start from the first element of arr2 which is 1, then we
move to 5, then 7.  From 7, we switch to ar1 (as 7 is common)
and traverse 10 and 12.

Input: ar1[] = {10, 12}
       ar2 = {5, 7, 9}
Output: 22

Explanation: 22 is the sum of 10 and 12.
Since there is no common element, we need to take all 
elements from the array with more sum.

Input: ar1[] = {2, 3, 7, 10, 12, 15, 30, 34}
        ar2[] = {1, 5, 7, 8, 10, 15, 16, 19}
Output: 122

Explanation: 122 is sum of 1, 5, 7, 8, 10, 12, 15, 30, 34
Recommended: Please solve it on “PRACTICE” first, before moving on to the solution.
Efficient Approach: The idea is to do something similar to merge process of merge sort. This involves calculating the sum of elements between all common points of both arrays. Whenever there is a common point, compare the two sums and add the maximum of two to the result.

Algorithm:

Create some variables, result, sum1, sum2. Initialize result as 0. Also initialize two variables sum1 and sum2 as 0. Here sum1 and sum2 are used to store sum of element in ar1[] and ar2[] respectively. These sums are between two common points.
Now run a loop to traverse elements of both arrays. While traversing compare current elements of array 1 and array 2 in the following order.
If current element of array 1 is smaller than current element of array 2, then update sum1, else if current element of array 2 is smaller, then update sum2.
If the current element of array 1 and array 2are same, then take the maximum of sum1 and sum2 and add it to the result. Also add the common element to the result.
This step can be compared to the merging of two sorted arrays, If the smallest element of the two current array indices is processed then it is guaranteed that if there is any common element it will be processed together.So the sum of elements between two common elements can be processed.
Implementation:


filter_none
edit
play_arrow

brightness_4
#include<iostream> 
using namespace std; 
  
// Utility function to find maximum of two integers 
int max(int x, int y) { return (x > y)? x : y; } 
  
// This function returns the sum of elements on maximum path 
// from beginning to end 
int maxPathSum(int ar1[], int ar2[], int m, int n) 
{ 
    // initialize indexes for ar1[] and ar2[] 
    int i = 0, j = 0; 
  
    // Initialize result and current sum through ar1[] and ar2[]. 
    int  result = 0, sum1 = 0, sum2 = 0; 
  
    // Below 3 loops are similar to merge in merge sort 
    while (i < m && j < n) 
    { 
        // Add elements of ar1[] to sum1 
        if (ar1[i] < ar2[j]) 
            sum1 += ar1[i++]; 
  
        // Add elements of ar2[] to sum2 
        else if (ar1[i] > ar2[j]) 
            sum2 += ar2[j++]; 
  
        else  // we reached a common point 
        { 
            // Take the maximum of two sums and add to result 
            result += max(sum1, sum2); 
  
            // Update sum1 and sum2 for elements after this 
            // intersection point 
            sum1 = 0, sum2 = 0; 
  
            // Keep updating result while there are more common 
            // elements 
            while (i < m &&  j < n && ar1[i] == ar2[j]) 
            { 
                result = result + ar1[i++]; 
                j++; 
            } 
        } 
    } 
  
    // Add remaining elements of ar1[] 
    while (i < m) 
        sum1  +=  ar1[i++]; 
  
    // Add remaining elements of ar2[] 
    while (j < n) 
        sum2 +=  ar2[j++]; 
  
    // Add maximum of two sums of remaining elements 
    result +=  max(sum1, sum2); 
  
    return result; 
} 
  
// Driver program to test above function 
int main() 
{ 
    int ar1[]  = {2, 3, 7, 10, 12, 15, 30, 34}; 
    int ar2[] =  {1, 5, 7, 8, 10, 15, 16, 19}; 
    int m = sizeof(ar1)/sizeof(ar1[0]); 
    int n = sizeof(ar2)/sizeof(ar2[0]); 
    cout << "Maximum sum path is " 
         << maxPathSum(ar1, ar2, m, n); 
    return 0; 
} 
Output:

Maximum sum path is 122
Complexity Analysis:

Space Complexity: O(1).
Any extra space is not required, so the space complexity is constant.
Time complexity: O(m+n).
In every iteration of while loops, an element from either of the two arrays is processed. There are total m + n elements. Therefore, the time complexity is O(m+n).

/////////////////////////////////////////////////////////////////////////////////////////
///


Maximum path sum in the given arrays with at most K jumps
(GFG)