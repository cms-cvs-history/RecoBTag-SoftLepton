#include "FWCore/Framework/interface/ModuleFactory.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "RecoBTag/SoftLepton/interface/SoftLepton.h"
#include "RecoBTag/SoftLepton/interface/SoftElectronProducer.h"

#include "RecoBTag/SoftLepton/interface/ElectronTagger.h"
#include "RecoBTag/SoftLepton/interface/MuonTagger.h"
#include "RecoBTag/SoftLepton/interface/MuonTaggerNoIP.h"
#include "RecoBTag/SoftLepton/interface/LeptonTaggerDistance.h"
#include "RecoBTag/SoftLepton/interface/LeptonTaggerByPt.h"
#include "RecoBTag/SoftLepton/interface/LeptonTaggerESProducer.h"

DEFINE_SEAL_MODULE();
DEFINE_ANOTHER_FWK_MODULE(SoftLepton);
DEFINE_ANOTHER_FWK_MODULE(SoftElectronProducer);
DEFINE_ANOTHER_FWK_EVENTSETUP_MODULE(LeptonTaggerESProducer<ElectronTagger>);
DEFINE_ANOTHER_FWK_EVENTSETUP_MODULE(LeptonTaggerESProducer<MuonTagger>);
DEFINE_ANOTHER_FWK_EVENTSETUP_MODULE(LeptonTaggerESProducer<MuonTaggerNoIP>);
DEFINE_ANOTHER_FWK_EVENTSETUP_MODULE(LeptonTaggerESProducer<LeptonTaggerDistance>);
DEFINE_ANOTHER_FWK_EVENTSETUP_MODULE(LeptonTaggerESProducer<LeptonTaggerByPt>);
