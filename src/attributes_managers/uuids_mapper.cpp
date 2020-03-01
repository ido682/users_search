#include <iostream>
#include "attributes_managers/uuids_mapper.h"
#include "common/cont_funcs.h"
#include "common/parser.h"


void UUIDsMapper::AddUUID(std::string key, uuid_t uuid)
{    
    std::string lowered_key = Parser::ToLower(key);
    
    auto key_iter = m_keys_and_uids.find(key);
    if (key_iter == m_keys_and_uids.end())
    {
        m_keys_and_uids.insert({key, ordered_uuids_t()});
    }

    m_keys_and_uids[lowered_key].insert(uuid);
}

void UUIDsMapper::export_uuids_with_exact_match(const std::string& key,
                                                ordered_uuids_t& ext_uuids_cont)
{
    auto key_iter = m_keys_and_uids.find(key);
    if (key_iter == m_keys_and_uids.end())
    {
        return;
    }

    for (const auto& user : key_iter->second)
    {
        ext_uuids_cont.insert(user);
    }
}

void UUIDsMapper::export_uuids_with_partial_match(const std::string& key,
                                                  ordered_uuids_t& ext_uuids_cont)
{
    const uuid_t DUMMY_USER = 0;
    size_t key_length = key.length();
    bool is_dummy_user_inserted = false;
    
    auto key_iter = m_keys_and_uids.find(key);
    if (key_iter == m_keys_and_uids.end())
    {
        // Inserting dummy user (if needed) enables us to search for partial matches
        // only in the relevant part of the map, without iterating it all
        AddUUID(key, DUMMY_USER);
        is_dummy_user_inserted = true;
        key_iter = m_keys_and_uids.find(key);
    }
    else
    {
        // Users will be added only if this key isn't a dummy
        ContFuncs::ExportAllUUIDs(key_iter->second, ext_uuids_cont);
    }
    
    // From this point - start iterating towards the map's end
    key_iter++;
    for (; (key_iter != m_keys_and_uids.end()) && (key_iter->first.compare(0, key_length, key) == 0); ++key_iter)
    {
        ContFuncs::ExportAllUUIDs(key_iter->second, ext_uuids_cont);
    }

    // And now - towards the map's beginning
    key_iter = m_keys_and_uids.find(key);
    bool is_iter_in_beginning_in_prev_loop = (key_iter == m_keys_and_uids.begin());
    --key_iter;

    for (; (!is_iter_in_beginning_in_prev_loop) && (key_iter->first.compare(0, key_length, key) == 0); --key_iter)
    {
        ContFuncs::ExportAllUUIDs(key_iter->second, ext_uuids_cont);

        is_iter_in_beginning_in_prev_loop = (key_iter == m_keys_and_uids.begin());
    }
    
    if (is_dummy_user_inserted)
    {
        m_keys_and_uids.erase(key);
    }
}

void UUIDsMapper::ExportMatchedUUIDs(const std::string& key,
                                     ordered_uuids_t& ext_uuids_cont,
                                     int partial_match_min_size)
{
    std::string lowered_key = Parser::ToLower(key);
    size_t key_length = lowered_key.length();

    if ((partial_match_min_size != 0) && (key_length >= partial_match_min_size))
    {
        export_uuids_with_partial_match(lowered_key, ext_uuids_cont);
    }
    else
    {
        export_uuids_with_exact_match(lowered_key, ext_uuids_cont);
    }
}

void UUIDsMapper::DeleteUUID(std::string key, uuid_t uuid)
{
    std::string lowered_key = Parser::ToLower(key);
    
    auto key_iter = m_keys_and_uids.find(key);
    
    m_keys_and_uids[lowered_key].erase(uuid);
}

