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
    int N, S, K; cin >> N >> S >> K;
    int sum = 0;
    rep(0, N)
    {
        int P, Q; cin >> P >> Q;
        sum += P*Q;
    }
    cout << (sum >= S ? sum : sum + K) << '\n';
    return 0;
}
