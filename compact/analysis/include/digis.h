#ifndef DIGIS_H
#define DIGIS_H

#include "TH1.h"
#include <iostream>
#include <algorithm>
#include "timeFrames.h"
#include "globals.h"

/*Digis for ECAL */
double int_charge(TH1F* out, double pre, double window);
void Elec_Sim(TH1F* In, TH1F* Out);
double SPR(double tNow);
double sipmpde(int isipm, double wavelength);
double AFILTER(int ifilter, double wavelength);

/*Digis for HCAL*/

#endif 