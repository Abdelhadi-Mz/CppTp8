#include "Lumiere.h"

float calculerEclairage(const std::vector<std::unique_ptr<Lumiere>>& lumieres, const Vec3& point) {
    float total = 0.0f;
    for (const auto& l : lumieres)
        total += l->intensite(point);
    return total;
}

int main() {
    std::vector<std::unique_ptr<Lumiere>> lumieres;

    lumieres.push_back(std::make_unique<LumiereDirectionnelle>(Vec3(1, -1, 0), 0.8f));
    lumieres.push_back(std::make_unique<LumierePonctuelle>(Vec3(2, 3, 1), 0.2f));
    lumieres.push_back(std::make_unique<LumiereSpot>(Vec3(0, 0, 0), Vec3(1, 0, 0), 30));

    std::vector<Vec3> points = {
        Vec3(0, 0, 0),
        Vec3(1, 1, 1),
        Vec3(3, 2, 0)
    };

    for (const auto& p : points) {
        std::cout << "Intensite totale au point (" << p.x << ", " << p.y << ", " << p.z
                  << ") : " << calculerEclairage(lumieres, p) << std::endl;
    }

    return 0;
}
