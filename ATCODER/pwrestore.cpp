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
    string O, E; cin >> O >> E;
    for(int i = 0; i < E.size(); ++i)
    {
        cout << O[i] << E[i];
    }
    if (O.size() > E.size()) cout << O.back();
    cout << '\n';
    return 0;
}
