#ifndef GLOBALS_H
#define GLOBALS_H
#include "../../../include/DualCrysCalorimeterHit.h"
#include "../../../../../install/include/DDG4/Geant4Particle.h"
#include <vector>
#include "TH1.h"
const int tfnx=25;
const int tfny=25;
const int tfndepth=2;
extern const int finenbin;
extern const float timemin;
extern const float timemax;
const float timebinsize=(timemax-timemin)/float(finenbin);
extern float biggesttime;
extern float timecut;
extern float betacut;
extern int SCECOUNT;
extern int SCECOUNT2;
extern int icount777;
extern int SCECOUNT3;
extern int SCECOUNTHITHIT;
extern int ihitcounts;
extern int ihitcountc;
extern float meanscinHcal,meancerHcal;
extern float meanSHcal,meanCHcal;
extern float meanscinEcal,meancerEcal,egEcal;
extern float meaneecaltimecut,meanerelecaltimecut;
extern float meanSEcal,meanCEcal;
extern float eesum,eesumcal,eesumem,eesumair,eesumdead,eesumcrystal,eesumPDe,eesumfiber1,eesumfiber2,eesumabs,eesumPDh,eesumedge,eesumedgerel,necertotecal,nescinttotecal,necertothcal,nescinttothcal,eecaltimecut,ehcaltimecut,erelecaltimecut,erelhcaltimecut,eesumairem,eesumdeadem,eesumcrystalem,eesumPDeem,eesumfiber1em,eesumfiber2em,eesumabsem,eesumPDhem;
extern int nine, ninh;
extern int nbyteecal, nbytehcal, nbyteedge;
extern float meanehcaltimecut,meanerelhcaltimecut;
typedef std::vector<CalVision::DualCrysCalorimeterHit*> CalHits;
typedef std::vector<dd4hep::sim::Geant4HitData::MonteCarloContrib> Contributions;
typedef std::vector<CalVision::DualCrysCalorimeterHit*> CalHits;
typedef std::vector<dd4hep::sim::Geant4Particle*> GenParts;
extern std::map<std::string, int> mapsampcalslice;
extern std::string aname_pd1_s[tfnx][tfny][tfndepth];
extern std::string aname_pd1_c[tfnx][tfny][tfndepth];
extern std::string aname_pd2_s[tfnx][tfny][tfndepth];
extern std::string aname_pd2_c[tfnx][tfny][tfndepth];
extern std::string anamee_pd1_s[tfnx][tfny][tfndepth];
extern std::string anamee_pd1_c[tfnx][tfny][tfndepth];
extern std::string anamee_pd2_s[tfnx][tfny][tfndepth];
extern std::string anamee_pd2_c[tfnx][tfny][tfndepth];
extern const char* bname_pd1_s[tfnx][tfny][tfndepth];
extern const char* bname_pd1_c[tfnx][tfny][tfndepth];
extern const char* bname_pd2_s[tfnx][tfny][tfndepth];
extern const char* bname_pd2_c[tfnx][tfny][tfndepth];
extern const char* bnamee_pd1_s[tfnx][tfny][tfndepth];
extern const char* bnamee_pd1_c[tfnx][tfny][tfndepth];
extern const char* bnamee_pd2_s[tfnx][tfny][tfndepth];
extern const char* bnamee_pd2_c[tfnx][tfny][tfndepth];
extern TH1F* timeframe_true_pd1_s[tfnx][tfny][tfndepth];
extern TH1F* timeframe_true_pd1_c[tfnx][tfny][tfndepth];
extern TH1F* timeframe_true_pd2_s[tfnx][tfny][tfndepth];
extern TH1F* timeframe_true_pd2_c[tfnx][tfny][tfndepth];
extern TH1F* timeframe_elec_pd1_s[tfnx][tfny][tfndepth];
extern TH1F* timeframe_elec_pd1_c[tfnx][tfny][tfndepth];
extern TH1F* timeframe_elec_pd2_s[tfnx][tfny][tfndepth];
extern TH1F* timeframe_elec_pd2_c[tfnx][tfny][tfndepth];
extern float kappaEcal;
extern float kappaHcal;
extern  float ContainedFrac;
#endif