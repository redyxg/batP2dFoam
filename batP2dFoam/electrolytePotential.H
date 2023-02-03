{    
	   
        fif.storePrevIter();
        fvScalarMatrix fifEqn
        (
                 fvm::laplacian(kf*Foam::pow(poro,brug), fif)
		-fvc::laplacian(2*kf*Foam::pow(poro,brug)*R*T*(1-transfNo)/F/Ce, Ce) 
	       == - ai*j + ai_anode*fif*j_anodeprimefif   +   ai_anode*fvm::SuSp(-j_anodeprimefif,fif)	       
	                 + ai_cathode*fif*j_cathodeprimefif + ai_cathode*fvm::SuSp(-j_cathodeprimefif,fif)
	                 
        );
        
        fifEqn.relax();
	fvConstraints.constrain(fifEqn);	
        fifEqn.solve();
        fvConstraints.constrain(fif);
	

}


// Info<< "Min/max fif:" << min(fif).value() << ' '<< max(fif).value() << nl << endl;
