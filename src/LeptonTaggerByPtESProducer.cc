#include "RecoBTag/SoftLepton/interface/LeptonTaggerByPtESProducer.h"
#include "RecoBTag/SoftLepton/interface/LeptonTaggerByPt.h"

LeptonTaggerByPtESProducer::LeptonTaggerByPtESProducer(const edm::ParameterSet & pset) : 
  m_pset(pset)
{
  std::string m_name = m_pset.getParameter<std::string>("ComponentName");
  setWhatProduced(this, m_name);
}

LeptonTaggerByPtESProducer::~LeptonTaggerByPtESProducer() {
}

boost::shared_ptr<LeptonTaggerBase> LeptonTaggerByPtESProducer::produce(const SoftLeptonBTagRecord & record) {
  m_softLeptonTagger = boost::shared_ptr<LeptonTaggerBase>(new LeptonTaggerByPt());
  return m_softLeptonTagger;
}
