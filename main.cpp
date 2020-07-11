#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include "TBigNum.h"

using namespace std;

void sumTest();

int main()
{;
    mt19937_64 eng(time(nullptr));
    uniform_int_distribution<unsigned int> distr;
    int n = 2;
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        int a1 = distr(eng), b1 = distr(eng), c1 = distr(eng);
        TBigNum a2, b2, c2;
        a2.setNum(a1), b2.setNum(b1), c2.setNum(c1);
        cout << a1 << " + " << b1 << " - " << c1 << " = " << (long long) a1 + b1 - c1
             << " // Calculated in long long int numbers" << endl;

        cout << a2.toDecimalString() << " + " << b2.toDecimalString() << " - " << c2.toDecimalString()
             << " = " << (a2 + b2 - c2).toDecimalString() << " // Calculated in TBigNum objects" << endl;
        cout << endl;
    }
    cout << endl;
    auto lv = (TBigNum) "123456789101112131415161718192021222324252627282930";
    auto rv = (TBigNum) "-987654321123456789";
    string ans = "123456789101112131415161718192020234669931503826141"; // Calculated in Python
    cout << lv.toDecimalString() << " + " << rv.toDecimalString() << endl << "  =" << endl;
    lv += rv;
    cout << ans << " // Calculated in Python" << endl;
    cout << lv.toDecimalString() << " // Calculated in TBigNum objects" << endl;
    cout << endl << endl;
    sumTest();
    return 0;
}

void sumTest()
{
    std::mt19937_64 eng(time(nullptr));
    std::uniform_int_distribution<unsigned int> distr;
    TBigNum sum;
    int n = 9;
    int rand_val = distr(eng);
    long long ll_sum = rand_val;
    sum.setNum(rand_val);
    cout << rand_val;
    for (int i = 0; i < n - 1; i++)
    {
        rand_val = distr(eng);
        TBigNum rand_val1;
        rand_val1.setNum(rand_val);
        if (i % 2 == 0)
        {
            ll_sum += rand_val;
            sum += rand_val1;
            cout << " + " << rand_val;
        }
        else
        {
            ll_sum -= rand_val;
            sum -= rand_val1;
            cout << " - " << rand_val;
        }
    }
    cout << endl << "  =" << endl;
    cout << ll_sum << " // Calculated in a long long int counter" << endl;
    cout << sum.toDecimalString() << " // Calculated in a TBigNum counter" << endl;

}