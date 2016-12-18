//
// Created by opot on 17.12.16.
//

#ifndef VESSELS_DESTINATION_H
#define VESSELS_DESTINATION_H

#include "common.h"
namespace vessels {

// Место назначения
    class Destination {
    private:
        // название порта назначения
        std::string description;
        // координаты места назначения
        int x, y;

    public:
        Destination(std::string description, int x, int y);

        Destination(const Destination *d);

        bool operator==(const Destination &d);

        friend std::ostream &operator<<(std::ostream &os, const Destination &d);

        friend class NavalFreightCompany;
    };
}

#endif //VESSELS_DESTINATION_H
