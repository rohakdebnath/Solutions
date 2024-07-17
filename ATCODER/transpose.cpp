#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void solve(){
    string s; cin >> s;
    int n = s.size();
    vector<int> match(n);
    stack<int> stk;
    rep(i, 0, n){
        if(s[i]=='(') stk.push(i);
        else if(s[i]==')') match[i] = stk.top(), match[stk.top()] = i, stk.pop();
    }
    string res = "";

    int dir = 1, pos = 0;
    while(pos < n){
        if(s[pos] == '(' or s[pos] == ')'){
            pos = match[pos];
            dir = -dir;
        }
        else{
            char c = s[pos];
            if(dir == -1){
                if(c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
                else c = c - 'a' + 'A';
            }
            res += c;
        }
        pos += dir;
    }
    cout << res << '\n';
}

int main()
{
    UNSYNC
    int T = 1;
    while(T--) solve();
    return 0;
}
