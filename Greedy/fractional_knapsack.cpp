#include <bits/stdc++.h>
using namespace std;
struct item
{
    int profit;
    int wt;
};

class fractional_knapsack
{
public:
    bool static comp(item A, item B)
    {
        double r1 = (double)A.profit / (double)A.wt;
        double r2 = (double)B.profit / (double)B.wt;
        return r1 > r2;
    }
    double fractionalKnapsack(item arr[], int n, int W)
    {
        sort(arr, arr + n, comp);

        int currWt = 0;
        int finalVal = 0.0;

        for (int i = 0; i < n; i++)
        {
            if (currWt + arr[i].wt <= W)
            {
                currWt += arr[i].wt;
                finalVal += arr[i].profit;
            }
            else
            { 
                int remaining = W - arr[i].wt;
                finalVal += ((double)arr[i].profit / (double)arr[i].wt) * (double)remaining;
                break;
            }
        }
        return finalVal;
    }
};

int main(void)
{
    int n = 3, weight = 50;
    item arr[n] = {{100, 20}, {60, 10}, {120, 30}};
    fractional_knapsack fk;
    double ans = fk.fractionalKnapsack(arr, n, weight);
    cout << "The maximum value is " << setprecision(2) << fixed << ans;
    return 0;
}