// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G__DualTestBeam
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "ROOT/RConfig.hxx"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Header files passed as explicit arguments
#include "/Users/shiva/DD4hep/install/include/ROOT/Warnings.h"
#include "/Users/shiva/DualTestBeam/include/DualCrysCalorimeterHit.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace dd4hep {
   namespace ROOTDict {
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance();
      static TClass *dd4hep_Dictionary();

      // Function generating the singleton type initializer
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance()
      {
         static ::ROOT::TGenericClassInfo 
            instance("dd4hep", 0 /*version*/, "DDG4/Geant4Data.h", 30,
                     ::ROOT::Internal::DefineBehavior((void*)nullptr,(void*)nullptr),
                     &dd4hep_Dictionary, 0);
         return &instance;
      }
      // Insure that the inline function is _not_ optimized away by the compiler
      ::ROOT::TGenericClassInfo *(*_R__UNIQUE_DICT_(InitFunctionKeeper))() = &GenerateInitInstance;  
      // Static variable to force the class initialization
      static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstance(); R__UseDummy(_R__UNIQUE_DICT_(Init));

      // Dictionary for non-ClassDef classes
      static TClass *dd4hep_Dictionary() {
         return GenerateInitInstance()->GetClass();
      }

   }
}

namespace dd4hep {
   namespace sim {
   namespace ROOTDict {
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance();
      static TClass *dd4hepcLcLsim_Dictionary();

      // Function generating the singleton type initializer
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance()
      {
         static ::ROOT::TGenericClassInfo 
            instance("dd4hep::sim", 0 /*version*/, "DDG4/Geant4Data.h", 37,
                     ::ROOT::Internal::DefineBehavior((void*)nullptr,(void*)nullptr),
                     &dd4hepcLcLsim_Dictionary, 0);
         return &instance;
      }
      // Insure that the inline function is _not_ optimized away by the compiler
      ::ROOT::TGenericClassInfo *(*_R__UNIQUE_DICT_(InitFunctionKeeper))() = &GenerateInitInstance;  
      // Static variable to force the class initialization
      static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstance(); R__UseDummy(_R__UNIQUE_DICT_(Init));

      // Dictionary for non-ClassDef classes
      static TClass *dd4hepcLcLsim_Dictionary() {
         return GenerateInitInstance()->GetClass();
      }

   }
}
}

namespace CalVision {
   namespace ROOTDict {
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance();
      static TClass *CalVision_Dictionary();

      // Function generating the singleton type initializer
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance()
      {
         static ::ROOT::TGenericClassInfo 
            instance("CalVision", 0 /*version*/, "", 130,
                     ::ROOT::Internal::DefineBehavior((void*)nullptr,(void*)nullptr),
                     &CalVision_Dictionary, 0);
         return &instance;
      }
      // Insure that the inline function is _not_ optimized away by the compiler
      ::ROOT::TGenericClassInfo *(*_R__UNIQUE_DICT_(InitFunctionKeeper))() = &GenerateInitInstance;  
      // Static variable to force the class initialization
      static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstance(); R__UseDummy(_R__UNIQUE_DICT_(Init));

      // Dictionary for non-ClassDef classes
      static TClass *CalVision_Dictionary() {
         return GenerateInitInstance()->GetClass();
      }

   }
}

