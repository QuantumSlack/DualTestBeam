#!bin/bash
#
# Script for hadding output files together, assuming a common file naming scheme

read -p "Enter the starting directory you're hadding from: " diri
read -p "Enter the finishing directory: " dirf

for particle in e- pi-
do
    	for energy in 10 15 20 25 30 35 40 45 50 100
	do
		for theta in 0 2 5 10
		do
		    for step in 0.0005 0.001 0.0015 0.002 0 -0.0005 -0.001 -0.0015 -0.002
		    do
             		        echo "${energy} GeV, ${theta} degrees theta, ${step} hadding"
			        hadd -f ${dirf}out_DRConly-dial_${energy}GeV_${particle}_theta-${theta}_step-${step}.root ${diri}out_DRConly-dial_${energy}GeV_${particle}_theta-${theta}_step-${step}*
			done
		done
	done
done
