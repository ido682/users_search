#include "attributes_managers/names_manager.h"
#include "common/parser.h"


void NamesManager::AddUUID(full_name_t full_name, uuid_t uuid)
{
    m_first_names.AddUUID(full_name.first, uuid);
    m_last_names.AddUUID(full_name.second, uuid);
}

ordered_uuids_t NamesManager::GetUUIDsByName(const name_t& name)
{  
    if (name.find(" ") == std::string::npos)
    {
        return get_uuids_by_name_with_one_word(name);
    }

    return get_uuids_by_name_with_two_words(name);
}

ordered_uuids_t NamesManager::get_uuids_by_name_with_one_word(const name_t& name)
{
    ordered_uuids_t uuids_result;

    m_first_names.ExportMatchedUUIDs(name, uuids_result, PARTIAL_MATCH_MIN_SIZE);
    m_last_names.ExportMatchedUUIDs(name, uuids_result, PARTIAL_MATCH_MIN_SIZE);

    return uuids_result;
}

ordered_uuids_t NamesManager::get_uuids_by_name_with_two_words(const name_t& name)
{
    ordered_uuids_t first_name_matches;
    ordered_uuids_t second_name_matches;
    ordered_uuids_t full_matches;

    full_name_t full_name = Parser::ParseName(name);

    m_first_names.ExportMatchedUUIDs(full_name.first, first_name_matches);
    m_last_names.ExportMatchedUUIDs(full_name.second, second_name_matches);

    for (const auto& first_name_match : first_name_matches)
    {
        for (const auto& second_name_match : second_name_matches)
        {
            if (first_name_match == second_name_match)
            {
                full_matches.insert(first_name_match);
            }
        }
    }

    return full_matches;    
}

void NamesManager::DeleteUUID(full_name_t full_name, uuid_t uuid)
{
    m_first_names.DeleteUUID(full_name.first, uuid);
    m_last_names.DeleteUUID(full_name.second, uuid);
}

