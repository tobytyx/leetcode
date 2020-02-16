# include <iostream>
# include <vector>
# include <algorithm>
# include <string.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int len = s.length();
        if(len == 0) return -1;
        int map[26];
        memset(map, -1, sizeof(map));
        for(int i=0; i<len; i++){
            int c = s[i] - 'a';
            if(map[c] == -1) map[c] = i;
            else if(map[c] >= 0) map[c] = -2;
        }
        int min_index = len;
        for(int i=0; i<26; i++){
            if(map[i] < 0) continue;
            min_index = min(min_index, map[i]);
        }
        if(min_index == len) return -1;
        return min_index;
    }
};

int main(){
    Solution s;
    cout << s.firstUniqChar("loveleetcode") << endl;
    return 0;
}
