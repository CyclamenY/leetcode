#include <vector>

using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int lineSize=matrix.size();
        int rowSize=matrix[0].size();
        if(lineSize==0) return false;
        int line=lineSize-1,row=0;
        while(line>=0 && line<lineSize && row>=0 && row<rowSize) {
            if(matrix[line][row]<target)
                {row++;}
            else if(matrix[line][row]>target)
                {line--;}
            else 
                {return true;}
        }
        return false;
    }
};