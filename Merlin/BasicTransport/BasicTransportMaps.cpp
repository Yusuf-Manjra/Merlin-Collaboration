/////////////////////////////////////////////////////////////////////////
//
// Merlin C++ Class Library for Charged Particle Accelerator Simulations
//  
// Class library version 3 (2004)
// 
// Copyright: see Merlin/copyright.txt
//
// Last CVS revision:
// $Date: 2004/12/13 08:38:52 $
// $Revision: 1.3 $
// 
/////////////////////////////////////////////////////////////////////////

#include "BasicTransport/BasicTransportMaps.h"
#include "BasicTransport/TransportMatrix.h"
#include <cmath>
#include <typeinfo>
using namespace std;

RTMap* SectorBendTM(double s, double h)
{
    RTMap* rtm = new RTMap;
    RTMap& rtMap = *rtm;

    // Code generated by Mathematica
    // -----------------------------
    double beta = 1.0;
    double gamma = 7460.5230711490913;
/*
    rtMap(1,1) = cos(h*s);
    rtMap(1,2) = a5;
    rtMap(1,6) = a8;
    rtMap(2,1) = -(a4*h);
    rtMap(2,2) = a2;
    rtMap(2,6) = a4;
    rtMap(3,3) = 1;
    rtMap(3,4) = s;
    rtMap(4,4) = 1;
    rtMap(5,1) = a9;
    rtMap(5,2) = a11;
    rtMap(5,5) = 1;
    rtMap(5,6) = a5 - s;
    rtMap(6,6) = 1;
*/

    // Ancillory variables created by Optimize[]
    double a1 = h*s;
    double a2 = cos(a1);
    double a3 = 1/h;
    double a4 = sin(a1);
    double a5 = a3*a4;
    double a6 = -a2;
    double a7 = 1 + a6;
    double a8 = a3*a7;
    double a9 = -a4;
    double a10 = -1 + a2;
    double a11 = a10*a3;
    double a12 = pow(a4,2);
    double a13 = (h*s)/2.;
    double a14 = sin(a13);
    double a15 = -a4/2.;
    double a16 = -(a3*a4)/2.;

    // Matrix terms
    rtMap(1,1) = a2;
    rtMap(1,2) = a5;
    rtMap(1,6) = a8;
    rtMap(2,1) = -(a4*h);
    rtMap(2,2) = a2;
    rtMap(2,6) = a4;
    rtMap(3,3) = 1;
    rtMap(3,4) = s;
    rtMap(4,4) = 1;
    rtMap(5,1) = a9;
    rtMap(5,2) = a11;
    rtMap(5,5) = 1;
    rtMap(5,6) = a5 - s;
    rtMap(6,6) = 1;
    
    double KL = h*s;
    double cx = cos(KL);
    double sx = sin(KL)/h;
    double dx = (1-cx)/(h*h);
    double J1 = (s - sx) / (h*h);
    double sy = s;
    double cy = 1;
//     te(1,1,2) = (- xs6*dx + h2*cx) * sx

    rtMap(1,1,1) = -(a12*h)/2.;
//    rtMap(1,1,2) = a9 + sin(2*h*s)/2.;
    rtMap(1,1,2) = h*sx*cx;
    rtMap(1,1,6) = a12;
    rtMap(1,2,2) = a2*a3*pow(a14,2);
//    rtMap(1,2,6) = 4*a3*cos(a13)*pow(a14,3);
    rtMap(1,2,6) = (((h*h)/(4*beta)*(sx*dx+cx*J1)) - ((1/(4*beta)) * (sx + s*cx))) * 2.0;
    rtMap(1,6,6) = -(a12*a3)/2.;
    rtMap(1,4,4) = (a10*a3)/2.;

//133,134 both zero?
//    rtMap(2,1,6) = a4*h;
    rtMap(2,2,2) = a15;
//    rtMap(2,6,6) = a9;
    rtMap(2,4,4) = a15;
    rtMap(2,6,6) = -h*sx/(2*beta*beta*gamma*gamma);

    rtMap(3,1,4) = a4;
    rtMap(3,2,4) = a8;
//    rtMap(3,4,6) = -(a3*a4) + s;
    rtMap(3,4,6) = ((h*h*J1*cy/(2*beta))  - ((sy + (s * cy))/(4*beta)))*2;

//    rtMap(5,1,2) = a7;
    rtMap(5,2,2) = a16;
    rtMap(5,1,6) =  (h*sx/(2*beta*beta*gamma*gamma))*2;
    rtMap(5,2,6) =  (h*dx/(2*beta*beta*gamma*gamma))*2;
    rtMap(5,6,6) =  3*(h*h*J1 - s)/(2*beta*beta*beta*gamma*gamma);
//    rtMap(5,2,6) = a11;
    rtMap(5,4,4) = a16;

//cout.precision(16);
//    cout << "SECTORBEND CORE" << endl;
//rtm->Print(std::cout);
    return rtm;
}

