/*
Name: Sahar Hosseinichegeni
Student Number: 139670202
Email: shosseinichegeni@myseneca.ca
Date: 21-10-03
Section: NAA
*/
#ifndef STRING_SET_H
#define STRING_SET_H

#include <string>

namespace sdds {
    class StringSet {
    public:
        StringSet();
        StringSet(const char* filename);
        StringSet(const StringSet& other);
        StringSet& operator=(const StringSet& other);
        StringSet(StringSet&& other);
        StringSet& operator=(StringSet&& other);
        size_t size() const;
        std::string operator[](size_t index) const;
        ~StringSet();

    private:
        size_t m_size;
        std::string* m_strings;
    };
}

#endif