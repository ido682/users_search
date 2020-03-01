#pragma once

#include "common/common.h"


class Day
{
public:
	Day() = default;
	~Day() = default;
	Day(const Day& other) = delete;
	Day& operator=(const Day& other) = delete;

	void AddUUID(uuid_t uuid);
    void ExportAllUUIDs(ordered_uuids_t& ext_uuids_cont);
	void DeleteUUID(uuid_t uuid);

private:
	ordered_uuids_t m_users_cont;
}; //Day


