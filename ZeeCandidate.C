#define ZeeCandidate_cxx
#include "ZeeCandidate.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <fstream>
using namespace std;


void ZeeCandidate::Loop(bool isMC)
{
//   In a ROOT session, you can do:
//      Root > .L ZeeCandidate.C
//      Root > ZeeCandidate t
       //      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntries();

//TFile * file = new TFile("ZeeOutput.root","RECREATE");



TFile * file=0;
   if (isMC)  file = new TFile("Zmass_MC.root","RECREATE");
   else file = new TFile("Zmass_data.root","RECREATE");

gStyle->SetPalette(1,0);
gStyle->SetMarkerSize(1.1); //was 1.0 without error
gStyle->SetOptStat(0);
gStyle->SetPaintTextFormat("4.3f "); //size of text in legend




   //For Z (for first selection cut)
                                                   //#bins  //min  //max

 TH1D *hZMass=new TH1D("hZMass","Z Mass Distribution",40,70000,110000.); //this is declares the mass histogram for the truth Z (the mass here is in MeV)
 hZMass->Sumw2(); //This takes errors into account
 TH1D *hZPtD=new TH1D("hZPtD","Z P_{T}", 160, 0, 160000); //this is declares the histogram for the truth Z transverse momentum 
 hZPtD->Sumw2(); //This takes errors into account
 TH1D *hZEtaD=new TH1D("hZEtaD","Z #eta", 120, -10, 10); //this is declares the histogram for the eta value of the truth Z 
 hZEtaD->Sumw2(); //This takes errors into account
 TH1D *hZPhiD=new TH1D("hZPhiD","Z #phi", 16, -3.2, 3.2); //this is declares the histogram for the truth Z transverse momentum 
 hZPhiD->Sumw2(); //This takes errors into account



 //For Elec1 (for second selection cut)

 TH1D *hElec1Pt=new TH1D("hElec1Pt","Electron candidate 1 P_{T}", 140, 20000, 160000); //this is declares the histogram for the transverse momentum of the tag electron
 hElec1Pt->Sumw2(); //This takes errors into account
 TH1D *hElec1Eta=new TH1D("hElec1Eta","Electron candidate 1 #eta",120, -3, 3); //this is declares the histogram for the eta value of the tag electron
 hElec1Eta->Sumw2();
 TH1D *hElec1Phi=new TH1D("hElec1Phi","Electron candidate 1 #phi",64, -3.2, 3.2); //this is declares the histogram for the phi value of the tag electron
 hElec1Phi->Sumw2(); //This takes errors into account


 //For Elec2 (for third selection cut)

 TH1D *hElec2Pt=new TH1D("hElec2Pt","Electron candidate 2 P_{T}", 140, 20000, 160000); //this is declares the histogram for the transverse momentum of the probe electron
 hElec2Pt->Sumw2(); //This takes errors into account
 TH1D *hElec2Eta=new TH1D("hElec2Eta","Electron candidate 2 #eta",120, -3, 3); //this is declares the histogram for the eta value of the probe electron
 hElec2Eta->Sumw2();
 TH1D *hElec2Phi=new TH1D("hElec2Phi","Electron candidate 2 #phi",64, -3.2, 3.2); //this is declares the histogram for the phi value of the probe electron
 hElec2Phi->Sumw2(); //This takes errors into account


 //for Z (for the last selection cut)

TH1D *hZMass2=new TH1D("hZMass2","Z Mass Distribution",40,70000,110000.); //this is declares the mass histogram for the truth Z (the mass here is in MeV)
 hZMass2->Sumw2(); //This takes errors into account
 TH1D *hZPtD2=new TH1D("hZPtD2","Z P_{T}", 160, 0, 160000); //this is declares the histogram for the truth Z transverse momentum 
 hZPtD2->Sumw2(); //This takes errors into account
 TH1D *hZEtaD2=new TH1D("hZEtaD2","Z #eta", 120, -10, 10); //this is declares the histogram for the eta value of the truth Z 
 hZEtaD2->Sumw2(); //This takes errors into account
 TH1D *hZPhiD2=new TH1D("hZPhiD2","Z #phi", 16, -3.2, 3.2); //this is declares the histogram for the truth Z transverse momentum 
  hZPhiD2->Sumw2(); //This takes errors into account



 //For ECand1 (for last selection cut)

 TH1D *hElCand1Pt=new TH1D("hElCand1Pt","Electron candidate 1 P_{T}", 140, 20000, 160000); //this is declares the histogram for the transverse momentum of the tag electron
 hElCand1Pt->Sumw2(); //This takes errors into account
 TH1D *hElCand1Eta=new TH1D("hElCand1Eta","Electron candidate 1 #eta",120, -3, 3); //this is declares the histogram for the eta value of the tag electron
 hElCand1Eta->Sumw2();
 TH1D *hElCand1Phi=new TH1D("hElCand1Phi","Electron candidate 1 #phi",64, -3.2, 3.2); //this is declares the histogram for the phi value of the tag electron
 hElCand1Phi->Sumw2(); //This takes errors into account


 //ForECand2 (for last selection cut)

 TH1D *hElCand2Pt=new TH1D("hElCand2Pt","Electron candidate 2 P_{T}", 140, 20000, 160000); //this is declares the histogram for the transverse momentum of the probe electron
 hElCand2Pt->Sumw2(); //This takes errors into account
 TH1D *hElCand2Eta=new TH1D("hElCand2Eta","Electron candidate 2 #eta",120, -3, 3); //this is declares the histogram for the eta value of the probe electron
 hElCand2Eta->Sumw2();
 TH1D *hElCand2Phi=new TH1D("hElCand2Phi","Electron candidate 2 #phi",64, -3.2, 3.2); //this is declares the histogram for the phi value of the probe electron
 hElCand2Phi->Sumw2(); //This takes errors into account 



 
 //for no selection cuts
 TH1D *hZMassNoCut=new TH1D("hZMassNoCut","Z Boson Mass Distribution",110,0,110000.); //this is declares the mass histogram for the truth Z (the mass here is in MeV)
 hZMassNoCut->Sumw2(); //This takes errors into account
 TH1D *hZPtNoCut=new TH1D("hZPtNoCut","Z boson P_{T} Distribution", 160, 0, 160000); //this is declares the histogram for the truth Z transverse momentum 
 hZPtNoCut->Sumw2(); //This takes errors into account
 TH1D *hZEtaNoCut=new TH1D("hZEtaNoCut","Z boson #eta Distribution", 120, -10, 10); //this is declares the histogram for the eta value of the truth Z 
 hZEtaNoCut->Sumw2(); //This takes errors into account
 TH1D *hZPhiNoCut=new TH1D("hZPhiNoCut","Z boson #phi Distribution", 16, -3.2, 3.2); //this is declares the histogram for the truth Z transverse momentum 
  hZPhiNoCut->Sumw2(); //This takes errors into account
 TH1D *hElec1PtNoCut=new TH1D("hElec1PtNoCut","Electron Candidate 1 P_{T} Distribution", 160, 0, 160000); //this is declares the histogram for the transverse momentum of the tag electron
 hElec1PtNoCut->Sumw2(); //This takes errors into account
 TH1D *hElec1EtaNoCut=new TH1D("hElec1EtaNoCut","Electron Candidate 1 #eta Distribution",120, -3, 3); //this is declares the histogram for the eta value of the tag electron
 hElec1EtaNoCut->Sumw2();
 TH1D *hElec1PhiNoCut=new TH1D("hElec1PhiNoCut","Electron Candidate 1 #phi Distribution",64, -3.2, 3.2); //this is declares the histogram for the phi value of the tag electron
 hElec1PhiNoCut->Sumw2(); //This takes errors into account
 TH1D *hElec2PtNoCut=new TH1D("hElec2PtNoCut","Electron Candidate 2 P_{T} Distribution", 160, 0, 160000); //this is declares the histogram for the transverse momentum of the tag electron
 hElec2PtNoCut->Sumw2(); //This takes errors into account
 TH1D *hElec2EtaNoCut=new TH1D("hElec2EtaNoCut","Electron Candidate 2 #eta Distribution",120, -3, 3); //this is declares the histogram for the eta value of the tag electron
 hElec2EtaNoCut->Sumw2();
 TH1D *hElec2PhiNoCut=new TH1D("hElec2PhiNoCut","Electron Candidate 2 #phi Distribution",64, -3.2, 3.2); //this is declares the histogram for the phi value of the tag electron
 hElec2PhiNoCut->Sumw2(); //This takes errors into account



//ntries=127420;

	fChain->SetBranchStatus("*",0);  // disable all branches
	fChain->SetBranchStatus("Zcand_M",1);  // activate branchname
	fChain->SetBranchStatus("Zcand_pt",1);  // activate branchname
        fChain->SetBranchStatus("Zcand_eta",1);  // activate branchname
        fChain->SetBranchStatus("Zcand_phi",1);  // activate branchname
        fChain->SetBranchStatus("elCand1_pt",1);  // activate branchname
        fChain->SetBranchStatus("elCand1_eta",1);  // activate branchname
        fChain->SetBranchStatus("elCand1_phi",1);  // activate branchname
        fChain->SetBranchStatus("elCand2_pt",1);  // activate branchname
        fChain->SetBranchStatus("elCand2_eta",1);  // activate branchname
        fChain->SetBranchStatus("elCand2_phi",1);  // activate branchname
	fChain->SetBranchStatus("elCand1_isTightLL",1);  // activate branchname
	fChain->SetBranchStatus("elCand2_isTightLL",1);  // activate branchname
	fChain->SetBranchStatus("elCand2_isMediumLL",1);  // activate branchname



	if (isMC) {     //these commands will only be executed for MC data
		cout<<"Monte Carlo File has been executed"<<endl;
	 
		fChain->SetBranchStatus("elCand1_origin",1);  // activate branchname
		fChain->SetBranchStatus("elCand2_origin",1);  // activate branchname               

	}




   Long64_t nbytes = 0, nb = 0;

//if (nentries>1e6)nentries=1e6;

   for (Long64_t jentry=0; jentry<nentries;jentry++) {
     //if (jentry %10000==0) cout << "processed entries:  "<<jentry<< "  " << "of "<<nentries<<"  "<< Form("(%2.1f %)",((double)jentry/nentries)*100) << endl;
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;



      nb = fChain->GetEntry(jentry);   nbytes += nb;


// cuts 
//this is only for monte carlo
//truth origin 13 is z boson, truth type 4 is background electron, truth origin background 40 is a FSR (final state radiation) photon
         if (elCand1_origin == 13 && elCand2_origin ==13  ){


	 //for no selection cuts
	 if(Zcand_M>0){
           
	 hZMassNoCut->Fill(Zcand_M);     //Z Mass 
         hZPtNoCut->Fill(Zcand_pt);         //for ZPt
	 hZEtaNoCut->Fill(Zcand_eta);       //for ZEta    
	 hZPhiNoCut->Fill(Zcand_phi);       //for ZPhi 
     
       	 hElec1PtNoCut->Fill(elCand1_pt);      //Elec 1 Pt
	 hElec1EtaNoCut->Fill(elCand1_eta);    //Elec 1 Eta
	 hElec1PhiNoCut->Fill(elCand1_phi);    //Elec 1 Phi
         hElec2PtNoCut->Fill(elCand2_pt);      //Elec 2 Pt
       	 hElec2EtaNoCut->Fill(elCand2_eta);    //Elec 2 Eta
	 hElec2PhiNoCut->Fill(elCand2_phi);    //Elec 2 Phi

}

	 // cout<< "I am in the loop" << endl;
      // if (Cut(ientry) < 0) continue;

      //for the z mass histogram (truth Z)

      if (70000.<=Zcand_M && Zcand_M<=110000.){  

         hZMass->Fill(Zcand_M);  	//for Z mass
	 hZPtD->Fill(Zcand_pt);         //for ZPtD
	 hZEtaD->Fill(Zcand_eta);       //for ZEtaD    
	 hZPhiD->Fill(Zcand_phi);       //for ZPhiD 

        //for the electron candidates

	  if(elCand1_isTightLL == 1){ //this is to apply a tight cut on elec1 and to do nothing on elec2
	    // cout << "this is the electron loop 1" << endl;
     
       	hElec1Pt->Fill(elCand1_pt);      //Elec 1 Pt
	hElec1Eta->Fill(elCand1_eta);    //Elec 1 Eta
	hElec1Phi->Fill(elCand1_phi);    //Elec 1 Phi
      


	 if(elCand2_isMediumLL == 1){
	   // cout << "this is the electron loop 2" << endl;

        hElec2Pt->Fill(elCand2_pt);      //Elec 2 Pt
	hElec2Eta->Fill(elCand2_eta);    //Elec 2 Eta
	hElec2Phi->Fill(elCand2_phi);    //Elec 2 Phi

        } 


	} //end of if statement for electron candidates 

      } //end of if statement with mass cut 




    if((70000.<=Zcand_M && Zcand_M<=110000) && elCand1_pt>20000. && elCand2_pt>20000 && elCand1_isTightLL == 1){

	  // cout << "this is last loop" << endl;


        hZMass2->Fill(Zcand_M);  	        //for Z mass
       	hZPtD2->Fill(Zcand_pt);             //for ZPtD
        hZEtaD2->Fill(Zcand_eta);           //for ZEtaD
        hZPhiD2->Fill(Zcand_phi);           //for ZPhiD
        hElCand1Pt->Fill(elCand1_pt);      //Elec 1 Pt
        hElCand1Eta->Fill(elCand1_eta);    //Elec 1 Eta
        hElCand1Phi->Fill(elCand1_phi);    //Elec 1 Phi
        hElCand2Pt->Fill(elCand2_pt);      //Elec 2 Pt
        hElCand2Eta->Fill(elCand2_eta);    //Elec 2 Eta
        hElCand2Phi->Fill(elCand2_phi);    //Elec 2 Phi
    }
       	} // this is end of truth origin MC truth classifier code


   } //end of for loop



 //for Z Mass
TCanvas *c1 = new TCanvas("hZMass","",50,44,800,600); //for hZMass (data or MC)
c1->SetRightMargin(0.15);
hZMass ->GetYaxis()->SetTitle("Number of events/1 GeV");
hZMass->GetYaxis()->SetTitleOffset(1.5); //this line shifts the position of the y axis title further away from the axis
hZMass ->GetXaxis()->SetTitle("Z Boson Mass [eV]");
hZMass ->SetTitle("M_{Z} Distribution");
 
//comment out for MC (from first line)
hZMass->SetLineColor(kBlue); //TColour into google
hZMass->SetFillColor(kBlue);
hZMass->Draw("bar"); //(to this line) */

//comment out for data (from first line)
/*  hZMass->SetMarkerColor(kBlack);
hZMass->SetMarkerSize(1.0); //type TMarker root into google
hZMass->SetMarkerStyle(20);//type TMarker root into google
      hZMass->SetLineColor(kBlack); //TColour into google
      hZMass->Draw(); //(to this line) */

   TPaveText* ptext11 = new TPaveText(0.6, 0.6, 0.8, 0.8, "NDC");
   TText *t31=ptext11->AddText("#it{ATLAS} #bf{Preliminary}");
   TText *t32=ptext11->AddText("#bf{#sqrt{s} = 13 TeV (2015)}");
   TText *t33=ptext11->AddText("#bf{Z #rightarrow e^{-}e^{+}}");
   ptext11->SetFillStyle(0);
   ptext11->SetBorderSize(0);
   ptext11->Draw(); 




      //for ZPtD

TCanvas *c2 = new TCanvas("hZPtD","",50,44,800,600); //for hZPtD (data or MC)
   c1->SetRightMargin(0.15);
   hZPtD ->GetYaxis()->SetTitle("Number of events/1 GeV");
   hZPtD->GetYaxis()->SetTitleOffset(1.5); //this line shifts the position of the y axis title further away from the axis
   hZPtD ->GetXaxis()->SetTitle("Z Boson P_{T} [eV]");
   hZPtD ->SetTitle("Z Boson P_{T} Distribution");
 
   //comment out for MC (from first line)
     hZPtD->SetLineColor(kBlue); //TColour into google
      hZPtD->SetFillColor(kBlue);
      hZPtD->Draw("bar0"); //(to this line) */

   //comment out for data (from first line)
      /*  hZPtD->SetMarkerColor(kBlack);
      hZPtD->SetMarkerSize(1.0); //type TMarker root into google
      hZPtD->SetMarkerStyle(20);//type TMarker root into google
      hZPtD->SetLineColor(kBlack); //TColour into google
      hZPtD->Draw(); //(to this line) */


   TPaveText* ptext12 = new TPaveText(0.5, 0.4, 0.7, 0.55, "NDC");
   TText *t34=ptext12->AddText("#it{ATLAS} #bf{Preliminary}");
   TText *t35=ptext12->AddText("#bf{#sqrt{s} = 13 TeV (2015)}");
   TText *t36=ptext12->AddText("#bf{Z #rightarrow e^{-}e^{+}}");
   ptext12->SetFillStyle(0);
   ptext12->SetBorderSize(0);
   ptext12->Draw();

      //for ZEtaD

TCanvas *c3 = new TCanvas("hZEtaD","",50,44,800,600); //for hZEtaD (data or MC)
   hZEtaD ->GetYaxis()->SetTitle("Number of events");
   hZEtaD->GetYaxis()->SetTitleOffset(1.5); //this line shifts the position of the y axis title further away from the axis
   hZEtaD ->GetXaxis()->SetTitle("Z Boson #eta");
   hZEtaD ->SetTitle("Z Boson #eta Distribution");
 
   //comment out for MC (from first line)
    hZEtaD->SetLineColor(kBlue); //TColour into google
      hZEtaD->SetFillColor(kBlue);
      hZEtaD->Draw("bar0"); //(to this line) */

   //comment out for data (from first line)
      /*  hZEtaD->SetMarkerColor(kBlack);
      hZEtaD->SetMarkerSize(1.0); //type TMarker root into google
      hZEtaD->SetMarkerStyle(20);//type TMarker root into google
      hZEtaD->SetLineColor(kBlack); //TColour into google
      hZEtaD->Draw(); //(to this line) */


  TPaveText* ptext13 = new TPaveText(0.65, 0.65, 0.85, 0.85, "NDC");
   TText *t37=ptext13->AddText("#it{ATLAS} #bf{Preliminary}");
   TText *t38=ptext13->AddText("#bf{#sqrt{s} = 13 TeV (2015)}");
   TText *t39=ptext13->AddText("#bf{Z #rightarrow e^{-}e^{+}}");
   ptext13->SetFillStyle(0);
   ptext13->SetBorderSize(0);
   ptext13->Draw();




   //for ZPhiD

TCanvas *c4 = new TCanvas("hZPhiD","",50,44,800,600); //for hZPhiD (data or MC)
   hZPhiD ->GetYaxis()->SetTitle("Number of events");
   hZPhiD->GetYaxis()->SetTitleOffset(1.5); //this line shifts the position of the y axis title further away from the axis
   hZPhiD ->GetXaxis()->SetTitle("Z Boson #phi");
   hZPhiD ->SetTitle("Z Boson #phi Distribution");
 
   //comment out for MC (from first line)
     hZPhiD->SetLineColor(kBlue); //TColour into google
      hZPhiD->SetFillColor(kBlue);
      hZPhiD->Draw("bar0");// (to this line) */

   //comment out for data (from first line)
   /*  hZPhiD->SetMarkerColor(kBlack);
      hZPhiD->SetMarkerSize(1.0); //type TMarker root into google
      hZPhiD->SetMarkerStyle(20);//type TMarker root into google
      hZPhiD->SetLineColor(kBlack); //TColour into google
      hZPhiD->Draw(); //(to this line) */


   TPaveText* ptext14 = new TPaveText(0.5, 0.3, 0.7, 0.45, "NDC");
   TText *t40=ptext14->AddText("#it{ATLAS} #bf{Preliminary}");
   TText *t41=ptext14->AddText("#bf{#sqrt{s} = 13 TeV (2015)}");
   TText *t42=ptext14->AddText("#bf{Z #rightarrow e^{-}e^{+}}");
   //  ptext14->SetFillStyle(0); //put this in a comment for MC
   // ptext14->SetBorderSize(0); //put this in a comment for MC
   ptext14->Draw();





   //for Elec1Pt
TCanvas *c5 = new TCanvas("hZEtaD","",50,44,800,600); //for hElec1Pt (data or MC)
   hElec1Pt ->GetYaxis()->SetTitle("Number of events");
   hElec1Pt->GetYaxis()->SetTitleOffset(1.5); //this line shifts the position of the y axis title further away from the axis
   hElec1Pt->GetXaxis()->SetTitle("Electron Candidate 1 P_{T}");
   hElec1Pt->SetTitle("Electron Candidate 1 P_{T} Distribution");
 
   //comment out for MC (from first line)
      hElec1Pt->SetLineColor(kBlue); //TColour into google
      hElec1Pt->SetFillColor(kBlue);
      hElec1Pt->Draw("bar0"); //(to this line) */

   //comment out for data (from first line)
   /*  hElec1Pt->SetMarkerColor(kBlack);
      hElec1Pt->SetMarkerSize(1.0); //type TMarker root into google
      hElec1Pt->SetMarkerStyle(20);//type TMarker root into google
      hElec1Pt->SetLineColor(kBlack); //TColour into google
      hElec1Pt->Draw(); //(to this line) */


   TPaveText* ptext15 = new TPaveText(0.5, 0.4, 0.7, 0.55, "NDC");
   TText *t43=ptext15->AddText("#it{ATLAS} #bf{Preliminary}");
   TText *t44=ptext15->AddText("#bf{#sqrt{s} = 13 TeV (2015)}");
   TText *t45=ptext15->AddText("#bf{Z #rightarrow e^{-}e^{+}}");
   ptext15->SetFillStyle(0);
   ptext15->SetBorderSize(0);
   ptext15->Draw();



   //for Elec1Eta
TCanvas *c6 = new TCanvas("hElec1Eta","",50,44,800,600); //for hElec1Eta (data or MC)
   hElec1Eta->GetYaxis()->SetTitle("Number of events");
   hElec1Eta->GetYaxis()->SetTitleOffset(1.5); //this line shifts the position of the y axis title further away from the axis
   hElec1Eta->GetXaxis()->SetTitle("Electron Candidate 1 #eta");
   hElec1Eta->SetTitle("Electron Candidate 1 #eta Distribution");
 
   //comment out for MC (from first line)
     hElec1Eta->SetLineColor(kBlue); //TColour into google
      hElec1Eta->SetFillColor(kBlue);
      hElec1Eta->Draw("bar0");// (to this line) */

   //comment out for data (from first line)
   /*   hElec1Eta->SetMarkerColor(kBlack);
      hElec1Eta->SetMarkerSize(1.0); //type TMarker root into google
      hElec1Eta->SetMarkerStyle(20);//type TMarker root into google
      hElec1Eta->SetLineColor(kBlack); //TColour into google
      hElec1Eta->Draw(); //(to this line) */

  TPaveText* ptext16 = new TPaveText(0.65, 0.65, 0.85, 0.85, "NDC");
   TText *t46=ptext16->AddText("#it{ATLAS} #bf{Preliminary}");
   TText *t47=ptext16->AddText("#bf{#sqrt{s} = 13 TeV (2015)}");
   TText *t48=ptext16->AddText("#bf{Z #rightarrow e^{-}e^{+}}");
   ptext16->SetFillStyle(0);
   ptext16->SetBorderSize(0);
   ptext16->Draw();






   //for Elec1Phi
TCanvas *c7 = new TCanvas("hElec1Phi","",50,44,800,600); //for hElec1Phi (data or MC)
   hElec1Phi->GetYaxis()->SetTitle("Number of events");
   hElec1Phi->GetYaxis()->SetTitleOffset(1.5); //this line shifts the position of the y axis title further away from the axis
   hElec1Phi->GetXaxis()->SetTitle("Electron Candidate 1 #phi");
   hElec1Phi->SetTitle("Electron Candidate 1 #phi Distribution");
 
   //comment out for MC (from first line)
    hElec1Phi->SetLineColor(kBlue); //TColour into google
      hElec1Phi->SetFillColor(kBlue);
      hElec1Phi->Draw("bar0");// (to this line) */

   //comment out for data (from first line)
   /*    hElec1Phi->SetMarkerColor(kBlack);
      hElec1Phi->SetMarkerSize(1.0); //type TMarker root into google
      hElec1Phi->SetMarkerStyle(20);//type TMarker root into google
      hElec1Phi->SetLineColor(kBlack); //TColour into google
      hElec1Phi->Draw(); //(to this line) */

TPaveText* ptext17 = new TPaveText(0.5, 0.3, 0.7, 0.45, "NDC");
   TText *t49=ptext17->AddText("#it{ATLAS} #bf{Preliminary}");
   TText *t50=ptext17->AddText("#bf{#sqrt{s} = 13 TeV (2015)}");
   TText *t51=ptext17->AddText("#bf{Z #rightarrow e^{-}e^{+}}");
   //   ptext17->SetFillStyle(0); //put this in a comment for MC
   // ptext17->SetBorderSize(0);  //put this in a comment for MC
   ptext17->Draw();




   //for Elec2Pt
TCanvas *c8 = new TCanvas("hElec2Pt","",50,44,800,600); //for hElec2Pt (data or MC)
   hElec2Pt ->GetYaxis()->SetTitle("Number of events");
   hElec2Pt->GetYaxis()->SetTitleOffset(1.5); //this line shifts the position of the y axis title further away from the axis
   hElec2Pt->GetXaxis()->SetTitle("Electron Candidate 2 P_{T}");
   hElec2Pt->SetTitle("Electron Candidate 2 P_{T} Distribution");
 
   //comment out for MC (from first line)
      hElec2Pt->SetLineColor(kBlue); //TColour into google
      hElec2Pt->SetFillColor(kBlue);
      hElec2Pt->Draw("bar0"); //(to this line) */

   //comment out for data (from first line)
   /*    hElec2Pt->SetMarkerColor(kBlack);
      hElec2Pt->SetMarkerSize(1.0); //type TMarker root into google
      hElec2Pt->SetMarkerStyle(20);//type TMarker root into google
      hElec2Pt->SetLineColor(kBlack); //TColour into google
      hElec2Pt->Draw(); //(to this line) */

 TPaveText* ptext18 = new TPaveText(0.5, 0.4, 0.7, 0.55, "NDC");
   TText *t52=ptext18->AddText("#it{ATLAS} #bf{Preliminary}");
   TText *t53=ptext18->AddText("#bf{#sqrt{s} = 13 TeV (2015)}");
   TText *t54=ptext18->AddText("#bf{Z #rightarrow e^{-}e^{+}}");
   ptext18->SetFillStyle(0);
   ptext18->SetBorderSize(0);
   ptext18->Draw();




   //for Elec2Eta
TCanvas *c9 = new TCanvas("hElec2Eta","",50,44,800,600); //for hElec2Eta (data or MC)
   hElec2Eta->GetYaxis()->SetTitle("Number of events");
   hElec2Eta->GetYaxis()->SetTitleOffset(1.5); //this line shifts the position of the y axis title further away from the axis
   hElec2Eta->GetXaxis()->SetTitle("Electron Candidate 2 #eta");
   hElec2Eta->SetTitle("Electron Candidate 2 #eta Distribution");
 
   //comment out for MC (from first line)
    hElec2Eta->SetLineColor(kBlue); //TColour into google
      hElec2Eta->SetFillColor(kBlue);
      hElec2Eta->Draw("bar0"); //(to this line) */

   //comment out for data (from first line)
   /*   hElec2Eta->SetMarkerColor(kBlack);
      hElec2Eta->SetMarkerSize(1.0); //type TMarker root into google
      hElec2Eta->SetMarkerStyle(20);//type TMarker root into google
      hElec2Eta->SetLineColor(kBlack); //TColour into google
      hElec2Eta->Draw(); //(to this line) */


   TPaveText* ptext19 = new TPaveText(0.65, 0.65, 0.85, 0.85, "NDC");
   TText *t55=ptext19->AddText("#it{ATLAS} #bf{Preliminary}");
   TText *t56=ptext19->AddText("#bf{#sqrt{s} = 13 TeV (2015)}");
   TText *t57=ptext19->AddText("#bf{Z #rightarrow e^{-}e^{+}}");
   ptext19->SetFillStyle(0);
   ptext19->SetBorderSize(0);
   ptext19->Draw();





   //for Elec2Phi
TCanvas *c10 = new TCanvas("hElec2Phi","",50,44,800,600); //for hElec2Phi (data or MC)
   hElec2Phi->GetYaxis()->SetTitle("Number of events");
   hElec2Phi->GetYaxis()->SetTitleOffset(1.5); //this line shifts the position of the y axis title further away from the axis
   hElec2Phi->GetXaxis()->SetTitle("Electron Candidate 2 #phi");
   hElec2Phi->SetTitle("Electron Candidate 2 #phi Distribution");
 
   //comment out for MC (from first line)
     hElec2Phi->SetLineColor(kBlue); //TColour into google
      hElec2Phi->SetFillColor(kBlue);
      hElec2Phi->Draw("bar0"); //(to this line) */

   //comment out for data (from first line)
   /*   hElec2Phi->SetMarkerColor(kBlack);
      hElec2Phi->SetMarkerSize(1.0); //type TMarker root into google
      hElec2Phi->SetMarkerStyle(20);//type TMarker root into google
      hElec2Phi->SetLineColor(kBlack); //TColour into google
      hElec2Phi->Draw(); //(to this line) */



   TPaveText* ptext20 = new TPaveText(0.5, 0.3, 0.7, 0.45, "NDC");
   TText *t58=ptext20->AddText("#it{ATLAS} #bf{Preliminary}");
   TText *t59=ptext20->AddText("#bf{#sqrt{s} = 13 TeV (2015)}");
   TText *t60=ptext20->AddText("#bf{Z #rightarrow e^{-}e^{+}}");
   // ptext20->SetFillStyle(0); //put this in a comment for MC
   // ptext20->SetBorderSize(0); //put this in a comment for MC
   ptext20->Draw();




//for Z Mass 2

TCanvas *c11 = new TCanvas("hZMass2","",50,44,800,600); //for hZMass2 (data or MC)
   hZMass2 ->GetYaxis()->SetTitle("Number of events/1 GeV");
   hZMass2->GetYaxis()->SetTitleOffset(1.5); //this line shifts the position of the y axis title further away from the axis
   hZMass2 ->GetXaxis()->SetTitle("Z Boson Mass [eV]");
   hZMass2 ->SetTitle("M_{Z} Distribution");
 
   //comment out for MC (from first line)
     hZMass2->SetLineColor(kBlue); //TColour into google
      hZMass2->SetFillColor(kBlue);
      hZMass2->Draw("bar0"); //(to this line) */

   //comment out for data (from first line)
   /*   hZMass2->SetMarkerColor(kBlack);
      hZMass2->SetMarkerSize(1.0); //type TMarker root into google
      hZMass2->SetMarkerStyle(20);//type TMarker root into google
      hZMass2->SetLineColor(kBlack); //TColour into google
      hZMass2->Draw(); //(to this line) */

 

   TPaveText* ptext21 = new TPaveText(0.6, 0.6, 0.8, 0.8, "NDC");
   TText *t61=ptext21->AddText("#it{ATLAS} #bf{Preliminary}");
   TText *t62=ptext21->AddText("#bf{#sqrt{s} = 13 TeV (2015)}");
   TText *t63=ptext21->AddText("#bf{Z #rightarrow e^{-}e^{+}}");
   ptext21->SetFillStyle(0);
   ptext21->SetBorderSize(0);
   ptext21->Draw();




      //for ZPtD2
TCanvas *c12 = new TCanvas("hZPtD2","",50,44,800,600); //for hZPtD2 (data or MC)
   hZPtD2 ->GetYaxis()->SetTitle("Number of events/1 GeV");
   hZPtD2->GetYaxis()->SetTitleOffset(1.5); //this line shifts the position of the y axis title further away from the axis
   hZPtD2 ->GetXaxis()->SetTitle("Z Boson P_{T} [eV]");
   hZPtD2 ->SetTitle("Z Boson P_{T} Distribution");
 
   //comment out for MC (from first line)
     hZPtD2->SetLineColor(kBlue); //TColour into google
      hZPtD2->SetFillColor(kBlue);
      hZPtD2->Draw("bar0"); //(to this line) */

   //comment out for data (from first line)
   /*   hZPtD2->SetMarkerColor(kBlack);
      hZPtD2->SetMarkerSize(1.0); //type TMarker root into google
      hZPtD2->SetMarkerStyle(20);//type TMarker root into google
      hZPtD2->SetLineColor(kBlack); //TColour into google
      hZPtD2->Draw(); //(to this line) */


   TPaveText* ptext22 = new TPaveText(0.5, 0.4, 0.7, 0.55, "NDC");
   TText *t64=ptext22->AddText("#it{ATLAS} #bf{Preliminary}");
   TText *t65=ptext22->AddText("#bf{#sqrt{s} = 13 TeV (2015)}");
   TText *t66=ptext22->AddText("#bf{Z #rightarrow e^{-}e^{+}}");
   ptext22->SetFillStyle(0);
   ptext22->SetBorderSize(0);
   ptext22->Draw();



      //for ZEtaD2
TCanvas *c13 = new TCanvas("hZEtaD2","",50,44,800,600); //for hZEtaD2 (data or MC)
   hZEtaD2 ->GetYaxis()->SetTitle("Number of events");
   hZEtaD2->GetYaxis()->SetTitleOffset(1.5); //this line shifts the position of the y axis title further away from the axis
   hZEtaD2 ->GetXaxis()->SetTitle("Z Boson #eta");
   hZEtaD2 ->SetTitle("Z Boson #eta Distribution");
 
   //comment out for MC (from first line)
     hZEtaD2->SetLineColor(kBlue); //TColour into google
      hZEtaD2->SetFillColor(kBlue);
      hZEtaD2->Draw("bar0"); //(to this line) */

   //comment out for data (from first line)
   /*    hZEtaD2->SetMarkerColor(kBlack);
      hZEtaD2->SetMarkerSize(1.0); //type TMarker root into google
      hZEtaD2->SetMarkerStyle(20);//type TMarker root into google
      hZEtaD2->SetLineColor(kBlack); //TColour into google
      hZEtaD2->Draw(); //(to this line) */

   TPaveText* ptext23 = new TPaveText(0.65, 0.65, 0.85, 0.85, "NDC");
   TText *t67=ptext23->AddText("#it{ATLAS} #bf{Preliminary}");
   TText *t68=ptext23->AddText("#bf{#sqrt{s} = 13 TeV (2015)}");
   TText *t69=ptext23->AddText("#bf{Z #rightarrow e^{-}e^{+}}");
   ptext23->SetFillStyle(0);
   ptext23->SetBorderSize(0);
   ptext23->Draw();








   //for ZPhiD2
TCanvas *c14 = new TCanvas("hZPhiD2","",50,44,800,600); //for hZPhiD2 (data or MC)
   hZPhiD2 ->GetYaxis()->SetTitle("Number of events");
   hZPhiD2->GetYaxis()->SetTitleOffset(1.5); //this line shifts the position of the y axis title further away from the axis
   hZPhiD2 ->GetXaxis()->SetTitle("Z Boson #phi");
   hZPhiD2 ->SetTitle("Z Boson #phi Distribution");
 
   //comment out for MC (from first line)
     hZPhiD2->SetLineColor(kBlue); //TColour into google
      hZPhiD2->SetFillColor(kBlue);
      hZPhiD2->Draw("bar0");// (to this line) */

   //comment out for data (from first line)
   /*  hZPhiD2->SetMarkerColor(kBlack);
      hZPhiD2->SetMarkerSize(1.0); //type TMarker root into google
      hZPhiD2->SetMarkerStyle(20);//type TMarker root into google
      hZPhiD2->SetLineColor(kBlack); //TColour into google
      hZPhiD2->Draw(); //(to this line) */

  TPaveText* ptext24 = new TPaveText(0.5, 0.3, 0.7, 0.45, "NDC");
   TText *t70=ptext24->AddText("#it{ATLAS} #bf{Preliminary}");
   TText *t71=ptext24->AddText("#bf{#sqrt{s} = 13 TeV (2015)}");
   TText *t72=ptext24->AddText("#bf{Z #rightarrow e^{-}e^{+}}");
   // ptext24->SetFillStyle(0); //put this in a comment for MC
   // ptext24->SetBorderSize(0);  //put this in a comment for MC
   ptext24->Draw();






   //for ElCand1Pt
TCanvas *c15 = new TCanvas("hElCand1Pt","",50,44,800,600); //for hElCand1Pt (data or MC)
   hElCand1Pt ->GetYaxis()->SetTitle("Number of events");
   hElCand1Pt->GetYaxis()->SetTitleOffset(1.5); //this line shifts the position of the y axis title further away from the axis
   hElCand1Pt->GetXaxis()->SetTitle("Electron Candidate 1 P_{T}");
   hElCand1Pt->SetTitle("Electron Candidate 1 P_{T} Distribution");
 
   //comment out for MC (from first line)
    hElCand1Pt->SetLineColor(kBlue); //TColour into google
      hElCand1Pt->SetFillColor(kBlue);
      hElCand1Pt->Draw("bar0"); //(to this line) */

   //comment out for data (from first line)
   /*   hElCand1Pt->SetMarkerColor(kBlack);
      hElCand1Pt->SetMarkerSize(1.0); //type TMarker root into google
      hElCand1Pt->SetMarkerStyle(20);//type TMarker root into google
      hElCand1Pt->SetLineColor(kBlack); //TColour into google
      hElCand1Pt->Draw(); //(to this line) */


 TPaveText* ptext25 = new TPaveText(0.5, 0.4, 0.7, 0.55, "NDC");
   TText *t73=ptext25->AddText("#it{ATLAS} #bf{Preliminary}");
   TText *t74 =ptext25->AddText("#bf{#sqrt{s} = 13 TeV (2015)}");
   TText *t75=ptext25->AddText("#bf{Z #rightarrow e^{-}e^{+}}");
   ptext25->SetFillStyle(0);
   ptext25->SetBorderSize(0);
   ptext25->Draw();




   //for ElCand1Eta
TCanvas *c16 = new TCanvas("hElCand1Eta","",50,44,800,600); //for hElCand1Eta (data or MC)
   hElCand1Eta->GetYaxis()->SetTitle("Number of events");
   hElCand1Eta->GetYaxis()->SetTitleOffset(1.5); //this line shifts the position of the y axis title further away from the axis
   hElCand1Eta->GetXaxis()->SetTitle("Electron Candidate 1 #eta");
   hElCand1Eta->SetTitle("Electron Candidate 1 #eta Distribution");
 
   //comment out for MC (from first line)
     hElCand1Eta->SetLineColor(kBlue); //TColour into google
      hElCand1Eta->SetFillColor(kBlue);
      hElCand1Eta->Draw("bar0"); //(to this line) */

   //comment out for data (from first line)
   /*   hElCand1Eta->SetMarkerColor(kBlack);
      hElCand1Eta->SetMarkerSize(1.0); //type TMarker root into google
      hElCand1Eta->SetMarkerStyle(20);//type TMarker root into google
      hElCand1Eta->SetLineColor(kBlack); //TColour into google
      hElCand1Eta->Draw(); //(to this line) */



   TPaveText* ptext26 = new TPaveText(0.65, 0.65, 0.85, 0.85, "NDC");
   TText *t76=ptext26->AddText("#it{ATLAS} #bf{Preliminary}");
   TText *t77=ptext26->AddText("#bf{#sqrt{s} = 13 TeV (2015)}");
   TText *t78=ptext26->AddText("#bf{Z #rightarrow e^{-}e^{+}}");
   ptext26->SetFillStyle(0);
   ptext26->SetBorderSize(0);
   ptext26->Draw();





   //for ElCand1Phi
TCanvas *c17 = new TCanvas("hElCand1Phi","",50,44,800,600); //for hElCand1Phi (data or MC)
   hElCand1Phi->GetYaxis()->SetTitle("Number of events");
   hElCand1Phi->GetYaxis()->SetTitleOffset(1.5); //this line shifts the position of the y axis title further away from the axis
   hElCand1Phi->GetXaxis()->SetTitle("Electron Candidate 1 #phi");
   hElCand1Phi->SetTitle("Electron Candidate 1 #phi Distribution");
 
   //comment out for MC (from first line)
    hElCand1Phi->SetLineColor(kBlue); //TColour into google
      hElCand1Phi->SetFillColor(kBlue);
      hElCand1Phi->Draw("bar0"); //(to this line) */

   //comment out for data (from first line)
   /*    hElCand1Phi->SetMarkerColor(kBlack);
      hElCand1Phi->SetMarkerSize(1.0); //type TMarker root into google
      hElCand1Phi->SetMarkerStyle(20);//type TMarker root into google
      hElCand1Phi->SetLineColor(kBlack); //TColour into google
      hElCand1Phi->Draw(); //(to this line) */

 TPaveText* ptext27 = new TPaveText(0.5, 0.3, 0.7, 0.45, "NDC");
   TText *t79=ptext27->AddText("#it{ATLAS} #bf{Preliminary}");
   TText *t80=ptext27->AddText("#bf{#sqrt{s} = 13 TeV (2015)}");
   TText *t81=ptext27->AddText("#bf{Z #rightarrow e^{-}e^{+}}");
   //  ptext27->SetFillStyle(0); //put this in a comment for MC
   // ptext27->SetBorderSize(0);  //put this in a comment for MC
   ptext27->Draw();





   //for ElCand2Pt
TCanvas *c18 = new TCanvas("hElCand2Pt","",50,44,800,600); //for hElCand2Pt (data or MC)
   hElCand2Pt ->GetYaxis()->SetTitle("Number of events");
   hElCand2Pt->GetYaxis()->SetTitleOffset(1.5); //this line shifts the position of the y axis title further away from the axis
   hElCand2Pt->GetXaxis()->SetTitle("Electron Candidate 1 P_{T}");
   hElCand2Pt->SetTitle("Electron Candidate 1 P_{T} Distribution");
 
   //comment out for MC (from first line)
     hElCand2Pt->SetLineColor(kBlue); //TColour into google
      hElCand2Pt->SetFillColor(kBlue);
      hElCand2Pt->Draw("bar0");// (to this line) */

   //comment out for data (from first line)
   /*  hElCand2Pt->SetMarkerColor(kBlack);
      hElCand2Pt->SetMarkerSize(1.0); //type TMarker root into google
      hElCand2Pt->SetMarkerStyle(20);//type TMarker root into google
      hElCand2Pt->SetLineColor(kBlack); //TColour into google
      hElCand2Pt->Draw(); //(to this line) */


 TPaveText* ptext28 = new TPaveText(0.5, 0.4, 0.7, 0.55, "NDC");
   TText *t82=ptext28->AddText("#it{ATLAS} #bf{Preliminary}");
   TText *t83=ptext28->AddText("#bf{#sqrt{s} = 13 TeV (2015)}");
   TText *t84=ptext28->AddText("#bf{Z #rightarrow e^{-}e^{+}}");
   ptext28->SetFillStyle(0);
   ptext28->SetBorderSize(0);
   ptext28->Draw();






   //for ElCand2Eta
TCanvas *c19 = new TCanvas("hElCand2Eta","",50,44,800,600); //for hElCand2Eta (data or MC)
   hElCand2Eta->GetYaxis()->SetTitle("Number of events");
   hElCand2Eta->GetYaxis()->SetTitleOffset(1.5); //this line shifts the position of the y axis title further away from the axis
   hElCand2Eta->GetXaxis()->SetTitle("Electron Candidate 2 #eta");
   hElCand2Eta->SetTitle("Electron Candidate 2 #eta Distribution");
 
   //comment out for MC (from first line)
    hElCand2Eta->SetLineColor(kBlue); //TColour into google
      hElCand2Eta->SetFillColor(kBlue);
      hElCand2Eta->Draw("bar0"); //(to this line) */

   //comment out for data (from first line)
   /*    hElCand2Eta->SetMarkerColor(kBlack);
      hElCand2Eta->SetMarkerSize(1.0); //type TMarker root into google
      hElCand2Eta->SetMarkerStyle(20);//type TMarker root into google
      hElCand2Eta->SetLineColor(kBlack); //TColour into google
      hElCand2Eta->Draw(); //(to this line) */



   TPaveText* ptext29 = new TPaveText(0.65, 0.65, 0.85, 0.85, "NDC");
   TText *t85=ptext29->AddText("#it{ATLAS} #bf{Preliminary}");
   TText *t86=ptext29->AddText("#bf{#sqrt{s} = 13 TeV (2015)}");
   TText *t87=ptext29->AddText("#bf{Z #rightarrow e^{-}e^{+}}");
   ptext29->SetFillStyle(0);
   ptext29->SetBorderSize(0);
   ptext29->Draw();






   //for ElCand2Phi
TCanvas *c20 = new TCanvas("hElCand2Phi","",50,44,800,600); //for hElCand2Phi (data or MC)
   hElCand2Phi->GetYaxis()->SetTitle("Number of events");
   hElCand2Phi->GetYaxis()->SetTitleOffset(1.5); //this line shifts the position of the y axis title further away from the axis
   hElCand2Phi->GetXaxis()->SetTitle("Electron Candidate 2 #phi");
   hElCand2Phi->SetTitle("Electron Candidate 2 #phi Distribution");
 
   //comment out for MC (from first line)
      hElCand2Phi->SetLineColor(kBlue); //TColour into google
      hElCand2Phi->SetFillColor(kBlue);
      hElCand2Phi->Draw("bar0"); //(to this line) */

   //comment out for data (from first line)
   /*   hElCand2Phi->SetMarkerColor(kBlack);
      hElCand2Phi->SetMarkerSize(1.0); //type TMarker root into google
      hElCand2Phi->SetMarkerStyle(20);//type TMarker root into google
      hElCand2Phi->SetLineColor(kBlack); //TColour into google
      hElCand2Phi->Draw(); //(to this line) */


  TPaveText* ptext30 = new TPaveText(0.5, 0.3, 0.7, 0.45, "NDC");
   TText *t88=ptext30->AddText("#it{ATLAS} #bf{Preliminary}");
   TText *t89=ptext30->AddText("#bf{#sqrt{s} = 13 TeV (2015)}");
   TText *t90=ptext30->AddText("#bf{Z #rightarrow e^{-}e^{+}}");
   //  ptext30->SetFillStyle(0); //put this in a comment for MC
   // ptext30->SetBorderSize(0);  //put this in a comment for MC
   ptext30->Draw();
















//for Z MassNoCut

TCanvas *c21 = new TCanvas("hZMassNoCut","",50,44,800,600); //for hZMassNoCut (data or MC)
   hZMassNoCut ->GetYaxis()->SetTitle("Number of events/1 GeV");
   hZMassNoCut->GetYaxis()->SetTitleOffset(1.5); //this line shifts the position of the y axis title further away from the axis
   hZMassNoCut ->GetXaxis()->SetTitle("Z Boson Mass [eV]");
   hZMassNoCut ->SetTitle("M_{Z} Distribution");
 
   //comment out for MC (from first line)
      hZMassNoCut ->SetLineColor(kBlue); //TColour into google
      hZMassNoCut ->SetFillColor(kBlue);
      hZMassNoCut ->Draw("bar0"); //(to this line) */

   //comment out for data (from first line)
   /*      hZMassNoCut->SetMarkerColor(kBlack);
      hZMassNoCut->SetMarkerSize(1.0); //type TMarker root into google
      hZMassNoCut->SetMarkerStyle(20);//type TMarker root into google
      hZMassNoCut->SetLineColor(kBlack); //TColour into google
      hZMassNoCut->Draw(); //(to this line) */

  TPaveText* ptext1 = new TPaveText(0.4, 0.4, 0.6, 0.6, "NDC");
   TText *t1=ptext1->AddText("#it{ATLAS} #bf{Preliminary}");
   TText *t2=ptext1->AddText("#bf{#sqrt{s} = 13 TeV (2015)}");
   TText *t3=ptext1->AddText("#bf{Z #rightarrow e^{-}e^{+}}");
   ptext1->SetFillStyle(0);
   ptext1->SetBorderSize(0);
   ptext1->Draw();


      //for ZPtNoCut 
TCanvas *c22 = new TCanvas("hZPtNoCut","",50,44,800,600); //for hZPtNoCut (data or MC)
   hZPtNoCut->GetYaxis()->SetTitle("Number of events/1 GeV");
   hZPtNoCut->GetYaxis()->SetTitleOffset(1.5); //this line shifts the position of the y axis title further away from the axis
   hZPtNoCut->GetXaxis()->SetTitle("Z Boson P_{T} [eV]");
   hZPtNoCut->SetTitle("Z Boson P_{T} Distribution");
 
   //comment out for MC (from first line)
    hZPtNoCut->SetLineColor(kBlue); //TColour into google
      hZPtNoCut ->SetFillColor(kBlue);
      hZPtNoCut ->Draw("bar0"); //(to this line) */

   //comment out for data (from first line)
   /*   hZPtNoCut ->SetMarkerColor(kBlack);
      hZPtNoCut ->SetMarkerSize(1.0); //type TMarker root into google
      hZPtNoCut ->SetMarkerStyle(20);//type TMarker root into google
      hZPtNoCut ->SetLineColor(kBlack); //TColour into google
      hZPtNoCut ->Draw(); //(to this line) */



   TPaveText* ptext2 = new TPaveText(0.5, 0.4, 0.7, 0.55, "NDC");
   TText *t4=ptext2->AddText("#it{ATLAS} #bf{Preliminary}");
   TText *t5=ptext2->AddText("#bf{#sqrt{s} = 13 TeV (2015)}");
   TText *t6=ptext2->AddText("#bf{Z #rightarrow e^{-}e^{+}}");
   ptext2->SetFillStyle(0);
   ptext2->SetBorderSize(0);
   ptext2->Draw();




      //for ZEtaNoCut 
TCanvas *c23 = new TCanvas("hZEtaNoCut","",50,44,800,600); //for hZEtaNoCut (data or MC)
   hZEtaNoCut  ->GetYaxis()->SetTitle("Number of events");
   hZEtaNoCut ->GetYaxis()->SetTitleOffset(1.5); //this line shifts the position of the y axis title further away from the axis
   hZEtaNoCut  ->GetXaxis()->SetTitle("Z Boson #eta");
   hZEtaNoCut  ->SetTitle("Z Boson #eta Distribution");
 
   //comment out for MC (from first line)
     hZEtaNoCut ->SetLineColor(kBlue); //TColour into google
      hZEtaNoCut ->SetFillColor(kBlue);
      hZEtaNoCut ->Draw("bar0");// (to this line) */

   //comment out for data (from first line)
   /*    hZEtaNoCut ->SetMarkerColor(kBlack);
      hZEtaNoCut ->SetMarkerSize(1.0); //type TMarker root into google
      hZEtaNoCut ->SetMarkerStyle(20);//type TMarker root into google
      hZEtaNoCut ->SetLineColor(kBlack); //TColour into google
      hZEtaNoCut ->Draw(); //(to this line) */


 TPaveText* ptext3 = new TPaveText(0.65, 0.65, 0.85, 0.85, "NDC");
   TText *t7=ptext3->AddText("#it{ATLAS} #bf{Preliminary}");
   TText *t8=ptext3->AddText("#bf{#sqrt{s} = 13 TeV (2015)}");
   TText *t9=ptext3->AddText("#bf{Z #rightarrow e^{-}e^{+}}");
   ptext3->SetFillStyle(0);
   ptext3->SetBorderSize(0);
   ptext3->Draw();





   //for ZPhiNoCut 
TCanvas *c24 = new TCanvas("hZPhiNoCut","",50,44,800,600); //for hZPhiNoCut (data or MC)
   hZPhiNoCut  ->GetYaxis()->SetTitle("Number of events");
   hZPhiNoCut ->GetYaxis()->SetTitleOffset(1.5); //this line shifts the position of the y axis title further away from the axis
   hZPhiNoCut  ->GetXaxis()->SetTitle("Z Boson #phi");
   hZPhiNoCut  ->SetTitle("Z Boson #phi Distribution");
 
   //comment out for MC (from first line)
     hZPhiNoCut->SetLineColor(kBlue); //TColour into google
      hZPhiNoCut->SetFillColor(kBlue);
      hZPhiNoCut->Draw("bar0"); //(to this line) */

   //comment out for data (from first line)
   /*   hZPhiNoCut->SetMarkerColor(kBlack);
      hZPhiNoCut->SetMarkerSize(1.0); //type TMarker root into google
      hZPhiNoCut->SetMarkerStyle(20);//type TMarker root into google
      hZPhiNoCut->SetLineColor(kBlack); //TColour into google
      hZPhiNoCut->Draw(); //(to this line) */


   TPaveText* ptext4 = new TPaveText(0.5, 0.3, 0.7, 0.45, "NDC");
   TText *t10=ptext4->AddText("#it{ATLAS} #bf{Preliminary}");
   TText *t11=ptext4->AddText("#bf{#sqrt{s} = 13 TeV (2015)}");
   TText *t12=ptext4->AddText("#bf{Z #rightarrow e^{-}e^{+}}");
   //   ptext4->SetFillStyle(0); //put this in a comment for MC
   // ptext4->SetBorderSize(0);  //put this in a comment for MC
   ptext4->Draw();





   //for Elec1PtNoCut
TCanvas *c25 = new TCanvas("hElec1PtNoCut","",50,44,800,600); //for hElec1PtNoCut (data or MC)
   hElec1PtNoCut ->GetYaxis()->SetTitle("Number of events");
   hElec1PtNoCut->GetYaxis()->SetTitleOffset(1.5); //this line shifts the position of the y axis title further away from the axis
   hElec1PtNoCut->GetXaxis()->SetTitle("Electron Candidate 1 P_{T}");
   hElec1PtNoCut->SetTitle("Electron 1 P_{T} Distribution");
 
   //comment out for MC (from first line)
       hElec1PtNoCut->SetLineColor(kBlue); //TColour into google
      hElec1PtNoCut->SetFillColor(kBlue);
      hElec1PtNoCut->Draw("bar0"); //(to this line) */

   //comment out for data (from first line)
   /*  hElec1PtNoCut->SetMarkerColor(kBlack);
      hElec1PtNoCut->SetMarkerSize(1.0); //type TMarker root into google
      hElec1PtNoCut->SetMarkerStyle(20);//type TMarker root into google
      hElec1PtNoCut->SetLineColor(kBlack); //TColour into google
      hElec1PtNoCut->Draw(); //(to this line) */


   TPaveText* ptext5 = new TPaveText(0.5, 0.4, 0.7, 0.55, "NDC");
   TText *t13=ptext5->AddText("#it{ATLAS} #bf{Preliminary}");
   TText *t14=ptext5->AddText("#bf{#sqrt{s} = 13 TeV (2015)}");
   TText *t15=ptext5->AddText("#bf{Z #rightarrow e^{-}e^{+}}");
   ptext5->SetFillStyle(0);
   ptext5->SetBorderSize(0);
   ptext5->Draw();




   //for Elec1EtaNoCut
TCanvas *c26 = new TCanvas("hElec1EtaNoCut","",50,44,800,600); //for hElec1EtaNoCut (data or MC)
   hElec1EtaNoCut->GetYaxis()->SetTitle("Number of events");
   hElec1EtaNoCut->GetYaxis()->SetTitleOffset(1.5); //this line shifts the position of the y axis title further away from the axis
   hElec1EtaNoCut->GetXaxis()->SetTitle("Electron Candidate 1 #eta");
   hElec1EtaNoCut->SetTitle("Electron 1 #eta Distribution");
 
   //comment out for MC (from first line)
     hElec1EtaNoCut->SetLineColor(kBlue); //TColour into google
      hElec1EtaNoCut->SetFillColor(kBlue);
      hElec1EtaNoCut->Draw("bar0"); //(to this line) */

   //comment out for data (from first line)
   /*   hElec1EtaNoCut->SetMarkerColor(kBlack);
      hElec1EtaNoCut->SetMarkerSize(1.0); //type TMarker root into google
      hElec1EtaNoCut->SetMarkerStyle(20);//type TMarker root into google
      hElec1EtaNoCut->SetLineColor(kBlack); //TColour into google
      hElec1EtaNoCut->Draw(); //(to this line) */


   TPaveText* ptext6 = new TPaveText(0.4, 0.4, 0.6, 0.6, "NDC");
   TText *t16=ptext6->AddText("#it{ATLAS} #bf{Preliminary}");
   TText *t17=ptext6->AddText("#bf{#sqrt{s} = 13 TeV (2015)}");
   TText *t18=ptext6->AddText("#bf{Z #rightarrow e^{-}e^{+}}");
   //  ptext6->SetFillStyle(0); //put this in a comment for MC
   // ptext6->SetBorderSize(0);  //put this in a comment for MC
   ptext6->Draw();





   //for Elec1PhiNoCut
TCanvas *c27 = new TCanvas("hElec1PhiNoCut","",50,44,800,600); //for hElec1PhiNoCut (data or MC)
   hElec1PhiNoCut->GetYaxis()->SetTitle("Number of events");
   hElec1PhiNoCut->GetYaxis()->SetTitleOffset(1.5); //this line shifts the position of the y axis title further away from the axis
   hElec1PhiNoCut->GetXaxis()->SetTitle("Electron Candidate 1 #phi");
   hElec1PhiNoCut->SetTitle("Electron Candidate 1 #phi Distribution");
 
   //comment out for MC (from first line)
     hElec1PhiNoCut->SetLineColor(kBlue); //TColour into google
      hElec1PhiNoCut->SetFillColor(kBlue);
      hElec1PhiNoCut->Draw("bar0"); //(to this line) */

   //comment out for data (from first line)
   /*   hElec1PhiNoCut->SetMarkerColor(kBlack);
      hElec1PhiNoCut->SetMarkerSize(1.0); //type TMarker root into google
      hElec1PhiNoCut->SetMarkerStyle(20);//type TMarker root into google
      hElec1PhiNoCut->SetLineColor(kBlack); //TColour into google
      hElec1PhiNoCut->Draw(); //(to this line) */

 TPaveText* ptext7 = new TPaveText(0.5, 0.3, 0.7, 0.45, "NDC");
   TText *t19=ptext7->AddText("#it{ATLAS} #bf{Preliminary}");
   TText *t20=ptext7->AddText("#bf{#sqrt{s} = 13 TeV (2015)}");
   TText *t21=ptext7->AddText("#bf{Z #rightarrow e^{-}e^{+}}");
   //  ptext7->SetFillStyle(0); //put in comment for MC
   // ptext7->SetBorderSize(0);  //put in comment for MC
   ptext7->Draw();



   //for Elec2PtNoCut
TCanvas *c28 = new TCanvas("hElec2PtNoCut","",50,44,800,600); //for hElec2PtNoCut (data or MC)
   hElec2PtNoCut ->GetYaxis()->SetTitle("Number of events");
   hElec2PtNoCut->GetYaxis()->SetTitleOffset(1.5); //this line shifts the position of the y axis title further away from the axis
   hElec2PtNoCut->GetXaxis()->SetTitle("Electron Candidate 2 P_{T}");
   hElec2PtNoCut->SetTitle("Electron Candidate 2 P_{T} Distribution");
 
   //comment out for MC (from first line)
     hElec2PtNoCut->SetLineColor(kBlue); //TColour into google
      hElec2PtNoCut->SetFillColor(kBlue);
      hElec2PtNoCut->Draw("bar0"); //(to this line) */

   //comment out for data (from first line)
   /*   hElec2PtNoCut->SetMarkerColor(kBlack);
      hElec2PtNoCut->SetMarkerSize(1.0); //type TMarker root into google
      hElec2PtNoCut->SetMarkerStyle(20);//type TMarker root into google
      hElec2PtNoCut->SetLineColor(kBlack); //TColour into google
      hElec2PtNoCut->Draw(); //(to this line) */


   TPaveText* ptext8 = new TPaveText(0.5, 0.4, 0.7, 0.55, "NDC");
   TText *t22=ptext8->AddText("#it{ATLAS} #bf{Preliminary}");
   TText *t23=ptext8->AddText("#bf{#sqrt{s} = 13 TeV (2015)}");
   TText *t24=ptext8->AddText("#bf{Z #rightarrow e^{-}e^{+}}");
   ptext8->SetFillStyle(0);
   ptext8->SetBorderSize(0);
   ptext8->Draw();





   //for Elec2EtaNoCut
TCanvas *c29 = new TCanvas("hElec2EtaNoCut","",50,44,800,600); //for hElec2EtaNoCut (data or MC)
   hElec2EtaNoCut->GetYaxis()->SetTitle("Number of events");
   hElec2EtaNoCut->GetYaxis()->SetTitleOffset(1.5); //this line shifts the position of the y axis title further away from the axis
   hElec2EtaNoCut->GetXaxis()->SetTitle("Electron Candidate 2 #eta");
   hElec2EtaNoCut->SetTitle("Electron Candidate 2 #eta Distribution");
 
   //comment out for MC (from first line)
    hElec2EtaNoCut->SetLineColor(kBlue); //TColour into google
      hElec2EtaNoCut->SetFillColor(kBlue);
      hElec2EtaNoCut->Draw("bar0"); //(to this line) */

   //comment out for data (from first line)
   /*     hElec2EtaNoCut->SetMarkerColor(kBlack);
      hElec2EtaNoCut->SetMarkerSize(1.0); //type TMarker root into google
      hElec2EtaNoCut->SetMarkerStyle(20);//type TMarker root into google
      hElec2EtaNoCut->SetLineColor(kBlack); //TColour into google
      hElec2EtaNoCut->Draw(); //(to this line) */

  TPaveText* ptext9 = new TPaveText(0.4, 0.4, 0.6, 0.6, "NDC");
   TText *t25=ptext9->AddText("#it{ATLAS} #bf{Preliminary}");
   TText *t26=ptext9->AddText("#bf{#sqrt{s} = 13 TeV (2015)}");
   TText *t27=ptext9->AddText("#bf{Z #rightarrow e^{-}e^{+}}");
   //  ptext9->SetFillStyle(0); //put this in a comment for MC
   // ptext9->SetBorderSize(0); //put this in a comment for MC
   ptext9->Draw();




   //for Elec2PhiNoCut
TCanvas *c30 = new TCanvas("hElec2PhiNoCut","",50,44,800,600); //for hElec2PhiNoCut (data or MC)
   hElec2PhiNoCut->GetYaxis()->SetTitle("Number of events");
   hElec2PhiNoCut->GetYaxis()->SetTitleOffset(1.5); //this line shifts the position of the y axis title further away from the axis
   hElec2PhiNoCut->GetXaxis()->SetTitle("Electron Candidate 2 #phi");
   hElec2PhiNoCut->SetTitle("Electron Candidate 2 #phi Distribution");
 
   //comment out for MC (from first line)
    hElec2PhiNoCut->SetLineColor(kBlue); //TColour into google
      hElec2PhiNoCut->SetFillColor(kBlue);
      hElec2PhiNoCut->Draw("bar0"); //(to this line) */

   //comment out for data (from first line)
   /*   hElec2PhiNoCut->SetMarkerColor(kBlack);
      hElec2PhiNoCut->SetMarkerSize(1.0); //type TMarker root into google
      hElec2PhiNoCut->SetMarkerStyle(20);//type TMarker root into google
      hElec2PhiNoCut->SetLineColor(kBlack); //TColour into google
      hElec2PhiNoCut->Draw(); //(to this line) */

   TPaveText* ptext10 = new TPaveText(0.5, 0.3, 0.7, 0.45, "NDC");
   TText *t28=ptext10->AddText("#it{ATLAS} #bf{Preliminary}");
   TText *t29=ptext10->AddText("#bf{#sqrt{s} = 13 TeV (2015)}");
   TText *t30=ptext10->AddText("#bf{Z #rightarrow e^{-}e^{+}}");
   //  ptext10->SetFillStyle(0); //put this in a comment for MC
   // ptext10->SetBorderSize(0); //put this in a comment for MC
   ptext10->Draw();



        //for MC

      c1->SaveAs("Mass1MonteCarlo.pdf"); //for Z Mass (MC)
 c2->SaveAs("Pt1MonteCarlo.pdf"); //for Z Pt1 (MC)
 c3->SaveAs("Eta1MonteCarlo.pdf"); //for Z Eta 1 (MC)
 c4->SaveAs("Phi1MonteCarlo.pdf"); //for Z Phi 1 (MC)
 c5->SaveAs("Elec1PtMonteCarlo.pdf"); //for Elec1 Pt (MC)
 c6->SaveAs("Elec1EtaMonteCarlo.pdf"); //for Elec1 Eta (MC)
 c7->SaveAs("Elec1PhiMonteCarlo.pdf"); //for Elec1 Phi (MC)
 c8->SaveAs("Elec2PtMonteCarlo.pdf"); //for Elec2 Pt (MC)
 c9->SaveAs("Elec2EtaMonteCarlo.pdf"); //for Elec2 Eta (MC)
 c10->SaveAs("Elec2PhiMonteCarlo.pdf"); //for Elec2 Phi (MC)
 c11->SaveAs("Mass2MonteCarlo.pdf"); //for Z Mass (MC)
 c12->SaveAs("Pt2MonteCarlo.pdf"); //for Z Pt1 (MC)
 c13->SaveAs("Eta2MonteCarlo.pdf"); //for Z Eta 1 (MC)
 c14->SaveAs("Phi2MonteCarlo.pdf"); //for Z Phi 1 (MC)
 c15->SaveAs("ElCand1PtMonteCarlo.pdf"); //for ElCand1 Pt (MC)
 c16->SaveAs("ElCand1EtaMonteCarlo.pdf"); //for ElCand1 Eta (MC)
 c17->SaveAs("ElCand1PhiMonteCarlo.pdf"); //for ElCand1 Phi (MC)
 c18->SaveAs("ElCand2PtMonteCarlo.pdf"); //for ElCand2 Pt (MC)
 c19->SaveAs("ElCand2EtaMonteCarlo.pdf"); //for ElCand2 Eta (MC)
 c20->SaveAs("ElCand2PhiMonteCarlo.pdf"); //for ElCand2 Phi (MC)
 c21->SaveAs("MassNoCutMonteCarlo.pdf"); //for Z MassNoCut (MC)
 c22->SaveAs("PtNoCutMonteCarlo.pdf"); //for Z Pt NoCut(MC)
 c23->SaveAs("EtaNoCutMonteCarlo.pdf"); //for Z EtaNoCut  (MC)
 c24->SaveAs("PhiNoCutMonteCarlo.pdf"); //for Z PhiNoCut  (MC)
 c25->SaveAs("Elec1NoCutPtMonteCarlo.pdf"); //for Elec1 PtNoCut (MC)
 c26->SaveAs("Elec1NoCutEtaMonteCarlo.pdf"); //for Elec1 Eta NoCut (MC)
 c27->SaveAs("Elec1NoCutPhiMonteCarlo.pdf"); //for Elec1 Phi NoCut(MC)
 c28->SaveAs("Elec2NoCutPtMonteCarlo.pdf"); //for Elec2 Pt NoCut (MC)
 c29->SaveAs("Elec2NoCutEtaMonteCarlo.pdf"); //for Elec2 Eta NoCut (MC)
 c30->SaveAs("Elec2NoCutPhiMonteCarlo.pdf"); //for Elec2 Phi NoCut  (MC) */

      //for data
   /*  c1->SaveAs("Mass1Data.pdf"); //for Z Mass (data)
 c2->SaveAs("Pt1Data.pdf"); //for Z Pt1  (data)
 c3->SaveAs("Eta1Data.pdf"); //for Z Eta 1  (data)
 c4->SaveAs("Phi1Data.pdf"); //for Z Phi 1  (data)
 c5->SaveAs("Elec1PtData.pdf"); //for Elec1 Pt  (data)
 c6->SaveAs("Elec1EtaData.pdf"); //for Elec1 Eta (data) 
 c7->SaveAs("Elec1PhiData.pdf"); //for Elec1 Phi (data) 
 c8->SaveAs("Elec2PtData.pdf"); //for Elec2 Pt  (data)
 c9->SaveAs("Elec2EtaData.pdf"); //for Elec2 Eta  (data)
 c10->SaveAs("Elec2PhiData.pdf"); //for Elec2 Phi (data) 
 c11->SaveAs("Mass2Data.pdf"); //for Z Mass  (data)
 c12->SaveAs("Pt2Data.pdf"); //for Z Pt1  (data)
 c13->SaveAs("Eta2Data.pdf"); //for Z Eta 1  (data)
 c14->SaveAs("Phi2Data.pdf"); //for Z Phi 1 (data)
 c15->SaveAs("ElCand1PtData.pdf"); //for ElCand1 Pt  (data)
 c16->SaveAs("ElCand1EtaData.pdf"); //for ElCand1 Eta  (data)
 c17->SaveAs("ElCand1PhiData.pdf"); //for ElCand1 Phi  (data)
 c18->SaveAs("ElCand2PtData.pdf"); //for ElCand2 Pt  (data)
 c19->SaveAs("ElCand2EtaData.pdf"); //for ElCand2 Eta  (data)
 c20->SaveAs("ElCand2PhiData.pdf"); //for ElCand2 Phi  (data)
 c21->SaveAs("MassNoCutData.pdf"); //for Z MassNoCut  (data)
 c22->SaveAs("PtNoCutData.pdf"); //for Z Pt NoCut (data)
 c23->SaveAs("EtaNoCutData.pdf"); //for Z EtaNoCut   (data)
 c24->SaveAs("PhiNoCutData.pdf"); //for Z PhiNoCut   (data)
 c25->SaveAs("Elec1NoCutPtData.pdf"); //for Elec1 PtNoCut (data)
 c26->SaveAs("Elec1NoCutEtaData.pdf"); //for Elec1 Eta NoCut (data)
 c27->SaveAs("Elec1NoCutPhiData.pdf"); //for Elec1 Phi NoCut (data)
 c28->SaveAs("Elec2NoCutPtData.pdf"); //for Elec2 Pt NoCut  (data)
 c29->SaveAs("Elec2NoCutEtaData.pdf"); //for Elec2 Eta NoCut  (data)
 c30->SaveAs("Elec2NoCutPhiData.pdf"); //for Elec2 Phi NoCut  (data)  */
	
   file->Write();
}
