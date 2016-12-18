// Vessels v1, Георгий Чернышев, 16.11.2013

#include <stdio.h>
#include <list>
#include <string>
#include "CargoVessel.h"
#include "PasengerVessel.h"
#include "NavalFreightCompany.h"
#include "Audit.h"

// Необходимо реализовать функциональность, где надо исправить ошибки и недописанные куски.
// Интерфейс можно менять в целях исправления, при этом надо быть готовым обосновать.
// Интерфейс можно расширять в целях улучшения, то же необходимо обосновать. Расставить const-ы.
// Типы данных менять нельзя, то есть если храним где-то указатель, нельзя начать хранить по значению.
// Кроме того, в конце будет необходимо модуляризовать код и написать вызовы демонстрирующие работу.

// Обратите внимание, сейчас код компилируется!

// Свойства корабля: был ли корабль поврежден и отремонтирован; дата соответствующих событий.
// Если не был поврежден, то пустая строка.









// класс аудитор компании, делает различные проверки

using namespace vessels;
int main(){
    std::string s1 ="10.02.2016";
    std::string s2="13.04.2016";
    ShipProperties *sp1 = new ShipProperties(&s1,&s2);
    std::string *rep = new std::string("02.04.2002");
    std::string *dam = new std::string("05.04.2005");
    ShipProperties *sp2 = new ShipProperties(dam, rep);
    ShipProperties *sp3 = new ShipProperties();

    std::string *sd1 = new std::string("Glazgo");
    std::string *sd2 = new std::string("Porta");
    Destination *d1 = new Destination(*sd1, 5, 3);
    Destination *d2 = new Destination(*sd2, 2, 1);
    Destination *d3 = new Destination("Glazgo", 4, 2);





  //  if (d3->getDescription() != d1->getDescription())
  //      std::cout << "Error with Destination::getDesctiption()";
    //if (d3 == d1) {
        std::cout << "Error with Destination::operator==" << std::endl;
   // }


    Vessel *v1 = new Vessel();
    Vessel *v2 = new Vessel(d1, 321, sp1);
    Vessel *v3 = v2->clone();
    delete v2;
    std::cout << *v3 << std::endl;
    delete v1;

   // CargoVessel *cv1 = new CargoVessel();
    CargoVessel *cv2 = new CargoVessel(v3, 15, 16, 3, CargoVessel::CargoType::FOOD, CargoVessel::WOOD, CargoVessel::WOOD);
    //CargoVessel *cv3 = new CargoVessel(d1, 431, sp2, 14);
    CargoVessel *cv4 = cv2->clone();
    CargoVessel *cv5 = new CargoVessel(v3, 15, 16, 3, CargoVessel::CargoType::FOOD, CargoVessel::WOOD, CargoVessel::WOOD);
    std::cout << *cv2 << std::endl;
    delete cv2;
    std::cout << *cv4 << std::endl;


  //  PassengerVessel *pv1 = new PassengerVessel();
    PassengerVessel *pv2 = new PassengerVessel(d3,312, sp1, 100, 90, 4, PassengerVessel::CabinType::FIRSTCLASS, PassengerVessel::CabinType::LUX, PassengerVessel::CabinType::FIRSTCLASS, PassengerVessel::CabinType::SECONDCLASS);
    PassengerVessel *pv3 = pv2->clone();
    PassengerVessel *pv4 = new PassengerVessel(d1, 23, sp2, 50, 34, 2, PassengerVessel::CabinType::LUX, PassengerVessel::CabinType::FIRSTCLASS);
    std::cout << *pv2 << std::endl << *pv3 << std::endl;
    Destination *d5 = new Destination("Genua", 414, 34);
    NavalFreightCompany *nfc1 = new NavalFreightCompany(d5);
   // nfc1->add(pv1);
   // nfc1->add(cv3);
   // nfc1->add(cv1);
    nfc1->add(pv4);
    Destination* d6 = new Destination("Venezia", 30, 134);
    nfc1->add(pv2, d6);
    nfc1->printStats();
    std::cout << *nfc1;
    nfc1->markDamaged(9, dam);
    nfc1->draft();
    std::cout << *nfc1;
    nfc1->markRepaired(9, rep);
    nfc1->draft();
    nfc1->remove(12);
    nfc1->remove(pv2);
    std::cout << *nfc1;
    Destination *d4 = new Destination("Murmansk", 41, 20);
    Destination *d7 = new Destination("Vladivostok", 1, 2);
    nfc1->changeDestination(10, d4);
    NavalFreightCompany *nfc2 = new NavalFreightCompany(d7);

    //nfc2->printHeadingTo("Vladivostok");
    if (Audit::isPassengerVesselsInPort(*nfc1)) {
        std::cout << "In "  << "there are PassengerVessels" << std::endl;
    }
    else {
        std::cout << "In "  << "there aren't PassengerVessels" << std::endl;
    }
    std::cout << "Largest company between nfc1 and nfc2 " << Audit::compare1(*nfc1, *nfc2) << std::endl;
    std::cout << "The most reliable company between nfc1 and nfc2" << Audit::compare2(*nfc1, *nfc2) << std::endl;
    if (Audit::inspectCargoVessel(cv5)) {
        std::cout << "Offense!" << std::endl;
    }
    else {
        std::cout << "No offense" << std::endl;

    }
    if (Audit::inspectPassengerVessel(pv2)) {
        std::cout << "Offense!" << std::endl;
    } else {
        std::cout << "No offense" << std::endl;

    }
    delete sp1;
    delete sp2;
    delete sp3;
    delete rep;
    delete dam;
    delete sd1;
    delete sd2;
    delete d1;
    delete d2;
    delete d3;
    delete d4;
    delete d6;
    delete d5;
    delete d7;
    delete v3;
 //   delete cv1;
 //   delete cv3;
    delete cv4;
    delete cv5;
 //   delete pv1;
    delete pv2;
    delete pv3;
    delete pv4;
    delete nfc1;
    delete nfc2;
    //*/

    return 0;
}
