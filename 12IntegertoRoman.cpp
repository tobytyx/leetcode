#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> numerals = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int i = 0;
        string res;
        while (num > 0){
            for(int times = num / values[i];times>0; times--)
                res = res + numerals[i];
            num = num % values[i];
            i++;
        }
        
        return res;
    }
};

int main(){
    Solution s;
    string res = s.intToRoman(58);
    cout<< res << endl;
    return 0;
}
