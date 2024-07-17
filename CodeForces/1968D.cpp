#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

i64 best(vector<i64>& v, i64 k){
    i64 b = 0;
    i64 n = v.size();
    vector<i64> pv (n + 1); partial_sum(all(v), pv.begin() + 1);
    rep(i, 0, min(n, k)){  
        b = max(b, (k - i) * v[i] + pv[i]);
    }
    return b;
}
void solve()
{
    i64 N, k, pb, ps; cin >> N >> k >> pb >> ps; --pb, --ps;
    vector<i64> P (N); rep(i, 0, N) cin >> P[i], --P[i];
    vector<i64> A (N); rep(i, 0, N) cin >> A[i];

    vector<i64> pathB;
    i64 s = pb;
    rep(i, 0, min(N, k)){
        pathB.push_back(A[s]);
        s = P[s];
    }

    vector<i64> pathS;
    s = ps;
    rep(i, 0, min(N, k)){
        pathS.push_back(A[s]);
        s = P[s];
    }
    i64 ab = best(pathB, k), as = best(pathS, k);
    
    if (as > ab){
        cout << "SASHA\n";
    } else if (as < ab){
        cout << "BODYA\n";
    } else {
        cout << "DRAW\n";
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
