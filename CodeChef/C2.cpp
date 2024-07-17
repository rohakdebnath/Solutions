#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<int>
#define VVI vector<vector<int>>

int N; 

bool alleq(VI& v)
{
    bool survive = true;
    rep(i, 0, N - 1) if (v[i] != v[i + 1])
    {
        survive = false;
        break;
    }
    return survive;
}

void solve()
{
    cin >> N;
    VI A(N); rep(i, 0, N) cin >> A[i];
    if (N == 4 and A[0] + A[1] == A[2] + A[3]) 
    {
        cout << "NO\n";
        return;
    }
    else if (alleq(A)) cout << "NO\n";
    else cout << "YES\n";
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
