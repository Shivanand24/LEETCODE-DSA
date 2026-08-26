#include <string>
#include <algorithm>
#include <climits>

class Solution {
public:
    std::string shortestBeautifulSubstring(std::string s, int k) {
        int n = s.length();
        int min_len = INT_MAX;
        std::string result = "";
        
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = i; j < n; ++j) {
                if (s[j] == '1') {
                    count++;
                }
                
                // If the substring has exactly k ones
                if (count == k) {
                    int curr_len = j - i + 1;
                    std::string sub = s.substr(i, curr_len);
                    
                    // Update result if it's shorter, or lexicographically smaller for the same length
                    if (curr_len < min_len) {
                        min_len = curr_len;
                        result = sub;
                    } else if (curr_len == min_len) {
                        if (sub < result) {
                            result = sub;
                        }
                    }
                } 
                // Since count exceeds k, extending further will not help for this starting index i
                else if (count > k) {
                    break;
                }
            }
        }
        
        return result;
    }
};