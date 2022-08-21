#ifndef CONFIG_H
#define CONFIG_H

#include <filesystem>
#include <string>

class Config
{
public:
    Config();

    void readConfigFile();

    const std::string &baseUrl() const;
    const std::filesystem::path &downloadDir() const;
    const std::string &authToken() const;

private:
    std::string m_baseUrl;
    std::filesystem::path m_downloadDir;
    std::string m_authToken;
};

#endif // CONFIG_H
