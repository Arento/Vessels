//
// Created by opot on 17.12.16.
//

#ifndef VESSELS_PSSENGERVESSEL_H
#define VESSELS_PSSENGERVESSEL_H


#include <cstdlib>
#include "Vessel.h"
namespace vessels {
    class PassengerVessel : public Vessel {
    public:
        enum CabinType {
            LUX, FIRSTCLASS, SECONDCLASS
        };

    private:
        int maxpax;
        int curpax;
        int cabin_num;

        CabinType *cabincontent;

    public:
        PassengerVessel(const PassengerVessel* pv);
        PassengerVessel(const PassengerVessel& pv);
        PassengerVessel(const Vessel *v, int maxpax, int curpax, int cabin_num, ...);
        PassengerVessel(const Vessel *v, int maxpax, int curpax, int cabin_num, const CabinType* cabincontent);
        PassengerVessel(const Destination *dest, int ETA, const ShipProperties *props,
                        int maxpax, int curpax, int cabin_num, ...);

        virtual ~PassengerVessel();

        PassengerVessel& operator=(const PassengerVessel& pv);

        virtual PassengerVessel* clone() const;


        friend std::ostream &operator<<(std::ostream &os, const PassengerVessel &v);

        friend class Audit;
    };

}
#endif //VESSELS_PSSENGERVESSEL_H
