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
    int N, T; cin >> N >> T;
    vector<int> E (N); rep(i, 0, N) cin >> E[i];
    vector<int> M (N); rep(i, 0, N) cin >> M[i];

    rep(i, 0, N){
        rep(j, i + 1, N){
            int sum = M[i] + M[j];
            if (binary_search(all(E), T - sum)){
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}
