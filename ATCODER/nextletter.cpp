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
    int K; cin >> K;

    rep(i, 0, s.size()){
        if ((i == s.size() - 1) and K){
            s[s.size() - 1] = (s[s.size() - 1] - 'a' + K) % 26 + 'a';
            continue;
        }
        if (s[i] == 'a') continue;
        int nex = 26 - (s[i] - 'a');
        if (nex <= K){
            s[i] = 'a';
            K -= nex;
        }
    }
    cout << s << '\n';
    return 0;
}
