#pragma once

#include <string>
#include <map>
#include <vector>

#include "common/common.h"
#include "attributes_managers/names_manager.h"
#include "attributes_managers/date_of_birth/dobs_manager.h"
#include "attributes_managers/long_ids_manager.h"
#include "attributes_managers/countries_manager.h"


class UsersManager
{
private:
    static size_t m_s_counter;

public:
    UsersManager() = default;
    ~UsersManager() = default;
    UsersManager(const UsersManager& other) = delete;
	UsersManager& operator=(const UsersManager& other) = delete;

    uuid_t AddUser(const user_t& user);
    ordered_uuids_t GetUUIDsByAttribute(search_attr_t attribute, const std::string& value);
    uuid_t GetUUIDByLongID(const long_id_t& long_id);
    uuid_t DeleteUser(const user_t& user, uuid_t uuid);

private:
    LongIDsManager m_long_ids_manager;
    NamesManager m_names_manager;
    DOBsManager m_dobs_manager;
    CountriesManager m_countries_manager;

}; //UsersManager


