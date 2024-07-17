#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

i64 N, K; 
vector<i64> A; 

i64 incexc(i64 id, i64 l, vector<i64> prod){
    if (id == K) {
        i64 n = N;
        for (i64 i: prod) n /= i;
        return (l & 1LL ? -n : n);
    };
    i64 cur = incexc(id + 1, l, prod);
    prod.push_back(A[id]);
    cur += incexc(id + 1, l + 1, prod);
    prod.pop_back();
    return cur;
}

int main()
{
    UNSYNC
    cin >> N >> K;
    A.resize(K);
    rep(i, 0, K) cin >> A[i];
    i64 ans = incexc(0, 0, vector<i64> ());
    cout << N - ans << '\n';
    return 0;
}
