#ifndef COMPLEXDB_HPP
#define COMPLEXDB_HPP

#include "complexNumber.hpp"
#include <string>

/**
 * insert (complex obj)
 * delete (complex obj)
 * string <- display ()
 * store (string file name)
 * 
 */

/**
 * @brief database for complex numbers 
 * 
 */
class ComplexDB
{
  
    private:
        complexNum<int> *m_array;
        int m_max_length;
        int m_end_idx;
        int m_length;

    public:
        /**
         * @brief Construct a new Complex DataBase object
         * 
         */
        ComplexDB();

        /**
         * @brief Destroy the Complex D B object
         * 
         */
        ~ComplexDB();
        
        /**
         * @brief insert a complex number into the database
         * 
         * @param complex_number 
         */
        void insert(complexNum<int> complex_number);

        /**
         * @brief delete a given complex number from the database if it exists
         * 
         * @param complex_number 
         */
        void del(complexNum<int> complex_number);

        /**
         * @brief returns the database as a string
         * 
         * @return std::string 
         */
        std::string toString();

        /**
         * @brief saves the database to a file 
         * 
         * @param file_name 
         */
        void save(std::string file_name);

};

#endif