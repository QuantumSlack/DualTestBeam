#ifndef HCALPROCESSING_H
#define HCALPROCESSING_H
#include "timeFrames.h"
#include "calibration.h"
#include "globals.h"

void DecodeFiber (long long int ihitchan, int& idet, int& ilayer, int& itube, int& iair, int&itype, int& ifiber, int& iabs, int& iphdet, int& ihole, int& ix, int& iy);

void DecodeSampling(long long int ihitchan, int& idet, int& ix, int& iy, int& ilayer, int& ibox2, int& islice);

void calibrateFiberHcalGendethThreeAndFour(CalVision::DualCrysCalorimeterHit* &ahcalhit,int idet, int ifiber, int gendeth, float &meanscinHcal, float &meancerHcal, float &ehcaltimecut, float &erelhcaltimecut);

void calibrateFiberHcal(int gendeth, int ifiber, int idet, int iphdet, CalVision::DualCrysCalorimeterHit* &ahcalhit, float &meanscinHcal, float &meancerHcal, float &ehcaltimecut, float &erelhcaltimecut);

void calibrateSamplingHcal(int gendeth, int islice, int idet, CalVision::DualCrysCalorimeterHit* &ahcalhit, int ievt, float &meanscinHcal, float &meancerHcal, float &ehcaltimecut, float &erelhcaltimecut);

void calibrateSamplingHcalGendethThreeAndFour(int idet, int islice, int gendeth, int ievt, CalVision::DualCrysCalorimeterHit* &ahcalhit, float &meanscinHcal, float &meancerHcal, float &ehcaltimecut, float &erelhcaltimecut);

void calibrateHcalGendeth(int hcaltype, CalVision::DualCrysCalorimeterHit* &ahcalhit, int gendeth, int ievt, float &meanscinHcal, float &meancerHcal, float &ehcaltimecut, float &erelhcaltimecut);

void calibrateHcal(int ievt, int gendeth, CalHits* &hcalhits, TBranch* &b_hcal, int hcaltype, float &meanscinHcal, float &meancerHcal, float &ehcaltimecut, float &erelhcaltimecut);

void calibrateHcalgetStuffSampling(int ah, CalVision::DualCrysCalorimeterHit* &ahcalhit, int gendeth, int islice, int idet, float &nescinttothcal, float &necertothcal, float &ehcaltimecut, float &erelhcaltimecut);

void calibrateHcalgetStuffSamplingGendethThreeAndFour(int ah, CalVision::DualCrysCalorimeterHit* &ahcalhit, int gendeth, int idet, int islice, float &nescinttothcal, float &necertothcal, float &ehcaltimecut, float &erelhcaltimecut);

void calibrateHcalgetStuffSamplingAfterForLoop(int ah, int aarel, int islice, float &eesumfiber1, float &eesumfiber1em, float &eesumfiber2, float &eesumfiber2em, float &eesumPDhem, float &eesumabs, float &eesumabsem);

void calibrateHcalgetStuffFiberGendethThreeAndFour(int ah, int gendeth, CalVision::DualCrysCalorimeterHit* &ahcalhit, int idet, int ifiber, float &nescinttothcal, float &necertothcal, float &ehcaltimecut, float &erelhcaltimecut);

void calibrateHcalgetStuffFiber(int ah, CalVision::DualCrysCalorimeterHit* &ahcalhit, int gendeth, int idet, int ifiber, int iphdet, float &nescinttothcal, float &necertothcal, float &ehcaltimecut, float &erelhcaltimecut);

void calibrateHcalgetStuffGendeth(CalVision::DualCrysCalorimeterHit* &ahcalhit, int gendeth, int hcaltype, float &nescinttothcal, float &necertothcal, float &ehcaltimecute, float &erelhcaltimecut, float& eesum, float& eesumcal, float& eesumem, float& eesumfiber1, float& eesumfiber2, float& eesumabs, float& eesumPDh, float& eesumfiber1em, float& eesumfiber2em, float& eesumabsem, float& eesumPDhem);

void calibrateHcalgetStuff(int ievt, TBranch* &b_hcal, float &nescinttothcal, float &necertothcal, float &ehcaltimecut, float &erelhcaltimecut, CalHits* &hcalhits, int gendeth, int hcaltype, int& ninh, float& eesum, float& eesumcal, float& eesumem, float& eesumfiber1, float& eesumfiber2, float& eesumabs, float& eesumPDh, float& eesumfiber1em, float& eesumfiber2em, float& eesumabsem, float& eesumPDhem);

void calibrateHcalFillTime(int ievt, TBranch* &b_hcal, CalHits* &hcalhits, int hcaltype, int gendeth, int nbytehcal, TH1F* ehcaltime, TH1F* hcalpd1scint, TH1F* hcalpd1cer, TH1F* hcalpd2scint, TH1F* hcalpd2cer, map<string, int> &mapsampcalslice);

void calibrateHcalFillTimeGendeth(CalVision::DualCrysCalorimeterHit* &ahcalhit, TH1F* &hcalpd1cer, TH1F* &hcalpd1scint, int hcaltype, int gendeth, long long int ihitchan, map<string, int> &mapsampcalslice, TH1F* &hcalpd2cer, TH1F* &ehcaltime);

void calibrateHcalFillTimeGendethFiber(CalVision::DualCrysCalorimeterHit* &ahcalhit, int iphdet, int gendeth, int idet, TH1F* &ehcaltime, TH1F* &hcalpd1scint, TH1F* &hcalpd1cer, TH1F* &hcalpd2cer, int ifiber);

void calibrateHcalFillTimeGendethSampling(int islice, CalVision::DualCrysCalorimeterHit* &ahcalhit, map<string, int> mapsampcalslice, int gendeth, TH1F* &ehcaltime);
#endif 
