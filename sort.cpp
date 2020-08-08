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

    void quick_sort2(vector<int>& nums){
        vector<pair<int, int>> stack;
        int len = nums.size();
        if(len < 2) return;
        stack.push_back({0, len-1});
        while(!stack.empty()){
            int left = stack.back().first;
            int right = stack.back().second;
            stack.pop_back();
            if(left >= right) continue;
            int tmp = nums[left];
            int i = left, j = right;
            while(i < j){
                while(i < j && nums[j] >= tmp) j--;
                if(i<j) nums[i++] = nums[j];
                while(i < j && nums[i] <= tmp) i++;
                if(i<j) nums[j--] = nums[i];
            }
            nums[j] = tmp;
            stack.push_back({left, j-1});
            stack.push_back({j+1, right});
        }
        return;
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

class MergeSort{
    public:
    //归并排序（自底向上）
    void sort(vector<int>& nums){
        int nlen = nums.size();
        int len = 1;
        int k = 0;
        while (len < nlen)  {  
            int i = 0;
            for (; i + 2*len <= nlen; i += 2*len){
                merge_array(nums, i, len, len); 
            }
            if (i + len <= nlen){  
                merge_array(nums, i, len, nlen-i-len);  
            }
            len *= 2;    //有序子序列长度*2  
        } 
    }

    //合并两个数组，并排序
    void merge_array(vector<int>& nums, int begin, int len1, int len2){
        //申请分配空间
        vector<int> list(len1+len2, 0);
        int i = begin, j = begin+len1, k = 0;
        while(i < begin+len1 && j < begin+len1+len2){
            // 把较小的那个数据放到结果数组里， 同时移动指针
            list[k++] = (nums[i] < nums[j]) ? nums[i++] : nums[j++];
        }
        // 如果 intArr1 还有元素，把剩下的数据直接放到结果数组
        while(i < len1){
            list[k++] = nums[i++];
        }
        // 如果 intArr2 还有元素，把剩下的数据直接放到结果数组
        while(j < len2){
            list[k++] = nums[j++];
        }
        // 把结果数组 copy 到 intArr1 里
        for(i = 0; i < k; i++){
            nums[i] = list[i];
        }
    }
};

int main(){
    
    return 0;
}