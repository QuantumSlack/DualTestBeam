#!bin/bash
#
# Shell script for submitting files to pbs for running Resolution.C

diri="/cms/data/whendric/ana/CalVision/new_repo/DualTestBeam/compact/output_incAngleTranslate/out_hadd/"
dirf="${PWD}/res_out/"

mkdir -p ${dirf}

mkdir -p pbs_log_res
cd pbs_log_res

for particle in e-
do
    for energy in 20
    do
		for theta in 0 2 5 10
		do
	    	for step in 0.0005 0.001 0.0015 0.002 0 -0.0005 -0.001 -0.0015 -0.002
	    	do
			filename=out_DRConly-dial_${energy}GeV_${particle}_theta-${theta}_step-${step}.root
			jobname=out_DRConly-dial_${energy}GeV_${particle}_theta-${theta}_step-${step}
			qsub -v dirf=${dirf},diri=${diri},filename=${filename},energy=${energy},jobname=${jobname} -N ${jobname} ../submit_res.pbs
	    	done
		done
    done
done
