class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0, j = n-1;
        while(i<j){
            int pairsum = numbers[i]+numbers[j];
            if(pairsum>target) j--;
            else if(pairsum<target) i++;
            else return {i+1,j+1};
        }
        return {};
    }
};