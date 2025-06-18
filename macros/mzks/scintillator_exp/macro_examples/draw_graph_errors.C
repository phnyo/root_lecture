// ---------------------------- //
// draw_graph_errors.C
// initial example to draw
// TGraphErrors
// ---------------------------- //

int draw_graph_errors(){
    gROOT->SetStyle("ATLAS");


    std::vector<double> x = {1,2,3,4};
    std::vector<double> y = {1,4,9,16};
    std::vector<double> x_err = {0.5, 0.5, 0.5, 0.5};
    std::vector<double> y_err = {1, 1.4, 1.7, 2};
    auto graph1 = new TGraphErrors(x.size(), x.data(), y.data(),
                            x_err.data(), y_err.data());

    auto graph2 = new TGraphErrors();
    for(int i=0; i<4; ++i){
        graph2->SetPoint(i, i+1, i*2);
        graph2->SetPointError(i, 0.5, TMath::Sqrt(i));
    }

    graph1->Draw("APE");
    graph2->SetMarkerColor(kRed);
    graph2->Draw("PE");

    return 0;
}
