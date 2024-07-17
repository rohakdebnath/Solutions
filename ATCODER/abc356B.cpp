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
    int N, M; cin >> N >> M;
    vector<int> A (M); rep(i, 0, M) cin >> A[i];
    vector<int> B (M);
    rep(i, 0, N){
        rep(j, 0, M){
            int x; cin >> x;
            B[j] += x;
        }
    }
    rep(i, 0, M){
        if (A[i] > B[i]){
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}
