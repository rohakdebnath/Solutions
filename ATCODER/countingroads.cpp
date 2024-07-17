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
    VVI adjList (N, VI (N));
    while(M--)
    {
        int a, b; cin >> a >> b;
        ++adjList[a - 1][b - 1];
        ++adjList[b - 1][a - 1];
    }
    for (auto i: adjList)
    {
        cout << accumulate(all(i), 0) << '\n';
    }
    return 0;
}
