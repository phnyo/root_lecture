TH1D * read_data(TString filename="data/sim_shower_events.root") {

  auto file = TFile::Open(filename);
  auto tree = dynamic_cast<TTree*>(file->Get("shower"));

  float zenith, azimuth;
  int num_particle, num_muon;

  tree->SetBranchAddress("zenith", &zenith);
  tree->SetBranchAddress("azimuth", &azimuth);
  tree->SetBranchAddress("num_particle", &num_particle);
  tree->SetBranchAddress("num_muon", &num_muon);

  long long entries = tree->GetEntries();

  const int nbin = 100;
  const int val_min = 0;
  const int val_max = 200;
  
  auto hist = new TH1D("hist", "hist", nbin, val_min, val_max);
  hist->SetTitle(";;");

  for (int i = 0; i < entries; i++) {
    tree->GetEntry(i);
    hist->Fill(num_particle, num_muon);
  }

  return hist;

}

void read_root_mult() {

  auto hist1 = read_data("data/sim_shower_events.root");
  auto hist2 = read_data("data/sim_shower_events_gamma.root");

  hist1->SetLineColor(kGreen);
  hist1->Draw();

  hist2->SetLineColor(kBlue);
  hist2->Draw("SAME");
}
