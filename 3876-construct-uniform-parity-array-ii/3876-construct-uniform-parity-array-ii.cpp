#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        if (n == 0) return true; 
        
        auto min_ptr = min_element(nums1.begin(), nums1.end());
        
        if (*min_ptr % 2 != 0) {
            return true;
        } 
        else {
            // If the minimum is even, all elements must be even
            int i = 0;
            while (i < n) {
                if (nums1[i] % 2 != 0) return false;
                i++;
            }
        }
        
        return true;
    }
};
