# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        int buff = 0;
        for(int i=0; i<len; i++){
            if(nums[i] >= len) continue;
            if(nums[i] != i){
                int j = nums[i];
                nums[i] = len;
                while(nums[j] != j){
                    buff = nums[j];
                    nums[j] = j;
                    if(buff >= len || nums[buff] == buff){
                        break;
                    }
                    j = buff;
                }
            }
        }
        for(int i=0; i<len; i++){
            if(nums[i] != i) return i;
        }
        return len;
    }
};

int main(){
    Solution s;
    vector<int> nums = {9,6,4,2,3,5,7,0,1};
    int i = s.missingNumber(nums);
    printf("%d\n", i);
    return 0;
}
