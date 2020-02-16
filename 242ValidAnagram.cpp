# include <iostream>
# include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_hash[26] = {0};
        hashString(s_hash, s);
        for(char c: t){
            s_hash[c-'a']--;
        }
        for(int i=0; i<26; i++){
            if(s_hash[i] != 0) return false;
        }
        return true;
    }

    void hashString(int (&a)[26], string s){
        for(char c: s){
            a[c-'a']++;
        }
    }
};


int main(){
    Solution s;
    cout << s.isAnagram("cat", "at") << endl;
    return 0;
}
