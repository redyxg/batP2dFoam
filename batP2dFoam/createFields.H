Info<< "Reading field fif\n" << endl;

volScalarField fif
(
    IOobject
    (
        "fif",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field fis\n" << endl;

volScalarField fis
(
    IOobject
    (
        "fis",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field Csav\n" << endl;

volScalarField Csav
(
    IOobject
    (
        "Csav",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field Css\n" << endl;

volScalarField Css
(
    IOobject
    (
        "Css",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field Ce\n" << endl;

volScalarField Ce
(
    IOobject
    (
        "Ce",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);


Info<< "Reading field is_anode\n" << endl;

volScalarField is_anode
(
    IOobject
    (
        "is_anode",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field is_cathode\n" << endl;

volScalarField is_cathode
(
    IOobject
    (
        "is_cathode",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);



Info<< "Reading field kf\n" << endl;

volScalarField kf
(
    IOobject
    (
        "kf",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field ks\n" << endl;

volScalarField ks
(
    IOobject
    (
        "ks",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

Info<< "Reading field De\n" << endl;

volScalarField De
(
    IOobject
    (
        "De",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);


Info<< "Reading field poro\n" << endl;

volScalarField poro
(
    IOobject
    (
        "poro",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);



// pressureReference fifReference(fif, pimple.dict());



Info<< "Reading transportProperties\n" << endl;

IOdictionary transportProperties
(
    IOobject
    (
        "transportProperties",
        runTime.constant(),
        mesh,
        IOobject::MUST_READ_IF_MODIFIED,
        IOobject::NO_WRITE
    )
);


Info<< "Reading temperature T\n" << endl;

dimensionedScalar T
(
    transportProperties.lookup("T")
);

Info<< "Reading gas constant R\n" << endl;

dimensionedScalar R
(
    transportProperties.lookup("R")
);

Info<< "Reading Faraday constant F\n" << endl;

dimensionedScalar F
(
    transportProperties.lookup("F")
);

Info<< "Reading beta_a \n" << endl;

dimensionedScalar beta_a
(
    transportProperties.lookup("beta_a")
);

Info<< "Reading beta_c \n" << endl;

dimensionedScalar beta_c
(
    transportProperties.lookup("beta_c")
);


Info<< "Reading normalizer_fi \n" << endl;

dimensionedScalar normalizer_fi
(
    transportProperties.lookup("normalizer_fi")
);

Info<< "Reading Uunit \n" << endl;

dimensionedScalar Uunit
(
    transportProperties.lookup("Uunit")
);

Info<< "Reading Ds_anode \n" << endl;

dimensionedScalar Ds_anode
(
    transportProperties.lookup("Ds_anode")
);

Info<< "Reading Ds_cathode \n" << endl;

dimensionedScalar Ds_cathode
(
    transportProperties.lookup("Ds_cathode")
);

Info<< "Reading specific interfacial area ai_anode\n" << endl;

dimensionedScalar ai_anode
(
    transportProperties.lookup("ai_anode")
);

Info<< "Reading specific interfacial area ai_cathode\n" << endl;

dimensionedScalar ai_cathode
(
    transportProperties.lookup("ai_cathode")
);

Info<< "Reading radius of anode Rs_anode\n" << endl;

dimensionedScalar Rs_anode
(
    transportProperties.lookup("Rs_anode")
);

Info<< "Reading radius of cathode Rs_cathode\n" << endl;

dimensionedScalar Rs_cathode
(
    transportProperties.lookup("Rs_cathode")
);



Info<< "Reading maximum solid concentration of anode Cs_anode_max\n" << endl;

dimensionedScalar Cs_anode_max
(
    transportProperties.lookup("Cs_anode_max")
);

Info<< "Reading maximum solid concentration of anode Cs_cathode_max\n" << endl;

dimensionedScalar Cs_cathode_max
(
    transportProperties.lookup("Cs_cathode_max")
);

Info<< "Reading minimum solid concentration of anode Cs_anode_min\n" << endl;

dimensionedScalar Cs_anode_min
(
    transportProperties.lookup("Cs_anode_min")
);

Info<< "Reading minimum solid concentration of anode Cs_cathode_min\n" << endl;

dimensionedScalar Cs_cathode_min
(
    transportProperties.lookup("Cs_cathode_min")
);

Info<< "Reading initial solid concentration of anode Cs_anode0\n" << endl;

dimensionedScalar Cs_anode0
(
    transportProperties.lookup("Cs_anode0")
);

Info<< "Reading initial solid concentration of anode Cs_cathode0\n" << endl;

dimensionedScalar Cs_cathode0
(
    transportProperties.lookup("Cs_cathode0")
);

Info<< "Reading reaction rate constant of anode rateK_anode\n" << endl;

dimensionedScalar rateK_anode
(
    transportProperties.lookup("rateK_anode")
);

Info<< "Reading reaction rate constant of cathode rateK_cathode\n" << endl;

dimensionedScalar rateK_cathode
(
    transportProperties.lookup("rateK_cathode")
);

Info<< "Reading 1C current density oneC_i\n" << endl;

dimensionedScalar oneC_i
(
    transportProperties.lookup("oneC_i")
);


Info<< "Reading position of blocked cell \n" << endl;

vector position1_
(
    transportProperties.lookup("exclude1")
);

vector position2_
(
    transportProperties.lookup("exclude2")
);

Info<< "Reading exchange current density of anode i0_anode\n" << endl;
dimensionedScalar i0_anode
(
    transportProperties.lookup("i0_anode")
);

Info<< "Reading exchange current density of cathode i0_cathode\n" << endl;
dimensionedScalar i0_cathode
(
    transportProperties.lookup("i0_cathode")
);

scalar brug(readScalar(transportProperties.lookup("brug")));
scalar transfNo(readScalar(transportProperties.lookup("transfNo")));
scalar ns_anodeR(readScalar(transportProperties.lookup("ns_anodeR")));
scalar ns_cathodeR(readScalar(transportProperties.lookup("ns_cathodeR")));
scalar ns_anode1D(readScalar(transportProperties.lookup("ns_anode1D")));
scalar ns_sep1D(readScalar(transportProperties.lookup("ns_sep1D")));
scalar ns_cathode1D(readScalar(transportProperties.lookup("ns_cathode1D")));
scalar relaxAnode(readScalar(transportProperties.lookup("relaxAnode")));
scalar relaxCathode(readScalar(transportProperties.lookup("relaxCathode")));

double omrelaxAnode = 1.0- relaxAnode;
double omrelaxCathode = 1.0- relaxCathode;

label Ns_anode = ns_anode1D*ns_anodeR; // nodes number in 1D direction * nodes number in particle
label Ns_cathode = ns_cathode1D*ns_cathodeR; // nodes number in 1D direction * nodes number in particle

Field<double> Cs_anode(Ns_anode);
forAll(Cs_anode, i){
Cs_anode[i] = Cs_anode0.value();
}

Field<double> Cs_cathode(Ns_cathode);
forAll(Cs_cathode, i){
Cs_cathode[i] = Cs_cathode0.value();
}

Field<double> Cs_anode_tmp(Ns_anode);
forAll(Cs_anode_tmp, i){
Cs_anode_tmp[i] = Cs_anode0.value();
}

Field<double> Cs_cathode_tmp(Ns_cathode);
forAll(Cs_cathode_tmp, i){
Cs_cathode_tmp[i] = Cs_cathode0.value();
}


volScalarField soc_anode =  (Css-Cs_anode_min)/(Cs_anode_max-Cs_anode_min);
volScalarField Ueq_anode =  (0.7222+0.1387*soc_anode+0.029*Foam::pow(soc_anode,0.5)-0.0172/soc_anode+0.0019/Foam::pow(soc_anode,1.5)+0.2808*Foam::exp(0.9-15*soc_anode)-0.7984*Foam::exp(0.4465*soc_anode-0.4108))*Uunit;

volScalarField soc_cathode =  (Css-Cs_cathode_min)/(Cs_cathode_max-Cs_cathode_min);
volScalarField Ueq_cathode =  (4.04596+Foam::exp(-42.30027*soc_cathode+16.56714)-0.0488*Foam::atan(50.01833*soc_cathode-26.48897) - 
    0.05447*Foam::atan(18.99678*soc_cathode-12.32362)-Foam::exp(78.240895*soc_cathode-78.68074))*Uunit;


fis = Ueq_anode*is_anode + Ueq_cathode*is_cathode;  //comment this IF we have initial list of phis distribution

volScalarField eta_anode =  fis - fif - Ueq_anode;	
volScalarField j_anode = i0_anode*(Foam::exp(eta_anode/beta_a)-Foam::exp(eta_anode/beta_c));	
volScalarField j_anodeprimefis = i0_anode*(Foam::exp(eta_anode/beta_a)/beta_a - Foam::exp(eta_anode/beta_c)/beta_c);            	    
volScalarField j_anodeprimefif = i0_anode*(-Foam::exp(eta_anode/beta_a)/beta_a + Foam::exp(eta_anode/beta_c)/beta_c);                   volScalarField j_anodeprimeUeq = j_anodeprimefif;   
volScalarField Ueq_anodeprimecs = (0.1387+0.5*0.029*Foam::pow(soc_anode,-0.5)+0.0172*Foam::pow(soc_anode,-2)-1.5*0.0019*Foam::pow(soc_anode,-2.5)-15*0.2808*Foam::exp(0.9-15*soc_anode)-0.4465*0.7984*Foam::exp(0.4465*soc_anode-0.4108))/(Cs_anode_max-Cs_anode_min)*Uunit; 
volScalarField j_anodeprimecs = j_anodeprimeUeq*Ueq_anodeprimecs;	
    
volScalarField eta_cathode =  fis - fif - Ueq_cathode;	    
volScalarField j_cathode = i0_cathode*(Foam::exp(eta_cathode/beta_a)-Foam::exp(eta_cathode/beta_c));      	    
volScalarField j_cathodeprimefif = i0_cathode*(-Foam::exp(eta_cathode/beta_a)/beta_a + Foam::exp(eta_cathode/beta_c)/beta_c);          	  
volScalarField j_cathodeprimefis = i0_cathode*(Foam::exp(eta_cathode/beta_a)/beta_a - Foam::exp(eta_cathode/beta_c)/beta_c);           	    
volScalarField j_cathodeprimeUeq = j_cathodeprimefif ;
volScalarField Ueq_cathodeprimecs =
(-42.30027*Foam::exp(-42.30027*soc_cathode+16.56714)-0.0488/(1+Foam::pow(50.01833*soc_cathode-26.48897,2))*50.01833 - 
    0.05447*18.99678/(1+Foam::pow(18.99678*soc_cathode-12.32362,2))-78.240895*Foam::exp(78.240895*soc_cathode-78.68074))/(Cs_cathode_max-Cs_cathode_min)*Uunit;
volScalarField j_cathodeprimecs = j_cathodeprimeUeq*Ueq_cathodeprimecs;



volScalarField j = j_anode*is_anode + j_cathode*is_cathode ;
volScalarField ai = ai_anode*is_anode + ai_cathode*is_cathode ; 
volScalarField Rs = Rs_anode*is_anode + Rs_cathode*is_cathode +Rs_cathode*(1-is_anode-is_cathode); // divided by R in calculating Css from Csav.
volScalarField jprimefis = j_anodeprimefis*is_anode + j_cathodeprimefis*is_cathode ;
volScalarField jprimefif = j_anodeprimefif*is_anode + j_cathodeprimefif*is_cathode ;

std::vector<double> U_terminal;
std::vector<double> t_terminal;
Info<< "### Finish reading and creating fields.###\n" << endl;

#include "createFvModels.H"
#include "createFvConstraints.H"
