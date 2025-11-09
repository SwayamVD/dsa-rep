/*
9. A marketing firm can choose from n advertisement campaigns, each having
a cost and an expected reach value (benefit). Given a total budget B ,use a 0/1
knapsack approach (Dynamic programming or branch and bound) to
determine the optimal set of campaign that maximizes the total reach value.
Display:
    1. Selected campaigns
    2. Total cost used
    3. Maximum reach achieved.
*/

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>
using namespace std;

struct Adv
{
    int cost, reach;
    double ratio;
};

bool cmp(Adv a, Adv b)
{
    return a.ratio > b.ratio;
}

double bound(int i, int n, int W, int currCost, int currReach, vector<Adv> &ads)
{
    int j = i;
    int totalw = currCost;
    double boundv = currReach;
    while (j < n && currCost + ads[j].cost <= W)
    {
        totalw = currCost + ads[j].cost;
        boundv = currReach + ads[j].reach;
        j++;
    }
    if (j < n)
    {
        boundv += (W - currCost) * ads[j].ratio;
    }
    return boundv;
}

int knapsackb2b(vector<Adv> &ads, int n, int W)
{
    sort(ads.begin(), ads.end(), cmp);
    int maxr = 0;
    queue<tuple<int, int, int, string>> q;
    q.push({0, 0, 0, ""});
    int bestcost = 0;
    while (!q.empty())
    {
        auto t = q.front();
        int level = get<0>(t); // item or single advertise
        int reach = get<1>(t); // value
        int cost = get<2>(t);  // weight
        string selected = get<3>(t);
        q.pop();
        if (level == n)
        {
            continue;
        }
        if (cost + ads[level].cost <= W)
        {
            int newcost = cost + ads[level].cost;
            int newreach = reach + ads[level].reach;
            string ns = selected + " Advertise" + to_string(level);
            // maxr = max(maxr, newreach);
            if (maxr < newreach)
            {
                maxr = newreach;
                cout << "New maxreach :" << maxr << " (" << ns << ")" << endl;
                bestcost = newcost;
            }

            if (bound(level + 1, n, W, newcost, newreach, ads) > maxr)
            {
                q.push({level + 1, newreach, newcost, ns});
            }
        }
        if (bound(level + 1, n, W, cost, reach, ads) > maxr)
        {
            q.push({level + 1, reach, cost, selected});
        }
    }
    cout << "Total Cost Used: " << bestcost << endl;
    return maxr;
}

int main()
{
    vector<Adv> ads = {
        {3, 25, 0},
        {2, 20, 0},
        {4, 28, 0},
        {3, 22, 0},
        {1, 12, 0}};
    int W = 7;
    int n = ads.size();

    for (auto &a : ads)
    {
        a.ratio = (double)a.reach / a.cost;
    }

    cout << "Maximum reach achieved: " << knapsackb2b(ads, n, W) << endl;
    return 0;
}
