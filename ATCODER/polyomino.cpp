#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

vector<vector<string>> p (3, vector<string> (4));

pair<vector<string>, bool> canfit(vector<string>& p, const vector<string>& a, int i, int j) {
    // here i and j are the shift parameters basically overlay p on a, but then shift p by i units horizontall, and j units vertically
    //if there is no conflict on the 1s and no 1s lie outside a (upon shifted p overlay) return the overlay, true, otherwise null, false 
}
// pair<vector<string>, bool> canfit(vector<string>& p, const vector<string>& a, int i, int j) {
//     vector<string> b = a;  // overlay to return on success
//     for (int r = 0; r < 4; ++r) {
//         for (int c = 0; c < 4; ++c) {
//             if (p[r][c] != '#') continue;      // only place '#' cells
//             int nr = r + j;                    // j = vertical shift (rows)
//             int nc = c + i;                    // i = horizontal shift (cols)
//             if (nr < 0 or nr >= 4 or nc < 0 or nc >= 4) return {{}, false}; // outside region
//             if (b[nr][nc] == '1') return {{}, false};                       // overlap forbidden
//             b[nr][nc] = '1';
//         }
//     }
//     return {b, true};
// }

void rotate (vector<string>& p, int i) {
    //rotate p CW i times.
}
void rotate(vector<string>& p, int k) {
    // rotate p CW k times in-place
    k = ((k % 4) + 4) % 4;
    while (k--) {
        vector<string> t(4, string(4, '.'));
        for (int r = 0; r < 4; ++r)
            for (int c = 0; c < 4; ++c)
                t[c][3 - r] = p[r][c];
        p.swap(t);
    }
}

bool rec(int t, vector<string> a) { // a is a 4 by 4 boolean like matrix, 4 strings of length 4 each character = 0 or 1 
    if (t == 3) {
        // if a is completely filled with 1s, return true otherwise false
    }
    // if (t == 3) {
    //     // board must be fully filled with '1'
    //     for (int r = 0; r < 4; ++r)
    //         for (int c = 0; c < 4; ++c)
    //             if (a[r][c] != '1') return false;
    //     return true;
    // }
    for (int i = -3; i <= 3; ++i) {
        for (int j = -3; j <= 3; ++j) {
            for (int k = 0; k < 4; ++k) {
                rotate(p[t], k);
                auto [overlay, ok] = canfit(p[t], a, i, j);
                rotate(p[t], 4 - k); //undo rotations
                if (ok and rec(t + 1, overlay)) return true;
            }
        }
    }
    return false;
}
void solve() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> p[i][j];
        }
    }
    vector<string> a(4, string(4, '0'));
    cout << (rec(0, a) ? "Yes\n" : "No\n");
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}




#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k; 
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    vector<pair<long long,int>> fact;
    for(int i = 2; i*i <= k; i++){
        int cr = 0;
        while(k % i == 0){
            cr++; 
            k/=i;
        }
        if(cr) fact.push_back({i, cr});
    }
    if(k > 1) fact.push_back({k, 1});
    int ans = 1e9;
    for(auto [fc, no] : fact){
        int cr = 0;
        for(auto it : v){
            while(it % fc == 0){
                cr++; it /= fc;
            }
        }
        ans = min(ans, cr/no);
    }
    cout << ans << '\n';
}


modulat
