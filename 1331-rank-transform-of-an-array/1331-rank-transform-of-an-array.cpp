class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> myarr;
        unordered_map<int,int> mymap;
        for(int num:arr){
            if(!mymap.count(num)){
                myarr.push_back(num);
                mymap[num]=0;
            }
        }
        sort(myarr.begin(),myarr.end());
        for(int i=0;i<myarr.size();i++){
            mymap[myarr[i]]=i+1;
        }
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = mymap[arr[i]];
        }       
        return arr;
    }
};