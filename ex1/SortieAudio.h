#ifndef SORTIEAUDIO_H
#define SORTIEAUDIO_H

#include <iostream>
#include <string>

class SortieAudio {
public:
    virtual void ouvrir() = 0;
    virtual void jouer(const std::string& son) = 0;
    virtual void fermer() = 0;

    virtual ~SortieAudio() {}
};

#endif
