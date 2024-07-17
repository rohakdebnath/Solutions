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
    int K, N; cin >> K >> N;
    VI A (N); rep(0, N) cin >> A[i];
    sort(all(A));
    A.emplace_back(K + A[0]);

    int maxdis = 0;
    for(int i = 1; i < N + 1; ++i)
    {
        maxdis = max(maxdis, A[i] - A[i - 1]);
    }

    cout << K - maxdis << '\n';
    return 0;
}
