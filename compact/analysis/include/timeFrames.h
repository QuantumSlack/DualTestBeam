#ifndef TIMEFRAMES_H
#define TIMEFRAMES_H

#include "../../../include/DualCrysCalorimeterHit.h"
#include <vector>
#include "TBranch.h"
#include <iostream>
#include <string>
#include "../../../../../install/include/DDG4/Geant4Particle.h"
#include "../../../../../install/include/DDG4/Geant4Data.h"
#include "TH1.h"
#include "TRandom3.h"
#include "digis.h"
#include "ecalProcessing.h"
using namespace std;

int SCECOUNT=5;
int SCECOUNT2=20;
int icount777=0;
int SCECOUNT3=10;
int SCECOUNTHITHIT=1;
int ihitcounts=0;
int ihitcountc=0;

const int tfnx=25;
const int tfny=25;
const int tfndepth=2;
const int finenbin=100;
const float timemin=0.;
const float timemax=100.;
float biggesttime=0.;
float timecut=10;
float betacut=1/1.5;
const float timebinsize=(timemax-timemin)/float(finenbin);

typedef std::vector<CalVision::DualCrysCalorimeterHit*> CalHits;
typedef std::vector<dd4hep::sim::Geant4HitData::MonteCarloContrib> Contributions;
TRandom3 aar;
extern TH1F* timeframe_true_pd1_s[tfnx][tfny][tfndepth];
extern TH1F* timeframe_true_pd1_c[tfnx][tfny][tfndepth];
extern TH1F* timeframe_true_pd2_s[tfnx][tfny][tfndepth];
extern TH1F* timeframe_true_pd2_c[tfnx][tfny][tfndepth];
extern std::string aname_pd1_s[tfnx][tfny][tfndepth];
extern std::string aname_pd1_c[tfnx][tfny][tfndepth];
extern std::string aname_pd2_s[tfnx][tfny][tfndepth];
extern std::string aname_pd2_c[tfnx][tfny][tfndepth];
extern const char* bname_pd1_s[tfnx][tfny][tfndepth];
extern const char* bname_pd1_c[tfnx][tfny][tfndepth];
extern const char* bname_pd2_s[tfnx][tfny][tfndepth];
extern const char* bname_pd2_c[tfnx][tfny][tfndepth];


extern TH1F* timeframe_elec_pd1_s[tfnx][tfny][tfndepth];
extern TH1F* timeframe_elec_pd1_c[tfnx][tfny][tfndepth];
extern TH1F* timeframe_elec_pd2_s[tfnx][tfny][tfndepth];
extern TH1F* timeframe_elec_pd2_c[tfnx][tfny][tfndepth];
extern std::string anamee_pd1_s[tfnx][tfny][tfndepth];
extern std::string anamee_pd1_c[tfnx][tfny][tfndepth];
extern std::string anamee_pd2_s[tfnx][tfny][tfndepth];
extern std::string anamee_pd2_c[tfnx][tfny][tfndepth];
extern const char* bnamee_pd1_s[tfnx][tfny][tfndepth];
extern const char* bnamee_pd1_c[tfnx][tfny][tfndepth];
extern const char* bnamee_pd2_s[tfnx][tfny][tfndepth];
extern const char* bnamee_pd2_c[tfnx][tfny][tfndepth];

void PrepareEcalTimeFrames(int ievt, TBranch* &b_ecal,CalHits* &ecalhits);
void initTrueTimeFrames();
void initElectronicTimeFrames();

#endif 
