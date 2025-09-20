#include "../include/hcalProcessing.h"

void DecodeFiber(long long int ihitchan, int& idet, int& ilayer, int& itube, int& iair, int&itype, int& ifiber, int& iabs, int& iphdet, int& ihole, int& ix, int& iy) {
  idet = (ihitchan) & 0xFF;
  ilayer = (ihitchan >>8) & 0xFFF;
  itube = (ihitchan >>20) & 0xFFF;
  //int iair=0; int itype=0;
  iair = (ihitchan >>32) & 0x7;
  itype = (ihitchan >>35) & 0x7;
  ifiber=0; iabs=0; iphdet=0;  ihole=0;
  ix=0; iy=0;
  if((itype==0)&&(iair==0)&&(itube!=0)) iabs=1;
  if(itype==1) ifiber=1; // scint
  if(itype==2) ifiber=2; // quartz
  if(itype==3) iphdet=1; //scint pt
  if(itype==4) iphdet=2; // quartz pt
  if(((iair==1)||(iair==2))&&(itype==0)) ihole=1;
  if(itube==0) ihole=1;
  ix=itube;
  iy=ilayer;
  return;
}

void DecodeSampling(long long int ihitchan,int& idet, int& ix, int& iy, int& ilayer, int& ibox2, int& islice) {
  idet = (ihitchan) & 0x07;
  iy = (ihitchan >>3) & 0xFFF;
  ix = (ihitchan >>15) & 0xFFF;
  ilayer = (ihitchan >>27) & 0xFFF;
  ibox2 = (ihitchan >> 39) & 0x03;
  islice = (ihitchan >>41) & 0xF;
  return;
}

void calibrateFiberHcalGendethThreeAndFour(CalVision::DualCrysCalorimeterHit* &ahcalhit,int idet, int ifiber, int gendeth, float &meanscinHcal, float &meancerHcal, float &ehcaltimecut, float &erelhcaltimecut) {
     if(idet==6) {
	    if(ifiber==1) {
	      meanscinHcal+=ahcalhit->energyDeposit;
	    }
	    if(ifiber==2) {
	      if(gendeth==3) meancerHcal+=ahcalhit->edeprelativistic;
	      if(gendeth==4) meancerHcal+=ahcalhit->energyDeposit;
	    }
	    if((ifiber==1)||(ifiber==2)) {
        Contributions zxzz=ahcalhit->truth;
	      for(size_t j=0;j<zxzz.size(); j++) {
		    if( (zxzz.at(j)).time>biggesttime) biggesttime=(zxzz.at(j)).time;
		    if((zxzz.at(j)).time<timecut) {
		        if(ifiber==1) {
		         ehcaltimecut+=(zxzz.at(j)).deposit;
		        }
		        if(ifiber==2) {
		            if(((ahcalhit->contribBeta)[j])>betacut) erelhcaltimecut+=(zxzz.at(j)).deposit;
		  }
		}
	  }
    }
  }
}

void calibrateFiberHcal(int gendeth, int ifiber, int idet, int iphdet, CalVision::DualCrysCalorimeterHit* &ahcalhit, float &meanscinHcal, float &meancerHcal, float &ehcaltimecut, float &erelhcaltimecut) {
    switch(gendeth) {
        case 1:
            if (ifiber == 1) { //scintillating fibers
                 meanscinHcal+=ahcalhit->nscintillator;
            } else if (ifiber == 2) { //quartz fibers
                 meancerHcal+=ahcalhit->ncerenkov;
            } break;
        case 2: 
            if(iphdet==1) {  // take light that hits photodetectors
	            meanscinHcal+=ahcalhit->nscintillator;
	        }
	        if(iphdet==2) {  // take light that hits photodetectors
	             meancerHcal+=ahcalhit->ncerenkov;
	        } break;
            
        case 3: 
        case 4: calibrateFiberHcalGendethThreeAndFour(ahcalhit, idet, ifiber, gendeth, meanscinHcal, meancerHcal, ehcaltimecut, erelhcaltimecut); break;
        default: 
            std::cout << "Wrong choice for gendeth" << std::endl;
            break;
    }
}

