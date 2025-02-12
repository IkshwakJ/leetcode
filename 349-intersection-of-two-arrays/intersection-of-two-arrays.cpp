class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int len_1 = nums1.size();
        int len_2 = nums2.size();
        vector<int> result;
        unordered_map<int,int> mp;
        for(int j = 0; j<len_2; j++){
            if(mp[nums2[j]]<1){
                mp[nums2[j]]++;
            }
        } 
        for(int i = 0; i<len_1; i++){
            if(mp[nums1[i]]>0){
                mp[nums1[i]]++;
            }
        }
        for(auto iter = mp.begin(); iter != mp.end(); iter++){
            if(iter->second>1){
                result.push_back(iter->first);
            }
        }
        return result;
    }
};