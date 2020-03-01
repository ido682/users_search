#include "file_handler/file_wrapper.h"


ReadOnlyFileWrapper::ReadOnlyFileWrapper(const std::string& file_name) :
    m_file(file_name)
{
    // Intentionally left blank
}

ReadOnlyFileWrapper::~ReadOnlyFileWrapper()
{
    m_file.close();
}

std::ifstream& ReadOnlyFileWrapper::GetFileRef()
{
    return m_file;
}

