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
    string s, t; cin >> s >> t;
    int j = 0;
    for(int i = 1; i <= N; ++i)
    {
        if (t.substr(0, i) == s.substr(N - i, i)) j = i;
    }
    cout << 2*N - j << '\n';
    return 0;
}
