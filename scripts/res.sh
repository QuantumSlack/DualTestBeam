#!bin/bash

diri=$1
dirf=$2

# First we run this thing
source /cvmfs/sft.cern.ch/lcg/views/LCG_107/x86_64-el9-gcc14-opt/setup.sh

# Now we're running this thing
source ~/ana/CalVision/new_repo/DualTestBeam/install/bin/thisDualTestBeam.sh


for particle in e- pi-
do
    for energy in 10 15 20 25 30 35 40 45 50 100
	do
		for theta in 0 2 5 10
		do
		    for step in 0.0005 0.001 0.0015 0.002 0 -0.0005 -0.001 -0.0015 -0.002
		    do
			        filename=out_DRConly-dial_${energy}GeV_${particle}_theta-${theta}_step-${step}.root
             		echo "Evaluating ${filename} resolution"
			        root.exe -b -q "Resolution.C(500, \"${diri}${filename}\",\"${diri}${filename}\",\"${diri}${filename}\", \"${diri}${filename}\", ${energy}, 1,0,1,1,0,0,0,1, \"${dirf}res_${filename}\", \"DRCNoSegment\", \"DRFNoSegment\", 1, 0, 0, 1)"
			done
		done
	done
done
