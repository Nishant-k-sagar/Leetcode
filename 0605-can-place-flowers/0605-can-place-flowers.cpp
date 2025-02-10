class Solution {
public:
    bool canPlaceFlowers(vector<int> &arr, int n) {
        int siz = arr.size();

        if (arr[0] == 1) {
            for (int i = 1; i < siz; i++) {
                if (arr[i] == 0 && arr[i - 1] == 0 && (i == siz - 1 || arr[i + 1] == 0)) {
                    arr[i] = 1;
                    n--;
                }
            }
        } else {
            if (siz == 1 || arr[1] == 0) {
                arr[0] = 1;
                n--;
            }
            for (int i = 1; i < siz; i++) {
                if (arr[i] == 0 && arr[i - 1] == 0 && (i == siz - 1 || arr[i + 1] == 0)) {
                    arr[i] = 1;
                    n--;
                }
            }
        }
        return n <= 0;
    }
};
