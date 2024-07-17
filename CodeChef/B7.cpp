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
template <class T> istream& operator>>(istream& is, vector<T>& v) {
    for (auto& x : v) is >> x;
    return is;
}

void solve()
{
    int N, Q; cin >> N >> Q;
    string s; cin >> s;
    int maxbeaut = 1;
    int beaut = 1;
    char last = s[0];
    rep(i, 1, N){
        if (s[i] == last){
            ++beaut;
        } else beaut = 1;
        maxbeaut = max(maxbeaut, beaut);
        last = s[i];
    }
    cout << maxbeaut << ' ';
    
    int beautlast = 1;
    last = s[N - 1];
    per(i, N - 2, 0){
        if (s[i] == last){
            ++beautlast;
        } else break;
    }   

    while (Q--){
        char c; cin >> c;
        if (c == last) {
            ++beautlast;
            maxbeaut = max(maxbeaut, beautlast);
        } else {
            last = c;
            beautlast = 1;
        }
        cout << maxbeaut << ' ';
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
