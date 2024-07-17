#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

const i64 MOD = 998244353; 
i64 binexp (i64 base, i64 pow){
    i64 res = 1;
    while (pow){
        if (pow & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        pow /= 2;
    }
    return res;
}

int main()
{
    UNSYNC
    int N; cin >> N;
    vector<int> A (N); rep(i, 0, N) cin >> A[i];
    if (A[0] != 0){
        cout << "0\n";
        return 0;
    }
    vector<int> level (*max_element(all(A)) + 1); level[0] = 1;
    for (int i = 1; i < N; ++i){
        if (A[i] == 0){
            cout << "0\n";
            return 0;
        }
        level[A[i]]++;
    }
    i64 ans = 1;
    for (int i = 0; i < level.size() - 1; ++i){
        ans = (ans * binexp(level[i], level[i + 1])) % MOD;
    }
    cout << ans << '\n';
    return 0;
}
