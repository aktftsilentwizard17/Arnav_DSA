class Solution {
public:
    int tos(string s){
        int h = stoi(s.substr(0,2));
        int m = stoi(s.substr(3,2));
        int sec = stoi(s.substr(6,2));
        return h*3600+m*60+sec;
    }

    int secondsBetweenTimes(string startTime, string endTime) {
        return tos(endTime) - tos(startTime);
    }
};