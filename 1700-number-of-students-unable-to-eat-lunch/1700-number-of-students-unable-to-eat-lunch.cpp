class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        int n = students.size();
        for(int i=0;i<n;i++){
            q.push(students[i]);
        }

        stack<int> st;
        for(int i=n-1;i>=0;i--){
            st.push(sandwiches[i]);
        }

        int rotations=0;
        while(!st.empty()&&rotations<q.size()){
            if(st.top()==q.front()){
                st.pop();
                q.pop();
                rotations=0;
            }
            else{
                int val = q.front();
                q.pop();
                q.push(val);
                rotations++;
            }
        }

        return q.size();
    }
};