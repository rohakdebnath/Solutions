#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve()
{
    int N; cin >> N;
    int o = 0, e = 0, all1 = 0;
    rep(i, 0, N){
        int X; cin >> X;
        if (X == 1) ++all1;
        X & 1 ? ++o : ++e;
    }
    if (N % 2 == 0 and all1 >= N - 1 and o == N){
        cout << "Draw\n";
    } else {
        if (o & 1) cout << "Alice\n";
        else cout << "Bob\n";
    }
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
