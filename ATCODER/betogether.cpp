#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i {ini}; i < x; ++i)
#define per(i, fin, x) for (int i {fin}; i >= x; --i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    int N; cin >> N;
    int sum = 0;
    VI A (N); rep(i, 0, N) cin >> A[i], sum += A[i];
    int mean1 = ceil(1.0*sum/N);
    int mean2 = sum/N;
    int diffs1 = accumulate(all(A), 0, [&] (int curr, int k) 
    {
        return curr + (mean1 - k)*(mean1 - k);
    });
    int diffs2 = accumulate(all(A), 0, [&] (int curr, int k) 
    {
        return curr + (mean2 - k)*(mean2 - k);
    });
    cout << min(diffs1, diffs2) << '\n';
    return 0;
}
