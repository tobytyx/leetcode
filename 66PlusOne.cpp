# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int jinwei=0, cache=0;
        vector<int>::iterator iter = digits.end();
        iter --;
        cache = *iter + 1;
        jinwei = cache / 10;
        res.push_back(cache - 10*jinwei);
        while (iter != digits.begin()){
            iter --;
            cache = *iter + jinwei;
            jinwei = cache / 10;
            res.push_back(cache-10*jinwei);
        }
        if (jinwei == 1) res.push_back(1);
        while (!res.empty() && res.back() == 0)
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
    vector<int> digits(3, 0);
    Solution s;
    vector<int> res = s.plusOne(digits);
    for(auto r: res){
        printf("%d",r);
    }
    printf("\n");
    return 0;
}
