#ifndef testLeptonAssociator_h
#define testLeptonAssociator_h

#include <memory>
#include <iostream>
#include <string>
#include <map>
#include <set>

#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"

class TrackAssociatorBase;

class testLeptonAssociator : public edm::EDAnalyzer {
public:
  explicit testLeptonAssociator(const edm::ParameterSet& iConfig);
  virtual ~testLeptonAssociator();
  virtual void beginJob(const edm::EventSetup& iSetup);
  virtual void analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup);

private:
  std::string   m_trackAssociator;
  edm::InputTag m_recoTracks;
  edm::InputTag m_recoLeptons;
  edm::InputTag m_trackingTruth;
  unsigned int  m_flavour;

  const TrackAssociatorBase* m_associator;
};

#endif
