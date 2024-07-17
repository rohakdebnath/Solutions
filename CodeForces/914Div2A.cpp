#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

void solve()
{
    int a, b; cin >> a >> b;
    int xk, yk, xq, yq;
    cin >> xk >> yk >> xq >> yq;
    vector<pair<int, int>> Kattacks (8);
    Kattacks[0] = make_pair(xk + a, yk + b);
    Kattacks[1] = make_pair(xk + a, yk - b);
    Kattacks[2] = make_pair(xk - a, yk + b);
    Kattacks[3] = make_pair(xk - a, yk - b);
    Kattacks[4] = make_pair(xk + b, yk + a);
    Kattacks[5] = make_pair(xk + b, yk - a);
    Kattacks[6] = make_pair(xk - b, yk + a);
    Kattacks[7] = make_pair(xk - b, yk - a);
    vector<pair<int, int>> Qattacks (8);
    Qattacks[0] = make_pair(xq + a, yq + b);
    Qattacks[1] = make_pair(xq + a, yq - b);
    Qattacks[2] = make_pair(xq - a, yq + b);
    Qattacks[3] = make_pair(xq - a, yq - b);
    Qattacks[4] = make_pair(xq + b, yq + a);
    Qattacks[5] = make_pair(xq + b, yq - a);
    Qattacks[6] = make_pair(xq - b, yq + a);
    Qattacks[7] = make_pair(xq - b, yq - a);

    set<pair<int, int>> ss;
    rep(0, 8)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (Kattacks[i].first == Qattacks[j].first and Kattacks[i].second == Qattacks[j].second)
            {
                ss.insert(make_pair(Kattacks[i].first, Kattacks[i].second));
            }
        }
    }
    cout << ss.size() << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
