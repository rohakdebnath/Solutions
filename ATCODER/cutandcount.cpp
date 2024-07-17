#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

int main()
{
    UNSYNC
    int N; cin >> N;
    string S; cin >> S;
    int maxcom = 0;
    rep(0, N)
    {
        VI freqAlf (26);
        int com = 0;
        for (int j = 0; j <= i; ++j)
        {
            ++freqAlf[S[j] - 'a'];
        }
        for (int j = i + 1; j < N; ++j)
        {
            if (freqAlf[S[j] - 'a'])
            {
                freqAlf[S[j] - 'a'] = 0;
                ++com;
            }
        }
        maxcom = max(maxcom, com);
    }
    cout << maxcom << '\n';
    return 0;
}
