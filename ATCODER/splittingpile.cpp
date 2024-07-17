#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (i64 i {ini}; i < x; ++i)
#define per(fin, x) for (i64 i {fin}; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

int main()
{
    UNSYNC
    i64 N; cin >> N;
    VI A (N);rep(0, N) cin >> A[i];
    VI preA (N); preA[0] = A[0];
    rep(1, N) preA[i] = preA[i - 1] + A[i]; 
    VI sufA (N); sufA[N - 1] = A[N - 1];
    per(N - 2, 0) sufA[i] = sufA[i + 1] + A[i];

    i64 mini = INT32_MAX;
    rep(0, N - 1)
    {
        mini = min(mini, abs(preA[i] - sufA[i + 1]));
    }
    cout << mini << '\n';
    return 0;
}
