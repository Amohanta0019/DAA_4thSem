#include <bits/stdc++.h>
using namespace std;
struct jobs
{
    int id;
    int dead;
    int profit;
};
class job_sequencing
{
public:
    bool static comp(jobs A, jobs B)
    {
        return A.profit > B.profit;
    }

    void JobScheduling(jobs arr[], int n, int &countJob, int &jobProfit, int selectJobs[])
    {
        sort(arr, arr + n, comp);

        int maxi = arr[0].dead;
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, arr[i].dead);
        }

        int slot[maxi + 1];
        for (int i = 0; i <= maxi; i++)
        {
            slot[i] = -1;
        }

        countJob = 0, jobProfit = 0;
        int selectJobIdx = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].dead; j > 0; j--)
            {
                if (slot[j] == -1)
                {
                    slot[j] = arr[i].id;
                    countJob++;
                    jobProfit += arr[i].profit;
                    selectJobs[selectJobIdx++] = (arr[i].id);
                    break;
                }
            }
        }
        cout << "Selected jobs :- " << endl;
        for (int i = 0; i < selectJobIdx; i++)
        {
            cout << selectJobs[i] << "   ";
        }
        cout << endl;
    }
};

int main(void)
{
    int n = 4;
    jobs arr[4] = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    int countJob, jobProfit;
    int selectJobs[n];

    job_sequencing js;

    js.JobScheduling(arr, n, countJob, jobProfit, selectJobs);
    cout << countJob << " " << jobProfit << endl;

    return 0;
}