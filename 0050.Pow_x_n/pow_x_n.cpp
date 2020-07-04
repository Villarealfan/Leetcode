#include "../include/tools.h"

class Solution {
public:
    double myPow(double x, int n) {
        if (n >= 0){
            return power(x, n);
        }
        else{
            return 1.0/power(x,n);
        }
    }

private:
    double power(double x, int n){
        if (n == 0) return 1.0;
        double y = power(x, n/2);
        if (n %2 == 0){
            return y*y;
        }
        else{
            return y*y*x;
        }
    }
};

int main(){
    Solution so;

    double x;
    int n;
    cout << "输入 x:" << endl;
    cin >> x;

    cout << "输入 n:" << endl;
    cin >> n;
    double output = so.myPow(x, n);
    cout << output << endl;
    return 0;
}
