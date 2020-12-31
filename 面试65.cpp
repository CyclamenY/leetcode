#include <bitset>
#include <iostream>
using namespace std;

class Solution {
public:
    int add(int a, int b) {
        bitset<32> bita(a);
        bitset<32> bitb(b);
        bitset<32> bitRes(0);
        for(int p=0;p<32;++p) {
            if(bita[p]==1 && bitb[p]==1) {
                int i=p;
                for(;bitb[i]!=0;++i) {
                    bitb[i]=0;
                }
                bitb[i]=1;
            }
            else if(bita[p]==0 && bitb[p]==0) {
                bitRes[p]=0;
            }
            else {
                bitRes[p]=1;
            }
        }
        return bitRes.to_ulong();
    }
};

int main() {
    Solution s;
    cout<<endl<<s.add(-1,2);
}