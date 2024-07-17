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
    int N, K; cin >> N >> K;
    string s; cin >> s;
    int hap = 0, X = 0, Y = 0;
    rep(i, 0, N){
        if ((i == 0 and s[i] == 'L') or (i == N - 1 and s[i] == 'R')) ++Y;
        else if (i < N - 1 and s[i] == 'R' and s[i + 1] == 'L') ++X;

        if (s[i] == 'R'){
            if (i != N - 1 and s[i + 1] == 'R') ++hap;
        } else {
            if (i != 0 and s[i - 1] == 'L') ++hap;
        }
    }

    hap += min(X, K) * 2 + min(max(0, K - X), Y);
    hap = min(hap, N - 1);
    cout << hap << '\n';
    return 0;
}
