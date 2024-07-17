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
    vector<int> A (N); rep(i, 0, N) cin >> A[i];
    vector<int> B (N); rep(i, 0, N) cin >> B[i];
    int M; cin >> M;
    vector<int> D (M); rep(i, 0, M) cin >> D[i];

    map<int, int> MP; //needed for B
    rep(i, 0, N){
        if (A[i] != B[i]){
            ++MP[B[i]];
        }
    }
    rep(i, 0, M){
        if (MP[D[i]]) --MP[D[i]];
    }
    for (auto [u, v]: MP){
        if (v){
            cout << "NO\n";
            return;
        }
    }
    if (find(all(B), D[M - 1]) == B.end()){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
