#include <bits/stdc++.h>
using namespace std;

int maxValue(int k, vector<int> prices) {
    sort(prices.begin(), prices.end());

    int n = prices.size();
    int left = 0, right = prices[n - 1] - prices[0];
    
    auto canAchieve = [&](int mid) {
        int count = 1;
        int last = prices[0];
        for (int i = 1; i < n; i++) {
            if (prices[i] - last >= mid) {
                count++;
                last = prices[i];
            }
            if (count >= k) return true;
        }
        return false;
    };
    
    while (left < right) {
        int mid = left + (right - left + 1) / 2;
        if (canAchieve(mid)) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }

    return left;
}
