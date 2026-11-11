#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void flip(vector<int> &a, int k) {
    reverse(a.begin(), a.begin() + k);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;

    vector<int> b = a;
    sort(b.begin(), b.end());

    vector<int> flips; 

    for(int current_size = n; current_size >= 1; --current_size){
        int current = b[current_size - 1];
        int idx = find(a.begin(), a.end(), current) - a.begin();

        if(idx == current_size - 1){
            continue;
        }

        if(idx != 0){
            flip(a, idx + 1);
            flips.push_back(idx + 1);
        }

        flip(a, current_size);
        flips.push_back(current_size);
    }

    for(int i = 0; i < flips.size(); ++i){
        cout << flips[i] << " \n"[i == flips.size() - 1];
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
