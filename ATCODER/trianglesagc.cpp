#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

int main()
{
    UNSYNC
    i64 S; cin >> S;
    i64 MOD = 1e9;
    i64 X = (MOD - S % MOD) % MOD;
    i64 Y = (S + X)/MOD;
    
    cout << "0 0 1000000000 1 " << X << ' ' << Y << '\n';
    return 0;
}
