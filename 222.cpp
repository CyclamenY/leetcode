#include <cmath>
#include <cstdlib>
#include <deque>
#include <iostream>

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
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        auto p = root;
        auto level = 0;
        deque<pair<int, TreeNode *>> que;
        while (p)
        {
            ++level;
            p = p->left;
        }
        que.push_back(make_pair(1, root));
        auto curlevel = 1;
        auto loss = 0;
        while (!que.empty())
        {
            TreeNode *temp = que.back().second;
            curlevel = que.back().first + 1;
            que.pop_back();
            if (temp->left && !temp->right)
            {
                que.push_back(make_pair(curlevel, temp->left));
                ++loss;
                break;
            }
            else if (!temp->left && !temp->right && curlevel == level)
            {
                loss += 2;
            }
            else if (temp->left && temp->right)
            {
                que.push_back(make_pair(curlevel, temp->left));
                que.push_back(make_pair(curlevel, temp->right));
            }
        }
        return pow(2, level) - 1 - loss;
    }
};

int main()
{
    Solution s;
    TreeNode *p = (TreeNode *)malloc(sizeof(TreeNode));
    s.create_tree(p);
    cout << s.countNodes(p);
    return 0;
}