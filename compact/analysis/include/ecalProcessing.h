#ifndef ECALPROCESSING_H
#define ECALPROCESSING_H

#include "timeFrames.h"
#include "globals.h"

void DecodeEcal(long long int ihitchan, int& idet, int& ix, int& iy, int& islice, int& ilayer, int& wc, int& type);
void calibrateEcal(int ievt, int gendete, CalHits* &ecalhits, TBranch* &b_ecal, float &meanscinEcal, float &meancerEcal);
void calibrateEcalGendete(int gendete, CalHits* &ecalhits, int ievt, TBranch* &b_ecal, int index);
void calibrateEcalGendeteThreeAndFour(int gendete, int idet, int type, CalVision::DualCrysCalorimeterHit* &aecalhit);
void calibrateEcalGendeteFive(float &meanscinEcal, float &meancerEcal);
void calibrateEcalGendeteSix(float &meanscinEcal, float &meancerEcal);
void calibrateEcalgetStuffGendeteSix(float &nescinttotecal, float &necertotecal);
void calibrateEcalgetStuffGendeteFive(float &nescinttotecal, float &necertotecal);
void calibrateEcalgetStuffGendete(CalVision::DualCrysCalorimeterHit* &aecalhit, int gendete, float &necertotecal, float &nescinttotecal, float &eecaltimecut, float &erelecaltimecut);
void calibrateEcalgetStuff(int ievt, int gendete, TBranch* &b_ecal, CalHits* &ecalhits, float &necertotecal, float &nescinttotecal, float &eecaltimecut, float &erelecaltimecut);

void calibrateEcalFillTimeGendete(CalVision::DualCrysCalorimeterHit* &aecalhit, int gendete, float &necertotecal, float &nescinttotecal, float &eecaltimecut, float &erelecaltimecut);

void calibrateEcalFilltime(int ievt, int nbyteecal, int gendete, TBranch* &b_ecal, CalHits* &ecalhits, float &necertotecal, float &nescinttotecal, float &eecaltimecut, float &erelecaltimecut, TH1F *ecalpd1scint, TH1F* ecalpd1cer, TH1F* eecaltime);
#endif 