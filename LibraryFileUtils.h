#ifdef LIBRARYFILEUTILS_H
#endif

#define LIBRARYFILEUTILS_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

const std::string userFile = "Userdata.txt";
const std::string libraryFile = "Librarydata.txt";

// Saves the user data to the file(database)
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

// Removes the specified user from file (database)
void removeUserFromFile(std::vector<std::string> userInfo)
{
    std::ifstream file(userFile);
    std::ofstream tempFile("temp.txt");
    bool mainFileOpen = false;
    bool tempFileOpen = false;
    bool userFound = false;
    if (file.is_open())
    {
        mainFileOpen = true;
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

            if ((line.find(userInfo[0]) != std::string::npos) && (line.find(userInfo[1]) != std::string::npos))
            {
                userFound = true;
                continue;
            }
            else if (userData[0] == userInfo[0] || userData[1] == userInfo[1])
            {
                std::cout << "User already removed from the database." << std::endl;
                return;
            }
            else
            {
                std::cout << "User not found in the database." << std::endl;
                return;
            }
        }
        file.close();
        mainFileOpen = false;
        tempFile.close();
        tempFileOpen = false;

        if (userFound)
        {
            std::remove(userFile.c_str());
            std::rename("temp.txt", userFile.c_str());
        }

        // Delete the userdata file and rename the tempfile to the userdata file if the main file and temp file are closed successfully
        if (!mainFileOpen && !tempFileOpen)
        {
            std::remove(userFile.c_str());
            std::rename("temp.txt", userFile.c_str());
        }
    }
    else
    {
        std::cout << "Unable to open file." << std::endl;
        return;
    }
    std::cout << "User has been removed from the database." << std::endl;
}

void fetchUsersFromFile()

{
    std::ifstream file(userFile);
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
            std::cout << "First Name: " << userData[0] << ", Last Name: " << userData[1] << std::endl;
        }
        file.close();
    }
    else
    {
        std::cout << "Unable to open file." << std::endl;
    }
}

// To save inputed book into file file(database)
void saveBookToFile(std::vector<std::string> bookInfo)
{
    std::ofstream file(libraryFile, std::ios::app);
    if (file.is_open())
    {
        file << "Title: " << bookInfo[0] << std::endl;
        file << "Author: " << bookInfo[1] << std::endl;
        file << "Year: " << bookInfo[2] << std::endl;
        file << "Genre: " << bookInfo[3] << std::endl;

        file << std::endl;
        file.close();
    }
    else
    {
        std::cout << "Unable to open file." << std::endl;
    }
}

// To remove the inputted book info from file(database)
void removeBookFromFile(std::vector<std::string> bookInfo)
{
    std::ifstream file(libraryFile);
    std::ofstream tempFile("temp.txt");

    if (file.is_open() && tempFile.is_open())
    {
        std::string line;
        bool bookFound = false; // Track if the book is found

        while (std::getline(file, line))
        {
            // Check if this line matches the book title
            if (line.find("Title: " + bookInfo[0]) != std::string::npos)
            {
                // Book found, now check if the subsequent lines match
                std::string authorLine, yearLine, genreLine;

                // Read the next 3 lines (Author, Year, Genre)
                std::getline(file, authorLine);
                std::getline(file, yearLine);
                std::getline(file, genreLine);

                if (authorLine.find("Author: " + bookInfo[1]) != std::string::npos &&
                    yearLine.find("Year: " + bookInfo[2]) != std::string::npos &&
                    genreLine.find("Genre: " + bookInfo[3]) != std::string::npos)
                {
                    // The book matches all the details, so skip writing it to the temp file
                    bookFound = true;
                    std::cout << "Book has been found and removed from the database." << std::endl;
                    continue; // Skip this block of book information
                }
                else
                {
                    // If the subsequent lines don't match, write the lines back to the temp file
                    tempFile << line << std::endl;
                    tempFile << authorLine << std::endl;
                    tempFile << yearLine << std::endl;
                    tempFile << genreLine << std::endl;
                }
            }
            else
            {
                // If the current line doesn't match the book, write it to the temp file
                tempFile << line << std::endl;
            }
        }

        file.close();
        tempFile.close();

        if (bookFound)
        {
            // Replace the original file with the updated temp file
            std::remove(libraryFile.c_str());
            std::rename("temp.txt", libraryFile.c_str());
        }
        else
        {
            std::cout << "Book not found in the database." << std::endl;
            std::remove("temp.txt"); // Remove the temp file since no changes were made
        }
    }
    else
    {
        std::cout << "Unable to open file." << std::endl;
        return;
    }
}

void fetchBooksFromFile()
{
    std::ifstream file(libraryFile);
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            std::cout << line << std::endl;
        }
        file.close();
    }
    else
    {
        std::cout << "Unable to open file." << std::endl;
    }
}

void fetchUserByFirstName(std::string firstName)
{
    std::ifstream file(userFile);
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            std::istringstream iss(line);
            if (line.find(firstName) != std::string::npos)
            {
                std::string token;
                std::vector<std::string> userData;
                while (std::getline(iss, token, ','))
                {
                    userData.push_back(token);
                }
                std::cout << "First Name: " << userData[0] << ", Last Name: " << userData[1] << std::endl;
            }
            else
            {
                continue;
            }
        }
        file.close();
    }
    else
    {
        std::cout << "Unable to open file." << std::endl;
    }
}

