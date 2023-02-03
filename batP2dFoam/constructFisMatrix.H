label NC = mesh.nCells(); //Number of cells 
simpleMatrix<scalar> fisMatrix(NC); //Coeff.matrix 

// Initialization of matrix 
for(label i=0; i<NC; i++) 
{ 
	fisMatrix.source()[i] = 0.0; 
	for(label j=0; j<NC; j++) 
	{ 
	fisMatrix[i][j] = 0.0; 
	} 
}

// Assigning diagonal coefficients 
for(label i=0; i<NC; i++) 
{
	fisMatrix[i][i] = fisEqn.diag()[i];
} 


// Assigning off-diagonal coefficients 

for(label faceI=0; faceI<fisEqn.lduAddr().lowerAddr().size(); faceI++)
{
	label l = fisEqn.lduAddr().lowerAddr()[faceI]; 
	label u = fisEqn.lduAddr().upperAddr()[faceI]; 
	fisMatrix[l][u] = fisEqn.upper()[faceI]; 
	fisMatrix[u][l] = fisEqn.upper()[faceI];
}

// Assigning contribution from BC 
forAll(fis.boundaryField(), patchI) 
{ 
	const fvPatch &pp = fis.boundaryField()[patchI].patch();
	 forAll(pp, faceI) 
	 { 
	 label cellI = pp.faceCells()[faceI]; 
	 fisMatrix[cellI][cellI] += fisEqn.internalCoeffs()[patchI][faceI]; 
	 fisMatrix.source()[cellI] += fisEqn.boundaryCoeffs()[patchI][faceI]; 
	 } 
 } 
 
 
 
 
 Info << "\n==Coefficients of Matrix fis ==" << endl;
 
 
 for(label i=0; i<NC; i++) 
 {
	 for(label j=0; j<NC; j++)
 	 {
 	 Info << fisMatrix[i][j] << " ";
 	 }
 	 
 	 Info << fisMatrix.source()[i] << endl;
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
