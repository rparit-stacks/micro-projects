// Write a function to find the longest common subsequence of two given strings.
#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int longestCommonSubsequence(string &str1, string &str2) {
    int a = str1.size();
    int b = str2.size();

    vector<vector<int>> res(a + 1, vector<int>(b + 1, 0));

    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                res[i][j] = res[i - 1][j - 1] + 1;
            } else {
                res[i][j] = max(res[i - 1][j], res[i][j - 1]);
            }
        }
    }

    return res[a][b];
}

int main() {
    string str1 = "ABCDE";
    string str2 = "ACE";

    cout << "Length of longest common subsequence : "
         << longestCommonSubsequence(str1, str2) << endl;

    return 0;
}