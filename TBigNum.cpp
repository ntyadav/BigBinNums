#include "TBigNum.h"
#include <algorithm>
#include <new>
#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;

TBigNum::TBigNum(size_t num_size) : f_pnum(nullptr), f_size(0)
{
    if (!resize(num_size))
        cerr << "Failed to allocate memory when creating TBigNum object!" << endl;
}

TBigNum::TBigNum(const TBigNum& other) : f_pnum(nullptr), f_size(0)
{
    if (!resize(other.f_size))
    {
        cerr << "Failed to allocate memory when creating TBigNum object!" << endl;
        return;
    }
    for (int i = 0; i < f_size; i++)
        f_pnum[i] = other.f_pnum[i];
}

/**
 * Converts str to a number using long division algorithm (conversion to 256-digit number system)
 */
TBigNum::TBigNum(std::string str) : f_pnum(nullptr), f_size(0)
{
    bool isNumNegative = false;
    if (str[0] == '-')
    {
        isNumNegative = true;
        str = str.substr(1);
    }
    for (auto symbol : str)
    {
        int digit = symbol - '0';
        if (digit < 0 || digit > 9)
            throw invalid_argument("Failed to convert string to number");
    }
    const int base = 10, div = 256;
    vector<unsigned char> res(0);
    while (!str.empty())
    {
        int carry = 0;
        int carry_num = 0;
        string quotient;
        for (auto digit : str)
        {
            carry *= base;
            carry += digit - '0';
            carry_num++;
            if (carry >= div)
            {
                carry_num = 0;
                quotient += to_string(carry / div);
                carry %= div;
            }
            if (carry_num > 0 && !quotient.empty())
                quotient += '0';
        }
        res.push_back(carry);
        str = quotient;
    }
    if (!isNegative() && res.back() >= 128)
        res.push_back(0);
    reverse(res.begin(), res.end());
    resize(res.size());
    for (int i = 0; i < f_size; i++)
        f_pnum[i] = res[i];
    if (isNumNegative)
        *this = -*this;
}

/**
 * Converts the number to a string using long
 * division algorithm (conversion from 256-digit number system to decimal)
 */
std::string TBigNum::toDecimalString() const
{
    const int base = 256, div = 10;
    TBigNum copy(*this);
    if (isNegative())
        copy = -copy;
    vector<unsigned char> num(copy.f_pnum, copy.f_pnum + copy.f_size);
    string res;
    while (!num.empty())
    {
        int carry = 0;
        int carry_num = 0;
        vector<unsigned char> quotient(0);
        for (auto digit : num)
        {
            carry *= base;
            carry += digit;
            carry_num++;
            if (carry >= div)
            {
                carry_num = 0;
                quotient.push_back(carry / div);
                carry %= div;
            }
            if (carry_num > 0 && !quotient.empty())
                quotient.push_back(0);
        }
        res += to_string(carry);
        swap(num, quotient);
    }
    if (isNegative())
        res += '-';
    reverse(res.begin(), res.end());
    return res;
}

bool TBigNum::setNum(int num)
{
    const size_t int_size = 4;
    union Cast
    {
        int num;
        unsigned char num_arr[int_size];
    } cast = {num};
    if (!resize(int_size))
        return false;
    for (int i = 0; i < int_size; i++)
        f_pnum[i] = cast.num_arr[int_size - i - 1];
    return true;
}


bool TBigNum::setNum(unsigned int num)
{
    const size_t uint_size = 4;
    union Cast
    {
        unsigned int num;
        unsigned char num_arr[uint_size];
    } cast = {num};
    bool isFirstBitOne = cast.num_arr[uint_size - 1] >= 128;
    if (!resize(uint_size + isFirstBitOne))
        return false;
    for (int i = 0; i < uint_size; i++)
        f_pnum[i + isFirstBitOne] = cast.num_arr[uint_size - i - 1];
    if (isFirstBitOne)
        f_pnum[0] = 0;
    return true;
}

bool TBigNum::setNum(long int num)
{
    return setNum((int) num);
}

bool TBigNum::setNum(unsigned long int num)
{
    return setNum((unsigned int) num);
}

bool TBigNum::setNum(long long int num)
{
    const size_t ll_size = 8;
    union Cast
    {
        long long num;
        unsigned char num_arr[ll_size];
    } cast = {num};
    if (!resize(ll_size))
        return false;
    for (int i = 0; i < ll_size; i++)
        f_pnum[i] = cast.num_arr[ll_size - i - 1];
    return true;
}


bool TBigNum::setNum(unsigned long long int num)
{
    const size_t ull_size = 8;
    union Cast
    {
        unsigned long long num;
        unsigned char num_arr[ull_size];
    } cast = {num};
    bool isFirstBitOne = cast.num_arr[ull_size - 1] >= 128;
    if (!resize(ull_size + isFirstBitOne))
        return false;
    for (int i = 0; i < ull_size; i++)
        f_pnum[i + isFirstBitOne] = cast.num_arr[ull_size - i - 1];
    if (isFirstBitOne)
        f_pnum[0] = 0;
    return true;
}

bool TBigNum::setNum(char num)
{
    if (!resize(1))
        return false;
    f_pnum[0] = num;
    return true;
}


