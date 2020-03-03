#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(m == 0){
            return (nums2[(n-1)/2] + nums2[n/2])/2.0;
        }
        if(n == 0){
            return (nums1[(m-1)/2] + nums1[m/2])/2.0;
        }
        vector<int> &A = m > n ? nums2 : nums1;
        vector<int> &B = m <= n ? nums2 : nums1;
        m = A.size(), n = B.size();
        int imin = 0, imax = m, half=(m+n+1)/2;
        while(imin <= imax){
            int i=(imin+imax)/2;
            int j=half-i;
            if(i < m && B[j-1] > A[i]){
                imin = i + 1;
            }
            else if(i > 0 && A[i-1] > B[j]){
                imax = i - 1;
            }
            else{
                int max_left = 0;
                if(i==0) max_left = B[j-1];
                else if(j==0) max_left = A[i-1];
                else{
                    max_left = A[i-1] > B[j-1] ? A[i-1]: B[j-1];
                }
                if((m+n)%2 == 1) return max_left;
                
                int min_right = 0;
                if(i==m) min_right = B[j];
                else if(j==n) min_right = A[i];
                else{
                    min_right = A[i] > B[j] ? B[j] : A[i];
                }
                return (max_left + min_right) / 2.0;
            }
        }
        return 0.0;
    }
};

int main(){
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};
    Solution s;
    printf("%lf\n", s.findMedianSortedArrays(nums1, nums2));
    return 0;
}