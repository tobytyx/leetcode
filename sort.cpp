#include<bits/stdc++.h>
using namespace std;

// 排序
struct tmp1{
    int x;
    tmp1(int a){x=a;}
};

struct tmp2{
    bool operator() (tmp1 x, tmp1 y){
        return x.x > y.x;
    }
};

class QuickSort{
    public:
    void sort(vector<int>& nums){
        if(nums.size() < 2) return;
        quick_sort(nums, 0, nums.size()-1);
    }

    void quick_sort(vector<int>& nums, int left, int right){
        if(left >= right) return;
        int i = left, j = right, tmp=nums[left];
        while(i<j){
            while(i<j && nums[j] >= tmp)j--;
            if(i<j) nums[i++] = nums[j];
            while(i<j && nums[i] <= tmp)i++;
            if(i<j) nums[j--] = nums[i];
        }
        nums[j] = tmp;
        quick_sort(nums, left, j-1);
        quick_sort(nums, j+1, right);
    }
};

class HeapSort{
    public:
    void sort(vector<int>& nums){
        int len = nums.size();
        if(len < 2) return;
        // 构建大根堆
        for(int i=len/2-1; i>=0; i--){
            adjust(nums, len, i);
        }
        for(int i=len-1; i>0; i--){
            swap(nums[i], nums[0]);
            adjust(nums, i, 0);
        }
    }

    void adjust(vector<int>& nums, int len, int index){
        int left = 2*index+1;
        int right = 2*index+2;
        int maxIn = index;
        if(left < len && nums[left]>nums[maxIn]) maxIn = left;
        if(right < len && nums[right]>nums[maxIn]) maxIn = right;
        if(maxIn != index){
            swap(nums[maxIn], nums[index]);
            adjust(nums, len, maxIn);
        }
    }
};


int main(){
    vector<int> nums = {1,3,4,5,6,8,7};
    HeapSort hs;
    QuickSort qs;
    qs.sort(nums);
    for(int i: nums) printf("%d ", i);
    printf("\n");
    return 0;
}