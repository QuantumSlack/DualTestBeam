## Table of Contents
- [Tracks and Propagation of Particles](#tracks-and-propagation-of-particles)
- [Creating ROOT file](#creating-root-file)
- [ROOT File Structure](#root-file-structure)

## Tracks and Propagation of Particles 
<img width="922" height="294" alt="Screenshot 2026-04-22 at 9 17 36 AM" src="https://github.com/user-attachments/assets/87e471fe-a0b7-462f-ba37-a4daa1d27406" />

 1. When an beam particle hits the detector, then it's defined as an **`event`**. One event can produce many subsequent hits in the detector.
 2. For each event, each particle in the simulation has a unique **`trackID`** which defines the trajectory of the particle in the detector. In this illustration, an incident particle produces three unique tracks with trackID's $t_{1}$, $t_{2}$, $t_{3}$. **`Note:- The trackIDs reset for each event. So, when analyzing data, event-0 and event-1 can have the same set of trackIDs.`**
 3. Each trackID corresponds to a particle which is propagating in the detector. So, for each trackID, there is a **`pdgID`** (Particle Data Group ID) which is unique for each type of particle. More information about it over here:- https://www.phy.bnl.gov/twister/bee/particles/ In this case, the track $t_{1}$ has a particle with pdgID $p_{1}$.
 4. Within each track, the particle can deposit energies multiple times. Each energy deposit in this track is called a **contribution**. Each contribution will have the same trackID, pdgID. However it will have different position (x,y,z) in the detector.
 5. In thw above picture, the red points on track $t_{1}$ represent these contributions. In ROOT file, these contribution will be recorded seperately even thought they will have the same trackID and pdgID. It's important to keep this in mind when doing analysis.
    
## Creating ROOT file

In `compact` directory, there are two files `massjobs.py` and `massjobs_ddsim.py`. These python files take  arguments and produce the `.sh` files which can be executed to simulate events. A DD4hep command called `ddsim` will be used to simulate particle events. An example of using this command is as follows:-

`ddsim --compactFile=/Users/shiva/DD4hep/examples/DualTestBeam/compact/DRFSCEPonly.xml --runType=batch -G --steeringFile /Users/shiva/DD4hep/examples/DualTestBeam/compact/SCEPCALsteering.py --outputFile=/Users/shiva/DD4hep/examples/DualTestBeam/compact/output/FSCEPonly/out_FSCEPonly_pi-10gev_$process_id.root --part.userParticleHandler= -G --gun.position="0.,-7*mm,-1*mm" --gun.direction "0. 0.05 0.99875" --gun.energy "10*GeV" --gun.particle="pi-" -N 1 >& /Users/shiva/DD4hep/examples/DualTestBeam/compact/output/FSCEPonly/Log_FSCEPonly_pi-10gev_$process_id.log`

1. `ddsim`:- DD4hep command used for simulation
2. `--compactFile`:- Tells the location of your `xml` file which contains your detector geometry parameters. This file will be used to construct the detector based on material and size specifications. Each geometry will have a different `xml` file.
3. `--runType`:- Specifies the type of simulation you want to do. If you specified `vis`, then it will open an event simulator and show all the interactions. `batch` value allows the simulation to record the entries in a ROOT file.
4. `--steeringFile`:- Uses a python file which specifies additional settings related to simulation like particle gun, physics engine, input files, output files etc.
5. `--outputFile`:- Specifies the location and name of your file which will be generated after the simulation is finished. This location will contain all the ROOT files which will be produced as a result of `ddsim` command.
6. `--gunPosition`:- Specifies the position of gun from which particles will be shot towards detector.
7. `--gunDirection`:- Specifies the direction in which the particle will be fired. This is important because certain directions don't lead to any interactions in detector.
8. `gunEnergy`:- Specifies the energy of the particle which is being shot at the detector from the gun.
9. `gunParticle`:- Specifies which particle is being fired, pions, photons, electrons, protons etc.
10. `-N 1`:- Defines the number of events. In this case, number of events is 1.
11. `>& ...`:- Specifies the location of log files which is useful for debugging if simulation fails.

## ROOT File Structure
<img width="272" height="365" alt="Screenshot 2026-04-22 at 8 37 37 AM" src="https://github.com/user-attachments/assets/ea12b76e-2486-4d02-998b-cedb3b63fd60" />

1. **`out_FSCEPonly_e-10gev_.root`** — File name
2. **`EVENT;1`** — Branch which contains information about energy deposits, timings, etc.
3. **`DRFNoSegment`** — Branch which contains information about particles inside the detector. This name is unique for each geometry being simulated. For FSCEPonly, it's DRFNoSegment; for other geometries it would be different.
4. **`EdgeDetNoSegment`** — Branch which contains the same information as the previous branch, but when particles are detected in the edge detector instead of the detector's interior.
5. **`MCParticles` (Monte-Carlo Particles)** — Contains information about trackID, parents, daughters, pdgID, spin, genstatus, etc. for each particle produced in the simulation irrespective of where they are.
6. **Remaining parameters** — Dials which are specified in `SCEPCALsteering.py`.

This is a simulation of a dual readout crystal calorimeter. 

## If you are not on alma9-like OS, but can use singularity
```
singularity run -B /cvmfs:/cvmfs -B /data:/data docker://gitlab-registry.cern.ch/sft/docker/alma9-core:latest
# at Baylor
# singularity run -B /cvmfs:/cvmfs -B /cms/data:/cms/data docker://gitlab-registry.cern.ch/sft/docker/alma9-core:latest
```

## All times:
```
source /cvmfs/sft.cern.ch/lcg/views/LCG_107/x86_64-el9-gcc14-opt/setup.sh
```

## First time only:
```
# setup directory
mkdir stuff4stuff
cd stuff4stuff

# git clone, compile, install
git clone ssh://git@gitlab.cern.ch:7999/calvisionsimulation/DualTestBeam.git
# or try sarah's version
# git clone git@github.com:saraheno/DualTestBeam.git
cd DualTestBeam
mkdir build
mkdir install
cd build

cmake -DDD4HEP_USE_GEANT4=ON -DBoost_NO_BOOST_CMAKE=ON -DDD4HEP_USE_LCIO=ON  -DROOT_DIR=$ROOTSYS -D CMAKE_BUILD_TYPE=Release  -DCMAKE_INSTALL_PREFIX=../install ..

# maybe at Baylor?
cmake -DDD4HEP_USE_GEANT4=ON -DBoost_NO_BOOST_CMAKE=ON -DDD4HEP_USE_LCIO=ON -DROOT_DIR=$ROOTSYS -D CMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=../install -D DD4HEP_USE_EDM4HEP=ON ..



make -j4
make install
```

## All times
```
cd to stuff4stuff/DualTestBeam
source ./install/bin/thisDualTestBeam.sh
cd compact
```

## running in batch mode

Look in [massjobs.py](https://gitlab.cern.ch/calvisionsimulation/DualTestBeam/-/blob/master/compact/massjobs.py) to see how to run it
to analyze the output, look at [massjobs_s2.py](https://gitlab.cern.ch/calvisionsimulation/DualTestBeam/-/blob/master/compact/massjobs_s2.py).
For Baylor users, see [massjobs_pbsarray.py](https://gitlab.cern.ch/calvisionsimulation/DualTestBeam/-/blob/master/compact/massjobs_pbsarray.py)

or see examples in CI (continuous integration) yaml file for running `ddsim` and `Resolution.C` in
[.gitlab-ci.yml](https://gitlab.cern.ch/calvisionsimulation/DualTestBeam/-/blob/master/.gitlab-ci.yml)

## running interactively
Change `--runType=batc` above to `--runType=vis`.
Then
```
/control/execute vis.mac
/run/beamOn 1
```
On the window that pops up, choose “Miscellany” and “Exit to G4Vis >”
Then do typical GEANT4 visualization commands such as:
```
/vis/viewer/refresh
/vis/viewer/zoomTo 10
/vis/viewer/pan -100 200 cm
/vis/viewer/set/viewpointThetaPhi 70 20
exit
```
