//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\
+                                                                               
// SensitiveVolume.cc                                                           
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\
+                                                                               
#include "PMTSensitiveVolume.hh"
#include "G4TouchableHistory.hh"
#include "G4Track.hh"
#include "G4Step.hh"
#include "G4ParticleDefinition.hh"
#include "G4HCofThisEvent.hh"
#include "G4VProcess.hh"

//-----------------------------------------------------------------------------\
-                                                                               
  PMTSensitiveVolume::PMTSensitiveVolume(G4String name)
  : G4VSensitiveDetector(name)
//-----------------------------------------------------------------------------\
-                                                                               
{}

//------------------------------------------------------------------------------            
  PMTSensitiveVolume::~PMTSensitiveVolume()
//------------------------------------------------------------------------------            
{}

//------------------------------------------------------------------------------            
  void PMTSensitiveVolume::Initialize(G4HCofThisEvent*)
//------------------------------------------------------------------------------            
{}

//------------------------------------------------------------------------------            
  void PMTSensitiveVolume::EndOfEvent(G4HCofThisEvent*)
//------------------------------------------------------------------------------            
{}

//------------------------------------------------------------------------------            
  G4bool PMTSensitiveVolume::ProcessHits(G4Step* aStep, G4TouchableHistory*)
//------------------------------------------------------------------------------            
{
  //G4cout << "***Hit***" <<G4endl;
  //

  // Retrivev information from the track object
  G4int nTrack = aStep->GetTrack()->GetTrackID(); //Get track ID
  G4int nStep = aStep->GetTrack()->GetCurrentStepNumber();  //Get step ID of the track
  G4String particleName = aStep->GetTrack()->GetDefinition()->GetParticleName(); //particle name
  G4Touchable* touchable = aStep->GetPreStepPoint()->GetTouchable();
  
  //if other particles than the optical photon are coming inside 
  //, we do not compute them
  if(particleName != "opticalphoton") 
    return false;
  else
    aTrack->SetTrackStatus(fStopAndKill);

  //Get hit info
  G4int pmtid = touchable->GetVolume(0)->GetCopyNo(); //Get PMT logical volume ID
  G4ThreeVector pmtpos = touchable->GetVolume(0)->GetTranslation(); //center position of PMT
  
  G4double hittime = aStep->GetPreStepPoint()->GetGlobalTime()/ns; //hititme [ns]
  

  





  

}
