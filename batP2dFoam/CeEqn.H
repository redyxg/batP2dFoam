{           
          fvModels.correct();
          Ce.storePrevIter();
	    fvScalarMatrix CeEqn
            (
                fvm::ddt(poro,Ce)
              - fvm::laplacian(De*Foam::pow(poro,brug), Ce)
              - ai*j/F*(1-transfNo)
       //      ==
       //         fvModels_anode.source(Ce_anode)
            );

            CeEqn.relax();
            fvConstraints.constrain(CeEqn);
            CeEqn.solve();
            fvConstraints.constrain(Ce);

}

// Info<< "Min/max Ce:" << min(Ce).value() << ' ' << max(Ce).value() << nl << endl;




// ************************************************************************* //
