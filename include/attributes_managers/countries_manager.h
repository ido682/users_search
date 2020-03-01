#pragma once

#include <map>

#include "common/common.h"
#include "attributes_managers/uuids_mapper.h"


class CountriesManager
{
public:
    CountriesManager() = default;
    ~CountriesManager() = default;
    CountriesManager(const CountriesManager& other) = delete;
    CountriesManager& operator=(const CountriesManager& other) = delete;

    void AddUUID(country_t country, uuid_t uuid);
    ordered_uuids_t GetUUIDsByCountry(const country_t& country);
    void DeleteUUID(country_t country, uuid_t uuid);

private:
    UUIDsMapper m_countries;
}; //CountriesManager