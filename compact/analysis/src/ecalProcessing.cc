#include "../include/ecalProcessing.h"

void DecodeEcal(long long int ihitchan, int& idet, int& ix, int& iy, int& islice, int& ilayer, int& wc, int& type) {
  idet = (ihitchan) & 0x07;
  ix = (ihitchan >>3) & 0x3F ;  // is this right?
  if(ix>32) ix=ix-64;
  iy =(ihitchan >>10) & 0x3F ; // is this right?
  if(iy>32) iy=iy-64;
  islice = (ihitchan >>17) & 0x07;
  ilayer = (ihitchan>> 20) & 0x07;
  wc=  (ihitchan>> 23) & 0x07;
  type=0;
  if((ilayer==0)&&(islice==1))  type=1;  //pd
  if((ilayer==0)&&(islice==2))  type=4;  //resin
  if((ilayer==0)&&(islice==3))  type=4;  //cookie
  if((ilayer==0)&&(islice==4))  type=2;  //crystal
  if((ilayer==0)&&(islice==5))  type=3;  //air


  if((ilayer==1)&&(islice==1))  type=2;  //crystal
  if((ilayer==1)&&(islice==2))  type=4;  //cookie
  if((ilayer==1)&&(islice==3))  type=4;  //resin
  if((ilayer==1)&&(islice==4))  type=1;  //pd
  if((ilayer==1)&&(islice==5))  type=3;  //air

  return;
}


void calibrateEcalGendeteThreeAndFour(int gendete, int idet, int type, CalVision::DualCrysCalorimeterHit* &aecalhit) {
    Contributions zxzz = aecalhit->truth;
    if (idet == 5) {
        if(type==2 ) {  // crystal
	      meanscinEcal+=aecalhit->energyDeposit;
	      if(gendete==3) meancerEcal+=aecalhit->edeprelativistic;
	      if(gendete==4) meancerEcal+=aecalhit->energyDeposit;

	      for(size_t j=0;j<zxzz.size(); j++) {
		    if( (zxzz.at(j)).time>biggesttime) biggesttime=(zxzz.at(j)).time;
		    if((zxzz.at(j)).time<timecut) {
		        eecaltimecut+=(zxzz.at(j)).deposit;
		        if(((aecalhit->contribBeta)[j])>betacut) {
                    erelecaltimecut+=(zxzz.at(j)).deposit;
                }
		    }
	      }
        }
    }
}

void calibrateEcalGendeteFive() {
    for (int i=0;i<tfnx;i++ ) {
	  for (int j=0;j<tfny;j++ ) {
	    for (int k=0;k<tfndepth;k++ ) {
	      meanscinEcal+=(timeframe_true_pd1_s[i][j][k]->Integral());
	      meancerEcal+=(timeframe_true_pd1_c[i][j][k]->Integral());
	      meanscinEcal+=(timeframe_true_pd2_s[i][j][k]->Integral());
	      meancerEcal+=(timeframe_true_pd2_c[i][j][k]->Integral());
	    }
	  }
    }
}

void calibrateEcalGendeteSix() {
    for (int i=0;i<tfnx;i++ ) {
	  for (int j=0;j<tfny;j++ ) {
	    for (int k=0;k<tfndepth;k++ ) {
	      meanscinEcal+=int_charge(timeframe_elec_pd1_s[i][j][k],10.,100.);
	      meancerEcal+=int_charge(timeframe_elec_pd1_c[i][j][k],10.,100.);
	      meanscinEcal+=int_charge(timeframe_elec_pd2_s[i][j][k],10.,100.);
	      meancerEcal+=int_charge(timeframe_elec_pd2_c[i][j][k],10.,100.);
	    }
	  }
	}
}

