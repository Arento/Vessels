//
// Created by opot on 17.12.16.
//

#ifndef VESSELS_CARGOVESSEL_H
#define VESSELS_CARGOVESSEL_H

    
#include "Vessel.h"
namespace vessels {
    class CargoVessel : public Vessel {
    public:
        enum CargoType {
            FOOD, WOOD, GOOD
        };

    private:
        int maxcargo;
        int curcargo;
        int container_num;
        CargoType* containercontent;

    public:
        CargoVessel(const CargoVessel* cv);
        CargoVessel(const CargoVessel& cv);
        CargoVessel(const Vessel *v, int maxcargo, int curcargo, int container_num, ...);
        CargoVessel(const Vessel *v, int maxcargo, int curcargo, int container_num, const CargoType* containercontent);
        CargoVessel(const Destination *dest, int ETA, const ShipProperties *props, int maxcargo,
                    int curcargo, int container_num, ...);

        virtual ~CargoVessel();

        CargoVessel& operator=(const CargoVessel& pv);

        virtual CargoVessel* clone() const;


        friend std::ostream &operator<<(std::ostream &os, const CargoVessel &v);

        friend class Audit;
    };
}


#endif //VESSELS_CARGOVESSEL_H
