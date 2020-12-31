#include <deque>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    void create_tree(TreeNode *&tree)
    {
        int data;
        cin >> data;
        if (data != '\n')
        {
            if (data == -1)
            {
                tree = nullptr;
            }
            else
            {
                tree = new TreeNode(data);
                create_tree(tree->left);
                create_tree(tree->right);
            }
        }
    }
    int DFSRecursive(TreeNode *root, int prevSum)
    {
        if (!root)
            return 0;
        //总体还是一套前序遍历的思路
        int sum = prevSum * 10 + root->val;
        //如果该节点为叶子节点，则不需要往下遍历了，直接返回sum即可
        if (!root->left && !root->right)
            return sum;
        else
            return DFSRecursive(root->left, sum) +
                   DFSRecursive(root->right, sum);
    }
    int sumNumbers(TreeNode *root)
    {
        return DFSRecursive(root, 0);
    }
};

int main()
{
    Solution s;
    TreeNode *p = (TreeNode *)malloc(sizeof(TreeNode));
    s.create_tree(p);
    cout << s.sumNumbers(p);
}