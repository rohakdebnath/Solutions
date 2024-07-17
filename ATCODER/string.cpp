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
    string s; cin >> s;
    stack<char> str;
    for (char c: s){
        if (str.empty()){
            str.push(c);
            continue;
        }
        char top = str.top();
        if (top == 'S' and c == 'T'){
            str.pop();
        } else {
            str.push(c);
        }
    }
    cout << str.size() << '\n';
    return 0;
}
