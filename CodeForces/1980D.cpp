#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

i64 N; 
bool check(vector<i64>&A, i64 i){
    vector<i64> T = A;
    T.erase(T.begin() + i);
    vector<i64> B (N - 2);
    rep(j, 1, N - 1){
        B[j - 1] = gcd(T[j], T[j - 1]);
    }
    return (is_sorted(all(B)));
}
void solve()
{
    cin >> N;
    vector<i64> A (N); rep(i, 0, N) cin >> A[i];
    vector<i64> B (N - 1);
    rep(i, 1, N){
        B[i - 1] = gcd(A[i], A[i - 1]);
    }
    if (is_sorted(1 + all(B)) or is_sorted(all(B) - 1)){
        cout << "YES\n";
        return;
    }
    rep(i, 1, N - 1){
        if (B[i] >= B[i - 1]) continue;
        else {
            if (check(A, i) or check(A, i - 1) or check(A, i + 1)){
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
            return;
        }
    }
    cout << "YES\n";
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
