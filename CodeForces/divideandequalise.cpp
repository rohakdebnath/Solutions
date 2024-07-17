#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>
#define MAXN 1e6 + 1

VI minprim (MAXN, -1);
void sieve()
{
    rep(i, 2, MAXN){
        if(minprim[i] == -1){
            for (int j = i; j < MAXN; j += i)
            if (minprim[j] == -1) minprim[j] = i;
        }
    }
}

void solve()
{
    map<int, int> fact;
    int N; cin >> N;
    rep(i, 0, N){
        int K; cin >> K;
        while (K > 1){
            ++fact[minprim[K]];
            K /= minprim[K];
        }
    }
    bool srv = true;
    for (auto [u, v]: fact){
        if (v % N){
            srv = false;
            break;
        }
    }
    cout << (srv ? "YES": "NO") << '\n';
}

int main()
{
    UNSYNC
    sieve();
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
