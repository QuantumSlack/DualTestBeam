#!/bin/bash
cd /eos/home-a/adagarwa/DD4hep/examples/DualTestBeam/compact/
START_TIME=`/bin/date`
echo "started at $START_TIME"
echo "started at $START_TIME on ${HOSTNAME}"
source /cvmfs/sft.cern.ch/lcg/views/LCG_107/x86_64-el9-gcc14-opt/setup.sh
echo "ran setup"
source  /eos/user/a/adagarwa/DD4hep/examples/DualTestBeam/install/bin/thisDualTestBeam.sh
echo "ran thisDualTestBeam"
ddsim --compactFile=/eos/home-a/adagarwa/DD4hep/examples/DualTestBeam/compact/DRSampOnly2.xml --runType=batch -G --steeringFile /eos/home-a/adagarwa/DD4hep/examples/DualTestBeam/compact/SCEPCALsteering.py --outputFile=/eos/home-a/adagarwa/DD4hep/examples/DualTestBeam/compact/output/SampOnly2/out_SampOnly2_30GeV_e-.root --part.userParticleHandler= -G --gun.position="0.,-7*mm,-1*mm" --gun.direction "0. 0.05 0.99875" --gun.energy "30*GeV" --gun.particle="e-" -N 1000 >& /eos/home-a/adagarwa/DD4hep/examples/DualTestBeam/compact/output/SampOnly2/sce_e_SampOnly2_30.log
exitcode=$?
echo ""
END_TIME=`/bin/date`
echo "finished at $END_TIME"
exit $exitcode
