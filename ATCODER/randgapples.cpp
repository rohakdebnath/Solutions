#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

int main()
{
    UNSYNC
    i64 X, Y, A, B, C; cin >> X >> Y >> A >> B >> C;
    vector<i64> p (A); rep(i, 0, A) cin >> p[i]; sort(all(p), greater<i64> ());
    vector<i64> q (B); rep(i, 0, B) cin >> q[i]; sort(all(q), greater<i64> ());
    vector<i64> r (C); rep(i, 0, C) cin >> r[i]; sort(all(r), greater<i64> ());

    priority_queue<i64, vector<i64>, greater<i64>> pq;
    i64 ans = 0;
    rep(i, 0, X) pq.push(p[i]), ans += p[i];
    rep(i, 0, Y) pq.push(q[i]), ans += q[i];

    rep(i, 0, C){
        i64 top = pq.top();
        if (top < r[i]){
            pq.pop();
            pq.push(r[i]);
            ans = ans - top + r[i];
        }
    }
    cout << ans << '\n';
    return 0;
}
