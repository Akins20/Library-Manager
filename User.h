#ifdef USER_H
#endif
#define USER_H

#include <iostream>
#include <string>

class User
{
public:
    std::string fName, lName;

    void setFirstName(){
        std::cout << "Enter first name: ";
        std::cin >> fName;
    };

    void setLastName(){
        std::cout << "Enter last name: ";
        std::cin >> lName;
    };

    std::string getFirstName(){
        return fName;
    };

    std::string getLastName(){
        return lName;
    };

    void displayInfo(){
        std::cout << "First name: " << fName << std::endl;
        std::cout << "Last name: " << lName << std::endl;
    }
};