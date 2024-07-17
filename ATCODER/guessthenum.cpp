#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    int N, M; cin >> N >> M;
    VI num (N, -1);
    rep(0, M)
    {
        int s, c; cin >> s >> c;
        if (N > 1 and s == 1 and c == 0)
        {
            cout << "-1\n";
            return 0;
        }
        if (num[s - 1] == -1) num[s - 1] = c;
        else if (num[s - 1] != c)
        {
            cout << "-1\n";
            return 0;
        }
    }
    if (N == 1 and M == 0) num[0] = 0;
    if (num[0] == -1) num[0] = 1;
    rep(0, N) if (num[i] == -1) num[i] = 0;
    vector<char> tochars;
    transform(all(num), back_inserter(tochars), [&] (int i) {return i + '0';});
    string s (all(tochars));
    cout << s << '\n';
    return 0;
}
