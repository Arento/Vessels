//
// Created by opot on 17.12.16.
//

#include "NavalFreightCompany.h"
namespace vessels {
    int NavalFreightCompany::remove(int id) {
        for (auto itShip = ships.begin(); itShip != ships.end(); itShip++)
            if (((Vessel * )(*itShip))->getId() == id) {
                delete *itShip;
                ships.erase(itShip);
                return 1;
            }
        return 0;

    }

    int NavalFreightCompany::remove(const Vessel *v) {
        return remove(v->getId());
    }

    void NavalFreightCompany::add(const Vessel *v, const Destination *d) {
        add(v);
        changeDestination(v->getId(), d);
    }

    int NavalFreightCompany::changeDestination(int id, const Destination *dest) {
        for (auto itShip = ships.begin(); itShip != ships.end(); itShip++)
            if (((Vessel * )(*itShip))->getId() == id) {
                delete ((Vessel * )(*itShip))->destination;
                ((Vessel * )(*itShip))->destination = new Destination(dest);
            }
    }

    void NavalFreightCompany::add(const Vessel *v) {
        ships.push_back(v->clone());
    }

    void NavalFreightCompany::draft() {

        for (auto it = ships.begin(); it != ships.end(); it++) {
            if ((*it)->props->repaired != nullptr) {
                auto tmp = it;
                it--;
                delete *tmp;
                ships.erase(tmp);
            }
        }

    }

    void NavalFreightCompany::printHeadingTo(std::string s) const {
        int ret = 0;
        for (auto ship : ships)
            if (ship->destination->description == s)
                ret++;
        std::cout << ret << " ships  headting to " << s << std::endl;
    }

    void NavalFreightCompany::markRepaired(int id, const std::string *date_repaired) {
        for (auto itShip = ships.begin(); itShip != ships.end(); itShip++)
            if (((*itShip))->getId() == id) {
                delete (*itShip)->props->repaired;
                (*itShip)->props->repaired = new std::string(*date_repaired);
                break;
            }
    }

    void NavalFreightCompany::markDamaged(int id, const std::string *date_damaged) {
        for (auto itShip = ships.begin(); itShip != ships.end(); itShip++)
            if (((*itShip))->getId() == id) {
                delete (*itShip)->props->damaged;
                (*itShip)->props->damaged = new std::string(*date_damaged);
                break;
            }
    }

    void NavalFreightCompany::printStats() const {
        int pass = 0, cargo = 0, repPass = 0, repCargo = 0;
    }

    NavalFreightCompany::NavalFreightCompany(Destination *dest) : location(dest) {

    }

    std::ostream& operator<<(std::ostream& os,const NavalFreightCompany& nfc) {
        os << "\nDestinaton: " <<*nfc.location << std::endl;
        for(auto ship : nfc.ships)
            os << *ship << std::endl;
        return os;
    }
}