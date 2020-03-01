#pragma once

#include <vector>
#include <map>

#include "common/common.h"
#include "attributes_managers/users_manager.h"

class DBProxy
{
private:
    const std::string USER_DOESNT_EXIT = "USER_DOESN'T_EXIT";

public:
    DBProxy(const std::string& db_file_name, UsersManager& users_manager);
    ~DBProxy() = default;
    DBProxy(const DBProxy& other) = delete;
    DBProxy& operator=(const DBProxy& other) = delete;

    std::vector<user_t> GetUsersByAttribute(search_attr_t attribute, const std::string& value);
    user_t GetUserByLongID(long_id_t long_id);
    void DeleteUser(long_id_t long_id);

private:
    std::string m_db_file_name;
    std::map<uuid_t, pos_in_file_t> m_users_and_positions;
    UsersManager& m_users_manager;

    void add_user_to_user_manager(pos_in_file_t pos, const std::string& line);
    void update_recently_added_users();

    user_t get_user_from_uuid(uuid_t uuid);
    std::vector<user_t> get_users_from_uuids(ordered_uuids_t& uuids);
}; //DBProxy