#!/bin/bash
cd /eos/home-a/adagarwa/DD4hep/examples/DualTestBeam/compact/
START_TIME=`/bin/date`
echo "started at $START_TIME"
echo "started at $START_TIME on ${HOSTNAME}"
source /cvmfs/sft.cern.ch/lcg/views/LCG_107/x86_64-el9-gcc14-opt/setup.sh
echo "ran setup"
source  /eos/user/a/adagarwa/DD4hep/examples/DualTestBeam/install/bin/thisDualTestBeam.sh
echo "ran thisDualTestBeam"
ddsim --compactFile=/eos/home-a/adagarwa/DD4hep/examples/DualTestBeam/compact/DRFSCEPSAonly.xml --runType=batch -G --steeringFile /eos/home-a/adagarwa/DD4hep/examples/DualTestBeam/compact/SCEPCALsteering.py --outputFile=/eos/home-a/adagarwa/DD4hep/examples/DualTestBeam/compact/output/FSCEPSAonly/out_FSCEPSAonly_10GeV_pi-.root --part.userParticleHandler= -G --gun.position="0.,-7*mm,-1*mm" --gun.direction "0. 0.05 0.99875" --gun.energy "10*GeV" --gun.particle="pi-" -N 1000 >& /eos/home-a/adagarwa/DD4hep/examples/DualTestBeam/compact/output/FSCEPSAonly/sce_pi_FSCEPSAonly_10.log
exitcode=$?
echo ""
END_TIME=`/bin/date`
echo "finished at $END_TIME"
exit $exitcode
