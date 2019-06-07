//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu May 16 11:16:32 2019 by ROOT version 6.16/00
// from TTree DecayTree/DecayTree
// found on file: myLcTuple_0.root
//////////////////////////////////////////////////////////

#ifndef BackgroundSubTemplate_h
#define BackgroundSubTemplate_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

// Headers needed by this particular selector


class BackgroundSubTemplate : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   // Readers to access the data (delete the ones you do not need).
   TTreeReaderValue<Double_t> Lambda_cplus_ENDVERTEX_X = {fReader, "Lambda_cplus_ENDVERTEX_X"};
   TTreeReaderValue<Double_t> Lambda_cplus_ENDVERTEX_Y = {fReader, "Lambda_cplus_ENDVERTEX_Y"};
   TTreeReaderValue<Double_t> Lambda_cplus_ENDVERTEX_Z = {fReader, "Lambda_cplus_ENDVERTEX_Z"};
   TTreeReaderValue<Double_t> Lambda_cplus_ENDVERTEX_XERR = {fReader, "Lambda_cplus_ENDVERTEX_XERR"};
   TTreeReaderValue<Double_t> Lambda_cplus_ENDVERTEX_YERR = {fReader, "Lambda_cplus_ENDVERTEX_YERR"};
   TTreeReaderValue<Double_t> Lambda_cplus_ENDVERTEX_ZERR = {fReader, "Lambda_cplus_ENDVERTEX_ZERR"};
   TTreeReaderValue<Double_t> Lambda_cplus_ENDVERTEX_CHI2 = {fReader, "Lambda_cplus_ENDVERTEX_CHI2"};
   TTreeReaderValue<Int_t> Lambda_cplus_ENDVERTEX_NDOF = {fReader, "Lambda_cplus_ENDVERTEX_NDOF"};
   TTreeReaderValue<Double_t> Lambda_cplus_OWNPV_X = {fReader, "Lambda_cplus_OWNPV_X"};
   TTreeReaderValue<Double_t> Lambda_cplus_OWNPV_Y = {fReader, "Lambda_cplus_OWNPV_Y"};
   TTreeReaderValue<Double_t> Lambda_cplus_OWNPV_Z = {fReader, "Lambda_cplus_OWNPV_Z"};
   TTreeReaderValue<Double_t> Lambda_cplus_OWNPV_XERR = {fReader, "Lambda_cplus_OWNPV_XERR"};
   TTreeReaderValue<Double_t> Lambda_cplus_OWNPV_YERR = {fReader, "Lambda_cplus_OWNPV_YERR"};
   TTreeReaderValue<Double_t> Lambda_cplus_OWNPV_ZERR = {fReader, "Lambda_cplus_OWNPV_ZERR"};
   TTreeReaderValue<Double_t> Lambda_cplus_OWNPV_CHI2 = {fReader, "Lambda_cplus_OWNPV_CHI2"};
   TTreeReaderValue<Int_t> Lambda_cplus_OWNPV_NDOF = {fReader, "Lambda_cplus_OWNPV_NDOF"};
   TTreeReaderValue<Double_t> Lambda_cplus_IP_OWNPV = {fReader, "Lambda_cplus_IP_OWNPV"};
   TTreeReaderValue<Double_t> Lambda_cplus_IPCHI2_OWNPV = {fReader, "Lambda_cplus_IPCHI2_OWNPV"};
   TTreeReaderValue<Double_t> Lambda_cplus_FD_OWNPV = {fReader, "Lambda_cplus_FD_OWNPV"};
   TTreeReaderValue<Double_t> Lambda_cplus_FDCHI2_OWNPV = {fReader, "Lambda_cplus_FDCHI2_OWNPV"};
   TTreeReaderValue<Double_t> Lambda_cplus_DIRA_OWNPV = {fReader, "Lambda_cplus_DIRA_OWNPV"};
   TTreeReaderValue<Double_t> Lambda_cplus_P = {fReader, "Lambda_cplus_P"};
   TTreeReaderValue<Double_t> Lambda_cplus_PT = {fReader, "Lambda_cplus_PT"};
   TTreeReaderValue<Double_t> Lambda_cplus_PE = {fReader, "Lambda_cplus_PE"};
   TTreeReaderValue<Double_t> Lambda_cplus_PX = {fReader, "Lambda_cplus_PX"};
   TTreeReaderValue<Double_t> Lambda_cplus_PY = {fReader, "Lambda_cplus_PY"};
   TTreeReaderValue<Double_t> Lambda_cplus_PZ = {fReader, "Lambda_cplus_PZ"};
   TTreeReaderValue<Double_t> Lambda_cplus_MM = {fReader, "Lambda_cplus_MM"};
   TTreeReaderValue<Double_t> Lambda_cplus_MMERR = {fReader, "Lambda_cplus_MMERR"};
   TTreeReaderValue<Double_t> Lambda_cplus_M = {fReader, "Lambda_cplus_M"};
   TTreeReaderValue<Int_t> Lambda_cplus_ID = {fReader, "Lambda_cplus_ID"};
   TTreeReaderValue<Double_t> Lambda_cplus_TAU = {fReader, "Lambda_cplus_TAU"};
   TTreeReaderValue<Double_t> Lambda_cplus_TAUERR = {fReader, "Lambda_cplus_TAUERR"};
   TTreeReaderValue<Double_t> Lambda_cplus_TAUCHI2 = {fReader, "Lambda_cplus_TAUCHI2"};
   TTreeReaderValue<Bool_t> Lambda_cplus_L0Global_Dec = {fReader, "Lambda_cplus_L0Global_Dec"};
   TTreeReaderValue<Bool_t> Lambda_cplus_L0Global_TIS = {fReader, "Lambda_cplus_L0Global_TIS"};
   TTreeReaderValue<Bool_t> Lambda_cplus_L0Global_TOS = {fReader, "Lambda_cplus_L0Global_TOS"};
   TTreeReaderValue<Bool_t> Lambda_cplus_Hlt1Global_Dec = {fReader, "Lambda_cplus_Hlt1Global_Dec"};
   TTreeReaderValue<Bool_t> Lambda_cplus_Hlt1Global_TIS = {fReader, "Lambda_cplus_Hlt1Global_TIS"};
   TTreeReaderValue<Bool_t> Lambda_cplus_Hlt1Global_TOS = {fReader, "Lambda_cplus_Hlt1Global_TOS"};
   TTreeReaderValue<Bool_t> Lambda_cplus_Hlt1Phys_Dec = {fReader, "Lambda_cplus_Hlt1Phys_Dec"};
   TTreeReaderValue<Bool_t> Lambda_cplus_Hlt1Phys_TIS = {fReader, "Lambda_cplus_Hlt1Phys_TIS"};
   TTreeReaderValue<Bool_t> Lambda_cplus_Hlt1Phys_TOS = {fReader, "Lambda_cplus_Hlt1Phys_TOS"};
   TTreeReaderValue<Bool_t> Lambda_cplus_Hlt2Global_Dec = {fReader, "Lambda_cplus_Hlt2Global_Dec"};
   TTreeReaderValue<Bool_t> Lambda_cplus_Hlt2Global_TIS = {fReader, "Lambda_cplus_Hlt2Global_TIS"};
   TTreeReaderValue<Bool_t> Lambda_cplus_Hlt2Global_TOS = {fReader, "Lambda_cplus_Hlt2Global_TOS"};
   TTreeReaderValue<Bool_t> Lambda_cplus_Hlt2Phys_Dec = {fReader, "Lambda_cplus_Hlt2Phys_Dec"};
   TTreeReaderValue<Bool_t> Lambda_cplus_Hlt2Phys_TIS = {fReader, "Lambda_cplus_Hlt2Phys_TIS"};
   TTreeReaderValue<Bool_t> Lambda_cplus_Hlt2Phys_TOS = {fReader, "Lambda_cplus_Hlt2Phys_TOS"};
   TTreeReaderValue<Double_t> Lambda_cplus_X = {fReader, "Lambda_cplus_X"};
   TTreeReaderValue<Double_t> Lambda_cplus_Y = {fReader, "Lambda_cplus_Y"};
   TTreeReaderValue<Double_t> PromptK_OWNPV_X = {fReader, "PromptK_OWNPV_X"};
   TTreeReaderValue<Double_t> PromptK_OWNPV_Y = {fReader, "PromptK_OWNPV_Y"};
   TTreeReaderValue<Double_t> PromptK_OWNPV_Z = {fReader, "PromptK_OWNPV_Z"};
   TTreeReaderValue<Double_t> PromptK_OWNPV_XERR = {fReader, "PromptK_OWNPV_XERR"};
   TTreeReaderValue<Double_t> PromptK_OWNPV_YERR = {fReader, "PromptK_OWNPV_YERR"};
   TTreeReaderValue<Double_t> PromptK_OWNPV_ZERR = {fReader, "PromptK_OWNPV_ZERR"};
   TTreeReaderValue<Double_t> PromptK_OWNPV_CHI2 = {fReader, "PromptK_OWNPV_CHI2"};
   TTreeReaderValue<Int_t> PromptK_OWNPV_NDOF = {fReader, "PromptK_OWNPV_NDOF"};
   TTreeReaderValue<Double_t> PromptK_IP_OWNPV = {fReader, "PromptK_IP_OWNPV"};
   TTreeReaderValue<Double_t> PromptK_IPCHI2_OWNPV = {fReader, "PromptK_IPCHI2_OWNPV"};
   TTreeReaderValue<Double_t> PromptK_ORIVX_X = {fReader, "PromptK_ORIVX_X"};
   TTreeReaderValue<Double_t> PromptK_ORIVX_Y = {fReader, "PromptK_ORIVX_Y"};
   TTreeReaderValue<Double_t> PromptK_ORIVX_Z = {fReader, "PromptK_ORIVX_Z"};
   TTreeReaderValue<Double_t> PromptK_ORIVX_XERR = {fReader, "PromptK_ORIVX_XERR"};
   TTreeReaderValue<Double_t> PromptK_ORIVX_YERR = {fReader, "PromptK_ORIVX_YERR"};
   TTreeReaderValue<Double_t> PromptK_ORIVX_ZERR = {fReader, "PromptK_ORIVX_ZERR"};
   TTreeReaderValue<Double_t> PromptK_ORIVX_CHI2 = {fReader, "PromptK_ORIVX_CHI2"};
   TTreeReaderValue<Int_t> PromptK_ORIVX_NDOF = {fReader, "PromptK_ORIVX_NDOF"};
   TTreeReaderValue<Double_t> PromptK_P = {fReader, "PromptK_P"};
   TTreeReaderValue<Double_t> PromptK_PT = {fReader, "PromptK_PT"};
   TTreeReaderValue<Double_t> PromptK_PE = {fReader, "PromptK_PE"};
   TTreeReaderValue<Double_t> PromptK_PX = {fReader, "PromptK_PX"};
   TTreeReaderValue<Double_t> PromptK_PY = {fReader, "PromptK_PY"};
   TTreeReaderValue<Double_t> PromptK_PZ = {fReader, "PromptK_PZ"};
   TTreeReaderValue<Double_t> PromptK_M = {fReader, "PromptK_M"};
   TTreeReaderValue<Int_t> PromptK_ID = {fReader, "PromptK_ID"};
   TTreeReaderValue<Double_t> PromptK_PIDe = {fReader, "PromptK_PIDe"};
   TTreeReaderValue<Double_t> PromptK_PIDmu = {fReader, "PromptK_PIDmu"};
   TTreeReaderValue<Double_t> PromptK_PIDK = {fReader, "PromptK_PIDK"};
   TTreeReaderValue<Double_t> PromptK_PIDp = {fReader, "PromptK_PIDp"};
   TTreeReaderValue<Double_t> PromptK_ProbNNe = {fReader, "PromptK_ProbNNe"};
   TTreeReaderValue<Double_t> PromptK_ProbNNk = {fReader, "PromptK_ProbNNk"};
   TTreeReaderValue<Double_t> PromptK_ProbNNp = {fReader, "PromptK_ProbNNp"};
   TTreeReaderValue<Double_t> PromptK_ProbNNpi = {fReader, "PromptK_ProbNNpi"};
   TTreeReaderValue<Double_t> PromptK_ProbNNmu = {fReader, "PromptK_ProbNNmu"};
   TTreeReaderValue<Double_t> PromptK_ProbNNghost = {fReader, "PromptK_ProbNNghost"};
   TTreeReaderValue<Bool_t> PromptK_hasMuon = {fReader, "PromptK_hasMuon"};
   TTreeReaderValue<Bool_t> PromptK_isMuon = {fReader, "PromptK_isMuon"};
   TTreeReaderValue<Bool_t> PromptK_hasRich = {fReader, "PromptK_hasRich"};
   TTreeReaderValue<Bool_t> PromptK_hasCalo = {fReader, "PromptK_hasCalo"};
   TTreeReaderValue<Bool_t> PromptK_L0Global_Dec = {fReader, "PromptK_L0Global_Dec"};
   TTreeReaderValue<Bool_t> PromptK_L0Global_TIS = {fReader, "PromptK_L0Global_TIS"};
   TTreeReaderValue<Bool_t> PromptK_L0Global_TOS = {fReader, "PromptK_L0Global_TOS"};
   TTreeReaderValue<Bool_t> PromptK_Hlt1Global_Dec = {fReader, "PromptK_Hlt1Global_Dec"};
   TTreeReaderValue<Bool_t> PromptK_Hlt1Global_TIS = {fReader, "PromptK_Hlt1Global_TIS"};
   TTreeReaderValue<Bool_t> PromptK_Hlt1Global_TOS = {fReader, "PromptK_Hlt1Global_TOS"};
   TTreeReaderValue<Bool_t> PromptK_Hlt1Phys_Dec = {fReader, "PromptK_Hlt1Phys_Dec"};
   TTreeReaderValue<Bool_t> PromptK_Hlt1Phys_TIS = {fReader, "PromptK_Hlt1Phys_TIS"};
   TTreeReaderValue<Bool_t> PromptK_Hlt1Phys_TOS = {fReader, "PromptK_Hlt1Phys_TOS"};
   TTreeReaderValue<Bool_t> PromptK_Hlt2Global_Dec = {fReader, "PromptK_Hlt2Global_Dec"};
   TTreeReaderValue<Bool_t> PromptK_Hlt2Global_TIS = {fReader, "PromptK_Hlt2Global_TIS"};
   TTreeReaderValue<Bool_t> PromptK_Hlt2Global_TOS = {fReader, "PromptK_Hlt2Global_TOS"};
   TTreeReaderValue<Bool_t> PromptK_Hlt2Phys_Dec = {fReader, "PromptK_Hlt2Phys_Dec"};
   TTreeReaderValue<Bool_t> PromptK_Hlt2Phys_TIS = {fReader, "PromptK_Hlt2Phys_TIS"};
   TTreeReaderValue<Bool_t> PromptK_Hlt2Phys_TOS = {fReader, "PromptK_Hlt2Phys_TOS"};
   TTreeReaderValue<Int_t> PromptK_TRACK_Type = {fReader, "PromptK_TRACK_Type"};
   TTreeReaderValue<Int_t> PromptK_TRACK_Key = {fReader, "PromptK_TRACK_Key"};
   TTreeReaderValue<Double_t> PromptK_TRACK_CHI2NDOF = {fReader, "PromptK_TRACK_CHI2NDOF"};
   TTreeReaderValue<Double_t> PromptK_TRACK_PCHI2 = {fReader, "PromptK_TRACK_PCHI2"};
   TTreeReaderValue<Double_t> PromptK_TRACK_MatchCHI2 = {fReader, "PromptK_TRACK_MatchCHI2"};
   TTreeReaderValue<Double_t> PromptK_TRACK_GhostProb = {fReader, "PromptK_TRACK_GhostProb"};
   TTreeReaderValue<Double_t> PromptK_TRACK_CloneDist = {fReader, "PromptK_TRACK_CloneDist"};
   TTreeReaderValue<Double_t> PromptK_TRACK_Likelihood = {fReader, "PromptK_TRACK_Likelihood"};
   TTreeReaderValue<Double_t> PromptK_X = {fReader, "PromptK_X"};
   TTreeReaderValue<Double_t> PromptK_Y = {fReader, "PromptK_Y"};
   TTreeReaderValue<Double_t> PromptPi_OWNPV_X = {fReader, "PromptPi_OWNPV_X"};
   TTreeReaderValue<Double_t> PromptPi_OWNPV_Y = {fReader, "PromptPi_OWNPV_Y"};
   TTreeReaderValue<Double_t> PromptPi_OWNPV_Z = {fReader, "PromptPi_OWNPV_Z"};
   TTreeReaderValue<Double_t> PromptPi_OWNPV_XERR = {fReader, "PromptPi_OWNPV_XERR"};
   TTreeReaderValue<Double_t> PromptPi_OWNPV_YERR = {fReader, "PromptPi_OWNPV_YERR"};
   TTreeReaderValue<Double_t> PromptPi_OWNPV_ZERR = {fReader, "PromptPi_OWNPV_ZERR"};
   TTreeReaderValue<Double_t> PromptPi_OWNPV_CHI2 = {fReader, "PromptPi_OWNPV_CHI2"};
   TTreeReaderValue<Int_t> PromptPi_OWNPV_NDOF = {fReader, "PromptPi_OWNPV_NDOF"};
   TTreeReaderValue<Double_t> PromptPi_IP_OWNPV = {fReader, "PromptPi_IP_OWNPV"};
   TTreeReaderValue<Double_t> PromptPi_IPCHI2_OWNPV = {fReader, "PromptPi_IPCHI2_OWNPV"};
   TTreeReaderValue<Double_t> PromptPi_ORIVX_X = {fReader, "PromptPi_ORIVX_X"};
   TTreeReaderValue<Double_t> PromptPi_ORIVX_Y = {fReader, "PromptPi_ORIVX_Y"};
   TTreeReaderValue<Double_t> PromptPi_ORIVX_Z = {fReader, "PromptPi_ORIVX_Z"};
   TTreeReaderValue<Double_t> PromptPi_ORIVX_XERR = {fReader, "PromptPi_ORIVX_XERR"};
   TTreeReaderValue<Double_t> PromptPi_ORIVX_YERR = {fReader, "PromptPi_ORIVX_YERR"};
   TTreeReaderValue<Double_t> PromptPi_ORIVX_ZERR = {fReader, "PromptPi_ORIVX_ZERR"};
   TTreeReaderValue<Double_t> PromptPi_ORIVX_CHI2 = {fReader, "PromptPi_ORIVX_CHI2"};
   TTreeReaderValue<Int_t> PromptPi_ORIVX_NDOF = {fReader, "PromptPi_ORIVX_NDOF"};
   TTreeReaderValue<Double_t> PromptPi_P = {fReader, "PromptPi_P"};
   TTreeReaderValue<Double_t> PromptPi_PT = {fReader, "PromptPi_PT"};
   TTreeReaderValue<Double_t> PromptPi_PE = {fReader, "PromptPi_PE"};
   TTreeReaderValue<Double_t> PromptPi_PX = {fReader, "PromptPi_PX"};
   TTreeReaderValue<Double_t> PromptPi_PY = {fReader, "PromptPi_PY"};
   TTreeReaderValue<Double_t> PromptPi_PZ = {fReader, "PromptPi_PZ"};
   TTreeReaderValue<Double_t> PromptPi_M = {fReader, "PromptPi_M"};
   TTreeReaderValue<Int_t> PromptPi_ID = {fReader, "PromptPi_ID"};
   TTreeReaderValue<Double_t> PromptPi_PIDe = {fReader, "PromptPi_PIDe"};
   TTreeReaderValue<Double_t> PromptPi_PIDmu = {fReader, "PromptPi_PIDmu"};
   TTreeReaderValue<Double_t> PromptPi_PIDK = {fReader, "PromptPi_PIDK"};
   TTreeReaderValue<Double_t> PromptPi_PIDp = {fReader, "PromptPi_PIDp"};
   TTreeReaderValue<Double_t> PromptPi_ProbNNe = {fReader, "PromptPi_ProbNNe"};
   TTreeReaderValue<Double_t> PromptPi_ProbNNk = {fReader, "PromptPi_ProbNNk"};
   TTreeReaderValue<Double_t> PromptPi_ProbNNp = {fReader, "PromptPi_ProbNNp"};
   TTreeReaderValue<Double_t> PromptPi_ProbNNpi = {fReader, "PromptPi_ProbNNpi"};
   TTreeReaderValue<Double_t> PromptPi_ProbNNmu = {fReader, "PromptPi_ProbNNmu"};
   TTreeReaderValue<Double_t> PromptPi_ProbNNghost = {fReader, "PromptPi_ProbNNghost"};
   TTreeReaderValue<Bool_t> PromptPi_hasMuon = {fReader, "PromptPi_hasMuon"};
   TTreeReaderValue<Bool_t> PromptPi_isMuon = {fReader, "PromptPi_isMuon"};
   TTreeReaderValue<Bool_t> PromptPi_hasRich = {fReader, "PromptPi_hasRich"};
   TTreeReaderValue<Bool_t> PromptPi_hasCalo = {fReader, "PromptPi_hasCalo"};
   TTreeReaderValue<Bool_t> PromptPi_L0Global_Dec = {fReader, "PromptPi_L0Global_Dec"};
   TTreeReaderValue<Bool_t> PromptPi_L0Global_TIS = {fReader, "PromptPi_L0Global_TIS"};
   TTreeReaderValue<Bool_t> PromptPi_L0Global_TOS = {fReader, "PromptPi_L0Global_TOS"};
   TTreeReaderValue<Bool_t> PromptPi_Hlt1Global_Dec = {fReader, "PromptPi_Hlt1Global_Dec"};
   TTreeReaderValue<Bool_t> PromptPi_Hlt1Global_TIS = {fReader, "PromptPi_Hlt1Global_TIS"};
   TTreeReaderValue<Bool_t> PromptPi_Hlt1Global_TOS = {fReader, "PromptPi_Hlt1Global_TOS"};
   TTreeReaderValue<Bool_t> PromptPi_Hlt1Phys_Dec = {fReader, "PromptPi_Hlt1Phys_Dec"};
   TTreeReaderValue<Bool_t> PromptPi_Hlt1Phys_TIS = {fReader, "PromptPi_Hlt1Phys_TIS"};
   TTreeReaderValue<Bool_t> PromptPi_Hlt1Phys_TOS = {fReader, "PromptPi_Hlt1Phys_TOS"};
   TTreeReaderValue<Bool_t> PromptPi_Hlt2Global_Dec = {fReader, "PromptPi_Hlt2Global_Dec"};
   TTreeReaderValue<Bool_t> PromptPi_Hlt2Global_TIS = {fReader, "PromptPi_Hlt2Global_TIS"};
   TTreeReaderValue<Bool_t> PromptPi_Hlt2Global_TOS = {fReader, "PromptPi_Hlt2Global_TOS"};
   TTreeReaderValue<Bool_t> PromptPi_Hlt2Phys_Dec = {fReader, "PromptPi_Hlt2Phys_Dec"};
   TTreeReaderValue<Bool_t> PromptPi_Hlt2Phys_TIS = {fReader, "PromptPi_Hlt2Phys_TIS"};
   TTreeReaderValue<Bool_t> PromptPi_Hlt2Phys_TOS = {fReader, "PromptPi_Hlt2Phys_TOS"};
   TTreeReaderValue<Int_t> PromptPi_TRACK_Type = {fReader, "PromptPi_TRACK_Type"};
   TTreeReaderValue<Int_t> PromptPi_TRACK_Key = {fReader, "PromptPi_TRACK_Key"};
   TTreeReaderValue<Double_t> PromptPi_TRACK_CHI2NDOF = {fReader, "PromptPi_TRACK_CHI2NDOF"};
   TTreeReaderValue<Double_t> PromptPi_TRACK_PCHI2 = {fReader, "PromptPi_TRACK_PCHI2"};
   TTreeReaderValue<Double_t> PromptPi_TRACK_MatchCHI2 = {fReader, "PromptPi_TRACK_MatchCHI2"};
   TTreeReaderValue<Double_t> PromptPi_TRACK_GhostProb = {fReader, "PromptPi_TRACK_GhostProb"};
   TTreeReaderValue<Double_t> PromptPi_TRACK_CloneDist = {fReader, "PromptPi_TRACK_CloneDist"};
   TTreeReaderValue<Double_t> PromptPi_TRACK_Likelihood = {fReader, "PromptPi_TRACK_Likelihood"};
   TTreeReaderValue<Double_t> PromptPi_X = {fReader, "PromptPi_X"};
   TTreeReaderValue<Double_t> PromptPi_Y = {fReader, "PromptPi_Y"};
   TTreeReaderValue<Double_t> PromptXi_ENDVERTEX_X = {fReader, "PromptXi_ENDVERTEX_X"};
   TTreeReaderValue<Double_t> PromptXi_ENDVERTEX_Y = {fReader, "PromptXi_ENDVERTEX_Y"};
   TTreeReaderValue<Double_t> PromptXi_ENDVERTEX_Z = {fReader, "PromptXi_ENDVERTEX_Z"};
   TTreeReaderValue<Double_t> PromptXi_ENDVERTEX_XERR = {fReader, "PromptXi_ENDVERTEX_XERR"};
   TTreeReaderValue<Double_t> PromptXi_ENDVERTEX_YERR = {fReader, "PromptXi_ENDVERTEX_YERR"};
   TTreeReaderValue<Double_t> PromptXi_ENDVERTEX_ZERR = {fReader, "PromptXi_ENDVERTEX_ZERR"};
   TTreeReaderValue<Double_t> PromptXi_ENDVERTEX_CHI2 = {fReader, "PromptXi_ENDVERTEX_CHI2"};
   TTreeReaderValue<Int_t> PromptXi_ENDVERTEX_NDOF = {fReader, "PromptXi_ENDVERTEX_NDOF"};
   TTreeReaderValue<Double_t> PromptXi_OWNPV_X = {fReader, "PromptXi_OWNPV_X"};
   TTreeReaderValue<Double_t> PromptXi_OWNPV_Y = {fReader, "PromptXi_OWNPV_Y"};
   TTreeReaderValue<Double_t> PromptXi_OWNPV_Z = {fReader, "PromptXi_OWNPV_Z"};
   TTreeReaderValue<Double_t> PromptXi_OWNPV_XERR = {fReader, "PromptXi_OWNPV_XERR"};
   TTreeReaderValue<Double_t> PromptXi_OWNPV_YERR = {fReader, "PromptXi_OWNPV_YERR"};
   TTreeReaderValue<Double_t> PromptXi_OWNPV_ZERR = {fReader, "PromptXi_OWNPV_ZERR"};
   TTreeReaderValue<Double_t> PromptXi_OWNPV_CHI2 = {fReader, "PromptXi_OWNPV_CHI2"};
   TTreeReaderValue<Int_t> PromptXi_OWNPV_NDOF = {fReader, "PromptXi_OWNPV_NDOF"};
   TTreeReaderValue<Double_t> PromptXi_IP_OWNPV = {fReader, "PromptXi_IP_OWNPV"};
   TTreeReaderValue<Double_t> PromptXi_IPCHI2_OWNPV = {fReader, "PromptXi_IPCHI2_OWNPV"};
   TTreeReaderValue<Double_t> PromptXi_FD_OWNPV = {fReader, "PromptXi_FD_OWNPV"};
   TTreeReaderValue<Double_t> PromptXi_FDCHI2_OWNPV = {fReader, "PromptXi_FDCHI2_OWNPV"};
   TTreeReaderValue<Double_t> PromptXi_DIRA_OWNPV = {fReader, "PromptXi_DIRA_OWNPV"};
   TTreeReaderValue<Double_t> PromptXi_ORIVX_X = {fReader, "PromptXi_ORIVX_X"};
   TTreeReaderValue<Double_t> PromptXi_ORIVX_Y = {fReader, "PromptXi_ORIVX_Y"};
   TTreeReaderValue<Double_t> PromptXi_ORIVX_Z = {fReader, "PromptXi_ORIVX_Z"};
   TTreeReaderValue<Double_t> PromptXi_ORIVX_XERR = {fReader, "PromptXi_ORIVX_XERR"};
   TTreeReaderValue<Double_t> PromptXi_ORIVX_YERR = {fReader, "PromptXi_ORIVX_YERR"};
   TTreeReaderValue<Double_t> PromptXi_ORIVX_ZERR = {fReader, "PromptXi_ORIVX_ZERR"};
   TTreeReaderValue<Double_t> PromptXi_ORIVX_CHI2 = {fReader, "PromptXi_ORIVX_CHI2"};
   TTreeReaderValue<Int_t> PromptXi_ORIVX_NDOF = {fReader, "PromptXi_ORIVX_NDOF"};
   TTreeReaderValue<Double_t> PromptXi_FD_ORIVX = {fReader, "PromptXi_FD_ORIVX"};
   TTreeReaderValue<Double_t> PromptXi_FDCHI2_ORIVX = {fReader, "PromptXi_FDCHI2_ORIVX"};
   TTreeReaderValue<Double_t> PromptXi_DIRA_ORIVX = {fReader, "PromptXi_DIRA_ORIVX"};
   TTreeReaderValue<Double_t> PromptXi_P = {fReader, "PromptXi_P"};
   TTreeReaderValue<Double_t> PromptXi_PT = {fReader, "PromptXi_PT"};
   TTreeReaderValue<Double_t> PromptXi_PE = {fReader, "PromptXi_PE"};
   TTreeReaderValue<Double_t> PromptXi_PX = {fReader, "PromptXi_PX"};
   TTreeReaderValue<Double_t> PromptXi_PY = {fReader, "PromptXi_PY"};
   TTreeReaderValue<Double_t> PromptXi_PZ = {fReader, "PromptXi_PZ"};
   TTreeReaderValue<Double_t> PromptXi_MM = {fReader, "PromptXi_MM"};
   TTreeReaderValue<Double_t> PromptXi_MMERR = {fReader, "PromptXi_MMERR"};
   TTreeReaderValue<Double_t> PromptXi_M = {fReader, "PromptXi_M"};
   TTreeReaderValue<Int_t> PromptXi_ID = {fReader, "PromptXi_ID"};
   TTreeReaderValue<Double_t> PromptXi_TAU = {fReader, "PromptXi_TAU"};
   TTreeReaderValue<Double_t> PromptXi_TAUERR = {fReader, "PromptXi_TAUERR"};
   TTreeReaderValue<Double_t> PromptXi_TAUCHI2 = {fReader, "PromptXi_TAUCHI2"};
   TTreeReaderValue<Bool_t> PromptXi_L0Global_Dec = {fReader, "PromptXi_L0Global_Dec"};
   TTreeReaderValue<Bool_t> PromptXi_L0Global_TIS = {fReader, "PromptXi_L0Global_TIS"};
   TTreeReaderValue<Bool_t> PromptXi_L0Global_TOS = {fReader, "PromptXi_L0Global_TOS"};
   TTreeReaderValue<Bool_t> PromptXi_Hlt1Global_Dec = {fReader, "PromptXi_Hlt1Global_Dec"};
   TTreeReaderValue<Bool_t> PromptXi_Hlt1Global_TIS = {fReader, "PromptXi_Hlt1Global_TIS"};
   TTreeReaderValue<Bool_t> PromptXi_Hlt1Global_TOS = {fReader, "PromptXi_Hlt1Global_TOS"};
   TTreeReaderValue<Bool_t> PromptXi_Hlt1Phys_Dec = {fReader, "PromptXi_Hlt1Phys_Dec"};
   TTreeReaderValue<Bool_t> PromptXi_Hlt1Phys_TIS = {fReader, "PromptXi_Hlt1Phys_TIS"};
   TTreeReaderValue<Bool_t> PromptXi_Hlt1Phys_TOS = {fReader, "PromptXi_Hlt1Phys_TOS"};
   TTreeReaderValue<Bool_t> PromptXi_Hlt2Global_Dec = {fReader, "PromptXi_Hlt2Global_Dec"};
   TTreeReaderValue<Bool_t> PromptXi_Hlt2Global_TIS = {fReader, "PromptXi_Hlt2Global_TIS"};
   TTreeReaderValue<Bool_t> PromptXi_Hlt2Global_TOS = {fReader, "PromptXi_Hlt2Global_TOS"};
   TTreeReaderValue<Bool_t> PromptXi_Hlt2Phys_Dec = {fReader, "PromptXi_Hlt2Phys_Dec"};
   TTreeReaderValue<Bool_t> PromptXi_Hlt2Phys_TIS = {fReader, "PromptXi_Hlt2Phys_TIS"};
   TTreeReaderValue<Bool_t> PromptXi_Hlt2Phys_TOS = {fReader, "PromptXi_Hlt2Phys_TOS"};
   TTreeReaderValue<Double_t> PromptXi_X = {fReader, "PromptXi_X"};
   TTreeReaderValue<Double_t> PromptXi_Y = {fReader, "PromptXi_Y"};
   TTreeReaderValue<Double_t> XiPi_OWNPV_X = {fReader, "XiPi_OWNPV_X"};
   TTreeReaderValue<Double_t> XiPi_OWNPV_Y = {fReader, "XiPi_OWNPV_Y"};
   TTreeReaderValue<Double_t> XiPi_OWNPV_Z = {fReader, "XiPi_OWNPV_Z"};
   TTreeReaderValue<Double_t> XiPi_OWNPV_XERR = {fReader, "XiPi_OWNPV_XERR"};
   TTreeReaderValue<Double_t> XiPi_OWNPV_YERR = {fReader, "XiPi_OWNPV_YERR"};
   TTreeReaderValue<Double_t> XiPi_OWNPV_ZERR = {fReader, "XiPi_OWNPV_ZERR"};
   TTreeReaderValue<Double_t> XiPi_OWNPV_CHI2 = {fReader, "XiPi_OWNPV_CHI2"};
   TTreeReaderValue<Int_t> XiPi_OWNPV_NDOF = {fReader, "XiPi_OWNPV_NDOF"};
   TTreeReaderValue<Double_t> XiPi_IP_OWNPV = {fReader, "XiPi_IP_OWNPV"};
   TTreeReaderValue<Double_t> XiPi_IPCHI2_OWNPV = {fReader, "XiPi_IPCHI2_OWNPV"};
   TTreeReaderValue<Double_t> XiPi_ORIVX_X = {fReader, "XiPi_ORIVX_X"};
   TTreeReaderValue<Double_t> XiPi_ORIVX_Y = {fReader, "XiPi_ORIVX_Y"};
   TTreeReaderValue<Double_t> XiPi_ORIVX_Z = {fReader, "XiPi_ORIVX_Z"};
   TTreeReaderValue<Double_t> XiPi_ORIVX_XERR = {fReader, "XiPi_ORIVX_XERR"};
   TTreeReaderValue<Double_t> XiPi_ORIVX_YERR = {fReader, "XiPi_ORIVX_YERR"};
   TTreeReaderValue<Double_t> XiPi_ORIVX_ZERR = {fReader, "XiPi_ORIVX_ZERR"};
   TTreeReaderValue<Double_t> XiPi_ORIVX_CHI2 = {fReader, "XiPi_ORIVX_CHI2"};
   TTreeReaderValue<Int_t> XiPi_ORIVX_NDOF = {fReader, "XiPi_ORIVX_NDOF"};
   TTreeReaderValue<Double_t> XiPi_P = {fReader, "XiPi_P"};
   TTreeReaderValue<Double_t> XiPi_PT = {fReader, "XiPi_PT"};
   TTreeReaderValue<Double_t> XiPi_PE = {fReader, "XiPi_PE"};
   TTreeReaderValue<Double_t> XiPi_PX = {fReader, "XiPi_PX"};
   TTreeReaderValue<Double_t> XiPi_PY = {fReader, "XiPi_PY"};
   TTreeReaderValue<Double_t> XiPi_PZ = {fReader, "XiPi_PZ"};
   TTreeReaderValue<Double_t> XiPi_M = {fReader, "XiPi_M"};
   TTreeReaderValue<Int_t> XiPi_ID = {fReader, "XiPi_ID"};
   TTreeReaderValue<Double_t> XiPi_PIDe = {fReader, "XiPi_PIDe"};
   TTreeReaderValue<Double_t> XiPi_PIDmu = {fReader, "XiPi_PIDmu"};
   TTreeReaderValue<Double_t> XiPi_PIDK = {fReader, "XiPi_PIDK"};
   TTreeReaderValue<Double_t> XiPi_PIDp = {fReader, "XiPi_PIDp"};
   TTreeReaderValue<Double_t> XiPi_ProbNNe = {fReader, "XiPi_ProbNNe"};
   TTreeReaderValue<Double_t> XiPi_ProbNNk = {fReader, "XiPi_ProbNNk"};
   TTreeReaderValue<Double_t> XiPi_ProbNNp = {fReader, "XiPi_ProbNNp"};
   TTreeReaderValue<Double_t> XiPi_ProbNNpi = {fReader, "XiPi_ProbNNpi"};
   TTreeReaderValue<Double_t> XiPi_ProbNNmu = {fReader, "XiPi_ProbNNmu"};
   TTreeReaderValue<Double_t> XiPi_ProbNNghost = {fReader, "XiPi_ProbNNghost"};
   TTreeReaderValue<Bool_t> XiPi_hasMuon = {fReader, "XiPi_hasMuon"};
   TTreeReaderValue<Bool_t> XiPi_isMuon = {fReader, "XiPi_isMuon"};
   TTreeReaderValue<Bool_t> XiPi_hasRich = {fReader, "XiPi_hasRich"};
   TTreeReaderValue<Bool_t> XiPi_hasCalo = {fReader, "XiPi_hasCalo"};
   TTreeReaderValue<Bool_t> XiPi_L0Global_Dec = {fReader, "XiPi_L0Global_Dec"};
   TTreeReaderValue<Bool_t> XiPi_L0Global_TIS = {fReader, "XiPi_L0Global_TIS"};
   TTreeReaderValue<Bool_t> XiPi_L0Global_TOS = {fReader, "XiPi_L0Global_TOS"};
   TTreeReaderValue<Bool_t> XiPi_Hlt1Global_Dec = {fReader, "XiPi_Hlt1Global_Dec"};
   TTreeReaderValue<Bool_t> XiPi_Hlt1Global_TIS = {fReader, "XiPi_Hlt1Global_TIS"};
   TTreeReaderValue<Bool_t> XiPi_Hlt1Global_TOS = {fReader, "XiPi_Hlt1Global_TOS"};
   TTreeReaderValue<Bool_t> XiPi_Hlt1Phys_Dec = {fReader, "XiPi_Hlt1Phys_Dec"};
   TTreeReaderValue<Bool_t> XiPi_Hlt1Phys_TIS = {fReader, "XiPi_Hlt1Phys_TIS"};
   TTreeReaderValue<Bool_t> XiPi_Hlt1Phys_TOS = {fReader, "XiPi_Hlt1Phys_TOS"};
   TTreeReaderValue<Bool_t> XiPi_Hlt2Global_Dec = {fReader, "XiPi_Hlt2Global_Dec"};
   TTreeReaderValue<Bool_t> XiPi_Hlt2Global_TIS = {fReader, "XiPi_Hlt2Global_TIS"};
   TTreeReaderValue<Bool_t> XiPi_Hlt2Global_TOS = {fReader, "XiPi_Hlt2Global_TOS"};
   TTreeReaderValue<Bool_t> XiPi_Hlt2Phys_Dec = {fReader, "XiPi_Hlt2Phys_Dec"};
   TTreeReaderValue<Bool_t> XiPi_Hlt2Phys_TIS = {fReader, "XiPi_Hlt2Phys_TIS"};
   TTreeReaderValue<Bool_t> XiPi_Hlt2Phys_TOS = {fReader, "XiPi_Hlt2Phys_TOS"};
   TTreeReaderValue<Int_t> XiPi_TRACK_Type = {fReader, "XiPi_TRACK_Type"};
   TTreeReaderValue<Int_t> XiPi_TRACK_Key = {fReader, "XiPi_TRACK_Key"};
   TTreeReaderValue<Double_t> XiPi_TRACK_CHI2NDOF = {fReader, "XiPi_TRACK_CHI2NDOF"};
   TTreeReaderValue<Double_t> XiPi_TRACK_PCHI2 = {fReader, "XiPi_TRACK_PCHI2"};
   TTreeReaderValue<Double_t> XiPi_TRACK_MatchCHI2 = {fReader, "XiPi_TRACK_MatchCHI2"};
   TTreeReaderValue<Double_t> XiPi_TRACK_GhostProb = {fReader, "XiPi_TRACK_GhostProb"};
   TTreeReaderValue<Double_t> XiPi_TRACK_CloneDist = {fReader, "XiPi_TRACK_CloneDist"};
   TTreeReaderValue<Double_t> XiPi_TRACK_Likelihood = {fReader, "XiPi_TRACK_Likelihood"};
   TTreeReaderValue<Double_t> XiPi_X = {fReader, "XiPi_X"};
   TTreeReaderValue<Double_t> XiPi_Y = {fReader, "XiPi_Y"};
   TTreeReaderValue<Double_t> Lambda_ENDVERTEX_X = {fReader, "Lambda_ENDVERTEX_X"};
   TTreeReaderValue<Double_t> Lambda_ENDVERTEX_Y = {fReader, "Lambda_ENDVERTEX_Y"};
   TTreeReaderValue<Double_t> Lambda_ENDVERTEX_Z = {fReader, "Lambda_ENDVERTEX_Z"};
   TTreeReaderValue<Double_t> Lambda_ENDVERTEX_XERR = {fReader, "Lambda_ENDVERTEX_XERR"};
   TTreeReaderValue<Double_t> Lambda_ENDVERTEX_YERR = {fReader, "Lambda_ENDVERTEX_YERR"};
   TTreeReaderValue<Double_t> Lambda_ENDVERTEX_ZERR = {fReader, "Lambda_ENDVERTEX_ZERR"};
   TTreeReaderValue<Double_t> Lambda_ENDVERTEX_CHI2 = {fReader, "Lambda_ENDVERTEX_CHI2"};
   TTreeReaderValue<Int_t> Lambda_ENDVERTEX_NDOF = {fReader, "Lambda_ENDVERTEX_NDOF"};
   TTreeReaderValue<Double_t> Lambda_OWNPV_X = {fReader, "Lambda_OWNPV_X"};
   TTreeReaderValue<Double_t> Lambda_OWNPV_Y = {fReader, "Lambda_OWNPV_Y"};
   TTreeReaderValue<Double_t> Lambda_OWNPV_Z = {fReader, "Lambda_OWNPV_Z"};
   TTreeReaderValue<Double_t> Lambda_OWNPV_XERR = {fReader, "Lambda_OWNPV_XERR"};
   TTreeReaderValue<Double_t> Lambda_OWNPV_YERR = {fReader, "Lambda_OWNPV_YERR"};
   TTreeReaderValue<Double_t> Lambda_OWNPV_ZERR = {fReader, "Lambda_OWNPV_ZERR"};
   TTreeReaderValue<Double_t> Lambda_OWNPV_CHI2 = {fReader, "Lambda_OWNPV_CHI2"};
   TTreeReaderValue<Int_t> Lambda_OWNPV_NDOF = {fReader, "Lambda_OWNPV_NDOF"};
   TTreeReaderValue<Double_t> Lambda_IP_OWNPV = {fReader, "Lambda_IP_OWNPV"};
   TTreeReaderValue<Double_t> Lambda_IPCHI2_OWNPV = {fReader, "Lambda_IPCHI2_OWNPV"};
   TTreeReaderValue<Double_t> Lambda_FD_OWNPV = {fReader, "Lambda_FD_OWNPV"};
   TTreeReaderValue<Double_t> Lambda_FDCHI2_OWNPV = {fReader, "Lambda_FDCHI2_OWNPV"};
   TTreeReaderValue<Double_t> Lambda_DIRA_OWNPV = {fReader, "Lambda_DIRA_OWNPV"};
   TTreeReaderValue<Double_t> Lambda_ORIVX_X = {fReader, "Lambda_ORIVX_X"};
   TTreeReaderValue<Double_t> Lambda_ORIVX_Y = {fReader, "Lambda_ORIVX_Y"};
   TTreeReaderValue<Double_t> Lambda_ORIVX_Z = {fReader, "Lambda_ORIVX_Z"};
   TTreeReaderValue<Double_t> Lambda_ORIVX_XERR = {fReader, "Lambda_ORIVX_XERR"};
   TTreeReaderValue<Double_t> Lambda_ORIVX_YERR = {fReader, "Lambda_ORIVX_YERR"};
   TTreeReaderValue<Double_t> Lambda_ORIVX_ZERR = {fReader, "Lambda_ORIVX_ZERR"};
   TTreeReaderValue<Double_t> Lambda_ORIVX_CHI2 = {fReader, "Lambda_ORIVX_CHI2"};
   TTreeReaderValue<Int_t> Lambda_ORIVX_NDOF = {fReader, "Lambda_ORIVX_NDOF"};
   TTreeReaderValue<Double_t> Lambda_FD_ORIVX = {fReader, "Lambda_FD_ORIVX"};
   TTreeReaderValue<Double_t> Lambda_FDCHI2_ORIVX = {fReader, "Lambda_FDCHI2_ORIVX"};
   TTreeReaderValue<Double_t> Lambda_DIRA_ORIVX = {fReader, "Lambda_DIRA_ORIVX"};
   TTreeReaderValue<Double_t> Lambda_P = {fReader, "Lambda_P"};
   TTreeReaderValue<Double_t> Lambda_PT = {fReader, "Lambda_PT"};
   TTreeReaderValue<Double_t> Lambda_PE = {fReader, "Lambda_PE"};
   TTreeReaderValue<Double_t> Lambda_PX = {fReader, "Lambda_PX"};
   TTreeReaderValue<Double_t> Lambda_PY = {fReader, "Lambda_PY"};
   TTreeReaderValue<Double_t> Lambda_PZ = {fReader, "Lambda_PZ"};
   TTreeReaderValue<Double_t> Lambda_MM = {fReader, "Lambda_MM"};
   TTreeReaderValue<Double_t> Lambda_MMERR = {fReader, "Lambda_MMERR"};
   TTreeReaderValue<Double_t> Lambda_M = {fReader, "Lambda_M"};
   TTreeReaderValue<Int_t> Lambda_ID = {fReader, "Lambda_ID"};
   TTreeReaderValue<Double_t> Lambda_TAU = {fReader, "Lambda_TAU"};
   TTreeReaderValue<Double_t> Lambda_TAUERR = {fReader, "Lambda_TAUERR"};
   TTreeReaderValue<Double_t> Lambda_TAUCHI2 = {fReader, "Lambda_TAUCHI2"};
   TTreeReaderValue<Bool_t> Lambda_L0Global_Dec = {fReader, "Lambda_L0Global_Dec"};
   TTreeReaderValue<Bool_t> Lambda_L0Global_TIS = {fReader, "Lambda_L0Global_TIS"};
   TTreeReaderValue<Bool_t> Lambda_L0Global_TOS = {fReader, "Lambda_L0Global_TOS"};
   TTreeReaderValue<Bool_t> Lambda_Hlt1Global_Dec = {fReader, "Lambda_Hlt1Global_Dec"};
   TTreeReaderValue<Bool_t> Lambda_Hlt1Global_TIS = {fReader, "Lambda_Hlt1Global_TIS"};
   TTreeReaderValue<Bool_t> Lambda_Hlt1Global_TOS = {fReader, "Lambda_Hlt1Global_TOS"};
   TTreeReaderValue<Bool_t> Lambda_Hlt1Phys_Dec = {fReader, "Lambda_Hlt1Phys_Dec"};
   TTreeReaderValue<Bool_t> Lambda_Hlt1Phys_TIS = {fReader, "Lambda_Hlt1Phys_TIS"};
   TTreeReaderValue<Bool_t> Lambda_Hlt1Phys_TOS = {fReader, "Lambda_Hlt1Phys_TOS"};
   TTreeReaderValue<Bool_t> Lambda_Hlt2Global_Dec = {fReader, "Lambda_Hlt2Global_Dec"};
   TTreeReaderValue<Bool_t> Lambda_Hlt2Global_TIS = {fReader, "Lambda_Hlt2Global_TIS"};
   TTreeReaderValue<Bool_t> Lambda_Hlt2Global_TOS = {fReader, "Lambda_Hlt2Global_TOS"};
   TTreeReaderValue<Bool_t> Lambda_Hlt2Phys_Dec = {fReader, "Lambda_Hlt2Phys_Dec"};
   TTreeReaderValue<Bool_t> Lambda_Hlt2Phys_TIS = {fReader, "Lambda_Hlt2Phys_TIS"};
   TTreeReaderValue<Bool_t> Lambda_Hlt2Phys_TOS = {fReader, "Lambda_Hlt2Phys_TOS"};
   TTreeReaderValue<Double_t> Lambda_X = {fReader, "Lambda_X"};
   TTreeReaderValue<Double_t> Lambda_Y = {fReader, "Lambda_Y"};
   TTreeReaderValue<Double_t> LambdaPi_OWNPV_X = {fReader, "LambdaPi_OWNPV_X"};
   TTreeReaderValue<Double_t> LambdaPi_OWNPV_Y = {fReader, "LambdaPi_OWNPV_Y"};
   TTreeReaderValue<Double_t> LambdaPi_OWNPV_Z = {fReader, "LambdaPi_OWNPV_Z"};
   TTreeReaderValue<Double_t> LambdaPi_OWNPV_XERR = {fReader, "LambdaPi_OWNPV_XERR"};
   TTreeReaderValue<Double_t> LambdaPi_OWNPV_YERR = {fReader, "LambdaPi_OWNPV_YERR"};
   TTreeReaderValue<Double_t> LambdaPi_OWNPV_ZERR = {fReader, "LambdaPi_OWNPV_ZERR"};
   TTreeReaderValue<Double_t> LambdaPi_OWNPV_CHI2 = {fReader, "LambdaPi_OWNPV_CHI2"};
   TTreeReaderValue<Int_t> LambdaPi_OWNPV_NDOF = {fReader, "LambdaPi_OWNPV_NDOF"};
   TTreeReaderValue<Double_t> LambdaPi_IP_OWNPV = {fReader, "LambdaPi_IP_OWNPV"};
   TTreeReaderValue<Double_t> LambdaPi_IPCHI2_OWNPV = {fReader, "LambdaPi_IPCHI2_OWNPV"};
   TTreeReaderValue<Double_t> LambdaPi_ORIVX_X = {fReader, "LambdaPi_ORIVX_X"};
   TTreeReaderValue<Double_t> LambdaPi_ORIVX_Y = {fReader, "LambdaPi_ORIVX_Y"};
   TTreeReaderValue<Double_t> LambdaPi_ORIVX_Z = {fReader, "LambdaPi_ORIVX_Z"};
   TTreeReaderValue<Double_t> LambdaPi_ORIVX_XERR = {fReader, "LambdaPi_ORIVX_XERR"};
   TTreeReaderValue<Double_t> LambdaPi_ORIVX_YERR = {fReader, "LambdaPi_ORIVX_YERR"};
   TTreeReaderValue<Double_t> LambdaPi_ORIVX_ZERR = {fReader, "LambdaPi_ORIVX_ZERR"};
   TTreeReaderValue<Double_t> LambdaPi_ORIVX_CHI2 = {fReader, "LambdaPi_ORIVX_CHI2"};
   TTreeReaderValue<Int_t> LambdaPi_ORIVX_NDOF = {fReader, "LambdaPi_ORIVX_NDOF"};
   TTreeReaderValue<Double_t> LambdaPi_P = {fReader, "LambdaPi_P"};
   TTreeReaderValue<Double_t> LambdaPi_PT = {fReader, "LambdaPi_PT"};
   TTreeReaderValue<Double_t> LambdaPi_PE = {fReader, "LambdaPi_PE"};
   TTreeReaderValue<Double_t> LambdaPi_PX = {fReader, "LambdaPi_PX"};
   TTreeReaderValue<Double_t> LambdaPi_PY = {fReader, "LambdaPi_PY"};
   TTreeReaderValue<Double_t> LambdaPi_PZ = {fReader, "LambdaPi_PZ"};
   TTreeReaderValue<Double_t> LambdaPi_M = {fReader, "LambdaPi_M"};
   TTreeReaderValue<Int_t> LambdaPi_ID = {fReader, "LambdaPi_ID"};
   TTreeReaderValue<Double_t> LambdaPi_PIDe = {fReader, "LambdaPi_PIDe"};
   TTreeReaderValue<Double_t> LambdaPi_PIDmu = {fReader, "LambdaPi_PIDmu"};
   TTreeReaderValue<Double_t> LambdaPi_PIDK = {fReader, "LambdaPi_PIDK"};
   TTreeReaderValue<Double_t> LambdaPi_PIDp = {fReader, "LambdaPi_PIDp"};
   TTreeReaderValue<Double_t> LambdaPi_ProbNNe = {fReader, "LambdaPi_ProbNNe"};
   TTreeReaderValue<Double_t> LambdaPi_ProbNNk = {fReader, "LambdaPi_ProbNNk"};
   TTreeReaderValue<Double_t> LambdaPi_ProbNNp = {fReader, "LambdaPi_ProbNNp"};
   TTreeReaderValue<Double_t> LambdaPi_ProbNNpi = {fReader, "LambdaPi_ProbNNpi"};
   TTreeReaderValue<Double_t> LambdaPi_ProbNNmu = {fReader, "LambdaPi_ProbNNmu"};
   TTreeReaderValue<Double_t> LambdaPi_ProbNNghost = {fReader, "LambdaPi_ProbNNghost"};
   TTreeReaderValue<Bool_t> LambdaPi_hasMuon = {fReader, "LambdaPi_hasMuon"};
   TTreeReaderValue<Bool_t> LambdaPi_isMuon = {fReader, "LambdaPi_isMuon"};
   TTreeReaderValue<Bool_t> LambdaPi_hasRich = {fReader, "LambdaPi_hasRich"};
   TTreeReaderValue<Bool_t> LambdaPi_hasCalo = {fReader, "LambdaPi_hasCalo"};
   TTreeReaderValue<Bool_t> LambdaPi_L0Global_Dec = {fReader, "LambdaPi_L0Global_Dec"};
   TTreeReaderValue<Bool_t> LambdaPi_L0Global_TIS = {fReader, "LambdaPi_L0Global_TIS"};
   TTreeReaderValue<Bool_t> LambdaPi_L0Global_TOS = {fReader, "LambdaPi_L0Global_TOS"};
   TTreeReaderValue<Bool_t> LambdaPi_Hlt1Global_Dec = {fReader, "LambdaPi_Hlt1Global_Dec"};
   TTreeReaderValue<Bool_t> LambdaPi_Hlt1Global_TIS = {fReader, "LambdaPi_Hlt1Global_TIS"};
   TTreeReaderValue<Bool_t> LambdaPi_Hlt1Global_TOS = {fReader, "LambdaPi_Hlt1Global_TOS"};
   TTreeReaderValue<Bool_t> LambdaPi_Hlt1Phys_Dec = {fReader, "LambdaPi_Hlt1Phys_Dec"};
   TTreeReaderValue<Bool_t> LambdaPi_Hlt1Phys_TIS = {fReader, "LambdaPi_Hlt1Phys_TIS"};
   TTreeReaderValue<Bool_t> LambdaPi_Hlt1Phys_TOS = {fReader, "LambdaPi_Hlt1Phys_TOS"};
   TTreeReaderValue<Bool_t> LambdaPi_Hlt2Global_Dec = {fReader, "LambdaPi_Hlt2Global_Dec"};
   TTreeReaderValue<Bool_t> LambdaPi_Hlt2Global_TIS = {fReader, "LambdaPi_Hlt2Global_TIS"};
   TTreeReaderValue<Bool_t> LambdaPi_Hlt2Global_TOS = {fReader, "LambdaPi_Hlt2Global_TOS"};
   TTreeReaderValue<Bool_t> LambdaPi_Hlt2Phys_Dec = {fReader, "LambdaPi_Hlt2Phys_Dec"};
   TTreeReaderValue<Bool_t> LambdaPi_Hlt2Phys_TIS = {fReader, "LambdaPi_Hlt2Phys_TIS"};
   TTreeReaderValue<Bool_t> LambdaPi_Hlt2Phys_TOS = {fReader, "LambdaPi_Hlt2Phys_TOS"};
   TTreeReaderValue<Int_t> LambdaPi_TRACK_Type = {fReader, "LambdaPi_TRACK_Type"};
   TTreeReaderValue<Int_t> LambdaPi_TRACK_Key = {fReader, "LambdaPi_TRACK_Key"};
   TTreeReaderValue<Double_t> LambdaPi_TRACK_CHI2NDOF = {fReader, "LambdaPi_TRACK_CHI2NDOF"};
   TTreeReaderValue<Double_t> LambdaPi_TRACK_PCHI2 = {fReader, "LambdaPi_TRACK_PCHI2"};
   TTreeReaderValue<Double_t> LambdaPi_TRACK_MatchCHI2 = {fReader, "LambdaPi_TRACK_MatchCHI2"};
   TTreeReaderValue<Double_t> LambdaPi_TRACK_GhostProb = {fReader, "LambdaPi_TRACK_GhostProb"};
   TTreeReaderValue<Double_t> LambdaPi_TRACK_CloneDist = {fReader, "LambdaPi_TRACK_CloneDist"};
   TTreeReaderValue<Double_t> LambdaPi_TRACK_Likelihood = {fReader, "LambdaPi_TRACK_Likelihood"};
   TTreeReaderValue<Double_t> LambdaPi_X = {fReader, "LambdaPi_X"};
   TTreeReaderValue<Double_t> LambdaPi_Y = {fReader, "LambdaPi_Y"};
   TTreeReaderValue<Double_t> LambdaPr_OWNPV_X = {fReader, "LambdaPr_OWNPV_X"};
   TTreeReaderValue<Double_t> LambdaPr_OWNPV_Y = {fReader, "LambdaPr_OWNPV_Y"};
   TTreeReaderValue<Double_t> LambdaPr_OWNPV_Z = {fReader, "LambdaPr_OWNPV_Z"};
   TTreeReaderValue<Double_t> LambdaPr_OWNPV_XERR = {fReader, "LambdaPr_OWNPV_XERR"};
   TTreeReaderValue<Double_t> LambdaPr_OWNPV_YERR = {fReader, "LambdaPr_OWNPV_YERR"};
   TTreeReaderValue<Double_t> LambdaPr_OWNPV_ZERR = {fReader, "LambdaPr_OWNPV_ZERR"};
   TTreeReaderValue<Double_t> LambdaPr_OWNPV_CHI2 = {fReader, "LambdaPr_OWNPV_CHI2"};
   TTreeReaderValue<Int_t> LambdaPr_OWNPV_NDOF = {fReader, "LambdaPr_OWNPV_NDOF"};
   TTreeReaderValue<Double_t> LambdaPr_IP_OWNPV = {fReader, "LambdaPr_IP_OWNPV"};
   TTreeReaderValue<Double_t> LambdaPr_IPCHI2_OWNPV = {fReader, "LambdaPr_IPCHI2_OWNPV"};
   TTreeReaderValue<Double_t> LambdaPr_ORIVX_X = {fReader, "LambdaPr_ORIVX_X"};
   TTreeReaderValue<Double_t> LambdaPr_ORIVX_Y = {fReader, "LambdaPr_ORIVX_Y"};
   TTreeReaderValue<Double_t> LambdaPr_ORIVX_Z = {fReader, "LambdaPr_ORIVX_Z"};
   TTreeReaderValue<Double_t> LambdaPr_ORIVX_XERR = {fReader, "LambdaPr_ORIVX_XERR"};
   TTreeReaderValue<Double_t> LambdaPr_ORIVX_YERR = {fReader, "LambdaPr_ORIVX_YERR"};
   TTreeReaderValue<Double_t> LambdaPr_ORIVX_ZERR = {fReader, "LambdaPr_ORIVX_ZERR"};
   TTreeReaderValue<Double_t> LambdaPr_ORIVX_CHI2 = {fReader, "LambdaPr_ORIVX_CHI2"};
   TTreeReaderValue<Int_t> LambdaPr_ORIVX_NDOF = {fReader, "LambdaPr_ORIVX_NDOF"};
   TTreeReaderValue<Double_t> LambdaPr_P = {fReader, "LambdaPr_P"};
   TTreeReaderValue<Double_t> LambdaPr_PT = {fReader, "LambdaPr_PT"};
   TTreeReaderValue<Double_t> LambdaPr_PE = {fReader, "LambdaPr_PE"};
   TTreeReaderValue<Double_t> LambdaPr_PX = {fReader, "LambdaPr_PX"};
   TTreeReaderValue<Double_t> LambdaPr_PY = {fReader, "LambdaPr_PY"};
   TTreeReaderValue<Double_t> LambdaPr_PZ = {fReader, "LambdaPr_PZ"};
   TTreeReaderValue<Double_t> LambdaPr_M = {fReader, "LambdaPr_M"};
   TTreeReaderValue<Int_t> LambdaPr_ID = {fReader, "LambdaPr_ID"};
   TTreeReaderValue<Double_t> LambdaPr_PIDe = {fReader, "LambdaPr_PIDe"};
   TTreeReaderValue<Double_t> LambdaPr_PIDmu = {fReader, "LambdaPr_PIDmu"};
   TTreeReaderValue<Double_t> LambdaPr_PIDK = {fReader, "LambdaPr_PIDK"};
   TTreeReaderValue<Double_t> LambdaPr_PIDp = {fReader, "LambdaPr_PIDp"};
   TTreeReaderValue<Double_t> LambdaPr_ProbNNe = {fReader, "LambdaPr_ProbNNe"};
   TTreeReaderValue<Double_t> LambdaPr_ProbNNk = {fReader, "LambdaPr_ProbNNk"};
   TTreeReaderValue<Double_t> LambdaPr_ProbNNp = {fReader, "LambdaPr_ProbNNp"};
   TTreeReaderValue<Double_t> LambdaPr_ProbNNpi = {fReader, "LambdaPr_ProbNNpi"};
   TTreeReaderValue<Double_t> LambdaPr_ProbNNmu = {fReader, "LambdaPr_ProbNNmu"};
   TTreeReaderValue<Double_t> LambdaPr_ProbNNghost = {fReader, "LambdaPr_ProbNNghost"};
   TTreeReaderValue<Bool_t> LambdaPr_hasMuon = {fReader, "LambdaPr_hasMuon"};
   TTreeReaderValue<Bool_t> LambdaPr_isMuon = {fReader, "LambdaPr_isMuon"};
   TTreeReaderValue<Bool_t> LambdaPr_hasRich = {fReader, "LambdaPr_hasRich"};
   TTreeReaderValue<Bool_t> LambdaPr_hasCalo = {fReader, "LambdaPr_hasCalo"};
   TTreeReaderValue<Bool_t> LambdaPr_L0Global_Dec = {fReader, "LambdaPr_L0Global_Dec"};
   TTreeReaderValue<Bool_t> LambdaPr_L0Global_TIS = {fReader, "LambdaPr_L0Global_TIS"};
   TTreeReaderValue<Bool_t> LambdaPr_L0Global_TOS = {fReader, "LambdaPr_L0Global_TOS"};
   TTreeReaderValue<Bool_t> LambdaPr_Hlt1Global_Dec = {fReader, "LambdaPr_Hlt1Global_Dec"};
   TTreeReaderValue<Bool_t> LambdaPr_Hlt1Global_TIS = {fReader, "LambdaPr_Hlt1Global_TIS"};
   TTreeReaderValue<Bool_t> LambdaPr_Hlt1Global_TOS = {fReader, "LambdaPr_Hlt1Global_TOS"};
   TTreeReaderValue<Bool_t> LambdaPr_Hlt1Phys_Dec = {fReader, "LambdaPr_Hlt1Phys_Dec"};
   TTreeReaderValue<Bool_t> LambdaPr_Hlt1Phys_TIS = {fReader, "LambdaPr_Hlt1Phys_TIS"};
   TTreeReaderValue<Bool_t> LambdaPr_Hlt1Phys_TOS = {fReader, "LambdaPr_Hlt1Phys_TOS"};
   TTreeReaderValue<Bool_t> LambdaPr_Hlt2Global_Dec = {fReader, "LambdaPr_Hlt2Global_Dec"};
   TTreeReaderValue<Bool_t> LambdaPr_Hlt2Global_TIS = {fReader, "LambdaPr_Hlt2Global_TIS"};
   TTreeReaderValue<Bool_t> LambdaPr_Hlt2Global_TOS = {fReader, "LambdaPr_Hlt2Global_TOS"};
   TTreeReaderValue<Bool_t> LambdaPr_Hlt2Phys_Dec = {fReader, "LambdaPr_Hlt2Phys_Dec"};
   TTreeReaderValue<Bool_t> LambdaPr_Hlt2Phys_TIS = {fReader, "LambdaPr_Hlt2Phys_TIS"};
   TTreeReaderValue<Bool_t> LambdaPr_Hlt2Phys_TOS = {fReader, "LambdaPr_Hlt2Phys_TOS"};
   TTreeReaderValue<Int_t> LambdaPr_TRACK_Type = {fReader, "LambdaPr_TRACK_Type"};
   TTreeReaderValue<Int_t> LambdaPr_TRACK_Key = {fReader, "LambdaPr_TRACK_Key"};
   TTreeReaderValue<Double_t> LambdaPr_TRACK_CHI2NDOF = {fReader, "LambdaPr_TRACK_CHI2NDOF"};
   TTreeReaderValue<Double_t> LambdaPr_TRACK_PCHI2 = {fReader, "LambdaPr_TRACK_PCHI2"};
   TTreeReaderValue<Double_t> LambdaPr_TRACK_MatchCHI2 = {fReader, "LambdaPr_TRACK_MatchCHI2"};
   TTreeReaderValue<Double_t> LambdaPr_TRACK_GhostProb = {fReader, "LambdaPr_TRACK_GhostProb"};
   TTreeReaderValue<Double_t> LambdaPr_TRACK_CloneDist = {fReader, "LambdaPr_TRACK_CloneDist"};
   TTreeReaderValue<Double_t> LambdaPr_TRACK_Likelihood = {fReader, "LambdaPr_TRACK_Likelihood"};
   TTreeReaderValue<Double_t> LambdaPr_X = {fReader, "LambdaPr_X"};
   TTreeReaderValue<Double_t> LambdaPr_Y = {fReader, "LambdaPr_Y"};
   TTreeReaderValue<UInt_t> nCandidate = {fReader, "nCandidate"};
   TTreeReaderValue<ULong64_t> totCandidates = {fReader, "totCandidates"};
   TTreeReaderValue<ULong64_t> EventInSequence = {fReader, "EventInSequence"};
   TTreeReaderValue<UInt_t> runNumber = {fReader, "runNumber"};
   TTreeReaderValue<ULong64_t> eventNumber = {fReader, "eventNumber"};
   TTreeReaderValue<UInt_t> BCID = {fReader, "BCID"};
   TTreeReaderValue<Int_t> BCType = {fReader, "BCType"};
   TTreeReaderValue<UInt_t> OdinTCK = {fReader, "OdinTCK"};
   TTreeReaderValue<UInt_t> L0DUTCK = {fReader, "L0DUTCK"};
   TTreeReaderValue<UInt_t> HLT1TCK = {fReader, "HLT1TCK"};
   TTreeReaderValue<UInt_t> HLT2TCK = {fReader, "HLT2TCK"};
   TTreeReaderValue<ULong64_t> GpsTime = {fReader, "GpsTime"};
   TTreeReaderValue<Short_t> Polarity = {fReader, "Polarity"};
   TTreeReaderValue<Int_t> L0Data_DiMuon_Pt = {fReader, "L0Data_DiMuon_Pt"};
   TTreeReaderValue<Int_t> L0Data_DiMuonProd_Pt1Pt2 = {fReader, "L0Data_DiMuonProd_Pt1Pt2"};
   TTreeReaderValue<Int_t> L0Data_Electron_Et = {fReader, "L0Data_Electron_Et"};
   TTreeReaderValue<Int_t> L0Data_GlobalPi0_Et = {fReader, "L0Data_GlobalPi0_Et"};
   TTreeReaderValue<Int_t> L0Data_Hadron_Et = {fReader, "L0Data_Hadron_Et"};
   TTreeReaderValue<Int_t> L0Data_LocalPi0_Et = {fReader, "L0Data_LocalPi0_Et"};
   TTreeReaderValue<Int_t> L0Data_Muon1_Pt = {fReader, "L0Data_Muon1_Pt"};
   TTreeReaderValue<Int_t> L0Data_Muon1_Sgn = {fReader, "L0Data_Muon1_Sgn"};
   TTreeReaderValue<Int_t> L0Data_Muon2_Pt = {fReader, "L0Data_Muon2_Pt"};
   TTreeReaderValue<Int_t> L0Data_Muon2_Sgn = {fReader, "L0Data_Muon2_Sgn"};
   TTreeReaderValue<Int_t> L0Data_Muon3_Pt = {fReader, "L0Data_Muon3_Pt"};
   TTreeReaderValue<Int_t> L0Data_Muon3_Sgn = {fReader, "L0Data_Muon3_Sgn"};
   TTreeReaderValue<Int_t> L0Data_PUHits_Mult = {fReader, "L0Data_PUHits_Mult"};
   TTreeReaderValue<Int_t> L0Data_PUPeak1_Cont = {fReader, "L0Data_PUPeak1_Cont"};
   TTreeReaderValue<Int_t> L0Data_PUPeak1_Pos = {fReader, "L0Data_PUPeak1_Pos"};
   TTreeReaderValue<Int_t> L0Data_PUPeak2_Cont = {fReader, "L0Data_PUPeak2_Cont"};
   TTreeReaderValue<Int_t> L0Data_PUPeak2_Pos = {fReader, "L0Data_PUPeak2_Pos"};
   TTreeReaderValue<Int_t> L0Data_Photon_Et = {fReader, "L0Data_Photon_Et"};
   TTreeReaderValue<Int_t> L0Data_Spd_Mult = {fReader, "L0Data_Spd_Mult"};
