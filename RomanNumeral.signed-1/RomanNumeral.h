#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_

#include <string>
#include <iostream>


using namespace std;

class RomanNumeral
{
public:

    /*
     *constructors
     * */
    RomanNumeral();
    RomanNumeral(string roman);
    RomanNumeral(int value);

    /*
     * set functions
     * */

    void Set_RomanNumeral(string roman);
    void Set_RomanNumeral(int value);

    /*
     * Getter functions
     * */

    string GetString();
    int GetInteger();

    /*
     *override operator functions
     * */

    friend RomanNumeral operator +(const RomanNumeral& a,const RomanNumeral& b);
    friend RomanNumeral operator -(const RomanNumeral& a,const RomanNumeral& b);
    friend RomanNumeral operator *(const RomanNumeral& a,const RomanNumeral& b);
    friend RomanNumeral operator /(const RomanNumeral& a,const RomanNumeral& b);
    friend bool operator ==(const RomanNumeral& a,const RomanNumeral& b);
    friend bool operator !=(const RomanNumeral& a,const RomanNumeral& b);
    friend ostream& operator <<(ostream& out,const RomanNumeral& b);
    friend istream& operator >>(istream& in, RomanNumeral& b);

    /***** Complete this class. *****/

private:
    string roman_array;      // Roman numeral as a string
    int decimal_value;    // decimal value of the Roman numeral

    void toRoman();    // calculate string from decimal value
    void toDecimal();  // calculate decimal value from string
};



#endif /* ROMANNUMERAL_H_ */
