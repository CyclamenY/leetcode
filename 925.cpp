#include <iostream>

using namespace std;

class Solution
{
public:
    bool isLongPressedName(string name, string typed)
    {
        auto nameLen = name.length();
        auto typedLen = typed.length();
        auto curTyped = 0;
        for (auto curName = 0; curName < nameLen; ++curName)
        {
            int count = 1;
            while (curName + 1 < nameLen && name[curName + 1] == name[curName])
            {
                curName += 1;
                count += 1;
            }
            auto cur = name[curName];
            while (typed[curTyped] == cur && curTyped + 1 <= typedLen)
            {
                count--;
                curTyped += 1;
            }
            if (count > 0)
                return false;
        }
        if (curTyped != typedLen)
            return false;
        return true;
    }
};