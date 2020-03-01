#include "common/cont_funcs.h"

namespace ContFuncs
{
    void ExportAllUUIDs(const ordered_uuids_t& base_cont,
                        ordered_uuids_t& ext_cont)
    {
        for (const auto& user : base_cont)
        {
            ext_cont.insert(user);
        }
    }
} //ContFuncs