# include <iostream>
# include <vector>
# include <unordered_map>
# include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for(auto s: strs){
            string sort_s = strSort(s);
            if(map.find(sort_s) == map.end()){
                map[sort_s] = vector<string>(1, s);
            }
            else{
                map[sort_s].push_back(s);
            }
        }
        vector<vector<string>> res;
        for(auto iter: map){
            res.push_back(iter.second);
        }
        return res;
    }
    string strSort(string& s){
        int a[26] = {0};
        for(char c: s){
            a[c-'a']++;
        }
        string new_s;
        for(int i=0; i<26; i++){
            while(a[i] > 0){
                new_s.push_back('a'+i);
                a[i]--;
            }
        }
        return new_s;
    }
};

int main(){
    Solution s;
    return 0;
}
