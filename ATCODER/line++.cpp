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
    int N, X, Y; cin >> N >> X >> Y;
    vector<int> freq (N);
    rep(i, 1, N + 1){
        rep(j, i + 1, N + 1){
            ++freq[min({abs(i - j), abs(X - i) + abs(Y - j) + 1, abs(Y - i) + abs(X - j) + 1})];
        }
    }
    rep(i, 1, N){;
        cout << freq[i] << '\n';
    }
    return 0;
}
