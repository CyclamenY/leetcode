#include <cstdlib>
#include <deque>
#include <iostream>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        deque<pair<TreeNode *, int>> dq;
        vector<vector<int>> returnVec(1);
        dq.push_back(make_pair(root, 1));
        while (!dq.empty())
        {
            TreeNode *temp = dq.front().first;
            if (temp->left)
                dq.push_back(make_pair(temp->left, dq.front().second + 1));
            if (temp->right)
                dq.push_back(make_pair(temp->right, dq.front().second + 1));
            if (dq.front().second == returnVec.size())
                returnVec.resize(dq.front().second + 1);
            if (dq.front().second % 2 == 0)  //偶数行，反向插入
            {
                returnVec[dq.front().second - 1].insert(
                    returnVec[dq.front().second - 1].begin(), temp->val);
            }
            else  //奇数，正向插入
                returnVec[dq.front().second - 1].push_back(temp->val);
            dq.pop_front();
        }
        if (!returnVec[returnVec.size() - 1].size())
            returnVec.pop_back();
        return returnVec;
    }
};

int main()
{
    Solution s;
    TreeNode *p = (TreeNode *)malloc(sizeof(TreeNode));
    s.create_tree(p);
    s.zigzagLevelOrder(p);
}