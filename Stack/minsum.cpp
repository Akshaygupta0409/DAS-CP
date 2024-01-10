Super Minimum Sum

Time-Limit: 1 sec Score: 0.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You have given an array A of size N. A1, A2, ..., AN are the elements of the array. All elements in the array A are distinct.
Find the sum of the minimum of all subarrays possible of array A.

A subarray of an -element array is an array composed from a contiguous block of the original array's elements


Input Format

The first line contains T, the number of test cases.
The first line of each test case contains N, the number of integers in an array A.
The second line of each test case contains N space-separated integers A1, A2, ..., AN.


Output Format

For each test case, print a single number representing the sum of the minimum of all subarrays of A.


Constraints

1 ≤ T ≤ 100000
1 ≤ N ≤ 100000
1 ≤ Ai ≤ 106
Sum of N over all test cases ≤ 5 * 105.
It is guaranteed that all elements in an array A are distinct.


Sample Input 1

5
3
1 2 3
2
1 5
4
2 3 4 10
8
1000000 1000001 1000002 1000003 1000004 1000005 1000006 1000007
3
3 1 2

Sample Output 1

10
7
35
36000084
9

Note

Explanation 1:
Min{1} + Min{1, 2} + Min{1, 2, 3} + Min{2} + Min{2, 3} + Min{3} = 1 + 1 + 1 + 2 + 2 + 3 = 10

Explanation 2:
Min{1} + Min{1, 5} + Min{5} = 1 + 1 + 5 = 7

idea and code are not that complicated to understand;