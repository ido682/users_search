#pragma once

#include <fstream>


class ReadOnlyFileWrapper
{
public:
    ReadOnlyFileWrapper(const std::string& file_name);
    ~ReadOnlyFileWrapper();
    ReadOnlyFileWrapper(const ReadOnlyFileWrapper& other) = delete;
    ReadOnlyFileWrapper& operator=(const ReadOnlyFileWrapper& other) = delete;

    std::ifstream& GetFileRef();

private:
    std::ifstream m_file;
};