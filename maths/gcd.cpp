// if i want to divide an array of  number into exactly k group i then i should use gcd for that 

/*Description
My Submissions
Hints/Editorial
AC Submissions
My Notes (0)
Divide the Piles

Time-Limit: 1 sec Score: 1.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

There are N piles of stones in front of you. ith pile contains Ai number of stones.
You want to find whether it is possible to split each pile into 1 or more piles of X (≥ 2) stones such that each splitted-pile has exactly X stones.
Note that X should be the same for each pile.


Input Format

The first line contains T (1 ≤ T ≤ 100000), the number of test cases. The description of each test case is as follows:
The first line contains N, the number of piles (1 ≤ N ≤ 100000).
The second line contains N space-separated positive integers A1, A2, ..., AN (2 ≤ Ai ≤ 109).
It is guaranteed that sum of N over all test cases doesn't exceed 106.


Output Format

For each test case, print "Yes" (without quotes) if it is possible to split. Otherwise, print "No" (without quotes).


Sample Input 1

2

5

2 2 6 8 12

4

2 6 3 8


Sample Output 1

Yes

No


Note

Explanation 1:
For X = 2, you can divide each pile into smaller piles of size 2.

Explanation 2:
It is not possible to divide piles into smaller piles with size ≥ 2.*/

 /*
hist ,


 */

code