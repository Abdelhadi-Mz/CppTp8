#ifndef PLUGIN_H
#define PLUGIN_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Plugin {
public:
    virtual std::string nom() const = 0;
    virtual std::string traiter(const std::string& texte) = 0;
    virtual ~Plugin() {}
    static std::unique_ptr<Plugin> creerPlugin(const std::string& type);
};

class CorrecteurOrthographique : public Plugin {
public:
    std::string nom() const override;
    std::string traiter(const std::string& texte) override;
};

class TraducteurAnglais : public Plugin {
public:
    std::string nom() const override;
    std::string traiter(const std::string& texte) override;
};

class AnalyseurStyle : public Plugin {
public:
    std::string nom() const override;
    std::string traiter(const std::string& texte) override;
};

#endif
