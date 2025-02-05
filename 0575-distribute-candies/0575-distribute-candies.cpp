class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();

        int eatOnly = (n/2);
        set<int> diffTypes(candyType.begin(), candyType.end());
        
        int numDiffTypes = diffTypes.size();

        if(eatOnly<numDiffTypes)return eatOnly;
        else return numDiffTypes;
    }
};