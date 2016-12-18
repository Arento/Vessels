//
// Created by opot on 17.12.16.
//

#ifndef VESSELS_NAVALFREIGHTCOMPANY_H
#define VESSELS_NAVALFREIGHTCOMPANY_H



#include "CargoVessel.h"
#include <list>
namespace vessels {
    class NavalFreightCompany {
    private:
        // имеющиеся корабли
        std::list<Vessel *> ships;
        Destination *location;
    public:
        // добавление корабля
        void add(const Vessel *v, const Destination *d);

        void add(const Vessel *v);

        // удаление корабля
        int remove(const Vessel *v);

        int remove(int id);

        // место где порт расположен


        // списать весь хлам - когда-либо ремонтировавшиеся суда

        void draft();

        // напечатать статистику: сколько пассажирских, сколько грузовых, из них когда-либо ломавшихся
        void printStats() const;

        // внести запись о ремонте корабля по id
        void markRepaired(int id, const std::string *date_repaired);

        // внести запись о повреждении корабля по id
        void markDamaged(int id, const std::string *date_damaged);

        // поменять пункт назначения корабля
        int changeDestination(int id, const Destination *dest);

        // напечатать сколько кораблей идут в пункт назначения X
        void printHeadingTo(std::string s) const;


        // Печать всех данных о компании
        NavalFreightCompany(Destination* dest);
        friend std::ostream &operator<<(std::ostream &os, const NavalFreightCompany &v);

        friend class Audit;
    };
}
#endif //VESSELS_NAVALFREIGHTCOMPANY_H
