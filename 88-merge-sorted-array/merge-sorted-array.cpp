class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = 0;
        for(int i = 0; i<m; i++){
            while(j<n && nums2[j]<nums1[i]){
                m++;
                for(int k = m-1; k>i; k--){
                    nums1[k] = nums1[k-1];
                }
                nums1[i] = nums2[j];
                j++;
            }
        }
        while(j<n){
            nums1[m] = nums2[j];
            m++;
            j++;
        }
    }
};