#ifndef CONFIG_H
#define CONFIG_H

#include <filesystem>
#include <string>

class Config
{
public:
    Config() = delete;

    static void readConfigFile();

    static const std::string &baseUrl();
    static const std::filesystem::path &downloadDir();
    static const std::string &authToken();

private:
    static std::string m_baseUrl;
    static std::filesystem::path m_downloadDir;
    static std::string m_authToken;
};

#endif // CONFIG_H
