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
    int N, M, K; cin >> N >> M >> K;
    vector<bool> val (1 << N, true);

    auto check = [&] (int a, int s){
        rep(i, 0, 1 << N){
            if (!val[i]) continue;
            if (s and __builtin_popcount(i & a) < K) val[i] = false;
            else if (!s and __builtin_popcount(i & a) >= K) val[i] = false;
        }
    };
    rep(i, 0, M){
        int a = 0;
        int c; cin >> c;
        rep(j, 0, c){
            int t; cin >> t; --t;
            a ^= (1 << t);
        }
        char d; cin >> d;
        int s = (d == 'o');
        check(a, s);
    }
    int ans = count(all(val), 1);
    cout << ans << '\n';
    return 0;
}
