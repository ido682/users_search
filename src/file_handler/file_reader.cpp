#include <sstream>
#include "common/common.h"
#include "file_handler/file_reader.h"


int FileReader::m_s_last_pos = 0;

FileReader::FileReader(const std::string& file_name) :
    m_file(file_name)
{
    // Intentionally left blank
}

std::map<pos_in_file_t, std::string> FileReader::GetNewLines()
{
    std::map<pos_in_file_t, std::string> new_lines;
        
    m_file.GetFileRef().seekg(m_s_last_pos, m_file.GetFileRef().beg);
    std::string curr_line;

    while (std::getline(m_file.GetFileRef(), curr_line))
    {
        new_lines[m_s_last_pos] = curr_line;
        m_s_last_pos = m_file.GetFileRef().tellg();
    }

    return new_lines;
}

std::string FileReader::GetLine(pos_in_file_t pos_in_file)
{
    std::string line;

    m_file.GetFileRef().seekg(pos_in_file, m_file.GetFileRef().beg);
    std::getline(m_file.GetFileRef(), line);

    return line;
}

