#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

string op = "&!|";
class Solution {
public:
    bool parseBoolExpr(string s) {
        auto eval = [&] (char op, vector<bool>& a) -> char{
            int fin;
            if (op == '&') {
                fin = 1;
                for (int i: a) fin &= i;
            } else if (op == '!') {
                fin = !a[0];
            } else {
                fin = 0;
                for (int i: a) fin |= i;
            }
            return fin ? 't': 'f';
        };

        vector<char> st;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] != ',') {
                st.push_back(s[i]);
            }
            if (s[i] == ')') {
                vector<bool> a;
                while (op.find(st.back()) == string::npos) {
                    char c = st.back();
                    st.pop_back();
                    if (c == 't' or c == 'f') a.push_back(c == 't');
                }
                char op = st.back();
                st.pop_back();
                st.push_back(eval(op, a));
            }
        }
        return st.back() == 't';
    }
};

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    Solution a;
    a.parseBoolExpr("!(f)");
    return 0;
}
