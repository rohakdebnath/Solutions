//Write the equation of sum of divisors on paper, there are two things which needs to be satisfied for applying mod to the geometric sum terms
//1.For a prime factor P, P % MOD != 0 (since P is prime, only way P is composite to something is if that something is a multiple of P), if it is equal to 0 then that whole term becomes equal to 1, trivially
//2.For a prime factor P, P % MOD != 1 (this condition is to make the modular inverse exist) if it's equal then the geometric term is trivially equal to 1 + B*P,
//If the above conditions are satisfied then both euler totient (fermat's little theorem since MOD is luckily prime) and modular inverse can be applied

#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

const i64 MOD = 1e9 + 7;
void setIO(string name = "")
{
    UNSYNC
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

i64 exp(i64 base, i64 pow){
    base %= MOD;    
    i64 res = 1;
    while (pow){
        if (pow & 1LL) res = (res * base) % MOD;
        base = base * base % MOD;
        pow /= 2;
    }
    return res;
}

i64 B;
i64 modulate(i64 base, i64 pow){
    if (base % MOD == 0) return 1;
    if (base % MOD == 1) return (pow * (B % MOD) + 1) % MOD;
    return (exp(base, (B % (MOD - 1) * pow + 1) % (MOD - 1)) - 1 + MOD) * exp(base - 1, MOD - 2) % MOD;
}

int main()
{
    UNSYNC
    setIO("sumdiv");
    i64 A; cin >> A >> B;
    i64 ans = 1;
    for (i64 i = 2; i * i <= A; ++i){
        i64 p = 0;
        while (A % i == 0){
            ++p;
            A /= i;
        }
        if (p) ans = ans * modulate(i, p) % MOD;
    }
    if (A > 1) ans = ans * modulate(A, 1) % MOD;
    cout << ans << '\n';
    return 0;
}
