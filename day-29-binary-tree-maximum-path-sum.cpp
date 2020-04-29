#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int maxv = INT_MIN;
    int maxPathSum(TreeNode *root)
    {
        DFS(root);
        return maxv;
    }

    int DFS(TreeNode *t)
    {
        if (t == NULL)
            return 0;
        int l = max(DFS(t->left), 0);
        int r = max(DFS(t->right), 0);

        maxv = max(maxv, t->val + l + r);

        return t->val + max(l, r);
    }
};

int main()
{
    return 0;
}