bool TBigNum::setNum(unsigned char num)
{
    bool isFirstBitOne = num >= 128;
    if (!resize(1 + isFirstBitOne))
        return false;
    f_pnum[isFirstBitOne] = num;
    if (isFirstBitOne)
        f_pnum[0] = 0;
    return true;
}

void TBigNum::minimize()
{
    unsigned char extra_byte = isNegative() ? 255 : 0;
    int k = 0;
    while (k + 1 < f_size)
    {
        if (extra_byte == f_pnum[k] && (isNegative() ? f_pnum[k + 1] >= 128 : f_pnum[k + 1] < 128))
            k++;
        else
            break;
    }
    if (k == 0)
        return;
    auto *new_arr = new(nothrow) unsigned char[f_size - k];
    if (!new_arr)
        return;
    size_t new_size = f_size - k;
    for (int i = 0; i < new_size; i++)
        new_arr[i] = f_pnum[i + k];
    delete[] f_pnum;
    f_pnum = new_arr;
    f_size = new_size;
}

void TBigNum::printDataArray(bool hex) const
{
    if (hex)
    {
        for (int i = 0; i < f_size; i++)
        {
            char digit1 = f_pnum[i] / 16;
            char digit2 = f_pnum[i] % 16;
            if (digit1 > 9)
                digit1 = 'A' + digit1 - 10;
            else
                digit1 = '0' + digit1;
            if (digit2 > 9)
                digit2 = 'A' + digit2 - 10;
            else
                digit2 = '0' + digit2;
            cout << (digit1 != '0' ? string(1, digit1) : "") << digit2 << " ";;
        }
    }
    else
    {
        for (int i = 0; i < f_size; i++)
            cout << std::to_string((int) f_pnum[i]) << " ";
    }
    cout << '\n';
}


bool TBigNum::resize(size_t new_size)
{
    if (f_size == new_size)
        return true;
    delete[] f_pnum;
    f_size = 0;
    f_pnum = new(nothrow) unsigned char[new_size];
    if (!f_pnum)
        return false;
    f_size = new_size;
    return true;
}

TBigNum& TBigNum::operator=(const TBigNum& rhs)
{
    if (!resize(rhs.f_size))
    {
        cerr << "Failed to allocate memory when assigning TBigNum objects!" << endl;
        return *this;
    }
    for (int i = 0; i < f_size; i++)
        f_pnum[i] = rhs.f_pnum[i];
    return *this;
}


TBigNum TBigNum::operator+() const
{
    return TBigNum(*this);
}

TBigNum TBigNum::operator-() const
{
    const int base = 256;
    auto res = TBigNum(*this);
    if (isNegative())
    {
        for (int i = res.f_size - 1; i >= 0; i--)
        {
            if (res.f_pnum[i] > 0)
            {
                res.f_pnum[i] -= 1;
                break;
            }
            res.f_pnum[i] -= 1;
        }
        for (int i = 0; i < res.f_size; i++)
            res.f_pnum[i] = ~res.f_pnum[i];
    }
    else
    {
        for (int i = 0; i < res.f_size; i++)
            res.f_pnum[i] = ~res.f_pnum[i];
        for (int i = res.f_size - 1; i >= 0; i--)
        {
            if (res.f_pnum[i] < base - 1)
            {
                res.f_pnum[i] += 1;
                break;
            }
            res.f_pnum[i] += 1;
        }
    }
    return res;
}

/**
 * The numbers are added in a 256-decimal number system (the algorithm of column addition is used)
 * Calls the minimize method at the end
 */
void TBigNum::operator+=(const TBigNum& rhs)
{
    const int base = 256;
    bool isLhsNegative = isNegative(), isRhsNegative = rhs.isNegative();
    vector<unsigned char> res_arr(f_pnum, f_pnum + f_size);
    reverse(res_arr.begin(), res_arr.end());
    int carry = 0;
    for (size_t i = 0; i < max(res_arr.size(), rhs.f_size); i++)
    {
        if (i == res_arr.size())
            res_arr.push_back(isLhsNegative ? base - 1 : 0);
        int tmp = res_arr[i] + carry + (i < rhs.f_size ? rhs.f_pnum[rhs.f_size - i - 1] :
                                        (isRhsNegative ? base - 1 : 0));
        carry = tmp >= base;
        if (carry)
            tmp -= base;
        res_arr[i] = tmp;
    }
    if (!isLhsNegative && !isRhsNegative)
    {
        if (carry)
            res_arr.push_back(1);
        else if (res_arr.back() >= base / 2)
            res_arr.push_back(0);
    }
    else if (isLhsNegative && isRhsNegative && carry)
    {
        res_arr.push_back(base - 1);
    }
    if (!resize(res_arr.size()))
    {
        cerr << "Failed to allocate memory when adding TBigNum objects!" << endl;
        return;
    }
    for (int i = 0; i < f_size; i++)
        f_pnum[i] = res_arr[f_size - i - 1];
    minimize();
}


TBigNum TBigNum::operator+(const TBigNum& rhs)
{
    TBigNum res_num(*this);
    res_num += rhs;
    return res_num;
}

void TBigNum::operator-=(const TBigNum& rhs)
{
    *this += -rhs;
}

TBigNum TBigNum::operator-(const TBigNum& rhs)
{
    auto res = TBigNum(*this);
    res -= rhs;
    return res;
}