#include "attributes_managers/date_of_birth/month.h"


void Month::AddUUID(day_t day, uuid_t uuid)
{
    m_days[day].AddUUID(uuid);
}

void Month::export_uuids_in_range(day_t begin_day, day_t end_day, ordered_uuids_t& ext_uuids_cont)
{
    for (day_t curr_day = begin_day; curr_day < end_day; ++curr_day)
	{
		m_days[curr_day].ExportAllUUIDs(ext_uuids_cont);
	}
}

void Month::ExportUUIDsBornAfterDay(day_t day, ordered_uuids_t& ext_uuids_cont)
{
    export_uuids_in_range(day + 1, MAX_DAYS_IN_MONTH + 1, ext_uuids_cont);
}

void Month::ExportUUIDsBornOnOrBeforeDay(day_t day, ordered_uuids_t& ext_uuids_cont)
{
    export_uuids_in_range(1, day + 1, ext_uuids_cont);
}

void Month::ExportAllUUIDs(ordered_uuids_t& ext_uuids_cont)
{
    export_uuids_in_range(1, MAX_DAYS_IN_MONTH + 1, ext_uuids_cont);
}

void Month::DeleteUUID(day_t day, uuid_t uuid)
{
    m_days[day].DeleteUUID(uuid);
}

