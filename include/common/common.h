  
#pragma once

#include <stdlib.h>
#include <set>
#include <vector>
#include <string>


typedef size_t uuid_t;
typedef std::set<uuid_t> ordered_uuids_t;
typedef size_t pos_in_file_t;
typedef std::string name_t;
typedef name_t first_name_t;
typedef name_t last_name_t;
typedef std::pair<first_name_t, last_name_t> full_name_t;
typedef std::string long_id_t;
typedef std::string country_t;
typedef std::string dob_t;

typedef int day_t;
typedef int month_t;
typedef int year_t;
typedef struct
{
    day_t day;
    month_t month;
    year_t year;
} date_t;

typedef struct 
{
    long_id_t long_id;
    name_t full_name;
    dob_t dob;
    country_t country;
} user_t;

typedef enum
{
    NAME,
    AGE,
    COUNTRY
} search_attr_t;

