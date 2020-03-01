#include "attributes_managers/date_of_birth/day.h"
#include "common/cont_funcs.h"


void Day::AddUUID(uuid_t uuid)
{
    m_users_cont.insert(uuid);
}

void Day::ExportAllUUIDs(ordered_uuids_t& ext_uuids_cont)
{
    ContFuncs::ExportAllUUIDs(m_users_cont, ext_uuids_cont);
}

void Day::DeleteUUID(uuid_t uuid)
{
    m_users_cont.erase(uuid);
}

