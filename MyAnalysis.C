#define MyAnalysis_cxx
// The class definition in MyAnalysis.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// Root > T->Process("MyAnalysis.C")
// Root > T->Process("MyAnalysis.C","some options")
// Root > T->Process("MyAnalysis.C+")
//

#include "MyAnalysis.h"
#include <iostream>
#include <TH1F.h>
#include <TLatex.h>
#include <TCanvas.h>
#include <TLegend.h>

using namespace std;

void MyAnalysis::BuildEvent() {
   
  
  
   hadB.SetXYZM(MChadronicBottom_px, MChadronicBottom_py, MChadronicBottom_pz, 4.8);
   lepB.SetXYZM(MCleptonicBottom_px, MCleptonicBottom_py, MCleptonicBottom_pz, 4.8);
   hadWq.SetXYZM(MChadronicWDecayQuark_px, MChadronicWDecayQuark_py, MChadronicWDecayQuark_pz, 0.0);
   hadWqb.SetXYZM(MChadronicWDecayQuarkBar_px, MChadronicWDecayQuarkBar_py, MChadronicWDecayQuarkBar_pz, 0.0);
   lepWl.SetXYZM(MClepton_px, MClepton_py, MClepton_pz, 0.0);
   lepWn.SetXYZM(MCneutrino_px, MCneutrino_py, MCneutrino_pz, 0.0);
   met.SetXYZM(MET_px, MET_py, 0., 0.);
   
   EventWeight *= weight_factor;
   
}

void MyAnalysis::Begin(TTree * /*tree*/) {
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).
   
   TString option = GetOption();
   
}

void MyAnalysis::SlaveBegin(TTree * /*tree*/) {
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).
   
   TString option = GetOption();
   
   // h_Mmumu = new TH1F("Mmumu", "Invariant di-muon mass", 60, 60, 120);
   // h_Mmumu->SetXTitle("m_{#mu#mu}");
   // h_Mmumu->Sumw2();
   // histograms.push_back(h_Mmumu);
   // histograms_MC.push_back(h_Mmumu);
   
   // h_NMuon = new TH1F("NMuon", "Number of muons", 7, 0, 7);
   // h_NMuon->SetXTitle("No. Muons");
   // h_NMuon->Sumw2();
   // histograms.push_back(h_NMuon);
   // histograms_MC.push_back(h_NMuon);
   
   h_w_decay_jet = new TH1F("W decay energy", "W inv-mass", 100,5,500);
   h_w_decay_jet -> SetXTitle("GeV");
   h_w_decay_lepton = new TH1F("h_w_decay_lep", "W inv-mass",100,5,500);
 
   h_top_to_b_decay_hadronic = new TH1F("Top quark decay products energy","Top decay",100,5,500);
   h_top_to_b_decay_hadronic -> SetXTitle("GeV");
   h_top_to_b_decay_leptonic = new TH1F("ignore","inv-mass",100,5,500);
   h_top_to_w_decay_leptonic = new TH1F("ignore1","inv-mass",100,5,500);
   h_top_to_w_decay_hadronic = new TH1F("ignore2","inv-mass",100,5,500);
   
   h_ttbar_invm = new TH1F("ttbar invm","inv-mass",100,250,750);
   h_ttbar_invm -> SetXTitle("GeV");
  
   h_w_decay_jet_noz = new TH1F("W decay energy no z","inv-mass",100,5,300);
   h_w_decay_jet_noz -> SetXTitle("GeV");
   h_w_decay_lepton_noz = new TH1F("h_w_decay_lep no z","inv-mass",100,5,300);

   h_top_to_b_decay_hadronic_noz = new TH1F("Top quark decay products energy no z","Top decay",100,5,300);
   h_top_to_b_decay_hadronic_noz -> SetXTitle("Gev");
   h_top_to_b_decay_leptonic_noz = new TH1F("ignore3","inv-mass",100,5,300);
   h_top_to_w_decay_leptonic_noz = new TH1F("ignore4","inv-mass",100,5,300);
   h_top_to_w_decay_hadronic_noz = new TH1F("ignore5","inv-mass",100,5,300);
   
   h_ttbar_invm_noz = new TH1F("ttbar invm no z","inv-mass",100,250,750);
   h_ttbar_invm_noz -> SetXTitle("GeV");

  // h_w_decay_lepton -> Sumw2();
  // h_top_pair = new TH1F("h_top_pair","top-pair inv-mass",100,-25,25);
  // h_top_pair -> SetXTitle("mass, ttbar");
  // histograms.push_back(h_top_pair);
  // histograms_MC.push_back(h_top_pair);
   


}

