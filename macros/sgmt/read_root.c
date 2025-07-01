void read_root(TString filename="data/sim_shower_events.root") {

  auto file = TFile::Open(filename);
  auto tree = dynamic_cast<TTree*>(file->Get("shower"));

  double zenith, azimuth;
  int num_particle, num_muon;

  tree->SetBranchAddress("zenith", &zenith);
  tree->SetBranchAddress("azimuth", &azimuth);
  tree->SetBranchAddress("num_particle", &num_particle);
  tree->SetBranchAddress("num_muon", &num_muon);

  long long entries = tree->GetEntries();

  const int nbin = 100;
  const int val_max = 200;
  const int val_min = 200;
  
  auto hist = new TH1D("hist", "hist", nbin, val_min, val_max);
  hist->SetTitle(";;");

  for (int i = 0; i < entries; i++) {
    tree->GetEntry(i);
    hist->Fill(num_particle);
  }
  hist->Draw();

}
