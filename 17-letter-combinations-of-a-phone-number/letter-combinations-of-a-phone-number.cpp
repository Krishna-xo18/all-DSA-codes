class Solution {
public:
    void generateCombinations(int len, vector<string>& result, vector<string>& mappings, int index, string current) {
        if (index == len) {
            if (current.size() == len) {
                result.push_back(current);
            }
            return;
        }
        
        for (int i = 0; i < mappings[index].size(); i++) {
            current.push_back(mappings[index][i]);
            generateCombinations(len, result, mappings, index + 1, current);
            current.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        int len = digits.size();
        vector<string> result;
        if (len == 0) {
            return result;
        }
        
        vector<string> mappings = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> temp;
        for (int i = 0; i < len; i++) {
            int digit = digits[i] - '0';
            temp.push_back(mappings[digit]);
        }
        
        string current;
        generateCombinations(len, result, temp, 0, current);
        return result;
    }
    };