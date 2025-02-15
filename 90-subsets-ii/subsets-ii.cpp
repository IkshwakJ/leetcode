class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> result_set;
        int len = nums.size();
        for(int i = 0; i < (1<<len); i++){
            vector<int> row;
            for(int j = 0; j < len; j++){
                if(i&(1<<j)){
                    row.push_back(nums[j]);
                }
            }
            if(row.size()){
                sort_vector(row, 0, row.size() - 1);
            }
            result_set.insert(row);
        }
        vector<vector<int>> result(result_set.begin(), result_set.end());
        return result;
    }
private:
    void sort_vector(vector<int>& nums, int low, int high){
        if(low < high){
            int piv = partition(nums,low,high);
            sort_vector(nums, low, piv - 1);
            sort_vector(nums, piv + 1, high);
        }
    }
    int partition(vector<int>& nums, int low, int high){
        int pivot = nums[high];
        int i = low;
        for(int j = low; j < high; j++){
            if(nums[j] <= pivot){
                swap(nums[j], nums[i]);
                i++;
            }
        }
        swap(nums[i], nums[high]);
        return i;
    }
};