namespace ROOT {
   static TClass *CalVisioncLcLDualCrysCalorimeterHit_Dictionary();
   static void CalVisioncLcLDualCrysCalorimeterHit_TClassManip(TClass*);
   static void *new_CalVisioncLcLDualCrysCalorimeterHit(void *p = nullptr);
   static void *newArray_CalVisioncLcLDualCrysCalorimeterHit(Long_t size, void *p);
   static void delete_CalVisioncLcLDualCrysCalorimeterHit(void *p);
   static void deleteArray_CalVisioncLcLDualCrysCalorimeterHit(void *p);
   static void destruct_CalVisioncLcLDualCrysCalorimeterHit(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CalVision::DualCrysCalorimeterHit*)
   {
      ::CalVision::DualCrysCalorimeterHit *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::CalVision::DualCrysCalorimeterHit));
      static ::ROOT::TGenericClassInfo 
         instance("CalVision::DualCrysCalorimeterHit", "", 157,
                  typeid(::CalVision::DualCrysCalorimeterHit), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CalVisioncLcLDualCrysCalorimeterHit_Dictionary, isa_proxy, 4,
                  sizeof(::CalVision::DualCrysCalorimeterHit) );
      instance.SetNew(&new_CalVisioncLcLDualCrysCalorimeterHit);
      instance.SetNewArray(&newArray_CalVisioncLcLDualCrysCalorimeterHit);
      instance.SetDelete(&delete_CalVisioncLcLDualCrysCalorimeterHit);
      instance.SetDeleteArray(&deleteArray_CalVisioncLcLDualCrysCalorimeterHit);
      instance.SetDestructor(&destruct_CalVisioncLcLDualCrysCalorimeterHit);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CalVision::DualCrysCalorimeterHit*)
   {
      return GenerateInitInstanceLocal(static_cast<::CalVision::DualCrysCalorimeterHit*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CalVision::DualCrysCalorimeterHit*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CalVisioncLcLDualCrysCalorimeterHit_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::CalVision::DualCrysCalorimeterHit*>(nullptr))->GetClass();
      CalVisioncLcLDualCrysCalorimeterHit_TClassManip(theClass);
   return theClass;
   }

   static void CalVisioncLcLDualCrysCalorimeterHit_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_CalVisioncLcLDualCrysCalorimeterHit(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CalVision::DualCrysCalorimeterHit : new ::CalVision::DualCrysCalorimeterHit;
   }
   static void *newArray_CalVisioncLcLDualCrysCalorimeterHit(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CalVision::DualCrysCalorimeterHit[nElements] : new ::CalVision::DualCrysCalorimeterHit[nElements];
   }
   // Wrapper around operator delete
   static void delete_CalVisioncLcLDualCrysCalorimeterHit(void *p) {
      delete (static_cast<::CalVision::DualCrysCalorimeterHit*>(p));
   }
   static void deleteArray_CalVisioncLcLDualCrysCalorimeterHit(void *p) {
      delete [] (static_cast<::CalVision::DualCrysCalorimeterHit*>(p));
   }
   static void destruct_CalVisioncLcLDualCrysCalorimeterHit(void *p) {
      typedef ::CalVision::DualCrysCalorimeterHit current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CalVision::DualCrysCalorimeterHit

namespace ROOT {
   static TClass *vectorlEpairlEfloatcOfloatgRsPgR_Dictionary();
   static void vectorlEpairlEfloatcOfloatgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEpairlEfloatcOfloatgRsPgR(void *p = nullptr);
   static void *newArray_vectorlEpairlEfloatcOfloatgRsPgR(Long_t size, void *p);
   static void delete_vectorlEpairlEfloatcOfloatgRsPgR(void *p);
   static void deleteArray_vectorlEpairlEfloatcOfloatgRsPgR(void *p);
   static void destruct_vectorlEpairlEfloatcOfloatgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<pair<float,float> >*)
   {
      vector<pair<float,float> > *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<pair<float,float> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<pair<float,float> >", -2, "vector", 389,
                  typeid(vector<pair<float,float> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEpairlEfloatcOfloatgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<pair<float,float> >) );
      instance.SetNew(&new_vectorlEpairlEfloatcOfloatgRsPgR);
      instance.SetNewArray(&newArray_vectorlEpairlEfloatcOfloatgRsPgR);
      instance.SetDelete(&delete_vectorlEpairlEfloatcOfloatgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEpairlEfloatcOfloatgRsPgR);
      instance.SetDestructor(&destruct_vectorlEpairlEfloatcOfloatgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<pair<float,float> > >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<pair<float,float> >","std::__1::vector<std::__1::pair<float, float>, std::__1::allocator<std::__1::pair<float, float>>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<pair<float,float> >*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEpairlEfloatcOfloatgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<pair<float,float> >*>(nullptr))->GetClass();
      vectorlEpairlEfloatcOfloatgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEpairlEfloatcOfloatgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEpairlEfloatcOfloatgRsPgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<pair<float,float> > : new vector<pair<float,float> >;
   }
   static void *newArray_vectorlEpairlEfloatcOfloatgRsPgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<pair<float,float> >[nElements] : new vector<pair<float,float> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEpairlEfloatcOfloatgRsPgR(void *p) {
      delete (static_cast<vector<pair<float,float> >*>(p));
   }
   static void deleteArray_vectorlEpairlEfloatcOfloatgRsPgR(void *p) {
      delete [] (static_cast<vector<pair<float,float> >*>(p));
   }
   static void destruct_vectorlEpairlEfloatcOfloatgRsPgR(void *p) {
      typedef vector<pair<float,float> > current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<pair<float,float> >

namespace ROOT {
   static TClass *vectorlEfloatgR_Dictionary();
   static void vectorlEfloatgR_TClassManip(TClass*);
   static void *new_vectorlEfloatgR(void *p = nullptr);
   static void *newArray_vectorlEfloatgR(Long_t size, void *p);
   static void delete_vectorlEfloatgR(void *p);
   static void deleteArray_vectorlEfloatgR(void *p);
   static void destruct_vectorlEfloatgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<float>*)
   {
      vector<float> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<float>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<float>", -2, "vector", 389,
                  typeid(vector<float>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEfloatgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<float>) );
      instance.SetNew(&new_vectorlEfloatgR);
      instance.SetNewArray(&newArray_vectorlEfloatgR);
      instance.SetDelete(&delete_vectorlEfloatgR);
      instance.SetDeleteArray(&deleteArray_vectorlEfloatgR);
      instance.SetDestructor(&destruct_vectorlEfloatgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<float> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<float>","std::__1::vector<float, std::__1::allocator<float>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<float>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEfloatgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<float>*>(nullptr))->GetClass();
      vectorlEfloatgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEfloatgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEfloatgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<float> : new vector<float>;
   }
   static void *newArray_vectorlEfloatgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<float>[nElements] : new vector<float>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEfloatgR(void *p) {
      delete (static_cast<vector<float>*>(p));
   }
   static void deleteArray_vectorlEfloatgR(void *p) {
      delete [] (static_cast<vector<float>*>(p));
   }
   static void destruct_vectorlEfloatgR(void *p) {
      typedef vector<float> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<float>

namespace ROOT {
   // Registration Schema evolution read functions
   int RecordReadRules_G__DualTestBeam() {
      return 0;
   }
   static int _R__UNIQUE_DICT_(ReadRules_G__DualTestBeam) = RecordReadRules_G__DualTestBeam();R__UseDummy(_R__UNIQUE_DICT_(ReadRules_G__DualTestBeam));
} // namespace ROOT
namespace {
  void TriggerDictionaryInitialization_G__DualTestBeam_Impl() {
    static const char* headers[] = {
"0",
nullptr
    };
    static const char* includePaths[] = {
"/Users/shiva/DualTestBeam/include",
"/Users/shiva/DD4hep/install/include",
"/opt/homebrew/include/root",
"/opt/homebrew/include",
"/Users/shiva/geant4-v11.3.2-install/include/Geant4",
"/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include",
"/opt/homebrew/Cellar/qt/6.9.1/lib/QtCore.framework/Headers",
"/opt/homebrew/Cellar/qt/6.9.1/lib/QtCore.framework",
"/opt/homebrew/Cellar/qt/6.9.1/share/qt/mkspecs/macx-clang",
"/opt/homebrew/Cellar/qt/6.9.1/include",
"/opt/homebrew/Cellar/qt/6.9.1/lib/QtGui.framework/Headers",
"/opt/homebrew/Cellar/qt/6.9.1/lib/QtGui.framework",
"/opt/homebrew/Cellar/qt/6.9.1/lib/QtWidgets.framework/Headers",
"/opt/homebrew/Cellar/qt/6.9.1/lib/QtWidgets.framework",
"/opt/homebrew/Cellar/root/6.36.00/include/root",
"/Users/shiva/DualTestBeam/build/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "G__DualTestBeam dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace CalVision{class DualCrysCalorimeterHit;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "G__DualTestBeam dictionary payload"

#ifndef BOOST_SPIRIT_USE_PHOENIX_V3
  #define BOOST_SPIRIT_USE_PHOENIX_V3 1
#endif
#ifndef DD4HEP_USE_GEANT4_UNITS
  #define DD4HEP_USE_GEANT4_UNITS 1
#endif
#ifndef DD4HEP_USE_TINYXML
  #define DD4HEP_USE_TINYXML 1
#endif
#ifndef ROOT_SUPPORT_CLAD
  #define ROOT_SUPPORT_CLAD 1
#endif
#ifndef G4LIB_BUILD_DLL
  #define G4LIB_BUILD_DLL 1
#endif
#ifndef PTL_BUILD_DLL
  #define PTL_BUILD_DLL 1
#endif
#ifndef G4VIS_USE_RAYTRACERX
  #define G4VIS_USE_RAYTRACERX 1
#endif
#ifndef G4VIS_USE_TOOLSSG_QT_GLES
  #define G4VIS_USE_TOOLSSG_QT_GLES 1
#endif
#ifndef G4VIS_USE_TOOLSSG_QT_ZB
  #define G4VIS_USE_TOOLSSG_QT_ZB 1
#endif
#ifndef G4VIS_USE_TOOLSSG_X11_GLES
  #define G4VIS_USE_TOOLSSG_X11_GLES 1
#endif
#ifndef G4VIS_USE_TOOLSSG_X11_ZB
  #define G4VIS_USE_TOOLSSG_X11_ZB 1
#endif
#ifndef G4VIS_USE_OPENGLQT
  #define G4VIS_USE_OPENGLQT 1
#endif
#ifndef G4VIS_USE_OPENGLX
  #define G4VIS_USE_OPENGLX 1
#endif
#ifndef G4VIS_USE_QT3D
  #define G4VIS_USE_QT3D 1
#endif
#ifndef G4UI_USE_QT
  #define G4UI_USE_QT 1
#endif
#ifndef QT_CORE_LIB
  #define QT_CORE_LIB 1
#endif
#ifndef QT_NO_DEBUG
  #define QT_NO_DEBUG 1
#endif
#ifndef QT_GUI_LIB
  #define QT_GUI_LIB 1
#endif
#ifndef QT_WIDGETS_LIB
  #define QT_WIDGETS_LIB 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#ifndef ROOT_WARNINGS_H
#define ROOT_WARNINGS_H

//==========================================================================
//  AIDA Detector description implementation 
//--------------------------------------------------------------------------
// Copyright (C) Organisation europeenne pour la Recherche nucleaire (CERN)
// All rights reserved.
//
// For the licensing terms see $DD4hepINSTALL/LICENSE.
// For the list of contributors see $DD4hepINSTALL/doc/CREDITS.
//
//--------------------------------------------------------------------------
//  These are the common warnings, which are generated by rootcling
//  and which cannot be avoided at all. We hence disable them in the
//  corresponding compilation units to reduce annoying warnings.
//
//  M.Frank
//==========================================================================

#if defined(__clang__)
  #pragma clang diagnostic ignored "-Wdeprecated-declarations"
  #pragma clang diagnostic ignored "-Wdeprecated"
  #pragma clang diagnostic ignored "-Wunused"
  #pragma clang diagnostic ignored "-Woverlength-strings"
#elif defined(__GNUC__) || defined(__GNUG__)
  #pragma GCC diagnostic ignored "-Wdeprecated-declarations"
  #pragma GCC diagnostic ignored "-Wdeprecated"
  #pragma GCC diagnostic ignored "-Wunused"
  #pragma GCC diagnostic ignored "-Woverlength-strings"
#endif


#if defined(__CINT__) || defined(__MAKECINT__) || defined(__CLANG__) || defined(__ROOTCLING__)
#define  DD4HEP_DICTIONARY_MODE 1
#endif

#if defined(G__DICTIONARY) && defined(G__ROOT)
#define  DD4HEP_DICTIONARY_CODE 1
#endif


#endif
//==========================================================================
//  AIDA Detector description implementation 
//--------------------------------------------------------------------------
// Copyright (C) Organisation europeenne pour la Recherche nucleaire (CERN)
// All rights reserved.
//
// For the licensing terms see $DD4hepINSTALL/LICENSE.
// For the list of contributors see $DD4hepINSTALL/doc/CREDITS.
//
// Author     : M.Frank
//
//==========================================================================
#ifndef EXAMPLES_DDDualCrys_SRC_DualCrysCalorimeterHIT_H
#define EXAMPLES_DDDualCrys_SRC_DualCrysCalorimeterHIT_H

/// Framework include files
#include "DDG4/Geant4Data.h"
#include "G4OpticalPhoton.hh"
#include "G4VProcess.hh"


typedef ROOT::Math::XYZVector Position;
typedef ROOT::Math::XYZVector Direction;



namespace CalVision {


  const int finenbin=40;
  const int coarsenbin=4;


    //const int truthnbin=1000;

  /// This is the hit definition.
  /** I took here the same definition of the default Geant4Tracker class,
   *  (see DDG4/Geant4Data.h)  but it could be anything else as well.
   *
   *  Please note:
   *  ============
   *  The MC truth handling as implemented in the Geant4ParticleHandler
   *  will not work with this class if the object(s) are saved with 
   *  the standard Geant4Output2ROOT event action. If the hit is 
   *  specialized, the output writing also must be specialized if
   *  MC truth handling should be supported.
   *  Otherwise it is sufficient to provide a ROOT dictionary as long as the
   *  base class dd4hep::sim::Geant4HitData is kept.
   *
   *  \author  M.Frank
   *  \version 1.0
   *  \ingroup DD4HEP_SIMULATION
   */
  class DualCrysCalorimeterHit : public dd4hep::sim::Geant4Calorimeter::Hit   {

  public:
    int n_inelastic;
    int ncerenkov,nscintillator;
    float edeprelativistic;
    float edepepgam;
    float wavelenmin=300;
    float wavelenmax=1000;


    int nfinebin=finenbin;
    float timemin=0;
    float timemax=400;
    float timemaxz=40;
    //    std::array<int,finenbin>  ncerwave;
    // std::array<int,finenbin> nscintwave;
    //std::array<int,finenbin>  ncertime;
    //std::array<int,finenbin> nscinttime;
    //std::array<int,finenbin>  ncertimez;
    //std::array<int,finenbin> nscinttimez;
    //std::array<float,finenbin> edeptime;
    //std::array<float,finenbin> ereldeptime;
    //float xmax=10;
    //float ymax=10;
    //float xmin=-10;
    //float ymin=-10;
    //int ncoarsebin=coarsenbin;
    // std::array<std::array<int,coarsenbin>,coarsenbin> cerhitpos;
    //std::array<std::array<int,coarsenbin>,coarsenbin> scinthitpos;

    std::vector<std::pair<float, float>> HitCer;
    std::vector<std::pair<float, float>> HitScin;
    //    std::vector<float> CerTime;
    //std::vector<float> ScinTime;



    //int ntruthbin=truthnbin;
    //std::array<float,truthnbin> contribBeta;
    //std::array<float,truthnbin> contribCharge;
    std::vector<float> contribBeta;
    std::vector<float> contribCharge;


  public:
    /// Default constructor
    DualCrysCalorimeterHit() = default;
    /// Initializing constructor
    DualCrysCalorimeterHit(const Position& cell_pos):dd4hep::sim::Geant4Calorimeter::Hit(cell_pos),ncerenkov(0),nscintillator(0),edeprelativistic(0.),n_inelastic(0),edepepgam(0.) {


      for( int i=0;i<finenbin;i++){
        //ncerwave[i]=0;
        //nscintwave[i]=0;
        //ncertime[i]=0;
        //nscinttime[i]=0;
        //ncertimez[i]=0;
        //nscinttimez[i]=0;
	//edeptime[i]=0.;
	//ereldeptime[i]=0.;
      }
      //      for( int i=0;i<coarsenbin;i++ ) {
      //  for( int j=0;j<coarsenbin;j++ ) {
      //    cerhitpos[i][j]=0;
      //    scinthitpos[i][j]=0;
      //  }
      // }

}

    /// Default destructor
    virtual ~DualCrysCalorimeterHit() = default;
    /// Assignment operator
    //DualCrysCalorimeterHit& operator=(const DualCrysCalorimeterHit& c);
  };

  /// Helper to dump data file
  /**
   *  Usage:  
   *  $> root.exe
   *  ....
   *  root [0] gSystem->Load("libDDG4Plugins.so");
   *  root [1] gSystem->Load("libDDG4_MySensDet.so");
   *  root [2] CalVision::Dump::dumpData(<num-ebents>,<file-name>);
   *
   */
  class Dump   {
  public:
    /// Standalone function to dump data from a root file
    static int DualCrysCalorimeterdumpData(int num_evts, const char* file_name);
  };
}

// CINT configuration
#if defined(__CINT__) || defined(__MAKECINT__) || defined(__CLING__) || defined(__ROOTCLING__)
#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

/// Define namespaces
#pragma link C++ namespace dd4hep;
#pragma link C++ namespace dd4hep::sim;
#pragma link C++ namespace CalVision;
#pragma link C++ class     CalVision::DualCrysCalorimeterHit+;
#pragma link C++ class     CalVision::DualCrysCalorimeterDump;
#endif

#endif // EXAMPLES_DDDualCrys_SRC_DualCrysCalorimeterHIT_H

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"CalVision::DualCrysCalorimeterHit", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("G__DualTestBeam",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_G__DualTestBeam_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_G__DualTestBeam_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_G__DualTestBeam() {
  TriggerDictionaryInitialization_G__DualTestBeam_Impl();
}
