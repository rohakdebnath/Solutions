#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    int A, B; cin >> A >> B;
    int btA, btB;
    btA = (((A*50)/4 * 8)/100 == A ? (A*50)/4 : (A*50)/4 + 1);
    btB = B*10;
    int lA = btA;
    int rA = btA;
    while (((rA + 1)*4)/50 == A) ++rA;
    int lB = btB;
    int rB = btB;
    while ((rB + 1)/10 == B) ++rB;
    int lI = max(lA, lB);
    int rI = min(rA, rB);
    if (lI > rI)
    {
        cout << "-1\n";
    }
    else cout << lI << '\n';
    return 0;
}
