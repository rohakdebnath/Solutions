#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve()
{
    int N, K; cin >> N >> K;
    string s; cin >> s;
    vector<int> p (N + 1);
    rep(i, 0, N) p[i + 1] = p[i] + s[i] - '0';

    vector<int> f (N + 1); f[N] = 1; //f[i] checks if suffix string ending at position can be valid or not.
    per(i, N - 1, 0){
        int j = min(i + K, N);
        f[i] = f[j] and (j == N or s[i] != s[j]) and (p[j] - p[i] == 0 or p[j] - p[i] == j - i);
    }
    rep(i, 1, N + 1){
        if ((s[i - 1] ^ s[0]) != (i - 1) / K % 2) break;
        if (f[i] and (i == N or (s[0] ^ s[i]) == (N - 1) / K % 2)){
            cout << i << '\n';
            return;
        }
    }
    cout << "-1\n";
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