Bool_t MyAnalysis::Process(Long64_t entry) {
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either MyAnalysis::GetEntry() or TBranch::GetEntry()
   // to read either all or the required parts of the data. When processing
   // keyed objects with PROOF, the object is already loaded and is available
   // via the fObject pointer.
   //
   // This function should contain the "body" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.
   
   ++TotalEvents;
   
   GetEntry(entry);
   
   if (TotalEvents % 10000 == 0)
      cout << "Next event -----> " << TotalEvents << endl;
   
   BuildEvent();
   
   double MuonPtCut = 25.;
   double MuonRelIsoCut = 0.10;
   
   //   cout << "Jets: " << endl;
   //   for (vector<MyJet>::iterator it = Jets.begin(); it != Jets.end(); ++it) {
   //      cout << "pt, eta, phi, btag, id: " << it->Pt() << ", " << it->Eta() << ", " << it->Phi() << ", " << it->IsBTagged() << ", " << it->GetJetID()
   //      << endl;
   //   }
   //   cout << "Muons: " << endl;
   //   for (vector<MyMuon>::iterator it = Muons.begin(); it != Muons.end(); ++it) {
   //      cout << "pt, eta, phi, iso, charge: " << it->Pt() << ", " << it->Eta() << ", " << it->Phi() << ", "
   //      << it->GetIsolation() << ", " << it->GetCharge() << endl;
   //   }
   //   cout << "Electrons: " << endl;
   //   for (vector<MyElectron>::iterator it = Electrons.begin(); it != Electrons.end(); ++it) {
   //      cout << "pt, eta, phi, iso, charge: " << it->Pt() << ", " << it->Eta() << ", " << it->Phi() << ", "
   //      << it->GetIsolation() << ", " << it->GetCharge() << endl;
   //   }
   //   cout << "Photons: " << endl;
   //   for (vector<MyPhoton>::iterator it = Photons.begin(); it != Photons.end(); ++it) {
   //      cout << "pt, eta, phi, iso: " << it->Pt() << ", " << it->Eta() << ", " << it->Phi() << ", " << it->GetIsolation()
   //      << endl;
   //   }
   
   
   //////////////////////////////
   // Exercise 1: Invariant Di-Muon mass
   
 // int N_IsoMuon = 0;
 // MyMuon *muon1, *muon2;
   
 //  for (vector<MyMuon>::iterator jt = Muons.begin(); jt != Muons.end(); ++jt) {
 //     if (jt->IsIsolated(MuonRelIsoCut)) {
 //        ++N_IsoMuon;
 //        if (N_IsoMuon == 1) muon1 = &(*jt);
 //        if (N_IsoMuon == 2) muon2 = &(*jt);
 //     }
 //  }
   
 //  h_NMuon->Fill(N_IsoMuon, EventWeight);
   
 //  if (N_IsoMuon > 1 && triggerIsoMu24) {
 //     if (muon1->Pt()>MuonPtCut) {
 //        h_Mmumu->Fill((*muon1 + *muon2).M(), EventWeight);
 //     }
 //  }
   
   

   double jet_W_invm;
   jet_W_invm = sqrt(pow(hadWq[0],2)+pow(hadWq[1],2)+pow(hadWq[2],2));
   double jetbar_W_invm;
   jetbar_W_invm = sqrt(pow(hadWqb[0],2)+pow(hadWqb[1],2)+pow(hadWqb[2],2));
   double lepton_w_invm;
   lepton_w_invm = sqrt(pow(lepWn[0],2)+pow(lepWl[1],2)+pow(lepWl[2],2));
   double neutrino_w_invm;
   neutrino_w_invm = sqrt(pow(lepWl[0],2)+pow(lepWl[1],2)+pow(lepWl[2],2));
   double leptonic_B_invm;
   leptonic_B_invm = sqrt(pow(lepB[0],2)+pow(lepB[1],2)+pow(lepB[2],2)-4.8*4.8);
   double hadronic_B_invm;
   hadronic_B_invm = sqrt(pow(hadB[0],2)+pow(hadB[1],2)+pow(hadB[2],2)-4.8*4.8);
   double ttbar_total;
   ttbar_total = jet_W_invm + jetbar_W_invm + lepton_w_invm + neutrino_w_invm + leptonic_B_invm + hadronic_B_invm;

   double jet_w_invm_noz;
   double jetbar_w_invm_noz;
   double lepton_w_invm_noz;
   double neutrino_w_invm_noz;
   double leptonic_B_invm_noz;
   double hadronic_B_invm_noz;
   double ttbar_total_noz;

   jet_w_invm_noz = sqrt(pow(hadWq[0],2)+pow(hadWq[1],2));
   jetbar_w_invm_noz = sqrt(pow(hadWqb[0],2)+pow(hadWqb[1],2));
   lepton_w_invm_noz = sqrt(pow(lepWl[0],2)+pow(lepWl[1],2));
   neutrino_w_invm_noz = sqrt(pow(lepWn[0],2)+pow(lepWn[1],2));
   leptonic_B_invm_noz = sqrt(pow(lepB[0],2)+pow(lepB[1],2)-4.8*4.8);
   hadronic_B_invm_noz = sqrt(pow(hadB[0],2)+pow(hadB[1],2)-4.8*4.8);
   ttbar_total_noz = jet_w_invm_noz + jetbar_w_invm_noz + lepton_w_invm_noz + neutrino_w_invm_noz + leptonic_B_invm_noz + hadronic_B_invm_noz;


   h_w_decay_jet -> Fill(jet_W_invm+jetbar_W_invm,EventWeight);
   h_w_decay_lepton -> Fill(lepton_w_invm+neutrino_w_invm,EventWeight);
   h_top_to_b_decay_leptonic -> Fill(leptonic_B_invm,EventWeight);
   h_top_to_b_decay_hadronic -> Fill(hadronic_B_invm,EventWeight);
   h_top_to_w_decay_leptonic -> Fill(lepton_w_invm+neutrino_w_invm,EventWeight);
   h_top_to_w_decay_hadronic -> Fill(jet_W_invm+jetbar_W_invm,EventWeight);
   h_ttbar_invm -> Fill(ttbar_total,EventWeight);

   h_w_decay_jet_noz -> Fill(jet_w_invm_noz + jetbar_w_invm_noz,EventWeight);
   h_w_decay_lepton_noz -> Fill(lepton_w_invm_noz + neutrino_w_invm_noz,EventWeight);
   h_top_to_b_decay_leptonic_noz -> Fill(leptonic_B_invm_noz,EventWeight);
   h_top_to_b_decay_hadronic_noz -> Fill(hadronic_B_invm_noz,EventWeight);
   h_top_to_w_decay_leptonic_noz -> Fill(lepton_w_invm_noz + neutrino_w_invm_noz,EventWeight);
   h_top_to_w_decay_hadronic_noz -> Fill(jet_w_invm_noz + jetbar_w_invm_noz,EventWeight);
   h_ttbar_invm_noz -> Fill(ttbar_total_noz,EventWeight);

   //////////////////////////////
   
   return kTRUE;
}

