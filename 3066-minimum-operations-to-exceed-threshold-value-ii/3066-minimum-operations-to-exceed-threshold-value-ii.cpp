class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for (int x : nums)
            pq.push(x);

        int operations = 0;

        while (pq.top() < k) {
            long long x = pq.top(); pq.pop();
            long long y = pq.top(); pq.pop();

            pq.push(2 * min(x, y) + max(x, y));
            operations++;
        }

        return operations;
    }
};
