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
    string s; cin >> s;
    int mv = 0;
    rep(k, 1, N + 1){
        vector<int> test (N + 1);
        rep(i, 0, N - k + 1){
            if (i) test[i] += test[i - 1];
            if ((test[i] + (s[i] == '1'))% 2) continue;
            ++test[i], --test[i + k];
        }
        rep(i, N - k + 1, N) test[i] += test[i - 1];
        int srv = 1;
        rep(i, N - k + 1, N){
            if ((test[i] + (s[i] == '1')) % 2 == 0){
                srv = 0;
                break;
            }
        }
        if (srv) mv = max(mv, k);
    }
    cout << mv << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