void calibrateEcalGendete(int gendete, CalVision::DualCrysCalorimeterHit* &aecalhit, int ievt, TBranch* &b_ecal) {
	  long long int ihitchan=aecalhit->cellID;
	  int idet,ix,iy,islice,ilayer,wc,type;
    DecodeEcal(ihitchan,idet,ix,iy,islice,ilayer,wc,type );
    Contributions zxzz=aecalhit->truth;
    switch(gendete) {
      case 1:
        if (type==2) {
          meancerEcal+=aecalhit->ncerenkov;
	        meanscinEcal+=aecalhit->nscintillator;
        } break;
      case 2:
        if (type==1) {
          meancerEcal+=aecalhit->ncerenkov;
	        meanscinEcal+=aecalhit->nscintillator;
        } break;
        case 3:
        case 4: 
          calibrateEcalGendeteThreeAndFour(gendete, idet, type, aecalhit);
          break;
        default:std::cout << "Wrong option" << std::endl;
          break;
    }
}

void calibrateEcal(int ievt, int gendete, CalHits* &ecalhits, TBranch* &b_ecal){
  switch(gendete) {
    case 1:
    case 2:
    case 3:
    case 4:
      nbyteecal = b_ecal->GetEntry(ievt);
      if(ievt<SCECOUNT) std::cout<<std::endl<<" number of ecal hits is "<<ecalhits->size()<<std::endl;
      for (int i = 0; i < ecalhits->size(); i++) {
        CalVision::DualCrysCalorimeterHit* aecalhit = ecalhits->at(i);
        calibrateEcalGendete(gendete, aecalhit, ievt, b_ecal);
      }
      break;
    case 5: calibrateEcalGendeteFive(); break;
    case 6: calibrateEcalGendeteSix(); break;
    default: std::cout << "invalid value gendete"<<std::endl;
          break;
      
  }
}

void calibrateEcalgetStuffGendeteThreeAndFour(int ae, CalVision::DualCrysCalorimeterHit* &aecalhit, int idet, int type, int gendete, float &nescinttotecal, float &necertotecal) {
  if (idet == 5){
    if (type == 2) {
	    nescinttotecal+=aecalhit->energyDeposit;
      if(gendete==3) necertotecal+=aecalhit->edeprelativistic;
	    if(gendete==4) necertotecal+=aecalhit->energyDeposit;
	    Contributions zxzz=aecalhit->truth;
	    float hacheck=0.;
      for(size_t j=0;j<zxzz.size(); j++) {
	      hacheck+=(zxzz.at(j)).deposit;
	      if((zxzz.at(j)).time<timecut) {
		        eecaltimecut+=(zxzz.at(j)).deposit;
		    if(((aecalhit->contribBeta)[j])>betacut) erelecaltimecut+=(zxzz.at(j)).deposit;
	        }
	      //if(fillhists) eecaltime->Fill((zxzz.at(j)).time);
	    }
      if(ae>0.001) {
	      if(hacheck/ae<0.999) {
		  
		if(icount777<SCECOUNT3) std::cout<<"missing contribs: ecal check contributions Ncontrib is "<<zxzz.size()<<" hackec is  "<<hacheck<<" ae is "<<ae<<" ratio "<<hacheck/ae<<std::endl;
		icount777+=1;
	      }
    }
  }
}
}

void calibrateEcalgetStuffGendeteFive(float &nescinttotecal, float &necertotecal) {
  for (int i=0;i<tfnx;i++ ) {
	  for (int j=0;j<tfny;j++ ) {
	    for (int k=0;k<tfndepth;k++ ) {
	      nescinttotecal+=timeframe_true_pd1_s[i][j][k]->Integral();
	      necertotecal+=timeframe_true_pd1_c[i][j][k]->Integral();
	      nescinttotecal+=timeframe_true_pd2_s[i][j][k]->Integral();
	      necertotecal+=timeframe_true_pd2_c[i][j][k]->Integral();
	    }
	  }
	}
}

