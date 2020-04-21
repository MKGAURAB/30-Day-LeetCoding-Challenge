#include <bits/stdc++.h>

using namespace std;

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class BinaryMatrix
{
public:
    int get(int x, int y);
    vector<int> dimensions();
};

class Solution
{
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix)
    {
        vector<int> dim = binaryMatrix.dimensions();

        int r = dim[0], c = dim[1];
        r--, c--;
        int prev = c;
        while (r >= 0 && c >= 0)
        {
            int val = binaryMatrix.get(r, c);
            if (val)
            {
                prev = c;
                c--;
            }
            else
                r--;
        }

        return prev == c ? -1 : prev;
    }
};

int main(int argv, const char **argc)
{
    return 0;
}