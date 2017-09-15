class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = 0;
        if (nums.size() > 0) size = 1;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] != nums[size - 1]){
                nums[size] = nums[i];
                size++;
            }
        }
        return size;
    }
};