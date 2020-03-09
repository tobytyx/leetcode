#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int len = numbers.size();
        if(len == 0) return 0;
        while(numbers.size() > 1 && numbers[0] == numbers.back()){
            numbers.pop_back();
        }
        len = numbers.size();
        if(len == 1) return numbers[0];
        int left = 0, right = len-1;
        while(left < right && numbers[left] > numbers[right]){
            int mid = (left + right) / 2;
            if(numbers[left] <= numbers[mid]){ // 逆序在右边
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        return numbers[right] < numbers[left] ? numbers[right] : numbers[left];
    }
};