{
    	 
	fis.storePrevIter();	
        fvScalarMatrix fisEqn
        (
                 fvm::laplacian(ks*Foam::pow(1-poro,brug), fis) 
		==
 		 ai*j - ai_anode*fis*j_anodeprimefis + ai_anode*fvm::SuSp(j_anodeprimefis,fis) 
 		      - ai_cathode*fis*j_cathodeprimefis + ai_cathode*fvm::SuSp(j_cathodeprimefis,fis)           
		 	
        );
               
 
	//  Find the sep. cell to exclude from calculation
        label cell1_ = mesh.findCell(position1_);
//	Info<< "Location " << position1_ << " is at the cell #" <<  cell1_ << "." << nl << endl; 
	label cell2_ = mesh.findCell(position2_);
//	Info<< "Location " << position2_ << " is at the cell #" <<  cell2_ << "." << nl << endl; 
  
	    
	//  Access lower, upper triangles and diagonal to modify
	    scalarField& lower_ = fisEqn.lower();
	    scalarField& upper_ = fisEqn.upper();
	    scalarField& diag_ = fisEqn.diag();
	  
	    	 

	   // right cell in anode. no flux between anode and separator	  
   	   diag_[cell1_-1] += upper_[cell1_-1]; 
   	   upper_[cell1_-1] = scalar(0);
           // separator region	   
   	   lower_[cell1_-1] = scalar(0); // left neighbour
	   fisEqn.source()[cell1_] = scalar(0);      	   
   	   
   	   // left cell in cathode. no flux between cathode and separator	 
   	   diag_[cell2_+1] += lower_[cell2_];   	   	 
   	   lower_[cell2_] = scalar(0);   	 
   	   // separator region  	     	   
      	   upper_[cell2_] = scalar(0); // right neighbour of right cell set as 0   	    	   
    	   fisEqn.source()[cell2_] = scalar(0);   	   
   	      
	   
        fisEqn.relax();
        fvConstraints.constrain(fisEqn);	        
        fisEqn.solve();
        fvConstraints.constrain(fis);

}

// Info<< "Min/max fis:" << min(fis).value() << ' '<< max(fis).value() << nl << endl;



