#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        k--;
        int total = 1, nt = n;
        vector<int> numbers;
        for(int i = 1; i<=n; i++) numbers.push_back(i);
        for(int i = 1; i<=n; i++) total *= i;
        string res;
        for(int i = 0; i<n; i++){
            total /= nt;
            int cur = k / total;
            res.push_back(numbers[cur] + '0');
            numbers.erase(numbers.begin() + cur);
            k = k % total;
            nt--;
        }
        return res;
    }
};

int main(){
    Solution s;
    string res = s.getPermutation(4, 9);
    cout << res << endl;
    return 0;
}
