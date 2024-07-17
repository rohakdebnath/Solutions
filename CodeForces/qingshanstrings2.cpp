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
    bitset<100> inbi (s);
    int popc = inbi.count();
    if (popc != N - popc){
        cout << "-1\n";
        return;
    }
    VI ans;
    int id = 0;
    int sz = s.size();
    while (true){
        while(s[id] != s[sz - id - 1] and id < sz/2) ++id;
        if (id == sz/2){
            break;
        }
        if (s[id] == '0') {
            ans.push_back(sz - id);
            s.insert(sz - id, "01");
            ++id;
        } else {
            ans.push_back(id);
            s.insert(id, "01");
            ++id;
        }
        sz += 2;
    }
    cout << ans.size() << '\n';
    for(int i: ans) cout << i << ' ';
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
