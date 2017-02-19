# ACM_ICPC
Goal: Know what they are, when they are used, and how they are used. Solve practice problems.

1. Week1: Dynamic Programming: 
	- Matrix Multiplication
	- Knapsack (0/1, unbounded, optimizations)
	- Tilings
	- Bitmask 
	- Game Theory (Grundy, Nim)
2. Week2: Greedy

3. Week3: Data Structures (Union-Find, PQ)

4. Week4: Graph

5. Week5: Mathematics, Binary Search

6. Week6: Geometry

7. Week7: More DP

8. Week8: More Data Structure

9. Week9: Advanced:
	- Network Flow (Min cut, Mincostflow)
	- LCA, 2SAT, SCC
	- Divide and Conquer


**HOW TO WRITE PSEUDO-CODE:**

```
TEMPLATE(A, i)
	<type> variable;
	for iterator: a → b
		while (condition)
			print value;
	return TEMPLATE(A, i - 1);
```

Example 1: 
http://codeforces.com/gym/100623 - Problem K
```
sort(A, <=)
SOLUTION(A)
    ll unable = 1;
    for i: 0 → n-1
        while (unable < A[i] && m > 0)
            print unable;
            unable *= 2;
            m--;
        unable += A[i];

    while (m > 0)
        print unable;
        unable *= 2;
        m--;
```

Example 2: 
Euclid's algorithm
```
GCD(a, b)
	if b == 0 then
		return a;
	return GCD(b, a mod b);
```
