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
    VI H (N); rep(0, N) cin >> H[i];

    bool survive = true;
    for(int i = 0; i < N - 1; ++i)
    {
        if (H[i] > H[i + 1]) ++H[i + 1];
        if (H[i] > H[i + 1])
        {
            survive = false;
            break;
        }
    }
    cout << (survive ? "Yes" : "No") << '\n';
    return 0;
}
