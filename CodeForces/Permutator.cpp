#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define rep1(x) for (int i {0}; i < x; ++i)
#define rep2(x) for (int i {0}; i <= x; ++i)

int main()
{
    UNSYNC
    int n;
    cin >> n;

    vector<i64> a (n);
    vector<i64> b (n);

    rep1(n) {cin >> a[i];}
    rep1(n) {cin >> b[i];}

    for (i64 i {0}; i < n; ++i)
    {
        a[i] = a[i]*(i + 1)*(n - i);
    }

    sort(all(a));
    sort(rall(b));

    i64 sum {0};
    for (i64 i {0}; i < n; ++i)
    {
        sum += a[i]*b[i];
    }

    cout << sum << '\n';
    

    return 0;
}
