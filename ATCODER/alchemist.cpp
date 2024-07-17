#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<double>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    double N; cin >> N;
    VI I (N); rep(0, N) cin >> I[i];
    sort(all(I));
    double maxsum = I[0];
    for (double i = 1; i < N; ++i) maxsum = (maxsum + I[i])/2;

    cout << maxsum << '\n';
    return 0;
}
