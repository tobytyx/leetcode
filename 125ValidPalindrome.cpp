# include <iostream>
# include <algorithm>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty())
            return true;
        int i = 0, j = s.size() - 1;
        int key = 0;
        while (i < j){
            if(s[i] < '0' || (s[i] > '9' && s[i] < 'A') || (s[i] > 'Z' && s[i] < 'a') || s[i] > 'z'){
                i++;
                continue;
            }
            if(s[j] < '0' || (s[j] > '9' && s[j] < 'A') || (s[j] > 'Z' && s[j] < 'a') || s[j] > 'z'){
                j--;
                continue;
            }
            if('A' <= s[i] && s[i] <= 'Z')
                s[i] = s[i] - 'A' + 'a';
            if('A' <= s[j] && s[j] <= 'Z')
                s[j] = s[j] - 'A' + 'a';
            if(s[i] == s[j]){
                i++;
                j--;
                continue;
            }
            printf("%c,%d,%c,%d\n", s[i], i, s[j], j);
            return false; 
        }
        return true;
    }
};

int main(){
    string str("`l;`` 1o1 ??;l`");
    Solution s;
    cout << s.isPalindrome(str) << endl;
    return 0;
}