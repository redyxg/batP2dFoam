{           
   
    	//  i0_anode = F*rateK_anode*Foam::pow(mag(Cs_anode_max - Css)*Css ,0.5)*is_anode;
    	  soc_anode =  (Css-Cs_anode_min)/(Cs_anode_max-Cs_anode_min);
	  Ueq_anode =  (0.7222 + 0.1387*soc_anode + 0.029*Foam::pow(soc_anode,0.5) - 0.0172/soc_anode + 0.0019/Foam::pow(soc_anode,1.5) + 0.2808*Foam::exp(0.9-15*soc_anode) - 0.7984*Foam::exp(0.4465*soc_anode-0.4108))*Uunit*is_anode;
	  eta_anode =  (fis - fif - Ueq_anode)*is_anode;	    
          j_anode = i0_anode*(Foam::exp(eta_anode/beta_a) - Foam::exp(eta_anode/beta_c));	   
          j_anodeprimefif = i0_anode*(-Foam::exp(eta_anode/beta_a)/beta_a + Foam::exp(eta_anode/beta_c)/beta_c)*is_anode;     
          j_anodeprimefis = i0_anode*(Foam::exp(eta_anode/beta_a)/beta_a - Foam::exp(eta_anode/beta_c)/beta_c)*is_anode;   
          j_anodeprimeUeq = j_anodeprimefif;
          Ueq_anodeprimecs = (0.1387+0.5*0.029*Foam::pow(soc_anode,-0.5)+0.0172*Foam::pow(soc_anode,-2)-1.5*0.0019*Foam::pow(soc_anode,-2.5)-15*0.2808*Foam::exp(0.9-15*soc_anode)-0.4465*0.7984*Foam::exp(0.4465*soc_anode-0.4108))/(Cs_anode_max-Cs_anode_min)*Uunit*is_anode; 
          j_anodeprimecs = j_anodeprimeUeq*Ueq_anodeprimecs;
          

        //  i0_cathode = F*rateK_cathode*Foam::pow(mag(Cs_cathode_max - Css)*Css ,0.5)*is_cathode;
    	  soc_cathode =  (Css-Cs_cathode_min)/(Cs_cathode_max-Cs_cathode_min) ;
          Ueq_cathode =  (4.04596+Foam::exp(-42.30027*soc_cathode+16.56714)-0.0488*Foam::atan(50.01833*soc_cathode-26.48897) -
    0.05447*Foam::atan(18.99678*soc_cathode-12.32362)-Foam::exp(78.240895*soc_cathode-78.68074))*Uunit*is_cathode ;
	  eta_cathode =  (fis - fif - Ueq_cathode)*is_cathode ;	    
          j_cathode = i0_cathode*(Foam::exp(eta_cathode/beta_a)-Foam::exp(eta_cathode/beta_c)) ; 
	  j_cathodeprimefif = i0_cathode*(-Foam::exp(eta_cathode/beta_a)/beta_a + Foam::exp(eta_cathode/beta_c)/beta_c)*is_cathode ;   
 	  j_cathodeprimefis = i0_cathode*(Foam::exp(eta_cathode/beta_a)/beta_a - Foam::exp(eta_cathode/beta_c)/beta_c)*is_cathode ;  	  
          j_cathodeprimeUeq = j_cathodeprimefif ;
	  Ueq_cathodeprimecs =
(-42.30027*Foam::exp(-42.30027*soc_cathode+16.56714)-0.0488/(1+Foam::pow(50.01833*soc_cathode-26.48897,2))*50.01833 - 
    0.05447*18.99678/(1+Foam::pow(18.99678*soc_cathode-12.32362,2))-78.240895*Foam::exp(78.240895*soc_cathode-78.68074))/(Cs_cathode_max-Cs_cathode_min)*Uunit*is_cathode ;	
	  j_cathodeprimecs = j_cathodeprimeUeq*Ueq_cathodeprimecs;

	  j = j_anode*is_anode + j_cathode*is_cathode ;
	  jprimefif = j_anodeprimefif*is_anode + j_cathodeprimefif*is_cathode ;
	  jprimefis = j_anodeprimefis*is_anode + j_cathodeprimefis*is_cathode ;

 //    Info<< "\n                             ------ Calculating source term j ------" << nl << endl;
 //    Info<< "                                       Min/max j_anode:" << min(j_anode.internalField()).value() << ' '    << max(j_anode.internalField()).value() << ' ' << ' ';
 //    Info<< "\n                                       Min/max j_cathode:" << min(j_cathode.internalField()).value() << ' ' << max(j_cathode.internalField()).value() << ' ';
 //     Info<< "\n                                ----------- ------ ------" << nl << endl;    
 
 
 //      Info<< "Min/max eta_cathode:" << min(eta_cathode).value() << ' '
//    << max(eta_cathode).value() << '\n';
    
 //    Info<< "\n j_anode:" << j_anode << ' ';
 //    Info<< "\n j_cathode:" << j_cathode << ' ';    
  //   Info<< "\n eta_cathode:" << eta_cathode << ' ';          
 //    Info<< "\n Ueq_cathode:" << Ueq_cathode << ' ';            
                
   //     Info<< " fis :" << nl << fis << nl << endl; 

}






// ************************************************************************* //
