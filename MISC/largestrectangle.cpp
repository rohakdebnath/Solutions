#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> p (n);
    //for each element we will find its closest left and closest right smaller element and make the area = that
    vector<int> st; //st will contain elements whose closest left smaller element is the element just behind it in the stack
    //an element smaller than the top elements of the stack becomes it's right ending
    int j = 0;
    while (j < n) {
        if (st.empty() or a[st.back()] <= a[j]) {
            st.push_back(j++);
        } else {
            int h = st.back();
            st.pop_back();
            int width = st.empty() ? j : j - st.back() - 1;
            p[h] = a[h] * width;
        }
    }
    
    while (!st.empty()) {
        int h = st.back();
        st.pop_back();
        int width = st.empty() ? n : n - st.back() - 1;
        p[h] = a[h] * width;
    }
    cout << *max_element(p.begin(), p.end()) << '\n';
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}

