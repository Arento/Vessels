//
// Created by opot on 17.12.16.
//

#ifndef VESSELS_AUDIT_H
#define VESSELS_AUDIT_H


#include "NavalFreightCompany.h"
#include "Vessel.h"
#include "CargoVessel.h"
#include "PasengerVessel.h"
namespace vessels {
    class Audit {
    public:
        // Узнать есть ли в порту данной компании дежурящие пассажирские суда (у которых destination совпадает с location)
        static bool isPassengerVesselsInPort(const NavalFreightCompany &nfc);

        // Сравнить две компании, вывести более крупную (считается суммарно), сигнатуру придумать самостоятельно
        static const NavalFreightCompany &compare1(const NavalFreightCompany &nfc1, const NavalFreightCompany &nfc2);

        // Сравнить две компании, вывести более надежную (меньше когда-либо ремонтировавшихся судов), сигнатуру придумать самостоятельно
        static const NavalFreightCompany &compare2(const NavalFreightCompany &nfc1, const NavalFreightCompany &nfc2);

        // проинспектировать пассажирский корабль на предмет наличия большего количества людей чем положено по нормативу
        static bool inspectPassengerVessel(PassengerVessel v);

        // проинспектировать пассажирский корабль на предмет наличия большего количества контейнеров чем положено по нормативу
        static bool inspectCargoVessel(CargoVessel v);
    };
}

#endif //VESSELS_AUDIT_H
