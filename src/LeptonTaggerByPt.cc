#include <limits>

#include "DataFormats/BTauReco/interface/SoftLeptonTagInfo.h"
#include "RecoBTag/SoftLepton/interface/LeptonTaggerByPt.h"
#include "RecoBTag/SoftLepton/interface/LeptonSelector.h"

/// b-tag a jet based on track-to-jet parameters in the extened info collection
float LeptonTaggerByPt::discriminator(const TagInfoHelper & tagInfo) const {
  // default value, used if there are no leptons associated to this jet
  float bestTag = - std::numeric_limits<float>::infinity();
  const reco::SoftLeptonTagInfo & info = tagInfo.get<reco::SoftLeptonTagInfo>();
  // if there are multiple leptons, look for the one with the highest pT_rel
  for (unsigned int i = 0; i < info.leptons(); i++) {
    const reco::SoftLeptonProperties & properties = info.properties(i);
    if ((m_selection == btag::LeptonSelector::any) or 
        (m_selection == btag::LeptonSelector::positive and properties.sip3d >= 0) or 
        (m_selection == btag::LeptonSelector::negative and properties.sip3d <= 0)) 
    {
      float tag = properties.ptRel;
      if (tag > bestTag)
        bestTag = tag;
    }
  }
  return bestTag;
}