std::vector<std::string> fetchBookByTitle(std::string title)
{
    std::ifstream file(libraryFile);
    std::vector<std::string> bookData;
    if (file.is_open())
    {
        std::string line;
        bool bookFound = false; // Flag to track if the book was found

        while (std::getline(file, line))
        {
            // Ignore empty lines
            if (line.empty())
                continue;

            // Check if the current line contains the desired title
            if (line.find("Title: " + title) != std::string::npos)
            {
                std::string authorLine, yearLine, genreLine;

                // Get the next lines for author, year, and genre
                std::getline(file, authorLine);
                std::getline(file, yearLine);
                std::getline(file, genreLine);

                // Make sure these lines contain valid book information
                if (authorLine.find("Author: ") != std::string::npos &&
                    yearLine.find("Year: ") != std::string::npos &&
                    genreLine.find("Genre: ") != std::string::npos)
                {
                    std::cout << "Found the book with title: " << title << std::endl;
                    // std::cout << "Title: " << title << std::endl;
                    std::cout << "Author: " << authorLine.substr(8) << std::endl;
                    bookData.push_back(authorLine.substr(8));
                    std::cout << "Year: " << yearLine.substr(6) << std::endl;
                    bookData.push_back(yearLine.substr(6));
                    std::cout << "Genre: " << genreLine.substr(7) << std::endl;
                    bookData.push_back(genreLine.substr(7));

                    bookFound = true; // Set flag to true since the book was found
                    break;            // Exit the loop once the book is found
                }
            }
        }

        file.close();

        // If the book was not found, print an appropriate message
        if (!bookFound)
        {
            std::cout << "Book with title '" << title << "' not found." << std::endl;
        }
    }
    else
    {
        std::cout << "Unable to open file." << std::endl;
    }
    return bookData;
}

std::vector<std::string> updateBookByTitle(std::string title)
{
    std::ifstream file(libraryFile);
    std::ofstream tempFile("temp.txt");
    std::vector<std::string> bookInformation;

    if (file.is_open() && tempFile.is_open())
    {
        std::string line;
        bool bookFound = false;

        while (std::getline(file, line))
        {
            if (line.find("Title: " + title) != std::string::npos)
            {
                // The book with the given title is found, get its details
                std::string authorLine, yearLine, genreLine;
                std::getline(file, authorLine);
                std::getline(file, yearLine);
                std::getline(file, genreLine);

                std::string newTitle, newAuthor, newYear, newGenre;
                fetchBookByTitle(title);

                bookFound = true;

                // Prompt for new details
                std::cout << "Enter new details for the book:" << std::endl;
                std::cout << "Title: ";
                std::getline(std::cin, newTitle);

                std::cout << "Author: ";
                std::getline(std::cin, newAuthor);

                std::cout << "Year: ";
                std::getline(std::cin, newYear); // Corrected to std::getline for consistency

                std::cout << "Genre: ";
                std::getline(std::cin, newGenre);

                // Store the new book data in the vector
                bookInformation.push_back(newTitle);
                bookInformation.push_back(newAuthor);
                bookInformation.push_back(newYear);
                bookInformation.push_back(newGenre);

                // Write the updated book information to the temp file
                tempFile << "Title: " << newTitle << std::endl;
                tempFile << "Author: " << newAuthor << std::endl;
                tempFile << "Year: " << newYear << std::endl;
                tempFile << "Genre: " << newGenre << std::endl;

                // Skip the next 3 lines in the original file (the original book's details)
                std::getline(file, line); // Skip Author line
                std::getline(file, line); // Skip Year line
                std::getline(file, line); // Skip Genre line
            }
            else
            {
                // If the current line doesn't match, write it to the temp file
                tempFile << line << std::endl;
            }
        }

        file.close();
        tempFile.close();

        // Replace the original file with the updated temp file
        if (bookFound)
        {
            std::remove(libraryFile.c_str());
            std::rename("temp.txt", libraryFile.c_str());
            std::cout << "Book with title '" << title << "' has been updated." << std::endl;
        }
        else
        {
            std::remove("temp.txt"); // Remove the temp file if no book was found
            std::cout << "Book with title '" << title << "' not found." << std::endl;
        }
    }
    else
    {
        std::cout << "Unable to open file." << std::endl;
    }

    return bookInformation;
}

std::vector<std::string> updateUserByFirstName(std::string firstName)
{
    std::ifstream file(userFile);
    std::ofstream tempFile("temp.txt");
    std::vector<std::string> userData;
    bool userFound = false;

    if (file.is_open() && tempFile.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            std::istringstream iss(line);
            if (line.find(firstName) != std::string::npos)
            {
                std::string token;
                std::vector<std::string> updatedUserData;
                fetchUserByFirstName(firstName);
                while (std::getline(iss, token, ','))
                {
                    userData.push_back(token);
                }

                std::string newFirstName, newLastName;
                std::cout << "Enter new details for the user:" << std::endl;
                std::cout << "First Name: ";
                std::cin.ignore();
                std::getline(std::cin, newFirstName);

                std::cout << "Last Name: ";
                std::getline(std::cin, newLastName);

                updatedUserData.push_back(newFirstName);
                updatedUserData.push_back(newLastName);

                userFound = true;

                tempFile << updatedUserData[0] << "," << updatedUserData[1] << std::endl;

                break;
            }
            else
            {
                tempFile << line << std::endl;
            }
        }

        file.close();
        tempFile.close();
        
        // Replace the original file with the updated temp file
        if (userFound)
        {
            std::remove(userFile.c_str());
            std::rename("temp.txt", userFile.c_str());
            std::cout << "User with first name '" << firstName << "' has been updated." << std::endl;
        }
        else
        {
            std::remove("temp.txt");
            std::cout << "User with first name '" << firstName << "' not found." << std::endl;
        }
    }
    else
    {
        std::cout << "Unable to open file." << std::endl;
    }
}

// End of file