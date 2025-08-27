#ifndef HCALPROCESSING_H
#define HCALPROCESSING_H
#include "timeFrames.h"
#include "calibration.h"
int nbytehcal;

float meanscinHcal(0.),meancerHcal(0),egHcal(0.);
float meanehcaltimecut(0),meanerelhcaltimecut(0);
float meanSHcal(0.),meanCHcal(0.);
typedef std::vector<CalVision::DualCrysCalorimeterHit*> CalHits;


void DecodeFiber (long long int ihitchan, int& idet, int& ilayer, int& itube, int& iair, int&itype, int& ifiber, int& iabs, int& iphdet, int& ihole, int& ix, int& iy);

void DecodeSampling(long long int ihitchan, int& idet, int& ix, int& iy, int& ilayer, int& ibox2, int& islice);

void calibrateFiberHcalGendethThreeAndFour(CalHits* &ahcalhit,int idet, int ifiber, int gendeth);

void calibrateFiberHcal(int gendeth, int ifiber, int idet, int iphdet, CalHits* &ahcalhit);

void calibrateSamplingHcal(int gendeth, int islice, int idet, CalHits* &ahcalhit, int ievt);

void calibrateSamplingHcalGendethThreeAndFour(int idet, int islice, int gendeth, int ievt, CalHits* &ahcalhit);

void calibrateHcalGendeth(int hcaltype, CalHits* &hcalhits);

void calibrateHcal(int ievt, int gendeth, CalHits* &hcalhits, TBranch* &b_hcal, int hcaltype);


#endif 