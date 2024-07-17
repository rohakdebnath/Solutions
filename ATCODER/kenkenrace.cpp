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
    int N, A, B, C, D; cin >> N >> A >> B >> C >> D;
    string S; cin >> S;
    S += '#';
    rep(A, C)
    {
        if (S[i] == '#' and S[i - 1] == '#')
        {
            cout << "No\n";
            return 0;
        }
    }
    rep(B, D)
    {
        if (S[i] == '#' and S[i - 1] == '#')
        {
            cout << "No\n";
            return 0;
        }
    }
    int free = 0;
    int t = 0;
    rep(B - 1, D)
    {
        if (S[i] == '.')
        {
            ++t;
            free = max(free, t);
        }
        else t = 0;
    }
    if (D > C)
    {
        cout << "Yes\n";
        return 0;
    }
    else
    {
        if ((S[B - 2] == '.' and S[B] == '.') or free >= 3) cout << "Yes\n";
        else
        {
            if (S[D] == '#' or S[D - 2] == '#') cout << "No\n";
            else cout << "Yes\n";
        }
    }

    return 0;
}
