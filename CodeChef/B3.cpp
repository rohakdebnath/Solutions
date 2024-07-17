#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<int>
#define VVI vector<vector<int>>

void solve()
{
    int N; cin >> N;
    string s; cin >> s;
    int strikes = (N - 1)/2;
    string ans = "";
    for(char c: s){
        if (c == 'R') ans += 'P';
        else if (strikes){
            ans += 'P';
            --strikes;
        }
        else if (c == 'P') ans += 'S';
        else if (c == 'S') ans += 'R';
    }
    cout << ans << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
