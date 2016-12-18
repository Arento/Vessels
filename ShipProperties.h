//
// Created by opot on 17.12.16.
//

#ifndef VESSELS_SHIPPROPERTIES_H
#define VESSELS_SHIPPROPERTIES_H

#include "common.h"
#include "ShipProperties.h"
namespace vessels {
    struct ShipProperties {
        // дата повреждения
        std::string *damaged;
        // дата ремонта
        std::string *repaired;

        ShipProperties();

        ShipProperties(const ShipProperties *sh);

        ShipProperties(const std::string *damaged, const std::string *repaired);

        friend std::ostream &operator<<(std::ostream &os, const ShipProperties &sp);

        ~ShipProperties();
    };
}


#endif //VESSELS_SHIPPROPERTIES_H
