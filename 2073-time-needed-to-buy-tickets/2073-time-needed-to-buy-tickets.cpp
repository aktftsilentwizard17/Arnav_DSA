class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>> q;
        int totaltime = 0;
        for(int i=0;i<tickets.size();i++){
            q.push({i,tickets[i]});
        }
        while(!q.empty()){
            auto [index,remaining] = q.front();
            q.pop();

            remaining--;
            totaltime++;

            if(index==k&&remaining==0){
                return totaltime;
            }

            if(remaining>0){
                q.push({index,remaining});
            }
        }
        return totaltime;
    }
};