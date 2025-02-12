class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int len_1 = nums1.size();
        int len_2 = nums2.size();
        set<int> set_1 (nums1.begin(), nums1.end());
        set<int> set_2 (nums2.begin(), nums2.end());
        set<int> inter;
        set_intersection(set_1.begin(), set_1.end(), set_2.begin(), set_2.end(),
                     inserter(inter, inter.begin()));
        vector<int> result;
        for(int element: inter){
            result.push_back(element);
        }
        return result;
    }
};