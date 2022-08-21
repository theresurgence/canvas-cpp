#include "Config.h"

#include <fmt/core.h>
#include <fstream>
#include <string>

std::string Config::m_baseUrl{};
std::filesystem::path Config::m_downloadDir{};
std::string Config::m_authToken{};

/**
 * TODO input validation
 * test login for token + url
 * test if download directory exists, otherwise create it and inform user
 * check if all members are assigned a value throw error if any not assigned at the end
 * 
 * Check if config file exists
 * have a way to change config file location
 * 
 * cross platform filesystem?
 */

void Config::readConfigFile()
{
    std::ifstream configFile("/home/user/canvas-config.txt");

    std::string str;
    while (std::getline(configFile, str)) {
        if (str.empty()) {
            continue;

        } else if (str.compare("[Canvas Url]")) {
            std::getline(configFile, str);
            m_baseUrl = str;

        } else if (str.compare("[Download Folder]")) {
            std::getline(configFile, str);
            m_downloadDir = std::filesystem::path(str);

        } else if (str.compare("[Token]")) {
            std::getline(configFile, str);
            m_authToken = str;
        }
    }
}

const std::string &Config::baseUrl()
{
    return m_baseUrl;
}

const std::filesystem::path &Config::downloadDir()
{
    return m_downloadDir;
}

const std::string &Config::authToken()
{
    return m_authToken;
}
