#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

vector<int> zfunc(const string& s){
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for(int i = 1; i < n; ++i){
        if(i < r){
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]){
            ++z[i];
        }
        if(i + z[i] > r){
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

class Solution {
public:
    int minStartingIndex(string s, string pattern) {
        int n = s.size();
        int m = pattern.size();

        if(m > n){
            return -1;
        }

        string x = pattern + '#' + s;
        string y = s + '#' + pattern; 
        reverse(y.begin(), y.end());

        vector<int> pf = zfunc(x);
        vector<int> sf = zfunc(y);
        
        vector<int> nsf(n - m +1, 0);
        for(int i = 0; i <= n - m; ++i){
            int z_index = n + 1 - i;
            if(z_index < sf.size()){
                nsf[i] = sf[z_index];
            } else{
                nsf[i] = 0;
            }
        }

        for(int i = 0; i <= n - m; ++i){
            if(pf[m + 1 + i] + 1 + nsf[i] >= m){
                return i;
            }
        }
        return -1;
    }
};

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    Solution a;
    cout << a.minStartingIndex("abcdefg", "bcdffg") << '\n';
    return 0;
}
//m + 1 
