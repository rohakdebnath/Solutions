#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    int N; cin >> N;
    VI A1 (N); rep(0, N) cin >> A1[i];
    VI A2 (N); rep(0, N) cin >> A2[i];
    for(int i = 1; i < N; ++i)
    {
        A1[i] += A1[i - 1];
    }
    for(int i = N - 2; i >= 0; --i)
    {
        A2[i] += A2[i + 1];
    }
    int maxim = 0;
    rep(0, N)
    {
        maxim = max(maxim, A1[i] + A2[i]);
    }
    cout << maxim << '\n';
    return 0;
}
