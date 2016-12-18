//
// Created by opot on 17.12.16.
//

#include "ShipProperties.h"
namespace vessels {
    std::ostream &operator<<(std::ostream &os, const ShipProperties &sh) {
        return os << *(sh.damaged) << " " << *(sh.repaired);
    }

    ShipProperties::ShipProperties(const ShipProperties *sh) {
        damaged = new std::string(*(sh->damaged));
        repaired = new std::string(*(sh->repaired));
    }

    ShipProperties::~ShipProperties() {
        delete damaged;
        delete repaired;
    }

    ShipProperties::ShipProperties() {
        damaged = nullptr;
        repaired = nullptr;
    }

    ShipProperties::ShipProperties(const std::string *damaged, const std::string *repaired) {
        this->damaged = new std::string(*damaged);
        this->repaired = new std::string(*repaired);
    }
}