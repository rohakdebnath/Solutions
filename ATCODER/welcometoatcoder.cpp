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
    VI stat (N, 0);
    VI wrongstat (N, 0);
    int totWA = 0;
    int totAC = 0;
    rep(0, M)
    {
        int p; cin >> p;
        string S; cin >> S;
        if (!stat[p - 1])
        {
            stat[p - 1] = S == "AC";
            if (!stat[p - 1]) ++wrongstat[p - 1];
            else ++totAC;
        }
    }
    rep(0, N)
    {
        if (stat[i] == 1) totWA += wrongstat[i];
    }
    cout << totAC << ' ' << totWA << '\n';
    return 0;
}