void calibrateSamplingHcalGendethThreeAndFour(int idet, int islice, int gendeth, int ievt, CalVision::DualCrysCalorimeterHit* &ahcalhit, float &meanscinHcal, float &meancerHcal, float &ehcaltimecut, float &erelhcaltimecut) {
    Contributions zxzz=ahcalhit->truth;
    if(idet==6) {
	    if( islice==(*mapsampcalslice.find("PS")).second) { // PS
	      meanscinHcal+=ahcalhit->energyDeposit;
	      if(ievt<SCECOUNT) std::cout<<" meanscinHcal "<<meanscinHcal<<std::endl;
	    }
	    if( islice==(*mapsampcalslice.find("Quartz")).second ) {  // quartz
	      if(gendeth==3) meancerHcal+=ahcalhit->edeprelativistic;
	      if(gendeth==4) meancerHcal+=ahcalhit->energyDeposit;
	      if(ievt<SCECOUNT) std::cout<<" meancerHcal "<<meancerHcal<<std::endl;
	    }
	    if(( islice==(*mapsampcalslice.find("PS")).second)||( islice==(*mapsampcalslice.find("Quartz")).second)) {
	      for(size_t j=0;j<zxzz.size(); j++) {
		if( (zxzz.at(j)).time>biggesttime) biggesttime=(zxzz.at(j)).time;
		if((zxzz.at(j)).time<timecut) {
		  ehcaltimecut+=(zxzz.at(j)).deposit;
		  if(((ahcalhit->contribBeta)[j])>betacut) erelhcaltimecut+=(zxzz.at(j)).deposit;
		}
	      }
	    }
	  }
}

void calibrateSamplingHcal(int gendeth, int islice, int idet, CalVision::DualCrysCalorimeterHit* &ahcalhit, int ievt, float &meanscinHcal, float &meancerHcal, float &ehcaltimecut, float &erelhcaltimecut) {
    switch(gendeth) {
        case 1:
            if(islice==(*mapsampcalslice.find("PS")).second) {
	             meanscinHcal+=ahcalhit->nscintillator;
	            }
	        if(islice==(*mapsampcalslice.find("Quartz")).second) {  // cherenkov
	                 meancerHcal+=ahcalhit->ncerenkov;
	             } break; 
        case 2:
            if( (islice==(*mapsampcalslice.find("PD1")).second)||(islice==(*mapsampcalslice.find("PD2")).second) ) { // either photo detector
	             meanscinHcal+=ahcalhit->nscintillator;
	            }
	        if( (islice==(*mapsampcalslice.find("PD3")).second)||(islice==(*mapsampcalslice.find("PD4")).second)) {  // take light that hits photodetectors
	            meancerHcal+=ahcalhit->ncerenkov;
	            } break;
        case 3:
        case 4: calibrateSamplingHcalGendethThreeAndFour(idet, islice, gendeth, ievt, ahcalhit, meanscinHcal, meancerHcal, ehcaltimecut, erelhcaltimecut); break;
    }
}

void calibrateHcalGendeth(int hcaltype, CalVision::DualCrysCalorimeterHit* &ahcalhit, int gendeth, int ievt, float &meanscinHcal, float &meancerHcal, float &ehcaltimecut, float &erelhcaltimecut) {
    switch(hcaltype) {
        int idet, ix, iy, ilayer;
	case 0: //fiber Hcal
            int itube,iair,itype,ifiber,iabs,iphdet,ihole;
            DecodeFiber(ahcalhit->cellID,idet,ilayer,itube,iair,itype,ifiber,iabs,iphdet,ihole,ix,iy);
            calibrateFiberHcal(gendeth, ifiber, idet, iphdet, ahcalhit, meanscinHcal, meancerHcal, ehcaltimecut, erelhcaltimecut);
	    break;
        case 1: //sampling Hcal
            int ibox2,islice;
	    DecodeSampling(ahcalhit->cellID,idet,ix,iy,ilayer,ibox2,islice);
            calibrateSamplingHcal(gendeth, islice, idet, ahcalhit, ievt, meanscinHcal, meancerHcal, ehcaltimecut, erelhcaltimecut);
	    break;
	default: 
	    std::cout << "Wrong type of HCAL" << std::endl;
    }

}

