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
    int N; cin >> N;
    vector<int> A (N); rep(i, 0, N) cin >> A[i];
    vector<int> B (N); rep(i, 0, N) cin >> B[i];
    i64 pos = 0, neg = 0;
    rep(i, 0, N){
        if (B[i] - A[i] >= 0) pos += (B[i] - A[i]) / 2 * 2;
        else neg += A[i] - B[i];
    }
    cout << (pos >= 2LL * neg ? "Yes\n" : "No\n");

    return 0;
}
