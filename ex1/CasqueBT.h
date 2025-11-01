#ifndef CASQUEBT_H
#define CASQUEBT_H

#include "SortieAudio.h"

class CasqueBT : public SortieAudio {
public:
    void ouvrir() override {
        std::cout << "[Casque Bluetooth] Connexion Bluetooth etablie.\n";
    }

    void jouer(const std::string& son) override {
        std::cout << "[Casque Bluetooth] Lecture du son : " << son << std::endl;
    }

    void fermer() override {
        std::cout << "[Casque Bluetooth] Déconnexion Bluetooth.\n";
    }
};

#endif
