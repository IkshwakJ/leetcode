class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> result;
        vector<int>::iterator num1 = nums1.begin();
        vector<int>::iterator num2 = nums2.begin();
        while(num1 != nums1.end() && num2 != nums2.end()){
            if(*num1 != *num2){
                if(*num1 < *num2){
                    num1++;
                }
                else if(*num2 < *num1){
                    num2++;
                }
            }
            else{
                result.push_back(*num1);
                num1++;
                num2++;
            }
        }
        return result;
    }
};