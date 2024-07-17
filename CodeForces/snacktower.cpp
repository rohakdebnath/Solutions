#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    int n; cin >> n;
    VI has (n);
    int req = n;
    rep(i, 0, n){
        int A; cin >> A;
        has[A - 1] = 1;
        if (A == req){
            per(j, A - 1, 0){
                if (has[j]){
                    --req;
                    cout << j + 1 << ' ';
                }
                else break;
            }
            cout << '\n';
        }
        else cout << '\n';
    }
    return 0;
}
