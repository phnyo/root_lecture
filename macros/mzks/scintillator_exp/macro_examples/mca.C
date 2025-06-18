
void mca(){

    auto hist = new TH1D("h", "h", 10, 0, 10);

    hist->SetBinContent(1, 4);
    hist->SetBinContent(5, 8);
    hist->SetBinContent(10, 2);
    hist->Draw();
}
