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
    string S, T; cin >> S >> T;
    vector<int> charmap (26, -1);
    vector<int> charmaprev (26, -1);
    rep(i, 0, T.size()){
        if (charmap[T[i] - 'a'] == -1){
            charmap[T[i] - 'a'] = S[i] - 'a';
        } else {
            if (charmap[T[i] - 'a'] != S[i] - 'a'){
                cout << "No\n";
                return 0;
            }
        }
        if (charmaprev[S[i] - 'a'] == -1){
            charmaprev[S[i] - 'a'] = T[i] - 'a';
        } else {
            if (charmaprev[S[i] - 'a'] != T[i] - 'a'){
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
    return 0;
}
