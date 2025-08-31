// #include "TSystem.h"
#include "include/Resolution.h"
//gSystem->Load("lib/libDualTestBeam_lib.dylib");
void runResolution() {
	gSystem->Load("lib/libDualTestBeam_lib.dylib");
	Resolution(10,"/Users/shiva/DD4hep/examples/DualTestBeam/compact/output/FSCEPonly/out_FSCEPonly_10GeV_e-.root","/Users/shiva/DD4hep/examples/DualTestBeam/compact/output/FSCEPonly/out_FSCEPonly_10GeV_pi-.root","/Users/shiva/DD4hep/examples/DualTestBeam/compact/output/FSCEPonly/out_FSCEPonly_10GeV_e-.root","/Users/shiva/DD4hep/examples/DualTestBeam/compact/output/FSCEPonly/out_FSCEPonly_10GeV_pi-.root",10,0,1,0,1,0,0,0,3,3,"/Users/shiva/DD4hep/examples/DualTestBeam/compact/output/FSCEPonly/hists_10GeV_FSCEPonly_trial.root","DRFNoSegment","DRFNoSegment",1,0,1,1);
}
