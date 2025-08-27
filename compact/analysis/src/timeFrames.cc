#include "../include/timeFrames.h"

void initTrueTimeFrames() {
    for (int i=0;i<tfnx;i++ ) {
    for (int j=0;j<tfny;j++ ) {
      for (int k=0;k<tfndepth;k++ ) {
	  aname_pd1_s[i][j][k] = "true pd1 s "+to_string(i)+"_"+to_string(j)+"_"+to_string(k);
	  bname_pd1_s[i][j][k]=aname_pd1_s[i][j][k].c_str();
	  aname_pd1_c[i][j][k] = "true pd1 c "+to_string(i)+"_"+to_string(j)+"_"+to_string(k);
	  bname_pd1_c[i][j][k]=aname_pd1_c[i][j][k].c_str();
	  aname_pd2_s[i][j][k] = "true pd2 s "+to_string(i)+"_"+to_string(j)+"_"+to_string(k);
	  bname_pd2_s[i][j][k]=aname_pd2_s[i][j][k].c_str();
	  aname_pd2_c[i][j][k] = "true pd2 c "+to_string(i)+"_"+to_string(j)+"_"+to_string(k);
	  bname_pd2_c[i][j][k]=aname_pd2_c[i][j][k].c_str();
	
	  timeframe_true_pd1_s[i][j][k]= new TH1F(bname_pd1_s[i][j][k],bname_pd1_s[i][j][k],finenbin,timemin,timemax);
	  timeframe_true_pd1_c[i][j][k]= new TH1F(bname_pd1_c[i][j][k],bname_pd1_c[i][j][k],finenbin,timemin,timemax);
	  timeframe_true_pd2_s[i][j][k]= new TH1F(bname_pd2_s[i][j][k],bname_pd2_s[i][j][k],finenbin,timemin,timemax);
	  timeframe_true_pd2_c[i][j][k]= new TH1F(bname_pd2_c[i][j][k],bname_pd2_c[i][j][k],finenbin,timemin,timemax);
      }
    }
  }
}


void initElectronTimeFrames() {
    for (int i=0;i<tfnx;i++ ) {
    for (int j=0;j<tfny;j++ ) {
      for (int k=0;k<tfndepth;k++ ) {
	anamee_pd1_s[i][j][k] = "elec pd1 s "+to_string(i)+"_"+to_string(j)+"_"+to_string(k);
	bnamee_pd1_s[i][j][k]=anamee_pd1_s[i][j][k].c_str();
	anamee_pd1_c[i][j][k] = "elec pd1 c "+to_string(i)+"_"+to_string(j)+"_"+to_string(k);
	bnamee_pd1_c[i][j][k]=anamee_pd1_c[i][j][k].c_str();
	anamee_pd2_s[i][j][k] = "elec pd2 s "+to_string(i)+"_"+to_string(j)+"_"+to_string(k);
	bnamee_pd2_s[i][j][k]=anamee_pd2_s[i][j][k].c_str();
	anamee_pd2_c[i][j][k] = "elec pd2 c "+to_string(i)+"_"+to_string(j)+"_"+to_string(k);
	bnamee_pd2_c[i][j][k]=anamee_pd2_c[i][j][k].c_str();
	
	timeframe_elec_pd1_s[i][j][k]= new TH1F(bnamee_pd1_s[i][j][k],bnamee_pd1_s[i][j][k],finenbin,timemin,timemax);
	timeframe_elec_pd1_c[i][j][k]= new TH1F(bnamee_pd1_c[i][j][k],bnamee_pd1_c[i][j][k],finenbin,timemin,timemax);
	timeframe_elec_pd2_s[i][j][k]= new TH1F(bnamee_pd2_s[i][j][k],bnamee_pd2_s[i][j][k],finenbin,timemin,timemax);
	timeframe_elec_pd2_c[i][j][k]= new TH1F(bnamee_pd2_c[i][j][k],bnamee_pd2_c[i][j][k],finenbin,timemin,timemax);

	
      }
    }
  }
}

