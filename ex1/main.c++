#include "HautParleur.h"
#include "CasqueBT.h"
#include "SortieHDMI.h"

void tester(SortieAudio* sortie) {
    sortie->ouvrir();
    sortie->jouer("Musique.mp3");
    sortie->fermer();

}

int main() {
    SortieAudio* sorties[3];

    sorties[0] = new HautParleur();
    sorties[1] = new CasqueBT();
    sorties[2] = new SortieHDMI();

    for (int i = 0; i < 3; ++i) {
        tester(sorties[i]);
        delete sorties[i];
    }

    return 0;
}
