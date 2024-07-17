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
    VI A (N); rep(0, N) cin >> A[i];
    int mean = accumulate(all(A), 0)/N;

    int stam1 = 0;
    int stam2 = 0;
    for(int i = 0; i < N; ++i)
    {
        stam1 += pow(mean - A[i], 2);
        stam2 += pow(mean + 1 - A[i], 2);
    }

    cout << min(stam1, stam2) << '\n';

    return 0;
}
