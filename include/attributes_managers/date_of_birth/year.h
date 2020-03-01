#pragma once

#include <array>

#include "common/common.h"
#include "attributes_managers/date_of_birth/month.h"



class Year
{
private:
	static const int MONTHS_IN_YEAR = 12;

public:
	Year() = default;
	~Year() = default;
	Year(const Year& other) = delete;
	Year& operator=(const Year& other) = delete;

	void AddUUID(day_t day, month_t month, uuid_t uuid);
	void ExportUUIDsBornAfterDay(day_t day, month_t month, ordered_uuids_t& ext_uuids_cont);
	void ExportUUIDsBornOnOrBeforeDay(day_t day, month_t month, ordered_uuids_t& ext_uuids_cont);
	void DeleteUUID(day_t day, month_t month, uuid_t uuid);

private:
	// month 0 will remain empty for code readablity
	std::array<Month, MONTHS_IN_YEAR + 1> m_months;
}; //Year

