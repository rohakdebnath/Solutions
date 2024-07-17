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
#define MAX 100000
#define bitscount 20

VVI prefix_count (MAX, VI (bitscount));
void findPrefixCount(VI& A, int N)
{
    rep(i, 1, N + 1){
        rep(j, 0, bitscount){
            if ((A[i - 1] >> j) & 1) prefix_count[i][j] = 1;
            prefix_count[i][j] += prefix_count[i - 1][j];
        }
    }
}

int rangeOr(int l, int r)
{
    int ans = 0;
    // VI cur (20);
    for (int i = 0; i < bitscount; i++) {
        if (prefix_count[r][i] - prefix_count[l][i]){
            ans += (1 << i);
        }
    }
    return ans;
}

int main()
{
    UNSYNC
    int N; cin >> N;
    VI A (N); rep(i, 0, N) cin >> A[i];
    findPrefixCount(A, N);
    int Q; cin >> Q;
    while (Q--){
        int s, x; cin >> s >> x;
        --s;
        int l = s - 1, r = N + 1;
        while (r - l > 1){
            int m = l + (r - l)/2;
            int ans = rangeOr(s, m);
            if (ans >= x){
                r = m;
            } else {
                l = m;
            }
        }
        cout << (r == N + 1 ? -1 : r) << '\n';
    }

    return 0;
}
    
