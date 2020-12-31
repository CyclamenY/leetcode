#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        vector<bool> vis(26, false);
        vector<int> num(26, 0);
        //首先确认字符串中有几种字符
        for (auto it : s)
            ++num[it - 'a'];
        string stk;  //初始化栈，这里使用string来代替栈
        for (auto it : s)
        {
            //只考虑栈内没有该字符的情况
            if (!vis[it - 'a'])
            {
                //开始循环和栈顶比较，直到栈空或者本字符小于栈顶
                while (!stk.empty() && stk.back() > it)
                {
                    //准备弹出栈顶前，先要判断后面的字符中还是否存在
                    //如果不存在是不允许弹出的
                    if (num[stk.back() - 'a'])
                    {
                        vis[stk.back() - 'a'] = false;
                        stk.pop_back();
                    }
                    else
                        break;
                }
                //在这里，栈空或者本字符小于栈顶了，正常入栈
                stk.push_back(it);
                vis[it - 'a'] = true;
            }
            //正常步进，该字符减一
            --num[it - 'a'];
        }
        return stk;
    }
};

int main()
{
    Solution s;
    cout << s.removeDuplicateLetters("eacb");
    return 0;
}