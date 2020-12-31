#include <cstring>
#include <unordered_map>

using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        if(s.empty()) return ' ';
        unordered_map<char,bool> hashmap;
        for(int i=0;i<s.size();++i) {
            if(!hashmap.count(s[i])) {
                hashmap.insert(make_pair(s[i],true));
            }
            else {
                hashmap[s[i]]=false;
            }
        }
        for(auto i=0;i<s.size();++i) {
            if(hashmap[s[i]]) {
                return s[i];
            }
        }
        return ' ';
    }
};