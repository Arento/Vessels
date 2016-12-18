//
// Created by opot on 17.12.16.
//

#ifndef VESSELS_VESSEL_H
#define VESSELS_VESSEL_H

#include "common.h"
#include "Destination.h"
#include "ShipProperties.h"
#include <iostream>
namespace vessels {
    class Vessel {
        static int idGen;
        // уникальный идентификатор
        int id;

        void generateId();


    protected:
        // пункт назначения
        Destination *destination;
        // сколько дней осталось время до прибытия
        int ETA;
        // свойства корабля
        ShipProperties *props;


    public:

        Vessel();

        Vessel(const Vessel &v);

        Vessel(const Vessel *v);

        Vessel(const Destination *dest, int ETA, const ShipProperties *props);

        Vessel& operator=(const Vessel& v);

        virtual ~Vessel();

        virtual Vessel* clone() const;

        int getId() const;

        friend std::ostream &operator<<(std::ostream &os, const Vessel &v);

        friend class Audit;

        friend class NavalFreightCompany;
    };

}

#endif //VESSELS_VESSEL_H
