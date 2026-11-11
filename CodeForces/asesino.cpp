#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

bool ask(int i, int j) {
    cout << "? " << i + 1 << ' ' << j + 1 << endl;
    bool b; cin >> b;
    return b;
}
void solve() {
    int n; cin >> n;
    auto run = [&] (int t) -> void {
        if (t == 5) {
            int x = ask(0, 1), y = ask(1, 2), z = ask(2, 0);
            if (x ^ y ^ z == 0) {
                int l = ask(1, 0), m = ask(2, 1);
                if (l == x) cout << "! 3" << endl;
                else if (m == y) cout << "! 1" << endl;
                else cout << "! 2" << endl;
            } else {
                x = ask(0, 3), y = ask(3, 0);
                cout << "! " << (x ^ y ? 4 : 5) << endl;
            }
        } else if (t == 4) {
            int x = ask(0, 1), y = ask(1, 0);
            if (x ^ y) {
                x = ask(0, 2), y = ask(2, 0);
                cout << "! " << (x ^ y ? 1 : 2) << endl;
            } else {
                x = ask(0, 2), y = ask(2, 0);
                cout << "! " << (x ^ y ? 3 : 4) << endl;
            }
        } else {
            int x = ask(0, 1), y = ask(1, 0);
            if (x ^ y) {
                x = ask(0, 2), y = ask(2, 0);
                cout << "! " << (x ^ y ? 1 : 2) << endl;
            } else {
                cout << "! 3" << endl;
            }
        }
    };

    while (true) {
        if (n <= 5) {
            run(n);
            break;
        }
        int x = ask(n - 1, n - 2), y = ask(n - 2, n - 1);
        if (x == y) {
            n -= 2;
        } else {
            int l = ask(n - 1, n - 3), m = ask(n - 3, n - 1);
            cout << "! " << (l ^ m ? n : n - 1) << endl;
            break;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
//tttin
