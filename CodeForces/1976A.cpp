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
    string let, cha;

    bool le = 0;
    rep(i, 0, N){
        if (s[i] - '0' <= 57){
            let.push_back(s[i]);
            if (le) {
                cout << "NO\n";
                return;
            }
            le = false;
        }
        else{
            cha.push_back(s[i]);
            le = true;
        }
    }
    if (is_sorted(all(let)) and is_sorted(all(cha))) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
