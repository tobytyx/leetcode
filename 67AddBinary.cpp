#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int len_a = a.length(), len_b = b.length();
        if(len_a == 0) return b;
        if(len_b == 0) return a;
        int max_len = 1 + (len_a > len_b ? len_a: len_b);
        string res(max_len, '0');
        len_a--;
        len_b--;
        int jinwei = 0;
        while(len_a>=0 && len_b>=0){
            int buff = jinwei + a[len_a] + b[len_b] - '0' - '0';
            res[max_len-1] += (buff % 2);
            jinwei = buff / 2;
            len_a--;
            len_b--;
            max_len--;
        }
        while (len_a >= 0){
            int buff = jinwei + a[len_a] - '0';
            res[max_len-1] += (buff % 2);
            jinwei = buff / 2;
            len_a--;
            max_len--;
        }
        while (len_b >= 0){
            int buff = jinwei + b[len_b] - '0';
            res[max_len-1] += (buff % 2);
            jinwei = buff / 2;
            len_b--;
            max_len--;
        }
        if(jinwei)
            res[0] += jinwei;
        else
            return res.substr(1);
        return res;
    }
};

int main(){
    Solution s;
    string res = s.addBinary("100", "110010");
    cout << res << endl;
    return 0;
}
