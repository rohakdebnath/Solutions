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
    int N, D; cin >> N >> D;
    VVI data (N, VI (D));
    for (int i = 0; i < N; ++i) for (int j = 0; j < D; ++j) cin >> data[i][j];

    int count = 0;
    for (int i = 0; i < N; ++i)
    {
        for(int j = i + 1; j < N; ++j)
        {
            int distsq = 0;
            for (int k = 0; k < D; ++k) distsq += pow(data[i][k] - data[j][k], 2);
            int dist = sqrt(distsq);
            if (pow(dist, 2) == distsq) ++count;
        }
    }
    cout << count << '\n';
    return 0;
}
