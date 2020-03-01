#pragma once

#include <string>
#include "common/common.h"

namespace Parser
{
    typedef enum
    {
        ID,
        EMAIL,
        FULL_NAME,
        DOB,
        COUNTRY,
        NUM_OF_ATTRS
    } user_attr_t;

    const std::string COMMA = ",";
    const std::string SPACE = " ";
    const std::string SLASH = "/";
    
    user_t ParseUser(const std::string& line);
    date_t ParseDate(const dob_t& date_in_string, const std::string& delimiter = SLASH);
    full_name_t ParseName(const name_t& name_in_one_string);
    std::vector<std::string> Split(const std::string& line, const std::string& delimiter);
    std::string ToLower(const std::string& original_string);
}; // Parser