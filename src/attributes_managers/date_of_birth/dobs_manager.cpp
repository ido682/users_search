#include "attributes_managers/date_of_birth/dobs_manager.h"


void DOBsManager::AddUUID(date_t dob, uuid_t uuid)
{
    auto year_iter = m_years.find(dob.year);
    if (year_iter == m_years.end())
    {
        m_years.emplace(std::piecewise_construct,
                        std::make_tuple(dob.year),
                        std::make_tuple());
    }

    m_years[dob.year].AddUUID(dob.day, dob.month, uuid);
}

date_t DOBsManager::get_curr_date()
{
    const int YEARS_TO_ADD = 1900;
    const int MONTHS_TO_ADD = 1;
    
    time_t curr_time = time(nullptr);
    struct tm *time_info = localtime(&curr_time);

    date_t curr_date;

    curr_date.day = time_info->tm_mday;
    curr_date.month = time_info->tm_mon + MONTHS_TO_ADD;
    curr_date.year = time_info->tm_year + YEARS_TO_ADD;

    return curr_date;
}

ordered_uuids_t DOBsManager::GetUUIDsInGivenAge(int age, date_t curr_date)
{    
    ordered_uuids_t users_in_given_age_result;

    year_t year_to_check_on_or_before_given_day = curr_date.year - age;
    year_t year_to_check_after_given_day = year_to_check_on_or_before_given_day - 1;

    m_years[year_to_check_after_given_day].ExportUUIDsBornAfterDay(curr_date.day, curr_date.month, users_in_given_age_result);
    m_years[year_to_check_on_or_before_given_day].ExportUUIDsBornOnOrBeforeDay(curr_date.day, curr_date.month, users_in_given_age_result);

    return users_in_given_age_result;
}

void DOBsManager::DeleteUUID(date_t dob, uuid_t uuid)
{
    auto year_iter = m_years.find(dob.year);
    
    m_years[dob.year].DeleteUUID(dob.day, dob.month, uuid);
}

