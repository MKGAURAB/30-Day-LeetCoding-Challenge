#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
    int ans;

    int dfs(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int lans = 0, lmax = 0;

        if (root->left)
        {
            lans = dfs(root->left) + 1;
            ans = max(ans, lmax + lans);
            lmax = max(lmax, lans);
        }

        if (root->right)
        {
            lans = dfs(root->right) + 1;
            ans = max(ans, lmax + lans);
            lmax = max(lmax, lans);
        }

        return lmax;
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        ans = 0;

        dfs(root);

        return ans;
    }
};

int main(int argv, const char *argc)
{
    return 0;
}