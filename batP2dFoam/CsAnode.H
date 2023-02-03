{
const double dr_anode = Rs_anode.value()/ns_anodeR;// delta_r
const double dr_anode2 = dr_anode*dr_anode;//delta_r square

double temp = 0.;
int diag_index = 0; 
// Assigning diagonal and off-diagonal coefficients 
for(label i=0; i<ns_anode1D; i++) 
{
     for(label j=0; j<ns_anodeR; j++)
     {
        double gn = runTime.deltaT().value()*Ds_anode.value()/((j*j+j+1/3.0)*dr_anode2) ;
        
	if(j==0)
	{
	temp = Cs_anode[diag_index] + gn*(j+1)*(j+1)*(Cs_anode_tmp[diag_index+1]-Cs_anode_tmp[diag_index]);
	Cs_anode_tmp[diag_index] = relaxAnode * temp + omrelaxAnode *Cs_anode[diag_index];
	}
	else if (j==(ns_anodeR-1))
	{
	temp = Cs_anode[diag_index] + gn*(j*j*(Cs_anode_tmp[diag_index-1]-Cs_anode_tmp[diag_index])) - gn*(j+1)*(j+1)*j_anode[i]/F.value()*dr_anode/Ds_anode.value(); 
	Cs_anode_tmp[diag_index] = relaxAnode * temp + omrelaxAnode *Cs_anode[diag_index];
	}
	else
	{
	temp = Cs_anode[diag_index] + gn*((j+1)*(j+1)*(Cs_anode_tmp[diag_index+1]-Cs_anode_tmp[diag_index]) + j*j*(Cs_anode_tmp[diag_index-1]-Cs_anode_tmp[diag_index]));
	Cs_anode_tmp[diag_index] = relaxAnode * temp + omrelaxAnode *Cs_anode[diag_index];
	
	}
	diag_index ++;    
     }
} 


// from Cs get Css to calculate Ueq  
for(label i=0; i<ns_anode1D; i++) 
{
Css[i] =(3*Cs_anode[i*ns_anodeR+ns_anodeR-1]-Cs_anode[i*ns_anodeR+ns_anodeR-2])/2.0 ;
} 

//        Info<< "\n Cs_anode:" << Cs_anode << ' '; 

     double rErrCsAnode = average(mag((Cs_anode_tmp - Cs_anode)/Cs_anode)) ;

       
        
     if (mag((rErrCsAnode_tmp - rErrCsAnode)/rErrCsAnode_tmp)<1e-3)
     {
     convergeCsAnode = true ;
     }
     
//      Info<< "\n convergeCsAnode:" << convergeCsAnode << ' ';  
          
     rErrCsAnode_tmp = rErrCsAnode ;
                        
}

      

// ************************************************************************* //