void PrepareEcalTimeFrames(int ievt, TBranch* &b_ecal, CalHits* &ecalhits) {
      for (int i=0;i<tfnx;i++ ) {
    for (int j=0;j<tfny;j++ ) {
      for (int k=0;k<tfndepth;k++ ) {
	timeframe_true_pd1_s[i][j][k]->Reset();
	timeframe_true_pd1_c[i][j][k]->Reset();
	timeframe_true_pd2_s[i][j][k]->Reset();
	timeframe_true_pd2_c[i][j][k]->Reset();

      }
    }
  }

  int nbyteecal = b_ecal->GetEntry(ievt);
  if(ievt<SCECOUNT) std::cout<<std::endl<<" number of ecal hits is "<<ecalhits->size()<<std::endl;
  for(size_t i=0;i<ecalhits->size(); ++i) {
    CalVision::DualCrysCalorimeterHit* aecalhit =ecalhits->at(i);
    long long int ihitchan=aecalhit->cellID;
    int idet,ix,iy,islice,ilayer,wc,type;
    DecodeEcal(ihitchan,idet,ix,iy,islice,ilayer,wc,type );
    bool i1=(ix>=0);
    bool i2=(ix<tfnx);
    bool i3=(iy>=0);
    bool i4=(iy<tfny);
    //std::cout<<" ix iy i1 i2 i3 i4 tfnx tfny "<<ix<<" "<<iy<<" "<<i1<<" "<<i2<<" "<<i3<<" "<<i4<<" "<<tfnx<<" "<<tfny<<std::endl;
    if(i1&&i2&&i3&&i4) {
      float ae=aecalhit->energyDeposit;
      if((ilayer==0)&&(islice==1)) {  // pd on entrance to ecal
	int iii=(aecalhit->HitScin).size();

	for(int jjj=0;jjj<iii;jjj++) {
	  if(aar.Rndm()<AFILTER(1,(aecalhit->HitScin)[jjj].second)) {
	    timeframe_true_pd1_s[ix][iy][0]->Fill((aecalhit->HitScin)[jjj].first);
	  }
	  if(ihitcounts<SCECOUNTHITHIT) {
	    std::cout<<" scin hit time wavelength is "<<(aecalhit->HitScin)[jjj].first<<" "<<(aecalhit->HitScin)[jjj].second<<std::endl;
	    ihitcounts+=1;
	  }
	}
	iii=(aecalhit->HitCer).size();
	for(int jjj=0;jjj<iii;jjj++) {
	  if(aar.Rndm()<AFILTER(2,(aecalhit->HitCer)[jjj].second)) timeframe_true_pd1_c[ix][iy][0]->Fill((aecalhit->HitCer)[jjj].first);
	  if(ihitcountc<SCECOUNTHITHIT) {
	    std::cout<<" cer hit time wavelength is "<<(aecalhit->HitCer)[jjj].first<<" "<<(aecalhit->HitCer)[jjj].second<<std::endl;
	    ihitcountc+=1;
	  }
	}
      }
      if((ilayer==1)&&(islice==4)) {  // pd on exist of ecal
	int iii=(aecalhit->HitScin).size();
	for(int jjj=0;jjj<iii;jjj++) {
	  if(aar.Rndm()<AFILTER(3,(aecalhit->HitScin)[jjj].second)) timeframe_true_pd2_s[ix][iy][1]->Fill((aecalhit->HitScin)[jjj].first);
	}
	iii=(aecalhit->HitCer).size();
	for(int jjj=0;jjj<iii;jjj++) {
	  if(aar.Rndm()<AFILTER(4,(aecalhit->HitCer)[jjj].second)) timeframe_true_pd2_c[ix][iy][1]->Fill((aecalhit->HitCer)[jjj].first);
	}
      }
    } else {
      std::cout<<" invalid ix iy "<<ix<<" "<<iy<<std::endl;
    }
  }  // end loop over ecal hits


  
  for (int i=0;i<tfnx;i++ ) {
    for (int j=0;j<tfny;j++ ) {
      for (int k=0;k<tfndepth;k++ ) {
	Elec_Sim(timeframe_true_pd1_s[i][j][k],timeframe_elec_pd1_s[i][j][k]);
	Elec_Sim(timeframe_true_pd1_c[i][j][k],timeframe_elec_pd1_c[i][j][k]);
	Elec_Sim(timeframe_true_pd2_s[i][j][k],timeframe_elec_pd2_s[i][j][k]);
	Elec_Sim(timeframe_true_pd2_c[i][j][k],timeframe_elec_pd2_c[i][j][k]);
      }
    }
  }
  

  
  return;
}