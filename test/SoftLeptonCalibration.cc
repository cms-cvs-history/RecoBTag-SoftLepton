#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ParameterSet/interface/InputTag.h"

class TrackAssociatorBase;

class SoftLeptonCalibration : public edm::EDAnalyzer {
public:
  explicit SoftLeptonCalibration(const edm::ParameterSet& config);
  virtual ~SoftLeptonCalibration();
  virtual void analyze(const edm::Event& event, const edm::EventSetup& setup);
  virtual void beginJob(const edm::EventSetup& setup);
  virtual void endJob(void);

private:
  edm::InputTag m_genPartons;
  edm::InputTag m_genJets;
  edm::InputTag m_genLeptons;
  edm::InputTag m_caloJets;
  edm::InputTag m_caloJetsCorrected;
  edm::InputTag m_caloJetsCorrectedB;
  edm::InputTag m_recoTracks;           // tracks or derived
  edm::InputTag m_recoLeptons;          // tracks, global muon tracks, electron tracks, or gsfElectron gsfTracks

  double m_leptonPtMin;
  double m_leptonAssocRadius;
  std::vector<bool> m_isLeptonMissing;  // true for MC leptons not reco'ed  (no MC-->Reco association)
  std::vector<bool> m_isLeptonFake;     // true for fake reco'ed leptons    (no MC<--Reco association)
  
  edm::InputTag m_trackingParticles;
  const TrackAssociatorBase* m_associatorByHits;
  const TrackAssociatorBase* m_associatorByChi2;
};

#include "FWCore/Framework/interface/MakerMacros.h"
DEFINE_FWK_MODULE(SoftLeptonCalibration);

#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/MuonReco/interface/Muon.h"
#include "SimDataFormats/TrackingAnalysis/interface/TrackingParticle.h"
#include "SimTracker/TrackAssociation/interface/TrackAssociatorBase.h"
#include "SimTracker/Records/interface/TrackAssociatorRecord.h"

SoftLeptonCalibration::SoftLeptonCalibration(const edm::ParameterSet& config) : 
  m_genPartons(config.getParameter<edm::InputTag>("GenPartons")),
  m_genJets(config.getParameter<edm::InputTag>("GenJets")),
  m_genLeptons(config.getParameter<edm::InputTag>("GenLeptons")),
  m_caloJets(config.getParameter<edm::InputTag>("CaloJets")),
  m_caloJetsCorrected(config.getParameter<edm::InputTag>("CaloJetsCorrected")),
  m_caloJetsCorrectedB(config.getParameter<edm::InputTag>("CaloJetsCorrectedB")),
  m_recoTracks(config.getParameter<edm::InputTag>("RecoTracks")),
  m_recoLeptons(config.getParameter<edm::InputTag>("RecoLetons")),
  m_leptonPtMin(config.getParameter<double>("LeptonPtMin")),
  m_leptonAssocRadius(config.getParameter<double>("LeptonAssocRadius")),
  m_trackingParticles(config.getParameter<edm::InputTag>("TrackingParticles"))
{
  
}

SoftLeptonCalibration::~SoftLeptonCalibration(void) {
}

void SoftLeptonCalibration::analyze(const edm::Event& event, const edm::EventSetup& setup) {
}

void SoftLeptonCalibration::beginJob(const edm::EventSetup& setup) {
  edm::ESHandle<TrackAssociatorBase> associatorByHitsHandle;
  setup.get<TrackAssociatorRecord>().get("TrackAssociatorByHits", associatorByHitsHandle);
  m_associatorByHits = associatorByHitsHandle.product();

  edm::ESHandle<TrackAssociatorBase> associatorByChi2Handle;
  setup.get<TrackAssociatorRecord>().get("TrackAssociatorByChi2", associatorByChi2Handle);
  m_associatorByChi2 = associatorByChi2Handle.product();
}

void SoftLeptonCalibration::endJob(void){
}

