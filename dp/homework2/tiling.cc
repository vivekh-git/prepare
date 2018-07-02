#include <bits/stdc++.h>
using namespace std;

/*
Problem - 3 x n board, 2 x 1 tiles
For n=2,  3 configurations
*/

/* Recurrence relation
f(n) -> Number of ways to fill 2*1 tiles on a 3xn board.
f(0) = 0
f(1) = 0 // not possibole
f(2) = 3
f(3) = 0
f(n) -> if (n %2 != 0) return 0;
        if (n == 2) return 3;
        // a tile can be place horizontally or vertically
        // 3 + f(n-3)


*/