void calibrateEcalgetStuffGendeteSix(float &nescinttotecal, float &necertotecal) {
  for (int i=0;i<tfnx;i++ ) {
	  for (int j=0;j<tfny;j++ ) {
	    for (int k=0;k<tfndepth;k++ ) {
	      nescinttotecal+=int_charge(timeframe_elec_pd1_s[i][j][k],10.,100.);
	      necertotecal+=int_charge(timeframe_elec_pd1_c[i][j][k],10.,100.);
	      nescinttotecal+=int_charge(timeframe_elec_pd2_s[i][j][k],10.,100.);
	      necertotecal+=int_charge(timeframe_elec_pd2_c[i][j][k],10.,100.);
	    }
	  }
	}
}

void calibrateEcalgetStuffGendete(CalVision::DualCrysCalorimeterHit* &aecalhit, int gendete, float &necertotecal, float &nescinttotecal, float &eecaltimecut, float &erelecaltimecut) {
      long long int ihitchan=aecalhit->cellID;
      int idet,ix,iy,islice,ilayer,wc,type;
      DecodeEcal(ihitchan,idet,ix,iy,islice,ilayer,wc,type);
      if((ilayer!=0)&&(ilayer!=1)) std::cout<<"danger danger will robinson ilayer not zero"<<std::endl;
      float ae=aecalhit->energyDeposit;
      nine+=aecalhit->n_inelastic;
      if(type==3) {eesumair+=ae;eesumcal+=aecalhit->energyDeposit;eesumem+=aecalhit->edeprelativistic;eesumairem+=aecalhit->edeprelativistic;};
      if(type==1) {eesumPDe+=ae;eesumcal+=aecalhit->energyDeposit;eesumem+=aecalhit->edeprelativistic;eesumPDeem+=aecalhit->edeprelativistic;};
      if(type==2) {eesumcrystal+=ae;eesumcal+=aecalhit->energyDeposit;eesumem+=aecalhit->edeprelativistic;eesumcrystalem+=aecalhit->edeprelativistic;};
      if(type==0||type==4) {eesumdead+=ae;eesumcal+=aecalhit->energyDeposit;eesumem+=aecalhit->edeprelativistic;eesumdeadem+=aecalhit->edeprelativistic;};
      switch(gendete) {
        case 1: {
          if(type==2) {  // crystal
	          necertotecal+=aecalhit->ncerenkov;
	          nescinttotecal+=aecalhit->nscintillator;
	        } break;
        }
        case 2: {
          if( type==1 ) { // either photo detector
	          necertotecal+=aecalhit->ncerenkov;
	          nescinttotecal+=aecalhit->nscintillator;
	        }
          break;
        }
        case 3:
        case 4:
          calibrateEcalgetStuffGendeteThreeAndFour(ae, aecalhit,idet, type, gendete, nescinttotecal, necertotecal);
          break;
        case 5:
          nescinttotecal=0;
          necertotecal=0;
          calibrateEcalgetStuffGendeteFive(nescinttotecal, necertotecal);
          break;
        case 6:
          nescinttotecal=0;
          necertotecal=0;
          calibrateEcalgetStuffGendeteSix(nescinttotecal, necertotecal);
          break;
        default:
        	std::cout<<"invalid choice gendete "<<gendete<<std::endl;
          break;
      }
}

void calibrateEcalgetStuff(int ievt, int gendete, TBranch* &b_ecal, CalHits* &ecalhits, float &necertotecal, float &nescinttotecal, float &eecaltimecut, float &erelecaltimecut) {
  nbyteecal = b_ecal->GetEntry(ievt);
      // ecal hits
    if(ievt<SCECOUNT) std::cout<<std::endl<<" number of ecal hits is "<<ecalhits->size()<<std::endl;
    eecaltimecut=0.;
    erelecaltimecut=0.;
    for(size_t index=0;index<ecalhits->size(); ++index) {
      CalVision::DualCrysCalorimeterHit* aecalhit =ecalhits->at(index);
      calibrateEcalgetStuffGendete(aecalhit, gendete, necertotecal, nescinttotecal, eecaltimecut, erelecaltimecut);
    }
}

