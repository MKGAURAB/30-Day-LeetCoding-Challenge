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
private:
    TreeNode *constructTree(vector<int> &rt, int pos, int min, int max)
    {
        if (pos >= rt.size())
            return NULL;
        TreeNode *root = NULL;
        if (rt[pos] > min && rt[pos] < max)
        {
            root = new TreeNode(rt[pos]);
            root->left = constructTree(rt, pos + 1, min, rt[pos]);
            root->right = constructTree(rt, pos + 1, rt[pos], max);
        }
        return root;
    }

public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        return constructTree(preorder, 0, INT_MIN, INT_MAX);
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
