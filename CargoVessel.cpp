#include "CargoVessel.h"
//
// Created by opot on 17.12.16.
//
namespace vessels {
    CargoVessel::CargoVessel(const Destination *dest, int eta, const ShipProperties *props, int maxcargo,
                             int curcargo, int container_num, ...) : Vessel(dest, eta, props),
                                                                     maxcargo(maxcargo),
                                                                     curcargo(curcargo),
                                                                     container_num(container_num) {
        this->containercontent = new CargoType[container_num];
        va_list vaList;
        va_start(vaList, container_num);

        for (int i = 0; i < container_num; i++)
            this->containercontent[i] = (CargoType) va_arg(vaList, int);
        va_end(vaList);
    }

    CargoVessel::CargoVessel(const Vessel *v, int maxcargo,
                             int curcargo, int container_num, const CargoType* containercontent) : Vessel(v),
                                                                     maxcargo(maxcargo),
                                                                     curcargo(curcargo),
                                                                     container_num(container_num) {
        this->containercontent = new CargoType[container_num];
        for (int i = 0; i < container_num; i++)
            this->containercontent[i] = containercontent[i];
    }

    CargoVessel::CargoVessel(const Vessel* v, int maxcargo,
                             int curcargo, int container_num, ...) : Vessel(v),
                                                                     maxcargo(maxcargo),
                                                                     curcargo(curcargo),
                                                                     container_num(container_num) {
        this->containercontent = new CargoType[container_num+200];
        va_list vaList;
        va_start(vaList, container_num);

        for (int i = 0; i < container_num; i++)
            this->containercontent[i] = (CargoType) va_arg(vaList, int);
        va_end(vaList);
    }



    CargoVessel::~CargoVessel() {
       // std::cout << "\n~CargoVessel() " << sizeof(containercontent) << " " << containercontent[container_num-1] << std::endl;
        delete [] containercontent;
    }

    CargoVessel* CargoVessel::clone() const {
        return new CargoVessel(this,maxcargo,curcargo,container_num,containercontent);

    }

    std::ostream &operator<<(std::ostream &os, const CargoVessel &v) {
        os << "Cargo Vessel"
           << "\n  Id: " << v.getId()
           << "\n  " << *v.destination
           << "\n  " << *v.props
           << "\n  Maxcargo: " << v.maxcargo
           << "\n  Curcargo: " << v.curcargo
           << "\n  Container size: " << v.container_num
           << "\n  Contuiner content:  ";
        for (int i = 0; i < v.container_num; i++)
            os << v.containercontent[i] << ' ';
        os << std::endl;
        return os;
    }

    CargoVessel::CargoVessel(const CargoVessel *cv) : Vessel(cv), curcargo(cv->curcargo),
                                                      maxcargo(cv->maxcargo),
                                                      container_num(cv->container_num){
        this->containercontent = new CargoType[this->container_num];
        for(int i =0;i<this->container_num;i++)
            this->containercontent[i] = cv->containercontent[i];
    }

    CargoVessel::CargoVessel(const CargoVessel &cv) : Vessel(cv), curcargo(cv.curcargo),
                                                      maxcargo(cv.maxcargo),
                                                      container_num(cv.container_num){
        this->containercontent = new CargoType[this->container_num];
        for(int i=0;i<this->container_num;i++)
            this->containercontent[i] = cv.containercontent[i];
    }

    CargoVessel& CargoVessel::operator=(const CargoVessel &cv) {
        delete containercontent;
        delete destination;
        delete props;
        container_num = cv.container_num;
        containercontent = new CargoType[container_num];
        for(int i=0;i<container_num;i++)
            containercontent[i] = cv.containercontent[i];
        maxcargo = cv.maxcargo;
        curcargo = cv.curcargo;
        destination = new Destination(cv.destination);
        props = new ShipProperties(cv.props);
        return *this;
    }
}
