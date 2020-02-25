#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int sig = 1;
        int total = 0, last_value = 0;
        int buff = 0;
        int len = s.length();
        for(int i = 0; i < len; i++){
            if(s[i] == ' ') continue;
            if('0' <= s[i] && s[i] <= '9'){
                buff = buff * 10 + s[i] - '0';
            }
            else if(s[i] == '+'){
                total = total + buff * sig;
                sig = 1;
                buff = 0;
            }
            else if(s[i] == '-'){
                total = total + buff * sig;
                sig = -1;
                buff = 0;
            }
            else if(s[i] == '*'){
                last_value = buff;
                buff = 0;
                i++;
                for(;i<len;i++){
                    if(s[i] == ' '){
                        continue;
                    }
                    else if('0' <= s[i] && s[i] <= '9'){
                        buff = buff * 10 + s[i] - '0';
                    }
                    else{
                        i--;
                        break;
                    }
                }
                buff = last_value * buff;
            }
            else if(s[i] == '/'){
                last_value = buff;
                buff = 0;
                i++;
                for(;i<len;i++){
                    if(s[i] == ' '){
                        continue;
                    }
                    else if('0' <= s[i] && s[i] <= '9'){
                        buff = buff * 10 + s[i] - '0';
                    }
                    else{
                        i--;
                        break;
                    }
                }
                buff = last_value / buff;
            }
        }
        total = total + buff * sig;
        return total;
    }
};

int main(){
    Solution s;
    printf("%d\n", s.calculate("2147483647"));
    return 0;
}
