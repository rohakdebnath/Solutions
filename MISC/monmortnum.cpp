#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)
#define MX 1000000

i64 derange[MX + 1];
void drm(i64 M){
    derange[0] = 1, derange[1] = 0;
    rep(i, 2, MX + 1){
        derange[i] = (i - 1) * (derange[i - 1] + derange[i - 2]) % M;
    }
}

int main()
{
    UNSYNC
    i64 N, M; cin >> N >> M;
    drm(M);
    rep(i, 0, N){
        cout << derange[i + 1] << " \n"[i == N - 1];
    }
    return 0;
}
