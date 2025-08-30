#ifndef CALIBRATION_H
#define CALIBRATION_H

#include <map>
#include <string>
#include "timeFrames.h"
#include "TBranch.h"
#include "hcalProcessing.h"
#include "globals.h"

void gatherDataEcal(int gendete, CalVision::DualCrysCalorimeterHit* &aecalhit, int type, int idet);


#endif 