void calibrateHcal(int ievt, int gendeth, CalHits* &hcalhits, TBranch* &b_hcal, int hcaltype, float &meanscinHcal, float &meancerHcal, float &ehcaltimecut, float &erelhcaltimecut){

    nbytehcal = b_hcal->GetEntry(ievt);

      // hcal hits
    if(ievt<SCECOUNT) std::cout<<" number of hcal hits is "<<hcalhits->size()<<std::endl;

    size_t hcal_size = hcalhits->size();
    for (size_t index = 0; index < hcal_size; index++) {
         CalVision::DualCrysCalorimeterHit* ahcalhit =hcalhits->at(index);
         calibrateHcalGendeth(hcaltype, ahcalhit, gendeth, ievt, meanscinHcal, meancerHcal, ehcaltimecut, erelhcaltimecut);
    }

}

void calibrateHcalgetStuffFiberGendethThreeAndFour(int ah, int gendeth, CalVision::DualCrysCalorimeterHit* &ahcalhit, int idet, int ifiber, float &nescinttothcal, float &necertothcal, float &ehcaltimecut, float &erelhcaltimecut) {
  if (idet == 6) {
    switch(ifiber) {
      case 1: 
      	 nescinttothcal+=ahcalhit->energyDeposit;
         break;
      case 2: {
      if(gendeth==3) necertothcal+=ahcalhit->edeprelativistic;
	    if(gendeth==4) necertothcal+=ahcalhit->energyDeposit; 
      }
      default: break;
    }
  Contributions zxzz=ahcalhit->truth;
	float hacheck=0.;
  for(size_t j=0;j<zxzz.size(); j++) {
		hacheck+=(zxzz.at(j)).deposit;
		if((zxzz.at(j)).time<timecut) {
		  if(ifiber==1) {
		  ehcaltimecut+=(zxzz.at(j)).deposit;
		  }
		  if(ifiber==2) {
		  if(((ahcalhit->contribBeta)[j])>betacut) erelhcaltimecut+=(zxzz.at(j)).deposit;
		  }
		}
  }
  if(ah>0.001) {
		if(hacheck/ah<0.99999) std::cout<<"missing contribs: hcal check contributions Ncontrib is "<<zxzz.size()<<" hackec is  "<<hacheck<<" ah is "<<ah<<" ratio "<<hacheck/ah<<std::endl;
	  }
  }
}


void calibrateHcalgetStuffFiber(int ah, CalVision::DualCrysCalorimeterHit* &ahcalhit, int gendeth, int idet, int ifiber, int iphdet, float &nescinttothcal, float &necertothcal, float &ehcaltimecut, float &erelhcaltimecut) {
  switch (gendeth) {
  case 1: {
    if (ifiber == 1) {
      nescinttothcal += ahcalhit->nscintillator;
    }
    if (ifiber == 2) {
	    necertothcal+=ahcalhit->ncerenkov;
    }
    break;
  }
  case 2: {
    if (iphdet == 1) {
	    nescinttothcal+=ahcalhit->nscintillator;
    } if (iphdet == 2) {
	    necertothcal+=ahcalhit->ncerenkov;
    }
    break;
  }
  case 3:
  case 4: 
    calibrateHcalgetStuffFiberGendethThreeAndFour(ah, gendeth, ahcalhit, idet, ifiber, nescinttothcal, necertothcal, ehcaltimecut, erelhcaltimecut);
  }
}


void calibrateHcalgetStuffSamplingGendethThreeAndFour(int ah, CalVision::DualCrysCalorimeterHit* &ahcalhit, int gendeth, int idet, int islice, float &nescinttothcal, float &necertothcal, float &ehcaltimecut, float &erelhcaltimecut) {
  if (idet == 6) {
    if( islice==(*mapsampcalslice.find("PS")).second) { //  ps
	      nescinttothcal+=ahcalhit->energyDeposit;
	  }
    if( islice==(*mapsampcalslice.find("Quartz")).second ) {  // quartz
	    if(gendeth==3) necertothcal+=ahcalhit->edeprelativistic;
	    if(gendeth==4) necertothcal+=ahcalhit->energyDeposit;
	  }  
     if((islice==(*mapsampcalslice.find("PS")).second)||(islice==(*mapsampcalslice.find("Quartz")).second) ){
      Contributions zxzz=ahcalhit->truth;
	    float hacheck=0.;
      for(size_t j=0;j<zxzz.size(); j++) {
		    hacheck+=(zxzz.at(j)).deposit;
		    if((zxzz.at(j)).time<timecut) {
		      ehcaltimecut+=(zxzz.at(j)).deposit;
		      if(((ahcalhit->contribBeta)[j])>betacut) erelhcaltimecut+=(zxzz.at(j)).deposit;
		      }
	      }
    if(ah>0.001) {
		if(hacheck/ah<0.99999) std::cout<<"missing contribs: hcal check contributions Ncontrib is "<<zxzz.size()<<" hackec is  "<<hacheck<<" ah is "<<ah<<" ratio "<<hacheck/ah<<std::endl;
	      }
     }
  }
}

