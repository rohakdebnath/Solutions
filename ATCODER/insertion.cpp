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
    int N; cin >> N;
    string S; cin >> S;
    string ans = "";
    int rightabun = 0;
    rep(i, 0, N){
        if (S[i] == '(') --rightabun;
        else ++rightabun;
        if (rightabun == 1){
            ans = '(' + ans;
            --rightabun;
        }
        ans += S[i];
    }
    ans += string(-rightabun, ')');
    cout << ans << '\n';
    return 0;
}
