#pragma once

#include <map>

#include "common/common.h"


class LongIDsManager
{
public:
    LongIDsManager() = default;
    ~LongIDsManager() = default;
    LongIDsManager(const LongIDsManager& other) = delete;
	LongIDsManager& operator=(const LongIDsManager& other) = delete;

    void AddUUID(long_id_t long_id, uuid_t uuid);
    uuid_t GetUUIDByLongID(long_id_t long_id);
    void DeleteUUID(long_id_t long_id);

private:
    std::map<long_id_t, uuid_t> m_long_ids_and_uuids;
}; //LongIDsManager


