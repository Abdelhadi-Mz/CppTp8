#include "Plugin.h"

int main() {
    std::vector<std::unique_ptr<Plugin>> plugins;
    plugins.push_back(Plugin::creerPlugin("correcteur"));
    plugins.push_back(Plugin::creerPlugin("traducteur"));
    plugins.push_back(Plugin::creerPlugin("analyseur"));

    std::string texte;
    std::cout << "Entrez un texte : ";
    std::getline(std::cin, texte);

    for (auto& p : plugins) {
        texte = p->traiter(texte);
        std::cout << "\n[" << p->nom() << "]\n" << texte << std::endl;
    }

    return 0;
}
