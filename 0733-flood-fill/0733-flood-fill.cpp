class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color) {
        int iniColor = img[sr][sc];

        if(iniColor != color){
            dfs(img, sr, sc, color, iniColor);
        }
        return img;
    }


    public:
    void dfs(vector<vector<int> > &img, int r, int c, int color, int iniColor){
        if(img[r][c] == iniColor){
            img[r][c] = color;

            if(r>=1){
                dfs(img, r-1, c, color, iniColor);
            }
            if(c>=1){
                dfs(img, r, c-1, color, iniColor);
            }
            if(r+1< img.size()){
                dfs(img, r+1, c, color, iniColor);
            }
            if(c+1< img[0].size()){
                dfs(img, r, c+1,color, iniColor);
            }
        }
    }

};