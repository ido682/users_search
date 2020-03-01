#pragma once

#include <map>

#include "common/common.h"
#include "attributes_managers/uuids_mapper.h"


class NamesManager
{
private:
    const int PARTIAL_MATCH_MIN_SIZE = 3;
    
public:
    NamesManager() = default;
    ~NamesManager() = default;
    NamesManager(const NamesManager& other) = delete;
    NamesManager& operator=(const NamesManager& other) = delete;

    void AddUUID(full_name_t full_name, uuid_t uuid);
    ordered_uuids_t GetUUIDsByName(const name_t& name);
    void DeleteUUID(full_name_t full_name, uuid_t uuid);

private:
    UUIDsMapper m_first_names;
    UUIDsMapper m_last_names;

    // The fastest access to names would be with a Trie data structure,
    // but that would cost us in storage, plus - using an STL implemented
    // data structures is always a good idea
    ordered_uuids_t get_uuids_by_name_with_one_word(const name_t& name);
    ordered_uuids_t get_uuids_by_name_with_two_words(const name_t& name);

}; //NamesManager