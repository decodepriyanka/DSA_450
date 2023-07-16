
#include <bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{

    int ans = 0, count = 0, index = -1;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                count++;
            }
        }
        if (count > ans)
        {
            ans = count;
            index = i;
        }
    }
    return index;
}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    auto ans = rowWithMax1s(arr, n, m);
    cout << ans << "\n";

    return 0;
}
