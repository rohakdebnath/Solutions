#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

VI num (5);

i64 divRec(i64 idx, i64 cnt, i64 end, i64 div){
    if (idx == 5){
        return (cnt % 2 ? -end/div : end/div);
    }
    i64 res = divRec(idx + 1, cnt + 1, end, lcm(div, num[idx])) + divRec(idx + 1, cnt, end, div); //here the first expression reprsents what we are adding/subtracting when we are including the next number, the second expression represents when we are not including the next number, in that case notice that cnt is not increased representing no change in sign, but the idx is increasing rperesenting that the recursive call carries the information to change the ith element included when it encounters the first expression in its recursive call, making sure that all possible combinations of a certain number of elements are included with the same sign. 
    return res;
}

void solve()
{
    i64 n, m, a, d; cin >> n >> m >> a >> d;
    rep(i, 0, 5) num[i] = a + i*d;
    i64 ans = divRec(0, 0, m, 1) - divRec(0, 0, n - 1, 1);
    cout << ans << '\n';
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
