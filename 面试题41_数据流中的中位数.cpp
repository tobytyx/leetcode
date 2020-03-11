#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    multiset<int, greater<int> > gheap;
    multiset<int, less<int> > lheap;
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(((gheap.size() + lheap.size()) & 1) == 0){
            if(lheap.empty()) gheap.insert(num);
            else{
                int lnum = *lheap.begin();
                if(num < lnum) gheap.insert(num);
                else{
                    gheap.insert(lnum);
                    lheap.erase(lheap.begin());
                    lheap.insert(num);
                }
            } 
        }
        else{
            int gnum = *gheap.begin();
            if(num > gnum) lheap.insert(num);
            else{
                lheap.insert(gnum);
                gheap.erase(gheap.begin());
                gheap.insert(num);
            }
        }
    }
    
    double findMedian() {
        if(((lheap.size() + gheap.size()) & 1) == 1){
            return double(*gheap.begin());
        }
        if(gheap.empty() && lheap.empty()) return 0.0;
        return (*gheap.begin() + *lheap.begin()) / 2.0;
    }
};
