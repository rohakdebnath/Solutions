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
    int a, b, c; cin >> a >> b >> c;
    int N; cin >> N;
    VI usb, ps2;
    rep(i, 0, N){
        int x; cin >> x;
        string s; cin >> s;
        s == "USB" ? usb.push_back(x) : ps2.push_back(x);
    }
    sort(all(usb));
    sort(all(ps2));

    i64 cost = 0;
    int i = min(sci(usb.size()), a);
    int j = min(sci(ps2.size()), b);
    cost += accumulate(usb.begin(), usb.begin() + i, 0LL);
    cost += accumulate(ps2.begin(), ps2.begin() + j, 0LL);

    while ((i < usb.size() or j < ps2.size()) and c > 0){
        if (i == usb.size() or (j < ps2.size() and ps2[j] < usb[i])){
            cost += ps2[j++];
        } else {
            cost += usb[i++];
        }
        --c;
    }

    cout << i + j << ' ' << cost << '\n';
    return 0;
}
