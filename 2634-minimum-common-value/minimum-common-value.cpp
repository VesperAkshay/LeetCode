
#include <vector>
#include <unordered_set>

class Solution {
public:
    int getCommon(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_set<int> set(nums1.begin(), nums1.end());
        
        for (int num : nums2) {
            if (set.count(num) > 0) {
                return num;
            }
        }
        
        return -1;
    }
};
