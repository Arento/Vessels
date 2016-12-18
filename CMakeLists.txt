cmake_minimum_required(VERSION 3.6)
project(Vessels)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES VesselMain.cpp Destination.cpp Destination.h Vessel.cpp Vessel.h CargoVessel.cpp CargoVessel.h PasengerVessel.cpp PasengerVessel.h NavalFreightCompany.cpp NavalFreightCompany.h Audit.cpp Audit.h common.h ShipProperties.cpp ShipProperties.h)
add_executable(Vessels ${SOURCE_FILES})