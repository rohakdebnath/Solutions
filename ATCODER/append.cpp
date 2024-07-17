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
    int Q; cin >> Q;
    vector<int> v;
    while(Q--){
        int t, N; cin >> t >> N;
        if (t == 1){
            v.push_back(N);
        } else {
            cout << *(v.rbegin() + N - 1) << '\n'; 
        }
    }
    return 0;
}
