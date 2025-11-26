class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<string> contents;       
        vector<vector<string>> output;

        for (string& p : paths) {
            int n = p.size();
            int j = 0;

            while (j < n && p[j] != ' ')
                j++;
            string dir = p.substr(0, j);

            j++; 

            while (j < n) {
                int start_file = j;

                while (j < n && p[j] != '(')
                    j++;
                string filename = p.substr(start_file, j - start_file);

                j++; 
                int start_content = j;

                while (j < n && p[j] != ')')
                    j++;
                string file_content =
                    p.substr(start_content, j - start_content);

                j++; 

                string full = dir + "/" + filename;

                int idx = -1;
                for (int k = 0; k < (int)contents.size(); k++) {
                    if (contents[k] == file_content) {
                        idx = k;
                        break;
                    }
                }

                if (idx == -1) {
                    contents.push_back(file_content);
                    output.push_back({full});
                } else {
                    output[idx].push_back(full);
                }

                if (j < n && p[j] == ' ')
                    j++;
            }
        }

        vector<vector<string>> result;
        for (int l = 0; l < output.size(); l++) {
            if (output[l].size() > 1)
                result.push_back(output[l]);
        }

        return result;
    }
};
