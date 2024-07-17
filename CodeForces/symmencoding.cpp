#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve()
{
    int N; cin >> N;
    string s; cin >> s;
    string r = s;
    sort(all(r)); r.erase(unique(all(r)), r.end()); reverse(all(r));
    map<char, char> mp;
    rep(i, 0, int(r.size())){
        mp[r[i]] = r[r.size() - 1 - i];
    }
    rep(i, 0, N){
        s[i] = mp[s[i]];
    }
    cout << s << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
