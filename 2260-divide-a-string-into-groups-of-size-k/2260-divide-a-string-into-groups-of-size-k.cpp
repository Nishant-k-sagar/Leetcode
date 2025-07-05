class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int partitions = s.length() / k;
        int rem = s.length() % k;
        vector<string> ans;

        for (int i = 0; i < partitions; i++) {
            ans.push_back(s.substr(i * k, k));
        }

        if (rem) {
            string temp = s.substr(partitions * k);
            temp.append(k - rem, fill);
            ans.push_back(temp);
        }

        return ans;
    }
};
