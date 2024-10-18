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
    int genre;

    // Constructor
    Book(std::string t, std::string a, int y, int p)
    {
        title = t;
        author = a;
        year = y;
        genre = p;
    }

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
    int getGenre()
    {
        return genre;
    }

    // Setters
    void setTitle()
    {
        std::cout << "Enter the title: ";
        std::cin >> title;
    }
    void setAuthor()
    {
        std::cout << "Enter the author: ";
        std::cin >> author;
    }
    void setYear()
    {
        std::cout << "Year: ";
        std::cin >> year;
    }
    void setGenre()
    {
        std::cout << "Enter ISBN: ";
        std::cin >> genre;
    }
};