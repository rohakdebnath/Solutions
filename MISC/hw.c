#include <stdio.h>

int gcd(int a, int b, int* x, int* y){
    if (b == 0){
        *x = 1;
        *y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - y1 * (a / b);
    return d;
}

int exp(int base, int pow, int mod){
    int res = 1;
    base = base % mod;
    while (pow){
        if (pow & 1) res = res * base % mod;
        base = base * base % mod;
        pow /= 2;
    }
    return res;
}

int main () {
    int o;
    scanf("%d", &o);
    if (o == 0) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        printf("%d\n", exp(a, b, c));
    } else {
        int a, m; scanf("%d %d", &a, &m);
        int x, y;
        int g = gcd(a, m, &x, &y);
        printf("%d %d\n", g, (g == 1 ? x = (x % m + m) % m : 0));
    }
    return 0;
}
