#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    if (s[0] == '-') s = '0' + s;
    int n = s.size();
    if (n % 2 == 0) {
         cout << "-1\n";
         return 0;
    }
    for (int i = 0; i < n; i += 2) {
        if (!(s[i] - '0' <= 9 and s[i] - '0' >= 0)) {
            cout << "-1\n";
            return 0;
        }
        if (i + 1 < n and s[i + 1] != '+' and s[i + 1] != '-' and s[i + 1] != '/' and s[i + 1] != '*') {
            cout << "-1\n";
            return 0;
        }
        if (i - 1 >= 0 and s[i] - '0' == 0 and s[i - 1] == '/'){
		cout << "-1\n";
            return 0;
        }
        
    }
    
    auto math = [&] (auto&& self, double last, double cur, double i, double x) ->double {
        if (i >= n) return cur + (x == 0? last : -last);
        double ans;
        if (s[i - 1] == '+') {
            ans = self(self, s[i] - '0', cur + (x == 0? last : -last), i + 2, 0);
        } else if (s[i - 1] == '-') {
            ans = self(self, s[i] - '0', cur + (x == 0? last : -last), i + 2, 1);
        } else if (s[i - 1] == '/') {
            ans = self(self, last / (s[i] - '0'), cur, i + 2, x);
        } else {
            ans = self(self, last * (s[i] - '0'), cur, i + 2, x);
        }
        return ans;
    };
    cout << math(math, s[0] - '0', 0, 2, 0) << '\n';
    return 0;
}
