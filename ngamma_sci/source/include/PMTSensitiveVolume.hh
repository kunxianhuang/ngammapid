#include "G4VSensitiveDetector.hh"
#include "globals.hh"

class G4Material;
class G4HCofThisEvent;
class G4Step;

class T2KWCPMTSD : public G4VSensitiveDetector
{
public:

  PMTSensitiveVolume(G4String);
  ~PMTSensitiveVolume();

  void    Initialize(G4HCofThisEvent*);
  G4bool  ProcessHits(G4Step* astep,G4TouchableHistory* ROHist);
  void    EndOfEvent(G4HCofThisEvent*);

  void clear();
  void DrawAll();
  void PrintAll();

private:

  //T2KWCOpticalHitsCollection*  OpticalHitsCollection;

};

