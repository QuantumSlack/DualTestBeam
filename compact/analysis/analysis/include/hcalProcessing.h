#ifndef HCALPROCESSING_H
#define HCALPROCESSING_H
#include "timeFrames.h"
#include "calibration.h"
#include "globals.h"
static int nbytehcal;

void DecodeFiber (long long int ihitchan, int& idet, int& ilayer, int& itube, int& iair, int&itype, int& ifiber, int& iabs, int& iphdet, int& ihole, int& ix, int& iy);

void DecodeSampling(long long int ihitchan, int& idet, int& ix, int& iy, int& ilayer, int& ibox2, int& islice);

void calibrateFiberHcalGendethThreeAndFour(CalVision::DualCrysCalorimeterHit* &ahcalhit,int idet, int ifiber, int gendeth);

void calibrateFiberHcal(int gendeth, int ifiber, int idet, int iphdet, CalVision::DualCrysCalorimeterHit* &ahcalhit);

void calibrateSamplingHcal(int gendeth, int islice, int idet, CalVision::DualCrysCalorimeterHit* &ahcalhit, int ievt);

void calibrateSamplingHcalGendethThreeAndFour(int idet, int islice, int gendeth, int ievt, CalVision::DualCrysCalorimeterHit* &ahcalhit);

void calibrateHcalGendeth(int hcaltype, CalVision::DualCrysCalorimeterHit* &hcalhits);

void calibrateHcal(int ievt, int gendeth, CalHits* &hcalhits, TBranch* &b_hcal, int hcaltype);


#endif 
