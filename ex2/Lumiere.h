#ifndef LUMIERE_H
#define LUMIERE_H

#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

struct Vec3 {
    float x, y, z;
    Vec3(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}
    float distance(const Vec3& other) const {
        return std::sqrt((x - other.x) * (x - other.x) +
                         (y - other.y) * (y - other.y) +
                         (z - other.z) * (z - other.z));
    }
    float dot(const Vec3& other) const {
        return x * other.x + y * other.y + z * other.z;
    }
    Vec3 normalize() const {
        float norm = std::sqrt(x * x + y * y + z * z);
        if (norm == 0) return Vec3(0, 0, 0);
        return Vec3(x / norm, y / norm, z / norm);
    }
};

class Lumiere {
public:
    virtual float intensite(const Vec3& position) const = 0;
    virtual ~Lumiere() {}
};

class LumiereDirectionnelle : public Lumiere {
    Vec3 direction;
    float intensiteBase;
public:
    LumiereDirectionnelle(const Vec3& dir, float intensiteBase = 1.0f)
        : direction(dir.normalize()), intensiteBase(intensiteBase) {}
    float intensite(const Vec3&) const override {
        return intensiteBase;
    }
};

class LumierePonctuelle : public Lumiere {
    Vec3 position;
    float attenuation;
public:
    LumierePonctuelle(const Vec3& pos, float attenuation = 0.1f)
        : position(pos), attenuation(attenuation) {}
    float intensite(const Vec3& point) const override {
        float dist = position.distance(point);
        return 1.0f / (1.0f + attenuation * dist * dist);
    }
};

class LumiereSpot : public Lumiere {
    Vec3 position;
    Vec3 direction;
    float angleOuverture;
public:
    LumiereSpot(const Vec3& pos, const Vec3& dir, float angle)
        : position(pos), direction(dir.normalize()), angleOuverture(angle) {}
    float intensite(const Vec3& point) const override {
        Vec3 toPoint = Vec3(point.x - position.x, point.y - position.y, point.z - position.z).normalize();
        float dotValue = direction.dot(toPoint);
        float angle = std::acos(dotValue) * (180.0 / M_PI);
        if (angle < angleOuverture)
            return std::max(0.0f, dotValue);
        return 0.0f;
    }
};

float calculerEclairage(const std::vector<std::unique_ptr<Lumiere>>& lumieres, const Vec3& point);

#endif
