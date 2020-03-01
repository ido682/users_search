#pragma once

#include <map>
#include <string>

#include "file_handler/file_wrapper.h"


class FileReader
{
private:
    static int m_s_last_pos;

public:
    FileReader(const std::string& file_name);
    ~FileReader() = default;
    FileReader(const FileReader& other) = delete;
    FileReader& operator=(const FileReader& other) = delete;

    std::map<pos_in_file_t, std::string> GetNewLines();
    std::string GetLine(pos_in_file_t);

private:
    ReadOnlyFileWrapper m_file;
}; //FileReader

