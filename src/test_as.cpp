 #include<iostream>
 #include<iomanip>
 #include<cmath>
 #include<complex>
 #include<string>
 #include<fstream> 
 
 #include"../include/alphas.h"
 



 int main(){ 
 //double mu;
 MSbarAlphaS AlphaS;
 //string schm;
 std::cout<<"-------------------- ▂▃▄▅▆▇█▓▒░MLiftBFKL 0.0.1░▒▓█▇▆▅▄▃▂ --------------------\n";
 std::cout<<"\n";
 std::ofstream mydataAS;
 mydataAS.open ("input/aS_generated_data.dat");
 
 std::cout<<"Test the running of Alpha strong coupling\n";
 std::cout<<"\n";
 
// std::cout<<"Energy Scale in GeV:";
 //std::cin>>mu;
 
 //cout<<"Number of loops running (1 or 2) :";
 //cin>>loop;
 //cout<<"Renormalization scheme (MSb or MOM) :";
 //cin>>schm;

 
 //std::cout.precision(17);
// cout<<"Running of Alpha strong couplings ="<<AlphaS.Run(mu,loop,schm)<<endl;
 
 double dataAS[40][2]={
                       {1.0,AlphaS.Run(1.0, 2)},{1.2,AlphaS.Run(1.2, 2)},{1.3,AlphaS.Run(1.3, 2)},{1.6,AlphaS.Run(1.6, 2)},
                       {1.9e0,AlphaS.Run(1.9, 2)},{2.7,AlphaS.Run(2.7, 2)},{3.2,AlphaS.Run(3.2, 2)},{3.8,AlphaS.Run(3.8, 2)},
                       {4.2,AlphaS.Run(4.2, 2)},{4.3,AlphaS.Run(4.3, 2)},{4.9,AlphaS.Run(4.9, 2)},{5.3,AlphaS.Run(5.3, 2)},
                       {6.9,AlphaS.Run(6.9, 2)},{7.3,AlphaS.Run(7.3, 2)},{10.,AlphaS.Run(10.9, 2)},{20.9,AlphaS.Run(20.9, 2)},
                       {30.9,AlphaS.Run(30.9, 2)},{50.9,AlphaS.Run(50.9, 2)},{70.9,AlphaS.Run(70.0, 2)},{110.9,AlphaS.Run(110.9, 2)},
                       {150.9,AlphaS.Run(150.9, 2)},{170.9,AlphaS.Run(170.9, 2)},{200.9,AlphaS.Run(200.9, 2)},{230.9,AlphaS.Run(230.9, 2)},
                       {250.9,AlphaS.Run(250.9, 2)},{300.9,AlphaS.Run(300.9, 2)},{350.9,AlphaS.Run(350.9, 2)},{400.9,AlphaS.Run(400.9, 2)},
                       {450.9,AlphaS.Run(450.9, 2)},{500.9,AlphaS.Run(500.9, 2)},{550.9,AlphaS.Run(550.9, 2)},{650.9,AlphaS.Run(650.9, 2)},
                       {850.9,AlphaS.Run(850.9, 2)},{1500.9,AlphaS.Run(1500.9, 2)},{2000.9,AlphaS.Run(2000.9, 2)},{3000.9,AlphaS.Run(3000.9, 2)},
                       {5000.9,AlphaS.Run(5000.9, 2)},{6000.9,AlphaS.Run(6000.9, 2)},{8000.9,AlphaS.Run(8000.9, 2)},{10000.9,AlphaS.Run(10000.9, 2)}
                       };
//  mydataAS<<"mu(energy scale)\t n-loop\t renormalization schame\t alpha_S\n";
 for(int i=0;i<=39;i++){
   
  // for(int j=0;j<=1;j++){

  //   mydataAS<<dataAS[i][0]<<"\t\t\t 2\t Msbar\t\t\t "<<std::setprecision(16)<<dataAS[i][1]<<std::endl;
       mydataAS<<dataAS[i][0]<<"  "<<std::setprecision(16)<<dataAS[i][1]<<std::endl;
  // }
 }   
 mydataAS.close();        
 
/* 
  for(int i=1;i<=200;i++){
   
  // for(int j=0;j<=1;j++){
     mydataAS<<i<<"  "<<std::setprecision(16)<<AlphaS.Run(i,2) <<std::endl;
  // }
   mydataAS.close(); 
 }    */
 
     //std::cout<<std::setprecision(16)<<AlphaS.Run(mu,2) <<std::endl;     
return 0;

 }
