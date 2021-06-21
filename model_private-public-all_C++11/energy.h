//
// Created by Magda on 17.02.2021.
//

#ifndef MODEL_PRIVATE_PUBLIC_ENERGY_H
#define MODEL_PRIVATE_PUBLIC_ENERGY_H

#include "lib.h"

double hamiltonian (int, int*, int*, double, double, double, double, double, double, double);
double calculateEnergySigma(int, int, int*, int* , double, double, double, double, double, double, double);
double calculateEnergyS(int, int, int*, int* , double, double, double, double, double, double, double);

#endif //MODEL_PRIVATE_PUBLIC_ENERGY_H
