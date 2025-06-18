// ------------------------------ //
// others/math_function.C
// to show function definition
// ------------------------------ //

int math_functions(){

    const double range_min = 0.;
    const double range_max = 10.;

    auto func1 = new TF1("func1",
                         "[2]*x**2 + [1]*x + [0]",
                        range_min, range_max);
    func1->SetParameter(0, 2.); // for [0]
    func1->SetParameter(1, 3.); // for [1]
    func1->SetParameter(2, 1.02); // for [2]

    auto func2 = new TF1("func2",
                         "gaus(0) + expo(3)",
                         range_min, range_max);
    func2->SetParameters(50, 3, 1, 1, 1.02);

    auto func3 = new TF1("func3",
                         "20*TMath::Sin(x) + 30",
                         range_min, range_max);


    func1->Draw();
    func2->SetLineColor(kOrange);
    func2->Draw("same");
    func3->SetLineColor(kBlue);
    func3->Draw("same");

    return 0;
}
