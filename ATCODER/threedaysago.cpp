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
    string S; cin >> S;
    vector<int> num (S.size());
    int N = 0;
    rep(i, 0, S.size()){
        int x = S[i] - '0';
        int b = (N >> x) & 1;
        if (b == 1) N -= (1 << x);
        else N += (1 << x);
        num[i] = N;
    }

    vector<int> runfreq (1 << 10);
    runfreq[0] = 1;
    i64 combo = 0;
    rep(i, 0, S.size()){
        combo += runfreq[num[i]];
        ++runfreq[num[i]];
    }
    cout << combo << '\n';
    return 0;
}
