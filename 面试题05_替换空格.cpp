#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int len = s.length();
        if(len==0) return s;
        int extra = 0;
        for(char c: s){
            if(c == ' ') extra += 2;
        }
        s.append(string(extra, ' '));
        int low = s.length()-1, fast = len-1;
        while(fast >= 0 && low>=0){
            if(s[fast] == ' '){
                s[low--] = '0';
                s[low--] = '2';
                s[low--] = '%';
            }
            else{
                s[low--] = s[fast];
            }
            fast--;
        }
        return s;
    }
};

int main(){
    Solution s;
    string str = "123 retrt ";
    cout << s.replaceSpace(str) << endl;
    return 0;
}
