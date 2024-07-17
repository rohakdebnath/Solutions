#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

int main()
{
    UNSYNC
    i64 N; cin >> N;
    VI A (N); rep(i, 0, N) cin >> A[i];
    string S; cin >> S;
    i64 bob = 0;
    rep(i, 0, N){
        bob += S[i] == 'B' ? A[i] : 0;
    }
    i64 maxbobpre = bob, maxbobpost = bob;
    rep(i, 0, N){
        bob += S[i] == 'B' ? -A[i] : A[i];
        maxbobpre = max(maxbobpre, bob);
    }
    bob = maxbobpost;
    per(i, N - 1, 0){
        bob += S[i] == 'B' ? -A[i] : A[i];
        maxbobpost = max(maxbobpost, bob);
    }
    cout << max(maxbobpost, maxbobpre) << '\n';
    return 0;
}
