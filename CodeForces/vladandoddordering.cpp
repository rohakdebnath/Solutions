#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

void solve()
{
    int N, K; cin >> N >> K;
    int x = N;
    int lvl = 1;
    while (x > 0){
        int countinlayer = x - x/2;
        if (K <= countinlayer){
            cout << lvl * (2*K - 1) << '\n';
            break;
        }
        K -= countinlayer;
        lvl *= 2;
        x /= 2;
    }
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
