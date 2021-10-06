/*
Name: Sahar Hosseinichegeni
Student Number: 139670202
Email: shosseinichegeni@myseneca.ca
Date: 21-10-03
Section: NAA
*/
#include "StringSet.h"
#include <string>
#include <fstream>
#include <iostream>
#include <utility>

namespace sdds {
    StringSet::StringSet()
        : m_size(0), m_strings(nullptr) {}

    StringSet::~StringSet() {
        delete[] m_strings;
    }

    StringSet::StringSet(const char* filename)
        : m_size(0), m_strings(nullptr)
    {
        // Open file for reading.
        std::ifstream infile(filename);
        if (! infile.is_open())
        {
            std::cerr << "Couldn't open " << filename << std::endl;
            return;
        }

        // Read the file to count the number of strings.
        const char delim = ' ';
        std::string s;
        while (std::getline(infile, s, delim))
        {
            // Empty strings are also counted.
            m_size++;
        }

        // Allocate memory to store m_size number of strings.
        m_strings = new std::string[m_size];

        // Re-read the file and store stirngs into the dynamically
        // allcoated memory.
        infile.clear();
        infile.seekg(0, std::ios::beg);

        size_t current_pos = 0;
        while (std::getline(infile, s, delim))
        {
            // Empty strings are also counted.
            m_strings[current_pos++] = s;
        }
        
        // Close file.
        infile.close();
    }

    StringSet::StringSet(const StringSet& other)
        : m_size(other.m_size), m_strings(nullptr) {
        
        // Alloate memory of appropriate size (same as the 'other' object).
        m_strings = new std::string[m_size];

        // Copy everything over.
        for (size_t i = 0; i < m_size; i++) {
            m_strings[i] = other.m_strings[i];
        }
    }

    StringSet& StringSet::operator=(const StringSet& other)
    {
        // Handle self assignment.
        if (this == &other) {
            return *this;
        }

        // Free heap memory associated with the existing array.
        delete[] m_strings;

        // Copy everything over to the newly allocated memory of appropriate size.
        m_size = other.m_size;
        m_strings = new std::string[m_size];
        for (size_t i = 0; i < m_size; i++)
        {
            m_strings[i] = other.m_strings[i];
        }

        // Keep the chain of assignment alive.
        return *this;
    }

    size_t StringSet::size() const { return m_size; }

    std::string StringSet::operator[](size_t index) const
    {
        // Bounds checking.
        if (index < 0 || index >= m_size) {
            // Invalid index should return an empty string.
            return std::string();
        }

        return m_strings[index];
    }

    StringSet::StringSet(StringSet&& other)
        : m_size(other.m_size), m_strings(other.m_strings) {
            
        // Render the 'other' object hollow after stealing its resources
        // to make sure it doesn't segfault when the destructor is called.
        other.m_size = 0;
        other.m_strings = nullptr;
    }

    StringSet& StringSet::operator=(StringSet&& other)
    {
        // Handle self reference.
        if (this == &other) {
            // No need to move. It's aleady there.
            // Just keep assignment chain alive.
            return *this;
        }

        // Delete heap memory associated with existing array.
        delete[] m_strings;
        
        // Steal resources of the 'other' object over.
        m_strings = other.m_strings;
        m_size = other.m_size;

        // Render the 'other' object hollow.
        other.m_strings = nullptr;
        other.m_size = 0;

        // Keep assignment chain alive.
        return *this;
    }
}