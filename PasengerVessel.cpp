//
// Created by opot on 17.12.16.
//

#include "PasengerVessel.h"
namespace vessels {
    PassengerVessel::PassengerVessel(const Destination *dest, int eta, const ShipProperties *props, int maxpax,
                                     int curpax, int cabin_num, ...) : Vessel(dest, eta, props),
                                                                       maxpax(maxpax),
                                                                       curpax(curpax),
                                                                       cabin_num(cabin_num) {
        this->cabincontent = new CabinType[cabin_num];
        va_list vaList;
        va_start(vaList, cabin_num);

        for (int i = 0; i < cabin_num; i++)
            this->cabincontent[i] = (CabinType) va_arg(vaList, int);
        va_end(vaList);
    }

    PassengerVessel::~PassengerVessel() {
        delete [] cabincontent;
    }

    PassengerVessel::PassengerVessel(const PassengerVessel& pv) : Vessel(pv),cabin_num(pv.cabin_num),
                                                                 curpax(pv.curpax),maxpax(pv.maxpax) {
        this->cabincontent = new CabinType[this->cabin_num];
        for(int i=0;i<this->cabin_num;i++)
            this->cabincontent[i] = pv.cabincontent[i];
    }

    PassengerVessel::PassengerVessel(const PassengerVessel *pv) : Vessel(pv),cabin_num(pv->cabin_num),
                                                                  curpax(pv->curpax),maxpax(pv->maxpax) {
        this->cabincontent = new CabinType[this->cabin_num];
        for(int i=0;i<this->cabin_num;i++)
            this->cabincontent[i] = pv->cabincontent[i];
    }

    PassengerVessel& PassengerVessel::operator=(const PassengerVessel &pv) {
        delete props;
        delete destination;
        delete cabincontent;
        maxpax = pv.maxpax;
        curpax = pv.curpax;
        cabin_num = pv.cabin_num;
        destination = new Destination(pv.destination);
        props = new ShipProperties(pv.props);
        cabincontent = new CabinType[cabin_num];
        for(int i=0;i<cabin_num;i++)
            cabincontent[i] = pv.cabincontent[i];

        return *this;
    }

    PassengerVessel::PassengerVessel(const Vessel *v, int maxpax,
                                     int curpax, int cabin_num, ...) : Vessel(v),
                                                                       maxpax(maxpax),
                                                                       curpax(curpax),
                                                                       cabin_num(cabin_num) {
        cabincontent = new CabinType[cabin_num];
        va_list vaList;
        va_start(vaList, cabin_num);

        for (int i = 0; i < cabin_num; i++)
            cabincontent[i] = (CabinType) va_arg(vaList, int);
        va_end(vaList);
    }

    PassengerVessel::PassengerVessel(const Vessel *v, int maxpax, int curpax,
                                     int cabin_num, const CabinType* cabincontent) : Vessel(v),
                                                                               maxpax(maxpax),
                                                                               curpax(curpax),
                                                                               cabin_num(cabin_num) {
        this->cabincontent = new CabinType[cabin_num];
        for (int i = 0; i < cabin_num; i++)
            this->cabincontent[i] = cabincontent[i];
    }

    PassengerVessel* PassengerVessel::clone() const{

        return new PassengerVessel(this,maxpax,curpax,cabin_num,cabincontent);

    }
    std::ostream &operator<<(std::ostream &os, const PassengerVessel &v) {
        os << "Passenger Vessel"
           << "\n  Id: " << v.getId()
           << "\n  " << *v.destination
           << "\n  " << *v.props
           << "\n  Maxpax: " << v.maxpax
           << "\n  Curpax: " << v.curpax
           << "\n  Cabin size: " << v.cabin_num
           << "\n  Cabin content: ";
        for (int i = 0; i < v.cabin_num; i++)
            os << v.cabincontent[i] << ' ';
        os << std::endl;
        return os;
    }


}