void calibrateHcalgetStuffSampling(int ah, CalVision::DualCrysCalorimeterHit* &ahcalhit, int gendeth, int islice, int idet, float &nescinttothcal, float &necertothcal, float &ehcaltimecut, float &erelhcaltimecut) {
  switch(gendeth) {
    case 1: {
      if(islice==(*mapsampcalslice.find("PS")).second) {
	      nescinttothcal+=ahcalhit->nscintillator;
	      std::cout<<"add scint"<<std::endl;
	    }
	  if(islice==(*mapsampcalslice.find("Quartz")).second) {  // chereknov
	      necertothcal+=ahcalhit->ncerenkov;
	      std::cout<<"add ceren"<<std::endl;
	    }
      break;
    }
    case 2:{
      if( (islice==(*mapsampcalslice.find("PD1")).second)||(islice==(*mapsampcalslice.find("PD2")).second) ) { // either photo detector
	      nescinttothcal+=ahcalhit->nscintillator;
	    }
	    if( (islice==(*mapsampcalslice.find("PD3")).second)||(islice==(*mapsampcalslice.find("PD4")).second)) {  // take light that hits photodetectors
	      necertothcal+=ahcalhit->ncerenkov;
	    }
      break;
    }
    case 3:
    case 4: calibrateHcalgetStuffSamplingGendethThreeAndFour(ah, ahcalhit, gendeth, idet, islice, nescinttothcal, necertothcal, ehcaltimecut, erelhcaltimecut);
            break;
    default: 
      break;
  }
}


void calibrateHcalgetStuffSamplingAfterForLoop(int ah, int aarel, int islice, float &eesumfiber1, float &eesumfiber1em, float &eesumfiber2, float &eesumfiber2em, float &eesumPDhem, float &eesumabs, float &eesumabsem) {
  if( islice==(*mapsampcalslice.find("PS")).second ) {eesumfiber1+=ah;eesumfiber1em+=aarel;}; // scint
	      if( islice==(*mapsampcalslice.find("Quartz")).second ) {eesumfiber2+=ah;eesumfiber2em+=aarel;};  //cer
	      if( (islice==(*mapsampcalslice.find("Iron")).second)||(islice==(*mapsampcalslice.find("Sep1")).second)||(islice==(*mapsampcalslice.find("Sep2")).second) ) {eesumabs+=ah;eesumabsem+=aarel;};
	      if(  (islice==(*mapsampcalslice.find("PD1")).second) || (islice==(*mapsampcalslice.find("PD2")).second) ||  (islice==(*mapsampcalslice.find("PD3")).second) || (islice==(*mapsampcalslice.find("PD4")).second)) {eesumPDh+=ah;eesumPDhem+=aarel;};
}

