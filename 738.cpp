#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int monotoneIncreasingDigits(int N)
    {
        string strN = to_string(N);
        int i = 1;
        for (; i < strN.length() && strN[i - 1] <= strN[i]; ++i)
            ;
        if (i < strN.length())
        {
            for (; i > 0 && strN[i - 1] > strN[i]; --strN[i - 1], --i)
                ;
            for (i += 1; i < strN.length(); ++i)
                strN[i] = '9';
        }
        return stoi(strN);
    }
};

int main()
{
    Solution s;
    cout << s.monotoneIncreasingDigits(120);
    return 0;
}