#ifndef TBIGNUM_H
#define TBIGNUM_H

#include <cstdlib>
#include <string>

class TBigNum
{
public:

    /**
     * Creates an empty number
     */
    TBigNum() : f_pnum(nullptr), f_size(0)
    {}

    /**
     * Creates a number (without a specific value) with the specified size in bytes
     * @param num_size The size of the number in bytes
     */
    explicit TBigNum(size_t num_size);

    TBigNum(const TBigNum& other);

    TBigNum(std::string str);

    std::string toDecimalString()  const;

    bool setNum(int num);

    bool setNum(unsigned int num);

    bool setNum(long int num);

    bool setNum(unsigned long int num);

    bool setNum(long long int num);

    bool setNum(unsigned long long int num);

    bool setNum(char num);

    bool setNum(unsigned char num);

    TBigNum &operator=(const TBigNum& rhs);

    TBigNum operator+() const;

    TBigNum operator-() const;

    void operator+=(const TBigNum& rhs);

    TBigNum operator+(const TBigNum& rhs);

    void operator-=(const TBigNum& rhs);

    TBigNum operator-(const TBigNum& rhs);

    std::string toString() const
    {
        std::string res;
        for (int i = 0; i < f_size; i++)
            res += std::to_string((int)f_pnum[i]) + " ";
        return res;
    }


    /**
     * Frees up memory occupied by the array with the number
     */
    ~TBigNum()
    {
        delete[] f_pnum;
    }

private:
    unsigned char *f_pnum; // Points to an array containing the number
    size_t f_size; // The size of the number in bytes

    /**
     * Indicates if the number is negative
     * @return true if negative and false otherwise
     */
    bool isNegative() const
    {
        if (f_pnum == nullptr || f_size == 0)
            return false;
        return (f_pnum[0] >= 128);
    }

    /**
     * Changes number array size
     * @param new_size New size of the array
     * @return true if memory successfully allocated and false otherwise
     */
    bool resize(size_t new_size);
};


#endif //TBIGNUM_H
