#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

int main()
{
    UNSYNC
    int N; cin >> N;
    VI A (N); rep(i, 0, N) cin >> A[i];
    map<int, int> uniqend;
    int ans = 0;
    int iso = 0;
    rep(i, 0, N){
        if (i + 1 == A[i]){
            ++iso;
            continue;
        }
        if (!uniqend[A[i]]){
            uniqend[A[i]] = 1;
            ++ans;
        }
    }
    cout << iso + ans/2 << '\n';
    return 0;
}