void calibrateHcalgetStuffGendeth(CalVision::DualCrysCalorimeterHit* &ahcalhit, int gendeth, int hcaltype, float &nescinttothcal, float &necertothcal, float &ehcaltimecute, float &erelhcaltimecut, float& eesum, float& eesumcal, float& eesumem, float& eesumfiber1, float& eesumfiber2, float& eesumabs, float& eesumPDh, float& eesumfiber1em, float& eesumfiber2em, float& eesumabsem, float& eesumPDhem) {
  ninh+=ahcalhit->n_inelastic;
  eesumcal+=ahcalhit->energyDeposit;
  eesumem+=ahcalhit->edeprelativistic;
  long long int ihitchan=ahcalhit->cellID;
  switch(hcaltype) {
    case 0: { // fiber
        float ah = ahcalhit->energyDeposit;
        float aarel = ahcalhit->edeprelativistic;
        eesum+=ah;
      	int idet,ilayer,itube,iair,itype,ifiber,iabs,iphdet,ihole,ix,iy;
	      DecodeFiber(ihitchan,idet,ilayer,itube,iair,itype,ifiber,iabs,iphdet,ihole,ix,iy);
        calibrateHcalgetStuffFiber(ah, ahcalhit, gendeth, idet, ifiber, iphdet, nescinttothcal, necertothcal, ehcaltimecut, erelhcaltimecut);
        if (ifiber == 1) {
          eesumfiber1+=ah;
          eesumfiber1em+=aarel;
        } if (ifiber == 2) {
          eesumfiber2+=ah;
          eesumfiber2em+=aarel;
        } if(iabs == 1) {
          eesumabs+=ah;
          eesumabsem+=aarel;
        } if(iphdet > 1) {
          eesumPDh+=ah;
          eesumPDhem+=aarel;
        }
        break;
    }
   case 1: { // sampling
        float aarel = ahcalhit->edeprelativistic;
        float ah = ahcalhit->energyDeposit;
        eesum+=ah;
	      int idet,ix,iy,ilayer,ibox2,islice;
	      DecodeSampling(ihitchan,idet,ix,iy,ilayer,ibox2,islice);
        calibrateHcalgetStuffSampling(ah, ahcalhit, gendeth, islice, idet, nescinttothcal, necertothcal, ehcaltimecut, erelhcaltimecut);
        calibrateHcalgetStuffSamplingAfterForLoop(ah, aarel, islice, eesumfiber1, eesumfiber1em, eesumfiber2, eesumfiber2em, eesumPDhem, eesumabs, eesumabsem);
        break;
   }
   default: break;
  }
}

void calibrateHcalgetStuff(int ievt, TBranch* &b_hcal, float &nescinttothcal, float &necertothcal, float &ehcaltimecut, float &erelhcaltimecut, CalHits* &hcalhits, int gendeth, int hcaltype, int& ninh, float& eesum, float& eesumcal, float& eesumem, float& eesumfiber1, float& eesumfiber2, float& eesumabs, float& eesumPDh, float& eesumfiber1em, float& eesumfiber2em, float& eesumabsem, float& eesumPDhem) {
  nbytehcal = b_hcal->GetEntry(ievt);
  if(ievt<SCECOUNT) std::cout<<std::endl<<" number of hcal hits is "<<hcalhits->size()<<std::endl;
    ehcaltimecut=0.;
    erelhcaltimecut=0.;
    eesum=0.;
    for(size_t index = 0; index < hcalhits->size(); ++index) {
      CalVision::DualCrysCalorimeterHit* ahcalhit = hcalhits->at(index);
      calibrateHcalgetStuffGendeth(ahcalhit, gendeth, hcaltype, nescinttothcal, necertothcal, ehcaltimecut, erelhcaltimecut, eesum, eesumcal, eesumem, eesumfiber1, eesumfiber1em, eesumabs, eesumPDh, eesumfiber1em, eesumfiber2em, eesumabsem, eesumPDhem);
    }
}
void calibrateHcalFillTimeGendethFiber(CalVision::DualCrysCalorimeterHit* &ahcalhit, int iphdet, int gendeth, int idet, TH1F* &ehcaltime, TH1F* &hcalpd1scint, TH1F* &hcalpd1cer, TH1F* &hcalpd2cer, int ifiber) {
  switch(iphdet) {
    case 1: {
      int iii = (ahcalhit->HitScin).size();
      std::cout << "pd1 ScintTime size pd1 is " << iii << std::endl;
      for (int jjj = 0; jjj < iii; jjj++) {
        if(aar.Rndm() < AFILTER(0, (ahcalhit->HitScin)[jjj].second)) {
          hcalpd1scint->Fill((ahcalhit->HitScin)[jjj].first);
        }
      }
      iii = (ahcalhit->HitCer).size();
      std::cout << "pd1 CerTime size pd1 is " << iii << std::endl;
      for(int jjj = 0; jjj < iii; jjj++) {
        std::cout << "hit first is " << (ahcalhit->HitCer)[jjj].first << std::endl;
        std::cout << "hit second is " << (ahcalhit->HitCer)[jjj].second << std::endl;
        std::cout << "filled histogram " << std::endl;
        if (aar.Rndm() < AFILTER(0, (ahcalhit->HitCer)[jjj].second)) {
          hcalpd1cer->Fill((ahcalhit->HitCer)[jjj].first);
        }
        std::cout << "filled histogram 2 " <<std::endl;
      }
    }
      break;
    case 2: {
      int iii = (ahcalhit->HitScin).size();
      std::cout << "pd2 ScintTime size pd2 is " << iii << std::endl;
      for (int jjj = 0; jjj < iii; jjj++) {
        if(aar.Rndm() < AFILTER(0, (ahcalhit->HitScin)[jjj].second)) {
          hcalpd2cer->Fill((ahcalhit->HitCer)[jjj].first);
        }

      }
    }
      break;
    default: 
      break;
  }

  if (gendeth == 3 || gendeth == 4) {
    if (idet == 6) {
      if ((ifiber ==1) || (ifiber == 2)) {
        Contributions zxzz = ahcalhit->truth;
        for (size_t j = 0; j < zxzz.size(); j++) {
          ehcaltime->Fill((zxzz.at(j)).time);
        }
      }
    }
  }

}