void calibrateEcalFillTimeGendete(CalVision::DualCrysCalorimeterHit* &aecalhit, long long int ihitchan, TH1F* &ecalpd1scint, TH1F* &ecalpd1cer, TH1F* &ecalpd2scint, TH1F* &ecalpd2cer, int gendete, TH1F* &eecaltime) {
  int idet, ix, iy, islice, ilayer, wc, type;
  DecodeEcal(ihitchan, idet, ix, iy, islice, ilayer, wc, type);
  float ae = aecalhit->energyDeposit;
  if ( (ilayer == 0) && (islice == 1) ) {
    int iii = (aecalhit->HitScin).size();
    for (int jjj = 0; jjj < iii; jjj++) {
      if (aar.Rndm() < AFILTER(1, (aecalhit->HitScin)[jjj].second)) {
        ecalpd1scint->Fill((aecalhit->HitScin)[jjj].first);
      }
      if (ihitcounts < SCECOUNTHITHIT) {
        std::cout << "scin hit time wavelength is " << (aecalhit->HitScin)[jjj].first << " " << ((aecalhit->HitScin)[jjj].second) << std::endl;
        ihitcounts+=1;
      }
    }
    iii = (aecalhit->HitCer).size();
    for (int jjj = 0; jjj < iii; jjj++) {
      if (aar.Rndm() < AFILTER(2, (aecalhit->HitCer)[jjj].second)) {
        ecalpd1cer->Fill((aecalhit->HitCer)[jjj].first);
      }
      if (ihitcountc < SCECOUNTHITHIT) {
        std::cout << "cer hit time wavelength is " << (aecalhit->HitCer)[jjj].first << " " << (aecalhit->HitCer)[jjj].second << std::endl;
        ihitcountc+=1;
      }
    }
  }
  if ( (ilayer == 1) && (islice == 4) ) {
    int iii = (aecalhit->HitScin).size();
    for(int jjj = 0; jjj < iii; jjj++) {
      if (aar.Rndm() < AFILTER(3, (aecalhit->HitScin)[jjj].second)) {
        ecalpd2scint->Fill((aecalhit->HitScin)[jjj].first);
      }
    }
    iii = (aecalhit->HitCer).size();
    for(int jjj = 0; jjj < iii; jjj++) {
      if (aar.Rndm() < AFILTER(4, (aecalhit->HitCer)[jjj].second)) {
        ecalpd2cer->Fill((aecalhit->HitCer)[jjj].first);
      }
    }
  }
   if ( (gendete == 3) || (gendete == 4) ) {
    if (idet == 5) {
      if (type == 2) {
        Contributions zxzz = aecalhit->truth;
        for(size_t j = 0; j < zxzz.size(); j++) {
          eecaltime->Fill((zxzz.at(j)).time);
        }
      }
    }
   }
}


void calibrateEcalFillTime(int ievt, int nbyteecal, TBranch* &b_ecal, CalHits* &ecalhits, TH1F* &ecalpd1scint, TH1F* &ecalpd1cer, TH1F* &ecalpd2scint, TH1F* &ecalpd2cer, TH1F* &eecaltime, int gendete) {
  nbyteecal = b_ecal->GetEntry(ievt);
  if(ievt < SCECOUNT) {
    std::cout << std::endl << "number of ecal hits is " << ecalhits->size() << std::endl;
  }
  for (size_t index = 0; index < ecalhits->size(); index++) {
    CalVision::DualCrysCalorimeterHit* aecalhit = ecalhits->at(index);
    long long int ihitchan = aecalhit->cellID;
    calibrateEcalFillTimeGendete(aecalhit, ihitchan, ecalpd1scint, ecalpd1cer, ecalpd2scint, ecalpd2cer, gendete, eecaltime);
  }
}
