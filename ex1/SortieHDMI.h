#ifndef SORTIEHDMI_H
#define SORTIEHDMI_H

#include "SortieAudio.h"

class SortieHDMI : public SortieAudio {
public:
    void ouvrir() override {
        std::cout << "[Sortie HDMI] Activation de la sortie HDMI.\n";
    }

    void jouer(const std::string& son) override {
        std::cout << "[Sortie HDMI] Lecture du son : " << son << std::endl;
    }

    void fermer() override {
        std::cout << "[Sortie HDMI] Désactivation de la sortie HDMI.\n";
    }
};

#endif
