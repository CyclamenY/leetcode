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
class Solution
{
    deque<pair<TreeNode *, int>> dq;

public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        vector<vector<int>> vec(1, vector<int>(0));
        dq.push_back(make_pair(root, 1));
        while (!dq.empty())
        {
            TreeNode *node = dq.front().first;
            auto num = dq.front().second;
            if (num >= vec.size())
                vec.resize(num);
            dq.pop_front();
            if (node->left)
                dq.push_back(make_pair(node->left, num + 1));
            if (node->right)
                dq.push_back(make_pair(node->right, num + 1));
            if (num % 2 == 0)  //偶数层，反向
                vec[num - 1].insert(vec[num - 1].begin(), node->val);
            else  //偶数层，正向
                vec[num - 1].push_back(node->val);
        }
        return vec;
    }
};

int main()
{
    Solution s;
    TreeNode *p = (TreeNode *)malloc(sizeof(TreeNode));
    create_tree(p);
    s.levelOrder(p);
}