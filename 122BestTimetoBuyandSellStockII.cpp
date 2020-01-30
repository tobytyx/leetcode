# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len < 2) return 0;
        int max_profit = 0;
        for(int i=0; i<len-1; i++){
            if(prices[i]<prices[i+1])
                max_profit = max_profit + (prices[i+1]-prices[i]);
        }
        return max_profit;
    }
};
