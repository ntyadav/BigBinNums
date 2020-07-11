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

    /**
     * Creates a copy of a TBigNum number
     * @param other Copying number
     */
    TBigNum(const TBigNum& other);

    /**
     * Creates a TBigNum object by a string representing a decimal number
     * @param str Source string
     */
    explicit TBigNum(std::string str);

    /**
     * Makes string by a TBigNum number
     * @return A string with the number in decimal form
     */
    std::string toDecimalString() const;


    // The following pack of set-methods is designed to work on
    // processors with the big-endian byte order and 32-bit version of the compiler

    /**
     * Set this TBigNum number equals to a signed int
     * @param num A source number of signed int type
     * @return Boolean value indicating whether the memory allocation was successful
     */
    bool setNum(int num);

    /**
     * Set this TBigNum number to a signed int
     * @param num A source number of unsigned int type
     * @return Boolean value indicating whether the memory allocation was successful
     */
    bool setNum(unsigned int num);

    /**
     * Set this TBigNum number to a signed int
     * @param num A source number of signed long int type
     * @return Boolean value indicating whether the memory allocation was successful
     */
    bool setNum(long int num);

    /**
     * Set this TBigNum number to a signed int
     * @param num A source number of unsigned long int type
     * @return Boolean value indicating whether the memory allocation was successful
     */
    bool setNum(unsigned long int num);

    /**
     * Set this TBigNum number to a signed int
     * @param num A source number of signed long long int type
     * @return Boolean value indicating whether the memory allocation was successful
     */
    bool setNum(long long int num);

    /**
    * Set this TBigNum number to a signed int
    * @param num A source number of unsigned long long int type
    * @return Boolean value indicating whether the memory allocation was successful
    */
    bool setNum(unsigned long long int num);

    /**
    * Set this TBigNum number to a signed int
    * @param num A source number of signed char type
    * @return Boolean value indicating whether the memory allocation was successful
    */
    bool setNum(char num);

    /**
    * Set this TBigNum number to a signed int
    * @param num A source number of unsigned int type
    * @return Boolean value indicating whether the memory allocation was successful
    */
    bool setNum(unsigned char num);

    /**
     * Removes extra bytes from the beginning
     */
    void minimize();

    std::string toString() const
    {
        std::string res;
        for (int i = 0; i < f_size; i++)
            res += std::to_string((int) f_pnum[i]) + " ";
        return res;
    }

    TBigNum& operator=(const TBigNum& rhs);

    TBigNum operator+() const;

    TBigNum operator-() const;

    void operator+=(const TBigNum& rhs);

    TBigNum operator+(const TBigNum& rhs);

    void operator-=(const TBigNum& rhs);

    TBigNum operator-(const TBigNum& rhs);

    /**
     * Frees up memory occupied by the array with the number
     */
    ~TBigNum()
    {
        delete[] f_pnum;
    }

private:
    unsigned char *f_pnum; // Points to an array containing the number
    size_t f_size;         // The size of the number in bytes

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
     * Changes number array (f_pnum) size
     * @param new_size New size of the array
     * @return true if memory successfully allocated and false otherwise
     */
    bool resize(size_t new_size);
};


#endif //TBIGNUM_H
