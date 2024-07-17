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
    string S; cin >> S;
    int tot = count(all(S), '1');
    if (tot <= K){
        rep(i, 0, N - K) cout << '0';
    } else {
        rep(i, 0, N){
            if (S[i] == '1' and K){
                S[i] = '0';
                --K;
            }
        }
        cout << S;
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
