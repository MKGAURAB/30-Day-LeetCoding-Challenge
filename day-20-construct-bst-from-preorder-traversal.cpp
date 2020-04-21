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
    int pos;
    TreeNode *constructTree(vector<int> &rt, int min, int max)
    {
        if (pos >= rt.size())
            return NULL;
        TreeNode *root = NULL;
        if (rt[pos] > min && rt[pos] < max)
        {
            int key = rt[pos++];
            root = new TreeNode(key);
            root->left = constructTree(rt, min, key);
            root->right = constructTree(rt, key, max);
        }
        return root;
    }

public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        pos = 0;
        return constructTree(preorder, INT_MIN, INT_MAX);
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