//   TTreeReaderValue<Int_t> L0Data_Sum_Et = {fReader, "L0Data_Sum_Et"};
//   TTreeReaderValue<Int_t> L0Data_Sum_Et,Next1 = {fReader, "L0Data_Sum_Et,Next1"};
//   TTreeReaderValue<Int_t> L0Data_Sum_Et,Next2 = {fReader, "L0Data_Sum_Et,Next2"};
//   TTreeReaderValue<Int_t> L0Data_Sum_Et,Prev1 = {fReader, "L0Data_Sum_Et,Prev1"};
//   TTreeReaderValue<Int_t> L0Data_Sum_Et,Prev2 = {fReader, "L0Data_Sum_Et,Prev2"};
   TTreeReaderValue<Int_t> nPV = {fReader, "nPV"};
   TTreeReaderArray<Float_t> PVX = {fReader, "PVX"};
   TTreeReaderArray<Float_t> PVY = {fReader, "PVY"};
   TTreeReaderArray<Float_t> PVZ = {fReader, "PVZ"};
   TTreeReaderArray<Float_t> PVXERR = {fReader, "PVXERR"};
   TTreeReaderArray<Float_t> PVYERR = {fReader, "PVYERR"};
   TTreeReaderArray<Float_t> PVZERR = {fReader, "PVZERR"};
   TTreeReaderArray<Float_t> PVCHI2 = {fReader, "PVCHI2"};
   TTreeReaderArray<Float_t> PVNDOF = {fReader, "PVNDOF"};
   TTreeReaderArray<Float_t> PVNTRACKS = {fReader, "PVNTRACKS"};
   TTreeReaderValue<Int_t> nPVs = {fReader, "nPVs"};
   TTreeReaderValue<Int_t> nTracks = {fReader, "nTracks"};
   TTreeReaderValue<Int_t> nLongTracks = {fReader, "nLongTracks"};
   TTreeReaderValue<Int_t> nDownstreamTracks = {fReader, "nDownstreamTracks"};
   TTreeReaderValue<Int_t> nUpstreamTracks = {fReader, "nUpstreamTracks"};
   TTreeReaderValue<Int_t> nVeloTracks = {fReader, "nVeloTracks"};
   TTreeReaderValue<Int_t> nTTracks = {fReader, "nTTracks"};
   TTreeReaderValue<Int_t> nBackTracks = {fReader, "nBackTracks"};
   TTreeReaderValue<Int_t> nRich1Hits = {fReader, "nRich1Hits"};
   TTreeReaderValue<Int_t> nRich2Hits = {fReader, "nRich2Hits"};
   TTreeReaderValue<Int_t> nVeloClusters = {fReader, "nVeloClusters"};
   TTreeReaderValue<Int_t> nITClusters = {fReader, "nITClusters"};
   TTreeReaderValue<Int_t> nTTClusters = {fReader, "nTTClusters"};
   TTreeReaderValue<Int_t> nOTClusters = {fReader, "nOTClusters"};
   TTreeReaderValue<Int_t> nSPDHits = {fReader, "nSPDHits"};
   TTreeReaderValue<Int_t> nMuonCoordsS0 = {fReader, "nMuonCoordsS0"};
   TTreeReaderValue<Int_t> nMuonCoordsS1 = {fReader, "nMuonCoordsS1"};
   TTreeReaderValue<Int_t> nMuonCoordsS2 = {fReader, "nMuonCoordsS2"};
   TTreeReaderValue<Int_t> nMuonCoordsS3 = {fReader, "nMuonCoordsS3"};
   TTreeReaderValue<Int_t> nMuonCoordsS4 = {fReader, "nMuonCoordsS4"};
   TTreeReaderValue<Int_t> nMuonTracks = {fReader, "nMuonTracks"};
   TTreeReaderValue<Int_t> L0Global = {fReader, "L0Global"};
   TTreeReaderValue<UInt_t> Hlt1Global = {fReader, "Hlt1Global"};
   TTreeReaderValue<UInt_t> Hlt2Global = {fReader, "Hlt2Global"};


   BackgroundSubTemplate(TTree * /*tree*/ =0) { }
   virtual ~BackgroundSubTemplate() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(BackgroundSubTemplate,0);

};

#endif

#ifdef BackgroundSubTemplate_cxx
void BackgroundSubTemplate::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

Bool_t BackgroundSubTemplate::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef BackgroundSubTemplate_cxx
