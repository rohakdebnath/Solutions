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
    sort(all(A));
    A.erase(unique(all(A)), A.end());
    if (A.size() == 1){
        cout << "YES\n";
        return;
    }
    int m1 = A[0], m2 = -1;
    rep(i, 0, A.size()){
        if (A[i] % m1 == 0) continue;
        else {
            m2 = A[i];
            break;
        }
    }
    rep(i, 0, int(A.size())){
        if (A[i] % m1 and A[i] % m2){
            cout << "NO\n";
            return;
        }
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
