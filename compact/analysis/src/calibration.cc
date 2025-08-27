#include "../include/calibration.h"
#include "../include/ecalProcessing.h"


void gatherDataEcal(int gendete, CalVision::DualCrysCalorimeterHit* &aecalhit, int type, int idet) {
    switch(gendete) {
        case 1: // use photons as generated in optical material
            if (type == 2) {  // crystal
                meancerEcal+=aecalhit->ncerenkov;
	            meanscinEcal+=aecalhit->nscintillator;
            } break;
        case 2: 
            if( type==1 ) { // either photo detector
	            meancerEcal+=aecalhit->ncerenkov;
	            meanscinEcal+=aecalhit->nscintillator;
	        } break;
        case 3: 
        case 4: calibrateEcalGendeteThreeAndFour(gendete, idet, type, aecalhit); break;
        case 5: calibrateEcalGendeteFive(); break;
        case 6: calibrateEcalGendeteSix(); break;
        default:
            std::cout<<"invalid value gendete"<<std::endl;       
    }
}

