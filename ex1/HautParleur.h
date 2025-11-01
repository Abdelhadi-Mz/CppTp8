#ifndef HAUTPARLEUR_H
#define HAUTPARLEUR_H

#include "SortieAudio.h"

class HautParleur : public SortieAudio {
public:
    void ouvrir() override {
        std::cout << "[HautParleur] Ouverture du haut-parleur.\n";
    }

    void jouer(const std::string& son) override {
        std::cout << "[HautParleur] Lecture du son : " << son << std::endl;
    }

    void fermer() override {
        std::cout << "[HautParleur] Fermeture du haut-parleur.\n";
    }
};

#endif
