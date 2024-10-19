#ifdef BOOK_H
#endif

#define BOOK_H

#include <iostream>
#include <string>

class Book
{

public:
    std::string title;
    std::string author;
    int year;
    std::string genre;

    // Getters
    std::string getTitle()
    {
        return title;
    }
    std::string getAuthor()
    {
        return author;
    }
    int getYear()
    {
        return year;
    }
    std::string getGenre()
    {
        return genre;
    }

    // Setters
    void setTitle()
    {
        std::cout << "Enter the title: ";
        std::cin.ignore();
        std::getline(std::cin, title);
    }
    void setAuthor()
    {
        std::cout << "Enter the author: ";
        std::getline(std::cin, author);
    }
    void setYear()
    {
        std::cout << "Year: ";
        std::cin >> year;
    }
    void setGenre()
    {
        std::cout << "Enter Genre: ";
        std::cin.ignore();
        std::getline(std::cin, genre);
    }
};