RTMap* QuadrupoleTM(double s, double K1)
{
    RTMap* rtm = new RTMap;
    RTMap& rtMap = *rtm;

    // Ancillory variables created by Optimize[]

    // Code generated by Mathematica
    // -----------------------------

    double ksgn=K1<0 ? -1:1;
    double kq=sqrt(fabs(K1));

    // Ancillory variables created by Optimize[]
    double a1 = kq*s;
    double a3 = 1/kq;
    double a2 = K1>0 ? cos(a1) : cosh(a1);
    double a4 = K1>0 ? sin(a1) : sinh(a1);
    double a5 = K1<0 ? cos(a1) : cosh(a1);
    double a6 = K1<0 ? sin(a1) : sinh(a1);
    double a7 = (ksgn*a4*kq*s)/2.;
    double a8 = -(ksgn*a6*kq*s)/2.;
    double a9 = 2*kq*s;
    double a10 = K1>0 ? sin(a9) : sinh(a9);
    double a11 = ksgn*pow(a4,2);
    double a12 = a11/2.;
    double a13 = K1<0? sin(a9) : sinh(a9);
    double a14 = pow(a6,2);
    double a15 = -a14/2.;

    // Matrix terms
    rtMap(1,1) = a2;
    rtMap(1,2) = a3*a4;
    rtMap(2,1) = -ksgn*a4*kq;
    rtMap(2,2) = a2;
    rtMap(3,3) = a5;
    rtMap(3,4) = a3*a6;
    rtMap(4,3) = ksgn*a6*kq;
    rtMap(4,4) = a5;
    rtMap(5,5) = 1;
    rtMap(6,6) = 1;
    rtMap(1,1,6) = a7;
    rtMap(1,2,6) = (a3*(a4 - a2*kq*s))/2.;
    rtMap(2,1,6) = (ksgn*kq*(a4 + a2*kq*s))/2.;
    rtMap(2,2,6) = a7;
    rtMap(3,3,6) = a8;
    rtMap(3,4,6) = (a3*(a6 - a5*kq*s))/2.;
    rtMap(4,3,6) = -(ksgn*kq*(a6 + a5*kq*s))/2.;
    rtMap(4,4,6) = a8;

    rtMap(5,1,1) = -((-a10 + a9)*kq*ksgn)/8.;
    rtMap(5,1,2) = a12;
    rtMap(5,2,2) = -(a3*(a10 + a9))/8.;
    rtMap(5,3,3) = ksgn*((-a13 + a9)*kq)/8.;
    rtMap(5,3,4) = ksgn*a15;
    rtMap(5,4,4) = -(a3*(a13 + a9))/8.;

    return rtm;
}

