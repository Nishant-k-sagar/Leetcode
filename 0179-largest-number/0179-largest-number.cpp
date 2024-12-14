class Solution {
public:
    static bool comp(string &a, string &b){
        return a+b>b+a;
    }
public:
    string largestNumber(vector<int>& nums) {
        vector<string> nstr;

        for(int it: nums){
            nstr.push_back(to_string(it));
        }

        sort(nstr.begin(), nstr.end(), comp);

        if(nstr[0]=="0")return "0";

        string ans;

        for(auto it: nstr){
            ans+=it;
        }

        return ans;
    }
};