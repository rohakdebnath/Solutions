#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    string s, p; cin >> s >> p;
    VI result(s.size() + p.size() - 1);

    for (int i = s.size() - 1; i >= 0; --i) {
        int carry = 0;
        for (int j = p.size() - 1; j >= 0; --j) {
            int tempSum = (s[i] - '0') * (p[j] - '0') + result[i + j] + carry;
            result[i + j] = tempSum % 10;
            carry = tempSum / 10;
        }
        result[i] += carry;
    }
    string res = accumulate(all(result), string(""), [&] (const string& s, int num) {return s + to_string(num);});
    int i = res.find_first_not_of('0');
    res = (i != string::npos ? res.substr(i) : "0");
    cout << res << '\n';
    return 0;
}
