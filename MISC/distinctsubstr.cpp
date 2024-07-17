#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

vector<int> zfunc(string s){
    int N = s.size();
    reverse(all(s));
    vector<int> z (N);
    int l = 0, r = 0;
    rep(i, 1, N){
        if (i < r){
            z[i] = min<int>(r - i, z[i - l]);
        }
        while(z[i] + i < N and s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] > r){
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main()
{
    UNSYNC
    string s; cin >> s;
    int N = s.size();

    string t = "";
    int ans = 0;

    rep(i, 0, N){
        t += s[i]; 
        ans += t.size() - *max_element(all(zfunc(t)));
    }
    cout << ans << '\n';
    return 0;
}
