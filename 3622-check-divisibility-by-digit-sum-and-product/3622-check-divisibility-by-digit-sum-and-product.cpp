class Solution {
public:
    bool checkDivisibility(int n) {
        int digitSum = 0, digitProd = 1;
        int temp = n;

        while (temp > 0) {
            int d = temp % 10;
            digitSum  += d;
            digitProd *= d;
            temp /= 10;
        }

        return n % (digitSum + digitProd) == 0;
    }
};