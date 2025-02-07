/*
 * Merlin++: C++ Class Library for Charged Particle Accelerator Simulations
 * Copyright (c) 2001-2018 The Merlin++ developers
 * This file is covered by the terms the GNU GPL version 2, or (at your option) any later version, see the file COPYING
 * This file is derived from software bearing the copyright notice in merlin4_copyright.txt
 */

#include <fstream>

#include "PhysicalUnits.h"
#include "MADInterface.h"
#include "ParticleBunch.h"
#include "ParticleTracker.h"

#include "ClosedOrbit.h"

#include "BPMVectorBuffer.h"
#include "ConstantStrayFieldProcess.h"

#define BEAMENERGY 5.0 * GeV

using namespace std;
using namespace PhysicalUnits;
using namespace ParticleTracking;

int main()
{
	// Construct the AcceleratorModel
	// from a lattice file produced by MAD
	MADInterface madi("../lattices/MERLINFodo.lattice.txt", BEAMENERGY);

	ofstream madlog("mad.log");
	madi.SetLogFile(madlog);
	madi.SetLoggingOn();

	AcceleratorModel* theModel = madi.ConstructModel();

	// Find the closed orbit in the ring.
	ClosedOrbit theClosedOrbit(theModel, BEAMENERGY);
	theClosedOrbit.AddProcess(new ConstantStrayFieldProcess(10.0, 0.001));
	PSvector co(0);
	theClosedOrbit.FindClosedOrbit(co);

	// Construct a bunch of particles
	// to track through the lattice.
	// Here we just add a single particle on the closed orbit.
	ParticleBunch* theBunch = new ParticleBunch(BEAMENERGY);
	theBunch->AddParticle(co);

	// Construct a ParticleTracker to perform the tracking
	ParticleTracker tracker(theModel->GetBeamline(), theBunch);
	tracker.AddProcess(new ConstantStrayFieldProcess(10.0, 0.001));

	// Construct a BPMBuffer to record the bunch centroid at each BPM
	BPMVectorBuffer* bpmVecBuffer = new BPMVectorBuffer();
	BPM::SetDefaultBuffer(bpmVecBuffer);

	// Do the tracking
	tracker.Run();

	// Write the tracking results to a file
	ofstream bpmLog("StrayFieldClosedOrbit.dat");
	vector<BPM::Data>& theBPMBuffer = bpmVecBuffer->BPMReading;
	for(vector<BPM::Data>::iterator bpm_iter = theBPMBuffer.begin(); bpm_iter != theBPMBuffer.end(); bpm_iter++)
	{
		bpmLog << std::setw(14) << (bpm_iter->x).value;
		bpmLog << std::setw(14) << (bpm_iter->x).error;
		bpmLog << std::setw(14) << (bpm_iter->y).value;
		bpmLog << std::setw(14) << (bpm_iter->y).error;
		bpmLog << endl;
	}

	BPM::SetDefaultBuffer(nullptr);
	delete bpmVecBuffer;

	delete theBunch;
	delete theModel;

	cout << "Finished!" << endl;

	return 0;
}
