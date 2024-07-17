#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

void solve()
{
    int N; cin >> N;
    string s; cin >> s;
    reverse(all(s));
    i64 cur = 0;
    int j = 0;
    rep(i, 0, N){
        j = max(j, i);
        while (s[j] == '1' and j < N) ++j;
        if (j == N){
                cout << "-1 ";
                continue;
            }
        if (s[i] == '1') {
            cur += j - i;
            s[j] = '1';
            ++j;
            cout << cur << ' ';
        }
        else {
            cout << cur << ' ';
        }
    }
    cout << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
