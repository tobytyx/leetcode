# include <iostream>
# include <math.h>
# include <unordered_map>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> map;
        int last = n, cur = 0;
        map[n] = 0;
        while(true){
            while(last){
                cur += pow(last % 10, 2);
                last /= 10;
            }
            if(cur == 1) return true;
            if(map.find(cur) != map.end()) return false;
            map[cur] = 0;
            last = cur;
            cur = 0;
        }
        return false;
    }
};

int main(){
    Solution s;
    cout << s.isHappy(18) << endl;
}