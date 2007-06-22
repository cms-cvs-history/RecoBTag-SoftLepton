#! /bin/bash
for FILE in validateSoftLepton_*.cfg; do
  cmsRun $FILE
done

hadd mergedMuon.root     softMuon_*.root
hadd mergedMuonNoIP.root softMuonNoIP_*.root
hadd mergedElectron.root softElectron_*.root

cmsRun mergeValidation.cfg
