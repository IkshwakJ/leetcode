class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int length = image[0].size();
        int height = image.size();
        int temp;
        for(int i = 0; i<height; i++){
            for(int j =0; j<length/2; j++){
                temp = 1^image[i][j];
                image[i][j] = 1^image[i][length - 1 - j];
                image[i][length - 1 - j] = temp;
            }
            if(length%2 != 0){
                image[i][length/2] ^= 1; 
            }
        }
        return image;
    }
};