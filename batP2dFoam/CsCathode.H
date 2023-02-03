{
const double dr_cathode = Rs_cathode.value()/ns_cathodeR;// delta_r
const double dr_cathode2 = dr_cathode*dr_cathode;//delta_r square

double temp = 0.;
int diag_index = 0; 
// Assigning diagonal and off-diagonal coefficients 
for(label i=0; i<ns_cathode1D; i++) 
{
     for(label j=0; j<ns_cathodeR; j++)
     {
        double gn = runTime.deltaT().value()*Ds_cathode.value()/(j*j+j+1/3.0)/dr_cathode2 ;	     
	if(j==0)
	{
	temp = Cs_cathode[diag_index] + gn*(j+1)*(j+1)*(Cs_cathode_tmp[diag_index+1]-Cs_cathode_tmp[diag_index]);
	Cs_cathode_tmp[diag_index] =  relaxCathode * temp + omrelaxCathode *Cs_cathode[diag_index] ;
	}
	else if (j==(ns_cathodeR-1))
	{
	temp = Cs_cathode[diag_index] + gn*(j*j*(Cs_cathode_tmp[diag_index-1]-Cs_cathode_tmp[diag_index])) - gn*(j+1)*(j+1)*j_cathode[ns_sep1D+ ns_anode1D +i]/F.value()*dr_cathode/Ds_cathode.value();
	Cs_cathode_tmp[diag_index] =  relaxCathode * temp + omrelaxCathode *Cs_cathode[diag_index] ;
	}
	else
	{
	temp = Cs_cathode[diag_index] + gn*((j+1)*(j+1)*(Cs_cathode_tmp[diag_index+1]-Cs_cathode_tmp[diag_index]) + j*j*(Cs_cathode_tmp[diag_index-1]-Cs_cathode_tmp[diag_index]));
	Cs_cathode_tmp[diag_index] =  relaxCathode * temp + omrelaxCathode *Cs_cathode[diag_index] ;
	
	}
	diag_index ++;    
     }
} 



 
 
// from Cs get Css to calculate Ueq  
for(label i=0; i<ns_cathode1D; i++) 
{
Css[ns_sep1D+ ns_anode1D +i]= (3*Cs_cathode[i*ns_cathodeR+ns_cathodeR-1]-Cs_cathode[i*ns_cathodeR+ns_cathodeR-2])/2.0 ;
} 

//        Info<< "\n Cs_cathode:" << Cs_cathode << ' '; 

  double rErrCsCathode = average(mag((Cs_cathode_tmp - Cs_cathode)/Cs_cathode)) ;
     

        
     if (mag((rErrCsCathode_tmp - rErrCsCathode)/rErrCsCathode_tmp)<1e-3)
     {
     convergeCsCathode = true ;
     }
     
//     Info<< "\n convergeCsCathode:" << convergeCsCathode << nl;    
       
     rErrCsCathode_tmp = rErrCsCathode ;               
}

      

// ************************************************************************* //
