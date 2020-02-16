# include<iostream>
# include<vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        if(len < 2) return;
        int i = 0, j = len - 1;
        while(i < j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return;
    }
};
