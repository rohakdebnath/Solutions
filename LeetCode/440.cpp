ri#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class Solution {
public:
    int findKthNumber(int n, int k) {
        int p = 1;
        --k;  
        
        while (k > 0) {
            int count = countNumbersWithPrefix(p, n);
            if (k >= count) {
                ++p; 
                k -= count;
            } else {
                p *= 10; 
                --k;
            }
        }
        
        return p;
    }

    int countNumbersWithPrefix(int prefix, int n) {
        i64 firstNumber = prefix, nextNumber = prefix + 1;
        int totalCount = 0;

        while (firstNumber <= n) {
            totalCount += min(n + 1LL, nextNumber) - firstNumber;
            firstNumber *= 10;
            nextNumber *= 10;
        }

        return totalCount;
    }
};

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    return 0;
}

