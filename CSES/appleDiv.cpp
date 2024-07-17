#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep1(x) for (int i {0}; i < x; ++i)
#define rep2(x) for (int i {0}; i <= x; ++i)

int n;
vector<int> appleWeights;

i64 appleRec(int i, i64 sum1, i64 sum2)
{
    if (i == n) return abs(sum1 - sum2);

    return min(appleRec(i + 1, sum1 + appleWeights[i], sum2), appleRec(i + 1, sum1, sum2 + appleWeights[i]));
}

int main()
{
    cin >> n;
    appleWeights.resize(n);
    rep1(n) {cin >> appleWeights[i];}
    sort(all(appleWeights));

    cout << appleRec(0, 0, 0) << '\n';

    return 0;
}
