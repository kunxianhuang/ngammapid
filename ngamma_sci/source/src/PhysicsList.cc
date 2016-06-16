//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// PhysicsList.cc
//  [Note] Based on "G4 Basic Example: B3"   
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "PhysicsList.hh"
#include "G4DecayPhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"
#include "G4EmStandardPhysics.hh"
#include "HadronPhysicsQGSP_BERT.hh"
#include "G4Cerenkov.hh"
#include "G4OpBoundryProcess.hh"

//------------------------------------------------------------------------------
  PhysicsList::PhysicsList()
  : G4VModularPhysicsList() 
//------------------------------------------------------------------------------
{
// Default physics
   RegisterPhysics(new G4DecayPhysics());

// Radioactive decay
   RegisterPhysics(new G4RadioactiveDecayPhysics());

// EM physics
   RegisterPhysics(new G4EmStandardPhysics());

   //Hadronic physics
   RegisterPhysics(new HadronPhysicsQGSP("hadron", quasiElastic=true));

   //Cherenkov light
   RegisterPhysics(new G4Cerenkov("Cerenkov"));

   //Optical boundary process
   RegisterPhysics(new G4OpBoundaryProcess());
}

//------------------------------------------------------------------------------
  PhysicsList::~PhysicsList()
//------------------------------------------------------------------------------
{}

//------------------------------------------------------------------------------
  void PhysicsList::SetCuts()
//------------------------------------------------------------------------------
{
  defaultCutValue = 0.5*mm;  
  SetCutValue(100*um, "gamma");
  SetCutValue(100*um, "neutron");
    G4VUserPhysicsList::SetCuts();

}

