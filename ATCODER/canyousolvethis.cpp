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
    int N, M , C; cin >> N >> M >> C;
    VI B (M); rep(0, M) cin >> B[i];
    int count = 0;
    for (int j = 0; j < N; ++j)
    {
        VI A (M); rep(0, M) cin >> A[i];
        int temp = 0;
        rep(0, M) temp += A[i] * B[i];
        if (temp + C > 0) ++count;
    }

    cout << count << '\n';
    return 0;
}
