//
// Created by opot on 17.12.16.
//
#include "Destination.h"
namespace vessels {
    Destination::Destination(std::string description, int x, int y) {
        this->description = description;
        this->x = x;
        this->y = y;
    }

    Destination::Destination(const Destination *d) {
        description = d->description;
        x = d->x;
        y = d->y;
    }

    bool Destination::operator==(const Destination &d) {
        return description == d.description && x == d.x && y == d.y;
    }

    std::ostream &operator<<(std::ostream &os, const Destination &d) {
        os << d.description << ' ' << d.x << ' ' << d.y;
        return os;
    }
}

