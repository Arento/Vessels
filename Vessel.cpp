//
// Created by Valery Antopol on 17.12.16.
//

#include "Vessel.h"

namespace vessels {
    int Vessel::idGen = 0;

    void Vessel::generateId() {
        id = idGen;
        idGen++;
    }

    Vessel::Vessel() {
        generateId();
        destination = nullptr;
        props = nullptr;
        ETA = -1;
    }

    Vessel::Vessel(const Vessel &v) : Vessel(v.destination,v.ETA,v.props) {}

    Vessel::Vessel(const Vessel *v) : Vessel(v->destination, v->ETA, v->props) {}

    Vessel::Vessel(const Destination *destination, int ETA, const ShipProperties *props) {
        generateId();
        this->destination = new Destination(destination);
        this->props = new ShipProperties(props);
        this->ETA = ETA;
    }

    Vessel& Vessel::operator=(const Vessel& v) {
        delete props;
        delete destination;
        props = new ShipProperties(v.props);
        destination = new Destination(v.destination);
        return *this;
    }

    int Vessel::getId() const {
        return id;
    }

    Vessel* Vessel::clone() const {
        return new Vessel(this);
    }

    std::ostream &operator<<(std::ostream &os, const Vessel &v) {
        os << "Vessel\n  Id: " << v.id << std::endl
           << "  Desstination: " << *(v.destination) << std::endl
           << "  Properties:  " << *(v.props);
        return os;
    }

    Vessel::~Vessel() {
        delete props;
        delete destination;
    }
}