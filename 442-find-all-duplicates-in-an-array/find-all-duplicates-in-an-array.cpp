class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> duplicates;

        for (int num : nums) {
            int index = abs(num) - 1;
            if (nums[index] < 0) {
                duplicates.push_back(abs(num));
            } else {
                nums[index] *= -1;
            }
        }

        for (int& num : nums) {
            num = abs(num);
        }

        return duplicates;
    }
};
