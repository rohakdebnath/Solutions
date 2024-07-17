#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<i64>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    i64 N, x; cin >> N >> x;
    VI A (N); rep(0, N) cin >> A[i];
    sort(all(A));

    i64 happyc = 0;
    i64 i;
    for (i = 0; i < N; ++i)
    {
        if (A[i] <= x)
        {
            x -= A[i];
            ++happyc;
        }
        else break;
    }
    if (i == N and x > 0) --happyc;
    cout << happyc << '\n';
    return 0;
}
