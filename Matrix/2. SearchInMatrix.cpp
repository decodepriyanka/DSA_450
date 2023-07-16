// https://leetcode.com/problems/search-a-2d-matrix/description/
// You are given an m x n integer matrix matrix with the following two properties:

/*Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true */
//-------------------------------Naive Solution TC : O(n*m) ----------------------------------------------------------------

// Linear traverse the entire matrix and check if the target exists or not
#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int row = matrix.size(),
        col = matrix[0].size();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == target)
                return true;
        }
    }
    return false;
}
//----------------------------------Efficient Solution ------------------------------------------------------------

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    if (!matrix.size())
        return false;
    int n = matrix.size(),
        m = matrix[0].size();
    int i = 0, j = m - 1; // initially the pointer will be at 1st row and last col
    while (i < n && j >= 0)
    { // keep on moving till it does not get out of bound
        if (matrix[i][j] == target)
        {
            return true;
        }
        if (matrix[i][j] > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return false;
}
/*------------------------------- Most Optimised Solution TC: 0(log(n*m))-----------------------------------

Approach - Total number of elements in the matrix will be n*m so do binary search from 0 to n*m only using index values
           low = 0 , high = 11 then mid = 5 : find the i and j index of mid we can get i aka row  = mid/column no , j aka col = mid%column no
so after finding the imaginary index row and column check if the target value iss greater than or less than it and then do accordingly
*/
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    if (!matrix.size())
        return false;         // if matrix is empty
    int n = matrix.size(),    // numnber of row
        m = matrix[0].size(); // number of col
    int l = 0;
    int h = (n * m) - 1;
    while (l <= h)
    {                              // perform binary search
        int mid = l + (h - l) / 2; // to avoid overflow
        if (matrix[mid / m][mid % m] == target)
        { // row index for imaginary mid index = mid/m  , col = mid%m
            return true;
        }
        if (matrix[mid / m][mid % m] > target)
        { // if target is lesser search on the left half
            h = mid - 1;
        }
        else
        { // if target is greater earch on the right half
            l = mid + 1;
        }
    }
    return false;
}