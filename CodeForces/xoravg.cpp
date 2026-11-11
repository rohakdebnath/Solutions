#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    if(n%2){
        for(int i = 0; i < n; i++){
            cout << 1 << ' ';
        }
    }
    else{
        for(int i = 0; i < n-2; i++){
            cout << 2 << ' ';
        }
        cout << 1 << ' ';
        cout << 3 << ' ';
    }
    cout << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}

int bitwiseand(int a, int b){
    if (a == b) return a;
    int final = 0;
    while (a != b) {
        ++final;
        a >>= 1;
        b >>= 1;
    }
    return (a * (1 << final));
}
