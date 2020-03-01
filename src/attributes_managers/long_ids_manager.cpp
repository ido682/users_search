#include "attributes_managers/long_ids_manager.h"


void LongIDsManager::AddUUID(long_id_t long_id, uuid_t uuid)
{
    m_long_ids_and_uuids[long_id] = uuid;
}

uuid_t LongIDsManager::GetUUIDByLongID(long_id_t long_id)
{
    auto found_iter = m_long_ids_and_uuids.find(long_id);
    if (found_iter == m_long_ids_and_uuids.end())
    {
        // uuid_t with value of 0 implies non-existing user
        return 0;
    }
    
    return found_iter->second;
}

void LongIDsManager::DeleteUUID(long_id_t long_id)
{
    m_long_ids_and_uuids.erase(long_id);
}

