#include "attributes_managers/users_manager.h"
#include "common/parser.h"
#include "file_handler/file_reader.h"


// starts with value of 1, since 0 implies a non-existing user 
size_t UsersManager::m_s_counter = 1;

uuid_t UsersManager::AddUser(const user_t& user)
{    
    // Having a uuid in addition to the long_id enables us to search
    // in the data base in a propriate order, what gives us better performance
    // when reading from I/O. Of course we can also keep the data itself,
    // but that would cost us in storage and in having duplicated data (not a good idea)
    uuid_t uuid = m_s_counter++;
    full_name_t full_name = Parser::ParseName(user.full_name);
    date_t dob = Parser::ParseDate(user.dob);

    m_long_ids_manager.AddUUID(user.long_id, uuid);
    m_names_manager.AddUUID(full_name, uuid);
    m_dobs_manager.AddUUID(dob, uuid);
    m_countries_manager.AddUUID(user.country, uuid);

    return uuid;
}

ordered_uuids_t UsersManager::GetUUIDsByAttribute(search_attr_t attribute, const std::string& value)
{    
    switch (attribute)
    {
    case NAME:
        return m_names_manager.GetUUIDsByName(value);

    case AGE:
        return m_dobs_manager.GetUUIDsInGivenAge(std::stoi(value));

    case COUNTRY:
        return m_countries_manager.GetUUIDsByCountry(value);
    
    default:
        break;
    }

    return ordered_uuids_t();
}

uuid_t UsersManager::GetUUIDByLongID(const long_id_t& long_id)
{
    return m_long_ids_manager.GetUUIDByLongID(long_id);
}

uuid_t UsersManager::DeleteUser(const user_t& user, uuid_t uuid)
{
    m_long_ids_manager.DeleteUUID(user.long_id);
    m_names_manager.DeleteUUID(Parser::ParseName(user.full_name), uuid);
    m_dobs_manager.DeleteUUID(Parser::ParseDate(user.dob), uuid);
    m_countries_manager.DeleteUUID(user.country, uuid);
}

