#include <filesystem>
#include <iostream>
#include <vector>
#include <regex>
#include <cstddef>
#include "searchFile.h"


void searchFile(std::string filename, std::string dirToSearch)
{
    std::filesystem::path filepath = dirToSearch;
    std::vector<std::string> foundFiles;

    if (std::filesystem::is_directory(filepath))
    {
        for(const auto& entry : std::filesystem::recursive_directory_iterator(filepath))
        {
            if(entry.is_regular_file())
            {
                std::string regularFileName = entry.path().filename().string();
                std::regex filenameRegex("^"+filename);
                if (std::regex_search(regularFileName, filenameRegex))
                {
                    foundFiles.push_back(entry.path().string());
                }
            }
        }

        std::cout << "Found " << foundFiles.size() << " file/s" << std::endl;
        for(const auto& files : foundFiles)
        {
            std::cout << files << std::endl;
        }
    }
    else
    {
        std::cout << "No " << dirToSearch << " directory found" << std::endl;
    }
}