#ifndef ECALPROCESSING_H
#define ECALPROCESSING_H

#include "timeFrames.h"

int nbyteecal, nbyteedge;
float meanscinEcal(0.),meancerEcal(0),egEcal(0.);
float meaneecaltimecut(0),meanerelecaltimecut(0);
float meanSEcal(0.),meanCEcal(0.);
float eesum(0.),eesumcal(0.),eesumem(0.),eesumair(0.),eesumdead(0.),eesumcrystal(0.),eesumPDe(0.),eesumfiber1(0.),eesumfiber2(0.),eesumabs(0.),eesumPDh(0.),eesumedge(0.),eesumedgerel(0.),necertotecal(0.),nescinttotecal(0.),necertothcal(0.),nescinttothcal(0.),eecaltimecut(0.),ehcaltimecut(0.),erelecaltimecut(0.),erelhcaltimecut(0.),eesumairem(0.),eesumdeadem(0.),eesumcrystalem(0.),eesumPDeem(0.),eesumfiber1em(0.),eesumfiber2em(0.),eesumabsem(0.),eesumPDhem(0.);
typedef std::vector<CalVision::DualCrysCalorimeterHit*> CalHits;

void DecodeEcal(long long int ihitchan, int& idet, int& ix, int& iy, int& islice, int& ilayer, int& wc, int& type);

void calibrateEcal(int ievt, int gendete, CalHits* &ecalhits, TBranch* &b_ecal);

void calibrateEcalGendete(int gendete, CalHits* &ecalhits, int ievt, TBranch* &b_ecal, int index);

void calibrateEcalGendeteThreeAndFour(int gendete, int idet, int type, CalVision::DualCrysCalorimeterHit* &aecalhit);
void calibrateEcalGendeteFive();
void calibrateEcalGendeteSix();
#endif 