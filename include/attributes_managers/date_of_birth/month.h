#pragma once

#include <array>

#include "common/common.h"
#include "attributes_managers/date_of_birth/day.h"


class Month
{
private:
	static const int MAX_DAYS_IN_MONTH = 31;

public:
    Month() = default;
    ~Month() = default;
    Month(const Month& other) = delete;
    Month& operator=(const Month& other) = delete;

    void AddUUID(day_t day, uuid_t uuid);
    void ExportUUIDsBornAfterDay(day_t day, ordered_uuids_t& ext_uuids_cont);
	void ExportUUIDsBornOnOrBeforeDay(day_t day, ordered_uuids_t& ext_uuids_cont);
	void ExportAllUUIDs(ordered_uuids_t& ext_uuids_cont);
    void DeleteUUID(day_t day, uuid_t uuid);

private:
    // day 0 will remain empty for code readablity
	std::array<Day, MAX_DAYS_IN_MONTH + 1> m_days;

    void export_uuids_in_range(day_t begin_day, day_t end_day, ordered_uuids_t& ext_uuids_cont);
}; //Month

