class Solution {
public:
    bool KMPSearch(vector<int>& vec1, vector<int>& text) {
        int n = text.size(), m = vec1.size();
        if (m == 0) return true;
        if (m > n) return false;

        vector<int> lps(m, 0);
        for (int i = 1, len = 0; i < m; ) {
            if (vec1[i] == vec1[len]) lps[i++] = ++len;
            else if (len) len = lps[len - 1];
            else lps[i++] = 0;
        }

        for (int i = 0, j = 0; i < n; ) {
            if (text[i] == vec1[j]) {
                i++; j++;
                if (j == m) return true;
            } else if (j) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
        return false;
    }

    bool isRotatable(vector<int>& vec1, vector<int>& vec2) {
        vector<int> text = vec2;
        text.insert(text.end(), vec2.begin(), vec2.end());
        return KMPSearch(vec1, text);
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        int result = 0;

        for (int k = 1; k <= n; k++) {              // was k = 0, k < n
            if (n % k != 0) continue;

            bool valid = true;                      // declared in loop scope
            for (int start = 0; start < n; start += k) {
                vector<int> vec1(nums.begin() + start, nums.begin() + start + k);
                vector<int> vec2(sorted.begin() + start, sorted.begin() + start + k);
                if (!isRotatable(vec1, vec2)) {
                    valid = false;
                    break;
                }
            }
            if (valid) result += k;
        }
        return result;
    }
};