#include "attributes_managers/countries_manager.h"


void CountriesManager::AddUUID(country_t country, uuid_t uuid)
{
    m_countries.AddUUID(country, uuid);
}

ordered_uuids_t CountriesManager::GetUUIDsByCountry(const country_t& country)
{
    ordered_uuids_t uuids_result;
    
    m_countries.ExportMatchedUUIDs(country, uuids_result);

    return uuids_result;                                           
}

void CountriesManager::DeleteUUID(country_t country, uuid_t uuid)
{
    m_countries.DeleteUUID(country, uuid);
}

