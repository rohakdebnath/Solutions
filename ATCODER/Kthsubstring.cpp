#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

int main()
{
    UNSYNC
    string s; cin >> s;
    int K;  cin >> K;
    int N = s.size();
    set<string> v;

    rep(i, 0, N){
        rep(j, 1, min(K, N - i) + 1){
            v.insert(s.substr(i, j));
        }
    }
    auto it = v.begin(); advance(it, K - 1);
    cout << *it << '\n';
    return 0;
}
