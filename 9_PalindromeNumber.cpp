#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x == 0) return true;
        int y = x, digit = 1;
        while(y > 9){
            y /= 10;
            digit *= 10;
        }
        while(x > 0){
            if(x / digit != x % 10) return false;
            x = (x % digit) / 10;
            digit /= 100;
        }
        return true;
    }
};

int main(){
    int x = 0;
    cin >> x;
    Solution s;
    cout << s.isPalindrome(x) << endl;
    return 0;
}
