#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

pair<i64, i64> operator+(const pair<i64, i64>& lhs, const pair<i64, i64>& rhs) {
    return {lhs.first + rhs.first, lhs.second + rhs.second};
}

pair<i64, i64> operator-(const pair<i64, i64>& lhs, const pair<i64, i64>& rhs) {
    return {lhs.first - rhs.first, lhs.second - rhs.second};
}

pair<i64, i64> operator*(i64 k, const pair<i64, i64>& lhs) { //this is to overload operator *, keep in mind that the int k must be plaed before the pair otherwise it shows error as it is position sensitive.
    return {lhs.first * k, lhs.second * k};
}

int main()
{
    UNSYNC
    i64 x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    pair<i64, i64> required {x2 - x1, y2 - y1};
    i64 n; cin >> n;
    string s; cin >> s;
    vector<pair<i64, i64>> count (n); //count of UDLR
    rep(i, 0, n) {
        if (s[i] == 'U') ++count[i].second;
        else if (s[i] == 'D') --count[i].second;
        else if (s[i] == 'L') --count[i].first;
        else ++count[i].first;
    }
    vector<pair<i64, i64>> windshift (n); windshift[0] = count[0];
    rep(i, 1, n){
        windshift[i] = windshift[i - 1] + count[i];
    }
    i64 l = 0, r = 1e14 + 1; //the leftmost possible answer is 1, thus i will take l = 0, rightmost if 1e14 so ill take 1e14 + 1, once again watch pashka's final video on binary search to learn this implementation of binary search.
    while(r - l > 1){
        i64 m = l + (r - l)/2;
        pair<i64, i64> shift = required - (m/n)*windshift[n - 1];
        if (m % n > 0) shift = shift - windshift[m % n - 1];
        i64 mod = abs(shift.first) + abs(shift.second); //if the abs is less than or equal to m then we can pick appropriate of UDL or R to shif the sip to the required position
        if (mod > m){
            l = m;
        } else {
            r = m;
        }
    }
    cout << (r == 1e14 + 1? -1 : r) << '\n';
    return 0;
}
