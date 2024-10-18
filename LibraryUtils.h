#ifdef LIBRARYUTILS_H
#endif

#define LIBRARYUTILS_H

#include "User.h"
#include "Books.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

const std::string userFile = "Userdata.txt";
const std::string libraryFile = "Librarydata.txt";

void saveUserToFile(std::vector<std::string> userInfo)
{
    std::ofstream file(userFile, std::ios::app);
    if (file.is_open())
    {
        for (int i = 0; i < userInfo.size(); i++)
        {
            file << userInfo[i] << ",";
        }
        file << std::endl;
        file.close();
    }
    else
    {
        std::cout << "Unable to open file." << std::endl;
    }
}

void removeUserFromFile(std::vector<std::string> userInfo)
{
    std::ifstream file(userFile);
    std::ofstream tempFile("temp.txt");
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            std::istringstream iss(line);
            std::string token;
            std::vector<std::string> userData;
            while (std::getline(iss, token, ','))
            {
                userData.push_back(token);
            }
            if (userData[0] != userInfo[0] || userData[1] != userInfo[1])
            {
                for (int i = 0; i < userData.size(); i++)
                {
                    tempFile << userData[i] << ",";
                }
                tempFile << std::endl;
            }
            else
            {
                std::cout << "User not found in the database." << std::endl;
                return;
            }
        }
        file.close();
        tempFile.close();
    }
    else
    {
        std::cout << "Unable to open file." << std::endl;
        return;
    }
    std::cout << "User has been removed from the database." << std::endl;
}

void addUser()
{
    User user;
    user.setFirstName();
    user.setLastame();

    std::vector<std::string> userInfo;
    std::string firstName, lastName;
    firstName = user.getFirstName();
    lastName = user.getLastName();
    userInfo.push_back(firstName);
    userInfo.push_back(lastName);

    saveUserToFile(userInfo);

    std::cout << "User added successfully.\n";
}

void initiateLibrarySystem(int choice)
{
    switch (choice)
    {
    case 1:
        addUser();
        break;
    // case 2:
    //     removeUser();
    //     break;
    // case 3:
    //     addBook();
    //     break;
    // case 4:
    //     removeBook();
    //     break;
    // case 5:
    //     searchForUser();
    //     break;
    // case 6:
    //     searchForBook();
    //     break;
    // case 7:
    //     displayUsers();
    //     break;
    // case 8:
    //     displayBooks();
    //     break;
    // case 9:
    //     updateBook();
    //     break;
    // case 10:
    //     updateUser();
    //     break;
    default:
        std::cout << "Invalid choice. Please try again.\n";
    }
}

void displayMenu()
{
    int inputChoice;
    std::cout << "\nLibrary Management System\n";
    std::cout << "1. Add a user\n";
    std::cout << "2. Remove a user\n";
    std::cout << "3. Add a book\n";
    std::cout << "4. Remove a book\n";
    std::cout << "5. Search for a user\n";
    std::cout << "6. Search for a book\n";
    std::cout << "7. Display all users\n";
    std::cout << "8. Display all books\n";
    std::cout << "9. Update a book\n";
    std::cout << "10. Update a user\n";
    std::cout << "11. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> inputChoice;
    if (inputChoice == 11)
    {
        exit(0);
    }
    else
    {
        initiateLibrarySystem(inputChoice);
    }
}

// End of file