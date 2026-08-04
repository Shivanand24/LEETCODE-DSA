class Solution {
public:
    int subtractProductAndSum(int n) {

        int sum =0;
        int pdt=1;

        while (n > 0){
            int a  = n % 10;
            sum += a;
            pdt *= a;
            n /= 10;



        }
        return pdt-sum;
        
    }
};