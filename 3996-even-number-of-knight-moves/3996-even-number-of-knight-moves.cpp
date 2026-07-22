class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        //odd number of moves change color, even number of moves results in same color hence same parity
        int sum1 = start[0]+target[0];
        int sum2 = start[1]+target[1];
        if(sum1%2==sum2%2){
            return true;
        }
        return false;
    }
};