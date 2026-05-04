for particle in e- pi-
do
    for energy in 10 15 20 25 30 35 40 45 50 100
    do
	for theta in 0 2 5 10
	do
	    for step in "0\\.0005" "0\\.001" "0\\.0015" "0\\.002" "0" "-0\\.0005" "-0\\.001" "-0\\.0015" "-0\\.002"
	    do
		echo ${particle} ${energy} ${theta} ${step}
		if [[ "$step" == "0" ]]; then
		    declare list=`ls -lh /cms/data/whendric/ana/CalVision/new_repo/DualTestBeam/compact/output_incAngleTranslate/out_prehadd/*.root | grep "${energy}GeV" | grep ${particle} | grep "theta-${theta}" | grep "step-${step}\\."` | grep -v "0\\.0" 
		else
		    declare list=`ls -lh /cms/data/whendric/ana/CalVision/new_repo/DualTestBeam/compact/output_incAngleTranslate/out_prehadd/*.root | grep "${energy}GeV" | grep ${particle} | grep "theta-${theta}" | grep "step-${step}\\."`
		fi
		echo "$list"
		echo "number of files:"
		echo "$list" | wc -l
		root.exe -b -q -l 'check.C("/cms/data/whendric/ana/CalVision/new_repo/DualTestBeam/compact/output_incAngleTranslate/out_prehadd/out_DRConly-dial_10GeV_e-_theta-0_step-0.0005.10.root")'
		echo ${particle} ${energy} ${theta} ${step}
	    done
	done
    done
done
