# include <iostream>
# include <string>
# include <unordered_map>
# include <math.h>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res;
        if(!numerator || !denominator) return 0;
        if(numerator > 0 ^ denominator > 0) res += "-";
        long numer = abs(long(numerator));
        long denom = abs(long(denominator));
        unordered_map<int, int> map;
        res += to_string(numer / denom);
        numer = numer % denom;
        if(numer == 0) return res;
        res += ".";
        while(numer){
            numer *= 10;
            int cur = numer / denom;
            numer = numer % denom;
            res += to_string(cur);
            if(map.find(numer) != map.end()){
                int pos = map[numer];
                res.insert(pos, "(");
                res += ")";
                break;
            }
            map[numer] = res.length();
        }
        return res;
    }
};

int main(){
    Solution s;
    string res = s.fractionToDecimal(-1, 6);
    cout << res << endl;
    return 0;
}
