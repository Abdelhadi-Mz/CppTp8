#include "Plugin.h"
#include <algorithm>

std::string CorrecteurOrthographique::nom() const { return "Correcteur Orthographique"; }

std::string CorrecteurOrthographique::traiter(const std::string& texte) {
    std::string resultat = texte;
    size_t pos;
    while ((pos = resultat.find("jsuis")) != std::string::npos)
        resultat.replace(pos, 5, "je suis");
    while ((pos = resultat.find("pk")) != std::string::npos)
        resultat.replace(pos, 2, "pourquoi");
    return resultat;
}

std::string TraducteurAnglais::nom() const { return "Traducteur Anglais"; }

std::string TraducteurAnglais::traiter(const std::string& texte) {
    std::string resultat = texte;
    size_t pos;
    while ((pos = resultat.find("bonjour")) != std::string::npos)
        resultat.replace(pos, 7, "hello");
    while ((pos = resultat.find("monde")) != std::string::npos)
        resultat.replace(pos, 5, "world");
    return resultat;
}

std::string AnalyseurStyle::nom() const { return "Analyseur de Style"; }

std::string AnalyseurStyle::traiter(const std::string& texte) {
    int longues = 0;
    size_t start = 0, end;
    while ((end = texte.find('.', start)) != std::string::npos) {
        std::string phrase = texte.substr(start, end - start);
        if (phrase.size() > 80) longues++;
        start = end + 1;
    }
    std::string resultat = texte;
    if (longues > 0)
        resultat += "\nAttention : " + std::to_string(longues) + " phrases sont trop longues.";
    return resultat;
}

std::unique_ptr<Plugin> Plugin::creerPlugin(const std::string& type) {
    if (type == "correcteur") return std::make_unique<CorrecteurOrthographique>();
    if (type == "traducteur") return std::make_unique<TraducteurAnglais>();
    if (type == "analyseur") return std::make_unique<AnalyseurStyle>();
    return nullptr;
}
