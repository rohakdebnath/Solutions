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
    VI row;
    rep(i, 0, 3){
        string s; cin >> s;
        int sum = 0;
        for(char c: s){
            if (c != '?') sum += c - 'A';
        }
        row.push_back(sum);
    }
    sort(all(row));
    cout << static_cast<char>('A' + row[1] - row[0]) << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
