#!/bin/bash
number_particles=$1
geometry=$2
energy=$3
hcaltype=$4
leaf1=$5
leaf2=$6
CWD="/Users/shiva/DD4hep/examples/DualTestBeam/compact"
echo $CWD
INPUT_FILE_DIR="$CWD/output/$geometry"
OUT_FILE_DIR="$CWD/output/$geometry"
LOG_FILE_DIR="$CWD/output/$geometry"
input_string="Resolution($number_particles,"\""$INPUT_FILE_DIR"/out_"$geometry"_"$energy"GeV_e-.root"\","\""$INPUT_FILE_DIR"/out_"$geometry"_"$energy"GeV_pi-.root"\","\""$INPUT_FILE_DIR"/out_"$geometry"_"$energy"GeV_e-.root"\","\""$INPUT_FILE_DIR"/out_"$geometry"_"$energy"GeV_pi-.root"\","$energy",0,1,$hcaltype,1,0,0,0,3,3,"\""$OUT_FILE_DIR"/hists_"$energy"GeV_"$geometry"_trial.root"\","\""$leaf1""\","\""$leaf2""\",1,0,1,1)"
echo $input_string
#root -l -b -q 'gSystem->Load("lib/libDualTestBeam_lib.dylib");$input_string' #>& ""$LOG_FILE_DIR"/log_new_"$energy"GeV_"$geometry"_trial.log"
