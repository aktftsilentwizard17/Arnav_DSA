class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for (int i = 0; i < asteroids.size(); i++) {
            bool destroyed = false;
            while (!st.empty() && st.back() > 0 && asteroids[i] < 0) {
                if (st.back() < abs(asteroids[i])) {
                    st.pop_back(); // Top asteroid explodes, continue checking against next in stack
                    continue;
                } else if (st.back() == abs(asteroids[i])) {
                    st.pop_back(); // Both asteroids explode
                }
                destroyed = true; // Current asteroid explodes
                break;
            }
            if (!destroyed) {
                st.push_back(asteroids[i]);
            }
        }
        return st;
    }
};