RTMap* SextupoleTM(double s, double K2)
{
    RTMap* rtm = new RTMap;
    RTMap& rtMap = *rtm;

    K2*=0.5; // transport defines this different

    // Code generated by Mathematica
    // -----------------------------

    // Ancillory variables created by Optimize[]
    double a1 = pow(s,2);
    double a2 = pow(s,3);
    double a3 = -(a2*K2)/3.;
    double a4 = pow(s,4);
    double a5 = (a2*K2)/3.;
    double a6 = a1*K2;
    double a7 = -s/2.;

    // Matrix terms
    rtMap(1,1) = 1;
    rtMap(1,2) = s;
    rtMap(2,2) = 1;
    rtMap(3,3) = 1;
    rtMap(3,4) = s;
    rtMap(4,4) = 1;
    rtMap(5,5) = 1;
    rtMap(6,6) = 1;
    rtMap(1,1,1) = -(a1*K2)/2.;
    rtMap(1,1,2) = a3;
    rtMap(1,2,2) = -(a4*K2)/12.;
    rtMap(1,3,3) = (a1*K2)/2.;
    rtMap(1,3,4) = a5;
    rtMap(1,4,4) = (a4*K2)/12.;
    rtMap(2,1,1) = -(K2*s);
    rtMap(2,1,2) = -(a1*K2);
    rtMap(2,2,2) = a3;
    rtMap(2,3,3) = K2*s;
    rtMap(2,3,4) = a6;
    rtMap(2,4,4) = a5;
    rtMap(3,1,3) = a6;
    rtMap(3,1,4) = a5;
    rtMap(3,2,3) = a5;
    rtMap(3,2,4) = (a4*K2)/6.;
    rtMap(4,1,3) = 2*K2*s;
    rtMap(4,1,4) = a6;
    rtMap(4,2,3) = a6;
    rtMap(4,2,4) = (2*a2*K2)/3.;
    rtMap(5,2,2) = a7;
    rtMap(5,4,4) = a7;

    return rtm;
}

RTMap* DriftTM(double s)
{
    RTMap* rtm = new RTMap;
    RTMap& rtMap = *rtm;

    rtMap(1,1)=1;
    rtMap(1,2)=s;
    rtMap(2,2)=1;
    rtMap(3,3)=1;
    rtMap(3,4)=s;
    rtMap(4,4)=1;
    rtMap(5,5)=1;
    rtMap(6,6)=1;

    rtMap(5,2,2)=-s/2;
    rtMap(5,4,4)=-s/2;

    return rtm;
}

