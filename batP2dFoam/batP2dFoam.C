/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2021 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is NOT part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Application
    batP2dFoam

Description
    Solver for the classical P2D model with porous electrode theory, Butler-Volmer 
    kinetics and concentrated solution theory. 

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"
#include "fvModels.H"
#include "fvConstraints.H"
#include "coordinateSystem.H"
#include "pimpleControl.H"
#include "simpleMatrix.H"
#include <vector>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
 //   #define NO_CONTROL
//    #define CREATE_MESH createMeshesPostProcess.H
    #include "postProcess.H"
    #include "setRootCaseLists.H"
    #include "createTime.H"
    #include "createMesh.H"
    pimpleControl pimple(mesh);
    #include "createFields.H"
    #include "readTimeControls.H"  
    #include "readMaxDiNo.H"
    
    // no solver residual output
    lduMatrix::debug=0;
    solverPerformance::debug=0;

    Info<< "\nStarting time loop\n" << endl;
    
        double jcsAnode = 1.0 ;
        double jcsCathode = 1.0 ;
    
    while (pimple.run(runTime))
    {    
        #include "setBatDeltaT.H"

        runTime++;    
        
        Info<< "Time = " << runTime.timeName() << nl << endl;  
        
        bool convergeCsAnode = false;  
        bool convergeCsCathode = false;    
        double rErrCsCathode_tmp = 1e-5;
        double rErrCsAnode_tmp = 1e-5;
        
    
    
               
        // --- PIMPLE loop    
        while(pimple.loop() || !convergeCsAnode ||!convergeCsAnode )
//        while(pimple.loop())
        {

		#include"setFields.H" 	    
		Info<< "\n=== Solving for electrolytePotential ===" << nl<< endl;   
		#include "electrolytePotential.H"	
	    

		Info<< "\n=== Solving for solidPotential ==="<< nl<< endl;        
		#include "solidPotential.H"
		

	    Info<< "\nSolving for Ce "<< nl<< endl;
	    #include "CeEqn.H" 
	    
    		#include"setFields.H" 	    
  	    Info<< "\nSolving for Cs_anode "<< nl<< endl;
	    #include "CsAnode.H"  
	    

  	    Info<< "\nSolving for Cs_cathode "<< nl<< endl;
	    #include "CsCathode.H"  

        }
	    #include "CsavEqn.H"  
	    
         jcsAnode = max(mag(Ueq_anodeprimecs)).value() ;
         jcsCathode = max(mag(Ueq_cathodeprimecs)).value() ;       
                
	Cs_anode = Cs_anode_tmp ;
	Cs_cathode = Cs_cathode_tmp ;	    
 
        U_terminal.push_back(fis[ns_anode1D+ns_sep1D+ns_cathode1D-1]);
        t_terminal.push_back(runTime.value());
        runTime.write();


    
    }
//    #include "outputU.H"
        Info << "fif : " << fif << nl << endl; 
        Info<< "Ce:" << Ce  << nl << endl; 
        Info << "fis : " << fis << nl << endl; 
        Info<< "Css:" << Css << nl << endl; 
        Info<< "\n Cs_anode:" << Cs_anode << ' '; 
        Info<< "\n Cs_cathode:" << Cs_cathode << ' '; 
        Info<< "\n Csav:" << Csav << ' ';  
        Info<< "j_anode:" << j_anode << nl << endl; 
        Info<< "j_cathode:" << j_cathode << nl << endl; 
        Info<< "Ueq_cathode:" << Ueq_cathode << nl << endl; 
        Info<< "soc_cathode:" << soc_cathode << nl << endl; 
        
                 
        Info<< "ExecutionTime = " << runTime.elapsedCpuTime() << " s"
            << "  ClockTime = " << runTime.elapsedClockTime() << " s" << nl << endl;
            
    Info<< "End\n" << endl;
    return 0;
    
}


// ************************************************************************* //