void calibrateHcalFillTimeGendethSampling(int islice, CalVision::DualCrysCalorimeterHit* &ahcalhit, map<string, int> mapsampcalslice, int gendeth, TH1F* &ehcaltime) {
  if(gendeth == 3 || gendeth == 4) {
    if ((islice == (*mapsampcalslice.find("PS")).second) || (islice == (*mapsampcalslice.find("Quartz")).second)) {
      Contributions zxzz = ahcalhit->truth;
      for (size_t j = 0; j < zxzz.size(); j++) {
        ehcaltime->Fill((zxzz.at(j)).time);
      }
    }
  }
}

void calibrateHcalFillTimeGendeth(CalVision::DualCrysCalorimeterHit* &ahcalhit, TH1F* &hcalpd1cer, TH1F* &hcalpd1scint, int hcaltype, int gendeth, long long int ihitchan, map<string, int> &mapsampcalslice, TH1F* &hcalpd2cer, TH1F* &ehcaltime){
  switch(hcaltype) {
    case 0:
      {
	  int idet,ilayer,itube,iair,itype,ifiber,iabs,iphdet,ihole,ix,iy;
    DecodeFiber(ihitchan,idet,ilayer,itube,iair,itype,ifiber,iabs,iphdet,ihole,ix,iy);
    calibrateHcalFillTimeGendethFiber(ahcalhit, iphdet, gendeth, idet, ehcaltime, hcalpd1scint, hcalpd1cer, hcalpd2cer, ifiber);
      }
      break;
    case 1: {
    	int idet,ix,iy,ilayer,ibox2,islice;
      DecodeSampling(ihitchan,idet,ix,iy,ilayer,ibox2,islice);
      calibrateHcalFillTimeGendethSampling(islice, ahcalhit, mapsampcalslice, gendeth, ehcaltime);
    }
      break;
    default: 
      break;
  }
}

void calibrateHcalFillTime(int ievt, TBranch* &b_hcal, CalHits* &hcalhits, int hcaltype, int gendeth, int nbytehcal, TH1F* ehcaltime, TH1F* hcalpd1scint, TH1F* hcalpd1cer, TH1F* hcalpd2scint, TH1F* hcalpd2cer, map<string, int> &mapsampcalslice) {
  nbytehcal = b_hcal->GetEntry(ievt);
  if(ievt < SCECOUNT) {
    std::cout << std::endl << "number of hcal hits is " 
    << hcalhits->size() << std::endl;
  }
  for(size_t index = 0; index < hcalhits->size(); index++) {
    CalVision::DualCrysCalorimeterHit* ahcalhit = hcalhits->at(index);
    float ah = ahcalhit->energyDeposit;
    float aarel = ahcalhit->edeprelativistic;
    long long int ihitchan = ahcalhit->cellID;
    calibrateHcalFillTimeGendeth(ahcalhit, hcalpd1cer, hcalpd1scint, hcaltype, gendeth, ihitchan, mapsampcalslice, hcalpd2cer, ehcaltime);
  }
}
