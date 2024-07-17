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
    int n, k; cin >> n >> k;
    vector<int> circ (n);
    rep(i, 0, 3){
        cout << "or " << i + 1 << ' ' << (i + 1) % 3 + 1 << endl;
        int aorb; cin >> aorb;
        cout << "and " << i + 1 << ' ' << (i + 1) % 3 + 1 << endl;
        int aandb; cin >> aandb;
        circ[i] = aandb + aorb;
    }
    vector<int> ans (n);
    ans[0] = (circ[0] - circ[1] + circ[2]) / 2;
    rep(i, 3, n){
        cout << "or " << i << ' ' << i + 1 << endl;
        int aorb; cin >> aorb;
        cout << "and " << i << ' ' << i + 1 << endl;
        int aandb; cin >> aandb;
        circ[i] = aandb + aorb;
    }
    rep(i, 1, 3) ans[i] = circ[i - 1] - ans[i - 1];
    rep(i, 3, n) ans[i] = circ[i] - ans[i - 1];
    sort(all(ans));
    cout << "finish " << ans[k - 1] << '\n';
    return 0;
}
