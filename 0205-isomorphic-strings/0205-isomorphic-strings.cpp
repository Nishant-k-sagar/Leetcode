class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> IndexS;
        unordered_map<char, int> IndexT;

        for(int i=0; i<s.length(); i++){
            if(IndexS.find(s[i]) == IndexS.end()){
                IndexS[s[i]] = i;
            }

            if(IndexT.find(t[i]) == IndexT.end()){
                IndexT[t[i]] = i;
            }

            if(IndexS[s[i]]!=IndexT[t[i]]){
                return false;
            }

        }
        return true;
    }
};