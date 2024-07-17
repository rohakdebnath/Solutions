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
    int A, B, K; cin >> A >> B >> K;
    for (int i = A; i <= min(A + K - 1, B); ++i) cout << i << '\n';
    for (int i = max(max(B - K + 1, A), min(A + K, B + 1)); i <= B; ++i) cout << i << '\n';
    return 0;
}
