/* General form of Linear Diophantine equation : ax + by = c

Generate all solution of equation by:
      x = x0 + k*b/g
      y = y0 - k*a/g
      
*/


int gcd(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

// Source : https://cp-algorithms.com/algebra/linear-diophantine-equation.html
// Source : https://cp-algorithms.com/algebra/linear_congruence_equation.html

// Problem : https://codeforces.com/contest/633/problem/A
// Solution : https://codeforces.com/contest/633/submission/62640906

// Problem : https://codeforces.com/contest/1244/problem/C
// Solution : https://codeforces.com/contest/1244/submission/63272323


