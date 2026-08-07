#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    string smallestNumber(string num, long long t) {
        auto [primeCount, isDivisible] = getPrimeCount(t);
        if (!isDivisible) return "-1";

        auto factorCount = getFactorCount(primeCount);
        int minLenReq = sumValues(factorCount);
        
        if (minLenReq > num.length()) {
            return construct(factorCount, num.length() + 1);
        }

        auto primeCountPrefix = getPrimeCountStr(num);
        int firstZeroIndex = num.find('0');
        if (firstZeroIndex == string::npos) {
            firstZeroIndex = num.length();
            if (isSubset(primeCount, primeCountPrefix)) {
                return num; // num itself is already valid
            }
        }

        for (int i = num.length() - 1; i >= 0; --i) {
            int d = num[i] - '0';
            primeCountPrefix = subtract(primeCountPrefix, kFactorCounts[d]);
            int spaceAfterThisDigit = num.length() - 1 - i;
            
            if (i > firstZeroIndex) continue;

            for (int biggerDigit = d + 1; biggerDigit < 10; ++biggerDigit) {
                if (biggerDigit == 0) continue;
                auto remainingFactors = subtract(subtract(primeCount, primeCountPrefix), kFactorCounts[biggerDigit]);
                auto factorsAfterReplacement = getFactorCount(remainingFactors);
                
                if (sumValues(factorsAfterReplacement) <= spaceAfterThisDigit) {
                    int fillOnes = spaceAfterThisDigit - sumValues(factorsAfterReplacement);
                    return num.substr(0, i) + to_string(biggerDigit) + string(fillOnes, '1') + construct(factorsAfterReplacement, 0);
                }
            }
        }

        // If no solution of the same length exists, extend length by 1
        return construct(factorCount, num.length() + 1);
    }

private:
    const vector<unordered_map<int, int>> kFactorCounts = {
        {}, // 0
        {}, // 1
        {{2, 1}}, // 2
        {{3, 1}}, // 3
        {{2, 2}}, // 4
        {{5, 1}}, // 5
        {{2, 1}, {3, 1}}, // 6
        {{7, 1}}, // 7
        {{2, 3}}, // 8
        {{3, 2}}  // 9
    };

    pair<unordered_map<int, int>, bool> getPrimeCount(long long t) {
        unordered_map<int, int> count = {{2, 0}, {3, 0}, {5, 0}, {7, 0}};
        for (int prime : {2, 3, 5, 7}) {
            while (t % prime == 0) {
                t /= prime;
                count[prime]++;
            }
        }
        return {count, t == 1};
    }

    unordered_map<int, int> getPrimeCountStr(const string& s) {
        unordered_map<int, int> count = {{2, 0}, {3, 0}, {5, 0}, {7, 0}};
        for (char c : s) {
            if (c == '0') continue;
            int d = c - '0';
            for (auto& [prime, freq] : kFactorCounts[d]) {
                count[prime] += freq;
            }
        }
        return count;
    }

    unordered_map<int, int> getFactorCount(unordered_map<int, int> primeCount) {
        int r2 = primeCount[2], r3 = primeCount[3], r5 = primeCount[5], r7 = primeCount[7];
        
        int count9 = r3 / 2;
        r3 %= 2;
        int count8 = r2 / 3;
        r2 %= 3;
        
        int count6 = 0;
        if (r2 >= 1 && r3 >= 1) {
            r2 -= 1;
            r3 -= 1;
            count6 = 1;
        }
        
        int count4 = r2 / 2;
        r2 %= 2;
        int count3 = r3;
        int count2 = r2;
        int count5 = r5;
        int count7 = r7;

        unordered_map<int, int> res;
        if (count9) res[9] = count9;
        if (count8) res[8] = count8;
        if (count7) res[7] = count7;
        if (count6) res[6] = count6;
        if (count5) res[5] = count5;
        if (count4) res[4] = count4;
        if (count3) res[3] = count3;
        if (count2) res[2] = count2;
        return res;
    }

    int sumValues(const unordered_map<int, int>& m) {
        int sum = 0;
        for (auto& [k, v] : m) sum += v;
        return sum;
    }

    bool isSubset(const unordered_map<int, int>& req, const unordered_map<int, int>& actual) {
        for (auto& [prime, count] : req) {
            if (actual.at(prime) < count) return false;
        }
        return true;
    }

    unordered_map<int, int> subtract(unordered_map<int, int> a, const unordered_map<int, int>& b) {
        for (auto& [prime, count] : b) {
            a[prime] -= count;
            if (a[prime] < 0) a[prime] = 0;
        }
        return a;
    }

    string construct(unordered_map<int, int> factorCount, int targetLen) {
        vector<int> digits;
        for (int d : {9, 8, 7, 6, 5, 4, 3, 2}) {
            if (factorCount.count(d)) {
                digits.insert(digits.end(), factorCount[d], d);
            }
        }
        string res = "";
        for (int d : digits) res += to_string(d);
        
        if (targetLen > 0 && res.length() < targetLen) {
            res = string(targetLen - res.length(), '1') + res;
        }
        sort(res.begin(), res.end());
        return res;
    }
};