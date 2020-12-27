/**
 * @file func_return_const.cpp
 * @author Kushal Dalsania
 * @brief This source demonstrates why sometimes returning const value from 
 * function is helpful.
 *   
 */
#include <iostream>

using namespace std;

/**
 * @brief Class for integer
 * 
 */
class Number {
public:
    /**
     * @brief Construct a new Number object
     * 
     * @param num 
     */
    Number(int num=0):num{num} {
    }
    /**
     * @brief Destroy the Number object
     * 
     */
    ~Number()=default;
    /**
     * @brief Get number
     * 
     * @return int 
     */
    int get() const {
        return num;
    }
    /**
     * @brief Adds two Number instances
     * 
     * @param obj 
     * @return Number 
     */
    const Number operator+(const Number& obj) {
        Number temp{};
        temp.num=this->num+obj.num;

        return temp;
    }
    /**
     * @brief Checks whether two Number objects are same
     * 
     * @param obj 
     * @return true 
     * @return false 
     */
    bool operator==(const Number& obj) const {
        if(this==&obj)
            return true;
        if(this->num==obj.num)
            return true;
        
        return false;
    }
    /**
     * @brief Auto Cast 
     * 
     * @return int 
     */
    operator int() const {
        if(num!=0)
            return 1; //true
        return 0; //false
    }

private:
    int num;
};

int main(int argc, char* argv[]) {

    // Two values
    Number n1{10};
    Number n2{20};

    // Expected result of above two values
    Number n3{30};

    cout << "n1=" << n1.get() << " n2=" << n2.get() << endl;
    cout << "Expected result of (n1+n2) should be " << (n1+n2).get() << endl;

    // Here
    // If developer does typo mistake by write `=` instead of `==`,
    // the code protects and throw compiler error. 
    // Because operator+() returns const value, the adventure like
    // `n1+n2=n3` throws compiler error, otherwise it compiles and introduce
    // bug.

    //if((n1+n2)=n3) {
    if((n1+n2)==n3) {
        cout << "Result is as expected" << endl;
    }
    else {
        cout << "Bad result" << endl;
    }

    return 0;
}