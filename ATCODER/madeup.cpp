#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep1(x) for (int i {0}; i < x; ++i)
#define rep2(x) for (int i {0}; i <= x; ++i)

int main()
{
    int n; cin >> n;

    vector<i64> A (n);
    vector<i64> B (n);
    vector<i64> C (n);
    vector<i64> BC (n);

    rep1(n) {cin >> A[i];}
    rep1(n) {cin >> B[i];}
    rep1(n) {cin >> C[i];}

    map<i64, i64> Aoccs;

    for (i64 i {0}; i < n; ++i)
    {
        ++Aoccs[A[i]];
    }
    i64 pairs {0};

    for (i64 i {0}; i < n ; ++i)
    {
        pairs += Aoccs[B[C[i] - 1]];
    }

    cout << pairs << '\n';
    return 0;
}
