// Write a function to solve the 0/1 Knapsack problem using dynamic programming.

// Input: weights = [1, 2, 3], values = [10, 15, 40], capacity = 6 Output: 55
// (Maximum value that can be obtained) it should be corrected that the maximum
// value that can be obtained is 65 and not 55

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int napsack(int W, vector<int>& weights, vector<int>& values, int n) {
    vector<vector<int>> res(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= W; ++j) {
            if (weights[i - 1] <= j) {
                res[i][j] = max(res[i - 1][j],
                                res[i - 1][j - weights[i - 1]] + values[i - 1]);
            } else {
                res[i][j] = res[i - 1][j];
            }
        }
    }
    return res[n][W];
}

int main() {
    int weight = 6;
    vector<int> weights = {1, 2, 3};
    vector<int> values = {10, 15, 40};

    int n = weights.size();

    cout << napsack(weight, weights, values, n);

    return 0;
}