class Solution {
public:
    long long countCommas(long long n) {
        long long total = 0;
        
        long long lower = 1000;
        int commas = 1;
        
        while (lower <= n) {
            long long upper = lower * 1000 - 1;
            
            long long count = min(upper, n) - lower + 1;
            
            total += count * commas;
            
            lower *= 1000;
            commas++;
        }
        
        return total;
    }
};