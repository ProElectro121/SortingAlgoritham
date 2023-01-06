class Solution {
    private:
    void countSort(vector<int>& nums , int pos) {
        vector<int> count(10 , 0);
        vector<int> outputArray(nums.size() , 0);
        for(int i = 0; i < nums.size(); i++) {
            count[(nums[i]/pos) % 10 ]++;
        }
        for(int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        for(int i = nums.size() - 1; i >= 0; i--) {
            outputArray[count[(nums[i] / pos) % 10] - 1] = nums[i];
            count[(nums[i]/pos) % 10]--;
        }
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = outputArray[i];
        }
    }
    void radixSort(vector<int>& nums) {
        int mini = *min_element(nums.begin() , nums.end());
        for(int i = 0; i < nums.size(); i++) {
            nums[i] -= mini;
        }
        int maxi = *max_element(nums.begin() , nums.end());
  
        for(int pos = 1; maxi / pos > 0; pos *= 10) {
            countSort(nums , pos);
        }
        for(int i = 0; i < nums.size(); i++) {
            nums[i] += mini;
        }
    }
public:
    //Radix Sort algoritham
    vector<int> sortArray(vector<int>& nums) {

        vector<int> sortedArray = nums;
        radixSort(sortedArray);

        return sortedArray; 
    }
};
