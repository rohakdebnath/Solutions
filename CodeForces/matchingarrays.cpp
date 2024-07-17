#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve()
{
    int N, X; cin >> N >> X;
    vector<int> A (N); rep(i, 0, N) cin >> A[i];

    vector<int> id (N); iota(all(id), 0);
    sort(all(id), [&] (int i, int j) {return A[i] < A[j];});
    vector<int> pid (N);
    rep(i, 0, N) pid[id[i]] = i;

    vector<int> B (N); rep(i, 0, N) cin >> B[i];
    sort(all(A)), sort(all(B));
    vector<int> C (N);
    rep(i, 0, X){
        if (A[N - X + i] <= B[i]) {
            cout << "No\n";
            return;
        }
        C[N - X + i] = B[i];
    }
    rep(i, 0, N - X){
        if (A[i] > B[X + i]){
            cout << "No\n";
            return;
        }
        C[i] = B[X + i];
    }
    cout << "Yes\n";
    rep(i, 0, N) cout << C[pid[i]] << " \n"[i == N - 1];
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
