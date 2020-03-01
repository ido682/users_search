#pragma once

#include <map>
#include "common/common.h"
#include "attributes_managers/date_of_birth/year.h"

class DOBsManager
{
public:
    DOBsManager() = default;
	~DOBsManager() = default;
	DOBsManager(const DOBsManager& other) = delete;
	DOBsManager& operator=(const DOBsManager& other) = delete;

    void AddUUID(date_t dob, uuid_t uuid);
    // curr_date is changeable for testing purpose
    ordered_uuids_t GetUUIDsInGivenAge(int age, date_t curr_date = get_curr_date());
    void DeleteUUID(date_t dob, uuid_t uuid);

private:
    std::map<year_t, Year> m_years;

    static date_t get_curr_date();
}; //DOBsManager

