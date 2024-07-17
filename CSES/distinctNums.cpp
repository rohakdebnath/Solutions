#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)

int main()
{
    UNSYNC
    int n;
    cin >> n;
    vector<int> num (n);
    rep(0, n) {cin >> num[i];}

    sort(all(num));
    int distinctNums {1};

    for (int i {1}; i < n; ++i)
    {
        if (num[i-1] != num[i]) distinctNums++;
    }

    cout << distinctNums << '\n';
    return 0;
}
