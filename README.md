# ACM_ICPC

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
