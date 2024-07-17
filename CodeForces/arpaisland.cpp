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
    int n; cin >> n;
    if (n == 0){
        cout << "1\n";
        return 0;
    }
    if (n % 4 == 1){
        cout << "8\n";
    } else if (n % 4 == 2){
        cout << "4\n";
    } else if (n % 4 == 3){
        cout << "2\n";
    } else {
        cout << "6\n";
    }

    return 0;
}
