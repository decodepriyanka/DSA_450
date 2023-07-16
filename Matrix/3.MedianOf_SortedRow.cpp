/* https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

Given a row wise sorted matrix of size R*C where R and C are always odd, find the median of the matrix.

Example 1:

Input:
R = 3, C = 3
M = [[1, 3, 5],
     [2, 6, 9],
     [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives
us {1,2,3,3,5,6,6,9,9}. Hence, 5 is median.
----------------------------------Naive Solution -----------------------------------------------------------
  TC - N*Mlog(M*M)
  Sc - o(N*M)
  Iterate over every element of matrix and push them into an array . sort the array and find the middle

--------------------- CODE ----------------------------------  */
#include <bits/stdc++.h>
using namespace std;
int median(vector<vector<int>> &matrix, int R, int C)
{
    // code here
    vector<int> ans;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            ans.push_back(matrix[i][j]);
        }
    }
    sort(ans.begin(), ans.end());

    return ans[ans.size() / 2];
}