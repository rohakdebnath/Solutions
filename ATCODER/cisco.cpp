#include<bits/stdc++.h>

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int getMinimumCost(const vector<int>& machineCount, const vector<int>& finalMachineCount, int shiftingCost) {
    int n = machineCount.size();
    int minCost = 1e9;

    for (int i = 0; i < (int)pow(4, n); ++i) {
        int val = i;
        int count = 0;
        int val1 = 0, val2 = 0, val3 = 0;

        for (int j = 0; j < n; ++j) {
            switch (val % 4) {
                case 1: val1 += machineCount[j]; break;
                case 2: val2 += machineCount[j]; break;
                case 3: val3 += machineCount[j]; break;
                default: count--; break;
            }
            count++;
            val /= 4;
        }

        if (val1 == 0 or val2 == 0 or val3 == 0) continue;

        int currentCost = abs(finalMachineCount[0] - val1) +
                          abs(finalMachineCount[1] - val2) +
                          abs(finalMachineCount[2] - val3) +
                          (count - 3) * shiftingCost;

        minCost = min(minCost, currentCost);
    }

    return minCost;
}

int main() {
    cout << getMinimumCost({10, 20, 15, 26}, {10, 22, 36}, 3);
    return 0;
}
