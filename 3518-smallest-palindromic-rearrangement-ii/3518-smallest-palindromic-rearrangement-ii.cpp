#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Globally precompute combination values safely to avoid TLE on multiple testcases.
static vector<vector<int>> C;
static bool initialized = false;

void init_combinations() {
    if (initialized) return;
    
    // Max length of `half` is 5000 (since max string length is 10000).
    C.resize(5005);
    for (int i = 0; i <= 5000; ++i) {
        C[i].resize(i + 1, 1);
        for (int j = 1; j < i; ++j) {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
            // Cap at 1,000,001 because k is bounded at 10^6.
            // This prevents long long overflows during multinomial calculations.
            if (C[i][j] > 1000000) {
                C[i][j] = 1000001; 
            }
        }
    }
    initialized = true;
}

class Solution {
private:
    long long get_perms(const vector<int>& freqs) {
        long long ways = 1;
        int rem = 0;
        for (int f : freqs) {
            if (f > 0) {
                rem += f;
                ways *= C[rem][f];
                if (ways > 1000000) {
                    ways = 1000001; // Maintain the cap
                }
            }
        }
        return ways;
    }

public:
    string smallestPalindrome(string s, int k) {
        init_combinations();
        
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        
        vector<int> freq(26, 0);
        char mid = 0;
        int half_len = 0;
        
        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2 != 0) {
                mid = i + 'a';
            }
            freq[i] = count[i] / 2;
            half_len += freq[i];
        }
        
        // If the k-th permutation doesn't exist
        long long total_perms = get_perms(freq);
        if (k > total_perms) {
            return "";
        }
        
        string half = "";
        // Build the lexicographically smallest half piece-by-piece
        for (int i = 0; i < half_len; ++i) {
            for (int c = 0; c < 26; ++c) {
                if (freq[c] > 0) {
                    // Try placing character 'c'
                    freq[c]--;
                    long long ways = get_perms(freq);
                    
                    if (k <= ways) {
                        // The k-th permutation is within this branch
                        half += (char)(c + 'a');
                        break; 
                    } else {
                        // Skip these permutations and search the next character
                        k -= ways;
                        freq[c]++; // Backtrack
                    }
                }
            }
        }
        
        // Reconstruct the full palindrome string
        string result = half;
        if (mid != 0) {
            result += mid;
        }
        reverse(half.begin(), half.end());
        result += half;
        
        return result;
    }
};