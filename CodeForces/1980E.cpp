#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> A (n, vector<int> (m));
    vector<vector<int>> B (n, vector<int> (m));

    rep(i, 0, n){
        rep(j, 0, m) cin >> A[i][j];
    }
    rep(i, 0, n){
        rep(j, 0, m) cin >> B[i][j];
    }
    vector<int> T = A[0]; int fnd = 0; sort(all(T));
    rep(i, 0, n){
        vector<int> S = B[i];
        sort(all(S));
        if (T == S){    
            fnd = 1;
            vector<int> SS = B[0];
            B[0] = B[i];
            B[i] = SS;
            break;
        }
    }
    if (!fnd){
        cout << "NO\n";
        return;
    }
    vector<int> M (n * m + 1);
    rep(i, 0, m) M[B[0][i]] = i;
    vector<int> I (m);
    rep(i, 0, m) I[i] = M[A[0][i]];

    rep(i, 0, n){
        vector<int> S = B[i];
        rep(j, 0, m) B[i][j] = S[I[j]];
    }
    map<vector<int>, int> mp; 
    rep(i, 0, n) mp[A[i]] = 1;
    int c = 0;
    rep(i, 0, n) if (mp[B[i]]) ++c;
    

    cout << (c == n ? "YES\n" : "NO\n");

}
int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
