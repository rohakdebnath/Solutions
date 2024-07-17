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
    int N, M; cin >> N >> M;
    VVI data (M, VI (0));
    rep(0, M)
    {
        int k; cin >> k;
        data[i].resize(k);
        for (int j = 0; j < k; ++j) cin >> data[i][j];
    }
    VI p (M);
    rep(0, M) cin >> p[i];

    int count = 0;
    for (int i = 0; i < (1 << N); ++i)
    {
        bool survive = true;
        for (int j = 0; j < M; ++j)
        {
            int switchon = 0;
            for (int k = 0; k < sci(data[j].size()); ++k) if (i & (1 << (data[j][k] - 1))) ++switchon;
            if (switchon % 2 != p[j])
            {
                survive = false;
                break;
            }
        }
        if (survive) ++count;
    }

    cout << count << '\n';
    return 0;
}
