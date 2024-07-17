#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

void solve()
{
    i64 N; cin >> N;
    vector<i64> A (N); rep(i, 0, N) cin >> A[i];
    vector<i64> B (N); rep(i, 0, N) cin >> B[i];
    vector<i64> pfA (N); partial_sum(all(A), pfA.begin());
    vector<i64> pfB (N); partial_sum(all(B), pfB.begin());

    if (pfA[N - 1] != pfB[N - 1]){
        cout << "NO\n";
        return;
    }

    vector<i64> evB; for(i64 i = 0; i < N - 1; i += 2) evB.push_back(pfB[i]); sort(all(evB));
    vector<i64> odB; for(i64 i = 1; i < N - 1; i += 2) odB.push_back(pfB[i]); sort(all(odB));
    vector<i64> evA; for(i64 i = 0; i < N - 1; i += 2) evA.push_back(pfA[i]); sort(all(evA));
    vector<i64> odA; for(i64 i = 1; i < N - 1; i += 2) odA.push_back(pfA[i]); sort(all(odA));

    if (evB == evA and odA == odB) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
