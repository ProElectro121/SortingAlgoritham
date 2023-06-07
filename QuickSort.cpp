/*
 TIme complexity --> O(nlog(n)
 worst case --> O(n*n)
 
 space compexity --> O(1) but there is a recurrsion stack space
*/ 

class Solution {
private:
    int helper(vector<int>& nums , int low , int high) {
        int i = low , j = high;
        int ele = nums[low];
        while(i < j) {
            while(i < high and nums[i] <= ele) {
                i++;
            }
            while(j > low and nums[j] > ele) {
                j--;
            }
            if(i < j) swap(nums[i] , nums[j]);
        }
        swap(nums[low] , nums[j]);
        return j;
    }
    void sortNums(vector<int>& nums , int low , int high) {
        if(low < high) {
            int partitionIndex = helper(nums , low , high);
            sortNums(nums, low , partitionIndex - 1);
            sortNums(nums , partitionIndex + 1 , high);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        sortNums(nums , 0 , n - 1);
        return nums;
    }
};
