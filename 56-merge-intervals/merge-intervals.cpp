class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;

        for (int i = 0; i < intervals.size(); i++) {
            int s = intervals[i][0];
            int e = intervals[i][1];

            bool placed = false;

            for (int j = 0; j < merged.size(); j++) {

                int *ms = &merged[j][0];
                int *me = &merged[j][1];

                // No overlap and should be inserted before
                if (e < *ms) {
                    merged.insert(merged.begin() + j, {s, e});
                    placed = true;
                    break;
                }

                // Overlaps so merge
                if (!(e < *ms || s > *me)) {
                    *ms = min(*ms, s);
                    *me = max(*me, e);

                    // Now merge forward if needed
                    int k = j + 1;
                    while (k < merged.size() && merged[k][0] <= *me) {
                        *me = max(*me, merged[k][1]);
                        merged[j][1] = *me;
                        merged.erase(merged.begin() + k);
                    }

                    placed = true;
                    break;
                }
            }

            if (!placed) {
                merged.push_back({s, e});
            }
        }

        return merged;
    }
};