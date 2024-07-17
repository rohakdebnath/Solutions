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
    int N, C, K; cin >> N >> C >> K;
    VI T (N); rep(0, N) cin >> T[i];
    sort(all(T));
    int buses = 0;
    int ptr = 0;
    while (ptr < N)
    {
        int t = ptr;
        ++t;
        while (t - ptr < C and T[t] - T[ptr] <= K and t < N) ++t;
        ++buses;
        ptr = t;
    }
    cout << buses << '\n';
    return 0;
}