RTMap* GenSectorBendTM(double s, double h, double K1, double K2)
{
    RTMap* rtm = new RTMap;
    RTMap& rtMap = *rtm;

    RealMatrix R(IdentityMatrix(6));
    TransportMatrix::SectorBend(s,h,K1,R);
    double cx = rtMap(1,1) = R(0,0);
    double sx = rtMap(1,2) = R(0,1);
    double dx = rtMap(1,6) = R(0,5);
    double cxp = rtMap(2,1) = R(1,0);
    double sxp = rtMap(2,2) = R(1,1);
    double dxp = rtMap(2,6) = R(1,5);
    double cy = rtMap(3,3) = R(2,2);
    double sy = rtMap(3,4) = R(2,3);
    double cyp = rtMap(4,3) = R(3,2);
    double syp = rtMap(4,4) = R(3,3);

    rtMap(5,1)=R(4,0);
    rtMap(5,2)=R(4,1);
    rtMap(5,5)=1;
    rtMap(5,6)=R(4,5);
    rtMap(6,6)=1;

    // Code generated by Mathematica
    // -----------------------------

    // Ancillory variables created by Optimize[]
    //	double a1 = pow(kx,2);
    double n = -K1/(h*h);
    double a1 = K1+h*h;
    double a2 = 1/h;
    double a3 = 2*a2*dx;
    double a4 = pow(sx,2);
    double a5 = -a4;
    double a6 = a3 + a5;
    double a7 = pow(h,3);
    double a8 = 1/a7;
    double a9 = -(a8*K2);
    double a10 = 2*n;
    double a11 = -1 + a10 + a9;
    double a12 = a2*dx;
    double a13 = a12 + a4;
    double a14 = pow(h,2);
    double a15 = (2*a11*a14*dx*sx)/3.;
    double a16 = -n;
    double a17 = 2 + a16;
    double a18 = (a14*a17*s*sx)/2.;
    double a19 = pow(h,4);
    double a20 = 1/a1;
    double a21 = (s*sx)/2.;
    double a22 = -(a2*dx);
    double a23 = -(cx*s);
    double a24 = a23 + sx;
    double a25 = pow(h,5);
    //	double a26 = pow(kx,4);
    double a26 = a1*a1;
    double a27 = 1/a26;
    double a28 = -K1;
    double a29 = -4*a28;
    double a30 = a1 + a29;
    double a31 = 1/a30;
    double a32 = -2*a2*dx;
    double a33 = pow(sy,2);
    double a34 = a32 + a33;
    double a35 = -sx;
    double a36 = cy*sy;
    double a37 = a35 + a36;
    double a38 = 2*a31*a37*K2;
    double a39 = 2*cx;
    double a40 = 1 + a39;
    double a41 = 2*a4;
    double a42 = a22 + a41;
    double a43 = 2*a2*cy*dx;
    double a44 = -(sx*sy);
    double a45 = a43 + a44;
    double a46 = a8*K2;
    double a47 = a16 + a46;
    double a48 = -cx;
    double a49 = 1 + a48;
    double a50 = a49*cy;
    double a51 = -2*a28*sx*sy;
    double a52 = a50 + a51;
    double a53 = 2*cy*sx;
    double a54 = 1 + cx;
    double a55 = -(a54*sy);
    double a56 = a53 + a55;
    double a57 = a20*sy;
    double a58 = -(cy*sx);
    double a59 = 2*a20*a28*a54*sy;
    double a60 = a58 + a59;
    double a61 = a31*a60;
    double a62 = a57 + a61;
    double a63 = (a28*s*sy)/2.;
    double a64 = (s*sy)/2.;
    double a65 = -(cy*s);
    double a66 = a65 + sy;
    double a67 = -2*a28;
    double a68 = a1 + a67;
    double a69 = a68*cy*sx;
    double a70 = -(a28*a54*sy);
    double a71 = a69 + a70;
    double a72 = cy*sx;
    double a73 = -(cx*sy);
    double a74 = -2*a2*a28*dx*sy;
    double a75 = a72 + a73 + a74;
    double a76 = -(a49*cy);
    double a77 = a68*sx*sy;
    double a78 = a76 + a77;
    double a79 = a20*cy;
    double a80 = -(cx*cy);
    double a81 = 2*a20*a28*a54*cy;
    double a82 = -(a28*sx*sy);
    double a83 = a80 + a81 + a82;
    double a84 = a31*a83;
    double a85 = a79 + a84;
    double a86 = -(a1*h);
    double a87 = -2*n;
    double a88 = 1 + a87;
    double a89 = a7*a88;
    double a90 = a86 + a89 + K2;
    double a91 = -2*K2;
    double a92 = 4*n;
    double a93 = -2 + a92;
    double a94 = a7*a93;
    double a95 = a86 + a91 + a94;
    double a96 = -2 + n;
    double a97 = -(a1*a96*h);
    double a98 = a91 + a94 + a97;
    double a99 = a1*h;
    double a100 = 8*n;
    double a101 = -4 + a100;
    double a102 = 2*K2;
    double a103 = -4*n;
    double a104 = 2 + a103;
    double a105 = a104*a7;
    double a106 = a102 + a105 + a99;
    double a107 = a1*a96*h;
    double a108 = a102 + a105 + a107;
    double a109 = pow(h,6);

    // Code generated by Mathematica
    // -----------------------------

    // Ancillory variables created by Optimize[]
    double kx2 = h*h+K1;
    double kx = sqrt(fabs(kx2));
    double ky2 = -K1;
    double ky  = sqrt(fabs(ky2));

    double sngx = (kx2<0)? -1 : 1;

    double b1 = pow(kx,2);
    double b2 = 1/b1;
    double b3 = kx*s;
    double b4 = (kx2<0)? cosh(b3) : cos(b3);
    double b5 = (kx2<0)? sinh(b3) : sin(b3);
    double b6 = pow(kx,3);
    double b7 = 1/b6;

    double b8 = (kx2<0)? sinh(2*b3) : sin(2*b3);
    double b9 = (kx2<0)? sinh(b3/2.) : sin(b3/2.);
    double b10 = (ky2<0)? cosh(ky*s) : cos(ky*s);
    double b11 = (ky2<0)? sinh(ky*s) : sin(ky*s);
    double b12 = (ky2<0)? sinh(2*ky*s) : sin(2*ky*s);

    // Matrix terms
    double P1 = b2*(sngx*(b4-1) + b5*kx*s);
    double P2 = sngx*(b3 - b5)*b7*h;
    double P3 = sngx*b2*(1 - b4);
    double P4 = sngx*b7*(b5 - b4*kx*s);
    double P5 = 2*h*pow(kx,-4)*pow(b9,4);
    double P6 = -sngx*(b7*(-2*kx*s + b8))/4.;
    double P7 = (pow(ky,-2)*pow(b11,2))/2.;
    double P8 = -(pow(ky,-3)*(-2*ky*s + b8))/4.;

    // Matrix terms
    rtMap(1,1,1) = (a11*a13*a7)/3. + (a1*a6*h)/6.;
    rtMap(1,1,2) = a15 - (a1*dx*sx)/3.;
    rtMap(1,1,6) = a18 + 2*a11*a19*a20*(a21 + (a22 + a5)/3.) - (a14*a6)/3.;
    rtMap(1,2,2) = (a11*a20*a6*a7)/3. + (a13*h)/6.;
    rtMap(1,2,6) = (a14*a17*a20*a24)/2. + (dx*h*sx)/3. + 2*a11*a19*a20*((a20*a24)/2. - (a2*dx*sx)/3.);
    rtMap(1,6,6) = (a20*a6*a7)/6. - dx + a11*a25*a27*(a4/3. + (4*a2*dx)/3. - s*sx) + a17*a20*a7*(a12 - (s*sx)/2.);
    rtMap(1,3,3) = -(a28*dx)/2. + (a12 - a28*a31*a34)*K2;
    rtMap(1,3,4) = a38;
    rtMap(1,4,4) = -dx/2. + a31*a34*K2;
    rtMap(2,1,1) = -(cx*cxp*h) + (a11*a40*a7*sx)/3. + (a26*dx*sx)/3.;
    rtMap(2,1,2) = (2*a11*a42*a7)/3. - (a1*a42*h)/3. + h*sxp - h*(cxp*sx + cx*sxp);
    rtMap(2,1,6) = -((cxp*dx + cx*dxp)*h) - (2*a1*dx*h*sx)/3. + (a14*a17*(cx*s + sx))/2. + 2*a11*a19*a20*((cx*s)/2. + sx/6. - (2*cx*sx)/3.);
    rtMap(2,2,2) = a15 + (a40*h*sx)/6. - h*sx*sxp;
    rtMap(2,2,6) = a18 + (a14*a42)/3. + 2*a11*a19*a20*(a21 - (2*a4)/3. + (a2*dx)/3.) - h*(dxp*sx + dx*sxp);
    rtMap(2,6,6) = (a17*a20*a24*a7)/2. - dx*dxp*h + (a14*dx*sx)/3. - h*sx + a11*a25*a27*(a23 + sx/3. + (2*cx*sx)/3.);
    rtMap(2,3,3) = -(a28*h*sx)/2. + K2*(-2*a28*a31*a37 + sx);
    rtMap(2,3,4) = 2*a31*(-2*a28*a33 + a1*a2*dx)*K2;
    rtMap(2,4,4) = a38 - (h*sx)/2.;
    rtMap(3,1,3) = 2*a31*a47*a52*a7 + a1*a28*a31*a45*h;
    rtMap(3,1,4) = 2*a31*a47*a56*a7 - a1*a62*h + h*sy;
    rtMap(3,2,3) = 2*a47*a62*a7 - a28*a31*a56*h;
    rtMap(3,2,4) = 2*a31*a45*a47*a7 + a31*a52*h;
    rtMap(3,3,6) = -(a14*a28*a31*a45) + a63 + 2*a19*a20*a47*(-(a31*a52) + a64);
    rtMap(3,4,6) = a14*a62 + a66/2. + 2*a19*a20*a47*(-(a31*a56) + a66/(2.*a28));
    rtMap(4,1,3) = 2*a31*a47*a7*a71 + a1*a28*a31*a75*h - cx*cyp*h;
    rtMap(4,1,4) = 2*a31*a47*a7*a78 - a1*a85*h + h*syp - cx*h*syp;
    rtMap(4,2,3) = 2*a47*a7*a85 - a28*a31*a78*h - cyp*h*sx;
    rtMap(4,2,4) = 2*a31*a47*a7*a75 + a31*a71*h - h*sx*syp;
    rtMap(4,3,6) = -(a14*a28*a31*a75) - cyp*dx*h + (a28*(cy*s + sy))/2. + 2*a19*a20*a47*((cy*s)/2. + sy/2. + a31*(-(a68*cy*sx) + a28*a54*sy));
    rtMap(4,4,6) = a63 + 2*a19*a20*a47*(a64 - a31*a78) + a14*a85 - dx*h*syp;
    rtMap(5,1,1) = (-2*a90*P2 + a95*h*P6 + 3*s*pow(cxp,2))/6.;
    rtMap(5,1,2) = (a95*P5 + 3*cxp*s*sxp)/3.;
    rtMap(5,1,6) = (a20*(6*a1*cxp*dxp*s + 4*a90*h*P2 + 3*a14*a98*P4 + 4*a25*P6 + 2*a1*a7*P6 + 4*a14*K2*P6 - 8*a25*n*P6))/6.;
    rtMap(5,2,2) = (a20*((a101*a7 + a99 - 4*K2)*P2 + a106*h*P6 + 3*a1*s*pow(sxp,2)))/6.;
    rtMap(5,2,6) = (a27*(3*a108*a14*P1 + 3*a14*a98*P3 + 2*a1*(a106*h*P5 + 3*a1*dxp*s*sxp)))/6.;
    rtMap(5,3,3) = (2*a28*h*K2*P8 + P2*(a1*a28*h - 2*a1*K2 + 4*a28*K2 - 4*h*K1*K1) - a30*s*pow(cyp + syp,2))/(-2*a1 + 8*a28);
    rtMap(5,3,4) = 2*a31*h*K2*(-P3 + P6);
    rtMap(5,4,4) = (a31*(-((a30*h + 4*K2)*P2) + 2*h*K2*P8))/2.;
    rtMap(5,6,6) = (a27*(2*h*(a101*a19 - 3*a26 - 4*h*K2 + a1*a14*(7 - 3*n))*P2 + 3*a108*a7*P4 - 2*a109*P6 - a1*a19*P6 - 2*a7*K2*P6 + 4*a109*n*P6 + 3*a26*s*\
                         pow(dxp,2)))/6.;


    return rtm;
}

