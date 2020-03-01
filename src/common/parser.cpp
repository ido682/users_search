#include <vector>
#include <algorithm>

#include "common/parser.h"


namespace Parser
{
    user_t ParseUser(const std::string& line)
    {
        user_t user;
        std::vector<std::string> attributes = Split(line, COMMA);

        user.long_id = attributes[ID];
        user.full_name = attributes[FULL_NAME];
        user.dob = attributes[DOB];
        user.country = attributes[COUNTRY];

        return user;
    }
    
    date_t ParseDate(const dob_t& date_in_string, const std::string& delimiter)
    {
        std::vector<std::string> dob_split = Split(date_in_string, delimiter);

        date_t date = {std::stoi(dob_split[0]),
                       std::stoi(dob_split[1]),
                       std::stoi(dob_split[2])};

        return date;
    }

    full_name_t ParseName(const name_t& name_in_one_string)
    {
        std::vector<std::string> name_split = Split(name_in_one_string, SPACE);

        full_name_t full_name = std::make_pair(name_split[0], name_split[1]);

        return full_name;
    }

    std::vector<std::string> Split(const std::string& line, const std::string& delimiter)
    {
        std::string line_copy(line);
        size_t delimiter_length = delimiter.length();
        size_t pos;
        std::string token;
        std::vector<std::string> words;

        while ((pos = line_copy.find(delimiter)) != std::string::npos)
        {
            token = line_copy.substr(0, pos);
            words.push_back(token);
            line_copy.erase(0, pos + delimiter_length);
        }
        words.push_back(line_copy);

        return words;
    }

    std::string ToLower(const std::string& original_string)
    {
        std::string lowered_string(original_string);
        std::transform(lowered_string.begin(), lowered_string.end(), lowered_string.begin(), ::tolower); 

        return lowered_string;
    }
} //Parser