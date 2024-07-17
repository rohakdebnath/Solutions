#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

i64 N; 
vector<i64> A; 

void addtoarrf(vector<i64>& bits, i64 x){
    rep(i, 0, 21){
        if ((x >> i) & 1){
            ++bits[i];
        }
    }
}

void subfromarrf(vector<i64>& bits, i64 x){
    rep(i, 0, 21){
        if ((x >> i) & 1){
            --bits[i];
        }
    }
}

i64 bitftonum(vector<i64>& bits){
    i64 ans = 0;
    rep(i, 0, 21){
        if (bits[i]){
            ans += (1 << i);
        }
    }
    return ans;
}

bool check(i64 k){
    vector<i64> bits (21);
    rep(i, 0, k){
        addtoarrf(bits, A[i]);
    }
    bool srv = 1;
    i64 OR = bitftonum(bits);
    rep(i, k, N){
        addtoarrf(bits, A[i]);
        subfromarrf(bits, A[i - k]);
        if (OR != bitftonum(bits)){
            srv = 0;
            break;
        }
    }
    return srv;
}

void solve()
{
    cin >> N; 
    A.clear(); A.resize(N);
    rep(i, 0, N) cin >> A[i];

    i64 l = 0, r = N + 1;
    while (r - l > 1){
        i64 m = l + (r - l) / 2;
        if (check(m)){
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << '\n';
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
