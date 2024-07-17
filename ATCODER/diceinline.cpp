#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<double>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<double>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    double N, K; cin >> N >> K;
    VI chance (N);
    rep(0, N)
    {
        double n; cin >> n;
        chance[i] = (n + 1)/2;
    }
    vector<double> sumvec (N);
    sumvec[0] = chance[0];
    rep(1, N) sumvec[i] = sumvec[i - 1] + chance[i];
    double sum = sumvec[K - 1];
    for(int i = 0; i < N - K; ++i) sum = max(sum, sumvec[i + K] - sumvec[i]);

    
    cout << setprecision (10) << sum << '\n';
    return 0;
}
