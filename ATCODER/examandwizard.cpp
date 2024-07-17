#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i {ini}; i < x; ++i)
#define per(i, fin, x) for (i64 i {fin}; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

int main()
{
    UNSYNC
    i64 N; cin >> N;
    VI A (N), B (N);
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) cin >> B[i];
    i64 changes = 0;
    i64 req = 0;
    VI surp;
    rep(i, 0, N)
    {
        if (A[i] < B[i])
        {
            ++changes;
            req += B[i] - A[i];
        }
        else if (A[i] > B[i]) surp.push_back(A[i] - B[i]);
    }
    sort(all(surp));
    if (req > accumulate(all(surp), 0LL))
    {
        cout << "-1\n";
        return 0;
    }
    while (req > 0)
    {
        ++changes;
        req -= surp.back();
        surp.pop_back();
    }
    cout << changes << '\n';
    return 0;
}
