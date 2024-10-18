class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans;
        ans.push_back({1});
         for(int i=1;i<=rowIndex;i++)
        {
            vector<int>v(i+1);
            v[0]=1;
            v[i]=1;
            for(int j=1;j<i;j++)
            {
                v[j]=ans[i-1][j-1]+ans[i-1][j];
            }
            ans.push_back(v);
        }
        return ans[rowIndex];
    }
};