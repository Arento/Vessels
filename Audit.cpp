//
// Created by opot on 17.12.16.
//


#include "Audit.h"
namespace vessels {
    bool Audit::isPassengerVesselsInPort(const NavalFreightCompany &nfc) {
        bool ret = false;
        for (auto ship : nfc.ships)
            ret |= (*(ship->destination) == *(nfc.location));
        return ret;
    }

    const NavalFreightCompany &Audit::compare1(const NavalFreightCompany &nfc1, const NavalFreightCompany &nfc2) {
        return (nfc1.ships.size() < nfc2.ships.size() ? nfc2 : nfc1);

    }

    const NavalFreightCompany &Audit::compare2(const NavalFreightCompany &nfc1, const NavalFreightCompany &nfc2) {
        int np1 = 0;
        for (auto ship: nfc1.ships)
            if (ship->props->repaired == nullptr)
                np1++;

        int np2 = 0;
        for (auto ship: nfc2.ships)
            if (ship->props->repaired == nullptr)
                np2++;
        return (np1 > np2 ? nfc1 : nfc2);
    }

    bool Audit::inspectPassengerVessel(PassengerVessel v) {
        return v.curpax > v.maxpax;
    }

    bool Audit::inspectCargoVessel(CargoVessel v) {
        return v.curcargo > v.maxcargo;
    }
}