RTMap* PoleFaceTM(double h, double K1, double beta, double c, double fint, double hgap, bool entrance)
{
    RTMap* rtm = new RTMap;
    RTMap& rtMap = *rtm;

    const double sinbeta = sin(beta);
//    const double phi = 2.0*fint*hgap*h*(1+sinbeta*sinbeta)/cos(beta);
	double phi = 2.0*fint*hgap*h*(1+sinbeta*sinbeta)/cos(beta);
    if(phi == -0)
    {
    	phi = 0;
    }
/*
cout << "sign: " << entrance << endl;
cout << "h: " << h << endl;
cout << "K1: " << K1 << endl;
cout << "beta: " << beta << endl;
cout << "c: " << c << endl;
cout << "fint: " << fint << endl;
cout << "hgap: " << hgap << endl;
*/
    // Code generated by Mathematica
    // -----------------------------

    // Ancillory variables created by Optimize[]
    double a1 = tan(beta);
    double a2 = a1*h;
    double a3 = -phi;
    double a4 = a3 + beta;
    double a5 = pow(a1,2);
    double a6 = 1/cos(beta);
    double a7 = pow(a6,2);
    double a8 = pow(a6,3);
    double a9 = a5*h;
    double a10 = pow(h,2);
    double a11 = -(a5*h);

	double sig=1;



if(entrance == 1)// do entrance
{
	sig = 1;
}
else
{
	sig = -1;
}


    // Matrix terms
    rtMap(2,1) = a2;
    rtMap(4,3) = -(h*tan(a4));
    
	const double hh = sig * 0.5 * h;

/*
	rtMap(1,1,1) =  (-hh * pow(a1,2));
	cout << rtMap(1,1,1) << endl;
	*/
//	rtMap(1,3,3) =  (hh * a7);
//	cout << rtMap(1,3,3) << endl;

//	rtMap(2,1,1) =  (((h/2) * c * a8) + (K1 *a1));
/*
	rtMap(2,1,2) =  (hh * pow(a1,2));
	rtMap(2,3,3) =  hh * h * pow(a1,3) - rtMap(2,1,1);
	rtMap(2,3,4) =  rtMap(1,1,1);
	rtMap(3,1,3) =  -rtMap(1,1,1);
	rtMap(4,1,3) =  -rtMap(2,1,1);
	rtMap(4,1,4) =  rtMap(1,1,1);
	rtMap(4,2,3) =  -rtMap(1,3,3);
*/

	rtMap(1,1,1) =  -hh * pow(a1,2);
	rtMap(1,3,3) =  hh * a7;
	rtMap(2,1,2) =  (hh * pow(a1,2))*2;
	rtMap(2,3,4) =  -hh * pow(a1,2)*2;
	rtMap(3,1,3) =  hh * pow(a1,2)*2;

	rtMap(4,1,4) =   -hh * pow(a1,2)*2;
	rtMap(4,2,3) =  -(hh * a7)*2;

if(entrance == true)// do entrance
{
	rtMap(2,1,1) =  ((h/2) * c * a8) + (K1 *a1);	//old
	rtMap(2,3,3) = hh * h * pow(a1,3) - ((h/2) * c * a8) + (K1 *a1) + pow((h*a6),2) * a1 * 0.5;
	rtMap(4,1,3) =  -(((h/2) * c * a8) + (K1 *a1));	//old
}
else	//do exit
{
//	rtMap(2,1,1) = ((h/2) * c * a8) + (K1 *a1) - pow((h*a6),2) * a1 * 0.5;
//	rtMap(4,1,3) = -(((h/2) * c * a8) + (K1 *a1)) + pow((h*a6),2) * a1 * 0.5;
	rtMap(2,1,1) = ((h/2) * c * a8) + (K1 *a1) - pow((h*a1),2) * a1 * 0.5;
	rtMap(2,3,3) =  hh * h * pow(a1,3) - ((h/2) * c * a8) + (K1 *a1);	//old
	rtMap(4,1,3) = -(((h/2) * c * a8) + (K1 *a1)) + pow((h*a6),2) * a1;
}

/*
    rtMap(1,1,1) = -(a5*h)/2.;
    rtMap(1,3,3) = (a7*h)/2.;
    rtMap(2,1,1) = (a8*c*h)/2. + a1*K1;
    rtMap(2,1,2) = a9;
    rtMap(2,1,6) = -(a1*h);
    rtMap(2,3,3) = -(a8*c*h)/2. + a1*a10*(0.5 + a5 - K1/a10);
    rtMap(2,3,4) = a11;
    rtMap(3,1,3) = a9;
    rtMap(4,1,3) = -(a8*c*h) - 2*a1*K1;
    rtMap(4,1,4) = a11;
    rtMap(4,2,3) = -(a7*h);
    rtMap(4,3,6) = a2 - h*phi*pow(cos(a4),-2);
*/
    
    
/*
	double hh = sig * 0.5 * h;
	rtMap(1,1,1) =  (-hh * pow(a1,2));
	cout << rtMap(1,1,1) << endl;
	cout << hh << "\t" << a1 << "\t" << pow(a1,2) << "\t" << hh * pow(a1,2) << endl;
	rtMap(1,3,3) =  + hh * a7;
	rtMap(2,1,1) =  ((h/2) * c * a8) + (K1 *a1);
	rtMap(2,1,2) =  -rtMap(1,1,1);
	rtMap(2,3,3) =  hh * h * pow(a1,3) - rtMap(2,1,1);
	rtMap(2,3,4) =  +rtMap(1,1,1);
	rtMap(3,1,3) =  -rtMap(1,1,1);
	rtMap(4,1,3) =  -rtMap(2,1,1);
	rtMap(4,1,4) =  +rtMap(1,1,1);
	rtMap(4,2,3) =  -rtMap(1,3,3);

if(entrance == true)// do entrance
{
	rtMap(2,3,3) = rtMap(2,3,3) + pow((h*a6),2) * a1 * 0.5;
}
else	//do exit
{
	rtMap(2,1,1) = rtMap(2,1,1) - pow((h*a6),2) * a1 * 0.5;
	rtMap(4,1,3) = rtMap(4,1,3) + pow((h*a6),2) * a1 * 0.5;
}
*/



/*
    if(a10 == 0 && K1 == 0)
    {
    	a12 = 0;
    }
    else
    {
    	a12 = K1/a10;
    }
    // Matrix terms
    rtMap(2,1) = a2;
    rtMap(4,3) = -(h*tan(a4));
*/
//cout << rtMap(2,1) << endl;
//cout << rtMap(4,3) << endl;
/*
    rtMap(1,1,1) = -(a5*h)/2.;
    rtMap(1,3,3) = (a7*h)/2.;
    rtMap(2,1,1) = (a8*c*h)/2. + a1*K1;
    rtMap(2,1,2) = a9;
    rtMap(2,1,6) = -(a1*h);
//    cout << a1 << "\t" << a10 << "\t" << a5 << "\t" << K1 << "\t" << h << endl;
//    cout << -(a8*c*h)/2. << "\t" << a1*a10*(0.5 + a5 - K1/a10) << endl;

//    rtMap(2,3,3) = -(a8*c*h)/2. + a1*a10*(0.5 + a5 - K1/a10);
    rtMap(2,3,3) = -(a8*c*h)/2. + a1*a10*(0.5 + a5 - a12);
    rtMap(2,3,4) = a11;
    rtMap(3,1,3) = a9;
    rtMap(4,1,3) = -(a8*c*h) - 2*a1*K1;
    rtMap(4,1,4) = a11;
    rtMap(4,2,3) = -(a7*h);
    rtMap(4,3,6) = a2 - h*phi*pow(cos(a4),-2);
*/


//    rtMap(2,3,4) = a11;
//    rtMap(4,1,4) = a11;

//    rtMap(2,1,6) = -(a1*h);
//    rtMap(4,3,6) = a2 - h*phi*pow(cos(a4),-2);
//c = 1/R?


//Entrance and exit faces have different higher order terms
//(m,r,c)
/*
if(entrance == true)
{
cout << -0.5*h*pow(tan(beta),2) << endl;
cout << 0.5*h*pow(1/cos(beta),2) << endl;
    rtMap(1,1,1) = a11/2.0;
    rtMap(1,3,3) = (a7*h)/2.0;
//    rtMap(1,1,1) = a11;
//    rtMap(1,3,3) = (a7*h);
    
    rtMap(2,3,4) = a11;
    rtMap(2,1,1) = 0.5*(a8*c*h) + a1*K1;
    rtMap(2,3,3) = -0.5*(a8*c*h) - a1*K1 + 0.5*a10*a1*(1+a7);
    rtMap(2,1,2) = a9;

    rtMap(3,1,3) = a9;

    rtMap(4,2,3) = -(a7*h);
    rtMap(4,1,3) = -(a8*c*h) - a1*K1;
    rtMap(4,1,4) = a11;
    cout << "I'm an entrance poleface" << endl;
}
else
{
    cout << 0.5*h*pow(tan(beta),2) << endl;
    cout << -0.5*h*pow(1/cos(beta),2) << endl;
    rtMap(1,1,1) = a9/2.0;
    rtMap(1,3,3) = -(a7*h)/2.0;
//    rtMap(1,1,1) = a9;
//    rtMap(1,3,3) = -(a7*h);

    rtMap(2,3,4) = a9;
    rtMap(2,1,1) = 0.5*(a8*c*h) + a1*K1 - 0.5*a10*pow(a1,3);
    rtMap(2,3,3) = -0.5*(a8*c*h) - a1*K1 - 0.5*a10*pow(a1,3);
    rtMap(2,1,2) = a11;

    rtMap(3,1,3) = a11;

    rtMap(4,1,4) = a9;
    rtMap(4,2,3) = (a7*h);
    rtMap(4,1,3) = -(a8*c*h) - 2*a1*K1 + a10*a1*a7;
    cout << "I'm an exit poleface" << endl;
}
*/
    rtMap(1,1)=1;
    rtMap(2,2)=1;
    rtMap(3,3)=1;
    rtMap(4,4)=1;
    rtMap(5,5)=1;
    rtMap(6,6)=1;

    //	rtm->Purge();
//	rtm->Print(std::cout);
//	if(entrance != true)
//		exit(1);
    return rtm;
}
