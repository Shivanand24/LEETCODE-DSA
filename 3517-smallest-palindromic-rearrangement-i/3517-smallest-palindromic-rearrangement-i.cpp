class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string firstHalf = "";
        char middle = '\0';

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1)
                middle = char(i + 'a');

            firstHalf.append(freq[i] / 2, char(i + 'a'));
        }

        string secondHalf = firstHalf;
        reverse(secondHalf.begin(), secondHalf.end());

        if (middle != '\0')
            return firstHalf + middle + secondHalf;

        return firstHalf + secondHalf;
    }
};