void MyAnalysis::SlaveTerminate() {
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.
   
}

void MyAnalysis::Terminate() {
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
   
   TCanvas *c1 = new TCanvas();
  //h_w_decay_jet -> GetXaxis()->SetRange(10,350);
   h_w_decay_jet -> SetFillColor(kRed);
   h_w_decay_jet -> Draw("hist");
   h_w_decay_lepton -> SetFillColor(kBlue);
   h_w_decay_lepton -> SetFillStyle(3354);
   h_w_decay_lepton -> Draw("hist same");
   TLegend *legend1 = new TLegend(0.5,0.4,0.9,0.7);
   legend1 -> AddEntry(h_w_decay_jet,"Summed W decay energy via jets","f");
   legend1 -> AddEntry(h_w_decay_lepton,"Summed W decay energy via leptonic decay","f");
   legend1 -> Draw();
   c1 -> SaveAs("W_decays.jpg");

   TCanvas *c2 = new TCanvas();
   h_top_to_b_decay_hadronic -> SetFillColor(kRed);
  // h_top_to_b_decay -> GetXaxis()->SetRange(10,350);
   h_top_to_b_decay_hadronic -> Draw("hist");
   h_top_to_b_decay_leptonic -> SetFillColor(kBlue);
   h_top_to_b_decay_leptonic -> SetFillStyle(3002);
   h_top_to_b_decay_leptonic -> Draw("hist same");
   h_top_to_w_decay_leptonic -> SetFillColor(kGreen);
   h_top_to_w_decay_leptonic -> SetFillStyle(3354);
   h_top_to_w_decay_leptonic -> Draw("hist same");
   h_top_to_w_decay_hadronic -> SetFillColor(kYellow);
   h_top_to_w_decay_hadronic -> SetFillStyle(3350);
   h_top_to_w_decay_hadronic -> Draw("hist same");
   TLegend *legend2 = new TLegend(0.5,0.4,0.9,0.7);
   legend2 -> AddEntry(h_top_to_b_decay_hadronic,"b quark Energy (hadronic decay)","f");
   legend2 -> AddEntry(h_top_to_b_decay_leptonic,"b quark Energy (leptonic decay)","f");
   legend2 -> AddEntry(h_top_to_w_decay_hadronic,"W Energy (hadronic decay)","f");
   legend2 -> AddEntry(h_top_to_w_decay_leptonic,"W Energy (leptonic decay)","f");
   legend2 -> Draw();

   c2 -> SaveAs("Top_decays.jpg");

   TCanvas *c3 = new TCanvas();

   h_ttbar_invm -> SetFillColor(kRed);
   h_ttbar_invm -> Draw("hist");
   TLegend *legend3 = new TLegend(0.1,0.7,0.4,0.9);
   legend3 -> AddEntry(h_ttbar_invm,"total inv-mass of ttbar pair");
   legend3 -> Draw();

   c3 -> SaveAs("ttbar_invm.jpg");
   
   TCanvas *c4 = new TCanvas();
   h_w_decay_jet_noz -> SetFillColor(kRed);
   h_w_decay_jet_noz -> Draw("hist");
   h_w_decay_lepton_noz -> SetFillColor(kBlue);
   h_w_decay_lepton_noz -> SetFillStyle(3354);
   h_w_decay_lepton_noz -> Draw("hist same");
   TLegend *legend4 = new TLegend(0.5,0.4,0.9,0.7);
   legend4 -> AddEntry(h_w_decay_jet_noz,"Summed W decay energy via jets (no z)","f");
   legend4 -> AddEntry(h_w_decay_lepton_noz,"Summed W decay energy via leptonic decay (no z)","f");
   legend4 -> Draw();
   c4 -> SaveAs("W_decays_noz.jpg");
   
   TCanvas *c5 = new TCanvas();
   h_top_to_b_decay_hadronic_noz -> SetFillColor(kRed);
   h_top_to_b_decay_hadronic_noz -> Draw("hist");
   h_top_to_b_decay_leptonic_noz -> SetFillColor(kBlue);
   h_top_to_b_decay_leptonic_noz -> SetFillStyle(3002);
   h_top_to_b_decay_leptonic_noz -> Draw("hist same");
   h_top_to_w_decay_leptonic_noz -> SetFillColor(kGreen);
   h_top_to_w_decay_leptonic_noz -> SetFillStyle(3354);
   h_top_to_w_decay_leptonic_noz -> Draw("hist same");
   h_top_to_w_decay_hadronic_noz -> SetFillColor(kYellow);
   h_top_to_w_decay_hadronic_noz -> SetFillStyle(3350);
   h_top_to_w_decay_hadronic_noz -> Draw("hist same");
   TLegend *legend5 = new TLegend(0.5,0.4,0.9,0.7);
   legend5 -> AddEntry(h_top_to_b_decay_hadronic_noz,"b quark Energy (hadronic decay no-z)","f");
   legend5 -> AddEntry(h_top_to_b_decay_leptonic_noz,"b quark Energy (leptonic decay no-z)","f");
   legend5 -> AddEntry(h_top_to_w_decay_hadronic_noz,"W Energy (hadronic decay no-z)","f");
   legend5 -> AddEntry(h_top_to_w_decay_leptonic_noz,"W Energy (leptonic decay no-z)","f");
   legend5 -> Draw();

   c5 -> SaveAs("Top_decays_noz.jpg");
   
   TCanvas *c6 = new TCanvas();
   
   h_ttbar_invm_noz -> SetFillColor(kRed);
   h_ttbar_invm_noz -> Draw("hist");
   TLegend *legend6 = new TLegend(0.4,0.7,0.7,0.9);
   legend6 -> AddEntry(h_ttbar_invm_noz,"total inv-mass of ttbar pair (no z)","f");
   legend6 -> Draw();
   
   c6 -> SaveAs("ttbar_invm_noz.jpg");
}
