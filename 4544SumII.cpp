# include <iostream>
# include <vector>
# include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int len = A.size();
        if(len == 0) return 0;
        unordered_map<int, int> mapAB;
        int sum = 0;
        for(int i: A){
            for(int j: B){
                sum = i + j;
                if(mapAB.find(sum) == mapAB.end())
                    mapAB[sum] = 1;
                else
                    mapAB[sum]++;
            }
        }
        int count = 0;
        for(int i: C){
            for(int j: D){
                sum = -(i+j);
                if(mapAB.find(sum) != mapAB.end()){
                    count = count + mapAB[sum];
                }
            }
        }
        return count;
    }
};

int main(){
    Solution s;
    vector<int> A = {-1, -1};
    vector<int> B = {-1, 1};
    vector<int> C = {-1, 1};
    vector<int> D = {1, -1};
    cout << s.fourSumCount(A, B, C, D) << endl;
    return 0;
}
