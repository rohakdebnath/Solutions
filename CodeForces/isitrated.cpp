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
    int N; cin >> N;
    VI rateB (N), rateA (N); rep(i, 0, N) cin >> rateA[i] >> rateB[i];
    if (rateA != rateB){
        cout << "rated\n";
    } else{
        auto sor = rateA;
        sort(all(sor), greater<int> ());
        if (sor == rateA){
            cout << "maybe\n";
        } else {
            cout << "unrated\n";
        }
    }

    return 0;
}
