#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

struct Item
{
    int weight, value;
    double ratio;
};

bool cmp(Item a, Item b) { return a.ratio > b.ratio; }

int bound(int i, int n, int W, int currentWeight, int currentValue, vector<Item> &items)
{
    int j = i;
    int totweight = currentWeight;
    double boundVal = currentValue;
    while (j < n && totweight + items[j].weight <= W)
    {
        totweight += items[j].weight;
        boundVal += items[j].value;
        j++;
    }
    if (j < n)
        boundVal += (W - totweight) * items[j].ratio;
    return boundVal;
}

int knapsackBB(vector<Item> &items, int n, int W)
{
    sort(items.begin(), items.end(), cmp);
    int maxValue = 0;
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    while (!q.empty())
    {
        // requires C++ 17 version to execute below line...
        // auto [level, value, weight] = q.front();

        auto t = q.front();
        int level = get<0>(t);
        int value = get<1>(t);
        int weight = get<2>(t);
        q.pop();
        if (level == n)
            continue;
        if (weight + items[level].weight <= W)
        {
            int newValue = value + items[level].value;
            int newWeight = weight + items[level].weight;
            maxValue = max(maxValue, newValue);
            if (bound(level + 1, n, W, newWeight, newValue, items) > maxValue)
            {
                q.push({level + 1, newValue, newWeight});
            }
        }
        if (bound(level + 1, n, W, weight, value, items) > maxValue)
        {
            q.push({level + 1, value, weight});
        }
    }
    return maxValue;
}

int main()
{
    vector<Item> items = {{2, 12, 0}, {1, 10, 0}, {3, 20, 0}, {2, 15, 0}};
    int W = 5, n = items.size();
    for (auto &it : items)
        it.ratio = (double)it.value / it.weight;
    cout << "Maximum value in Knapsack = " << knapsackBB(items, n, W) << endl;
    return 0;
}
