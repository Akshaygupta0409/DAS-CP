/*
My Notes (0)
Budget Travelling

Time-Limit: 2 sec Score: 0.00/100
Difficulty : 
 Memory: 256 MB Accepted Submissions: 100
Relevant For:
Description

You want to visit the country of wonderland. There are N cities in the country. Not all cities are connected by roads. You know which cities are connected. 

You landed in city A, and you want to visit city B. You already booked your car, but it doesn’t have any petrol. The capacity of the tank of the car is C. You know the Per Liter cost of petrol in each city, and you also have the map of the country, i.e., you know the length of road between two cities. To travel one unit of distance, you need one liter of petrol.

Find the minimum cost to travel from city A to city B.


Input Format

The first line of input contains N - the number of cities in the country of wonderland.
The second line contains M - the number of roads in the country.
Next M lines contain three integers u, v, d - there is a road between city u and v of length d.
The next lines contain N space-separated integers P[1], P[2], …., P[N] - P[i] is the per liter cost of petrol in the city i.
The last line of input contains A, B, and C - the starting city, the destination city, and the capacity of the tank of car you booked.
It’s guaranteed that it’s always possible to reach city B from A.


Output Format

Print the minimum cost to reach city B on a new line.


Constraints

1 ≤ N ≤ 10000
1 ≤ M ≤ 100000
1 ≤ C ≤ 100
1 ≤ u, v ≤ N
1 ≤ d ≤ C
1 ≤ A, B ≤ N
1 ≤ P[i] ≤ 100
 


Sample Input 1

5
5
1 2 1
2 3 1
3 4 1
4 5 1
1 4 6
1 10 10 10 1
1 5 8

Sample Output 1

4

Sample Input 2

6
6
1 2 1
2 3 1
3 4 1
4 5 1
1 6 1
6 5 5
10 10 10 10 1 1
1 5 8

Sample Output 2

15

Note

Explanation 1:

Fill petrol of 4 liters in city 1, and travel via path 1 → 2 → 3 → 4 → 5.

Explanation 2:

Fill 1 liter of petrol in city 1 of cost 10, travel to city 6. Fill 5 liters of petrol at city 6 of cost 5 x 1 = 5. Travel to city 5. Total cost = 10 + 5 = 15. The path took 1 → 6 → 5.
*/


// logic and code -> think for a linear chain and then try to comeup with some dp state and solution ;


