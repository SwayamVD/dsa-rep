#include <iostream>
#include <vector>
using namespace std;

int knapsackDP(int W, vector<int> &wt, vector<int> &val, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (wt[i - 1] <= w)
            {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - wt[i - 1]] + val[i - 1]);
                // example => max(4 + 0, 3) or max(3, 4 + 0)
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

int main()
{
    int n = 4;
    vector<int> wt = {2, 1, 3, 2};
    vector<int> val = {12, 10, 20, 15};
    int W = 5;
    cout << "Maximum value in knapsack = " << knapsackDP(W, wt, val, n) << endl;
    return 0;
}