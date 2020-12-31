#include <iostream>
#include <string>

using namespace std;

// class Solution
// {
// public:
//     string reverseWords(string s)
//     {
//         // if (s.empty())
//         //     return s;
//         // string returnStr;
//         // int lengthMark = s.size() - 1;
//         // auto riter = s.rbegin();
//         // while (riter != s.rend())
//         // {
//         //     while (riter != s.rend() && *riter == ' ')
//         //     {
//         //         --lengthMark;
//         //         ++riter;
//         //         continue;
//         //     }
//         //     int front = lengthMark;
//         //     int num = 0;
//         //     while (riter != s.rend() && *riter != ' ')
//         //     {
//         //         --front;
//         //         --lengthMark;
//         //         ++riter;
//         //         ++num;
//         //     }
//         //     if (front >= -1 && num != 0)
//         //         returnStr.append(s, front + 1, num);
//         //     returnStr.append(" ");
//         // }
//         // while (returnStr[returnStr.size() - 1] == ' ')
//         //     returnStr.pop_back();
//         // return returnStr;
//     }
// };

class Solution
{
public:
    string reverseWords(string s)
    {
        string str;
        string returnStr;
        if (s.empty())
            return str;
        int frontIndex = 0;
        int size = s.size();
        for (; frontIndex < size - 1; ++frontIndex)
        {
            if (s[frontIndex] != ' ')
                break;
        }
        if (frontIndex == size)
            return str;
        int lastIndex = size - 1;
        for (; lastIndex > -1; --lastIndex)
        {
            if (s[lastIndex] != ' ')
                break;
        }
        str = string(s, frontIndex, lastIndex - frontIndex + 1);
        // return str;
        int lengthMark = str.size() - 1;
        auto iter = str.rbegin();
        while (lengthMark >= 0)
        {
            int num = 0;
            while (lengthMark >= 0 && *iter != ' ')
            {
                --lengthMark;
                ++num;
                ++iter;
            }
            returnStr.append(str, lengthMark + 1, num);
            returnStr.append(" ");
            while (lengthMark >= 0 && *iter == ' ')
                ++iter;
        }
        while (returnStr[returnStr.size() - 1] == ' ')
            returnStr.pop_back();
        return returnStr;
    }
};

int main()
{
    // string s1 = "    hello      world!    ";
    // Solution s;
    // cout << s.reverseWords(s1) << endl;
    while ((c = getchar()) != EOF)
}