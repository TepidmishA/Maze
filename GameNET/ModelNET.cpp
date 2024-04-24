#include "ModelNET.h"

void ModelNET::addObsC()
{
	// Obtain a native pointer to the managed ModelNET object
	GCHandle handle = GCHandle::Alloc(this);
	IntPtr ptr = GCHandle::ToIntPtr(handle);
	ModelNET^* nativePtr = static_cast<ModelNET^*>(ptr.ToPointer());

	// Create an instance of Omodel using the native pointer
	Omodel* tmp = new Omodel(nativePtr);
	modelC->addObserver(tmp);
}

ModelNET::ModelNET()
{
	modelC = new Model(10, 10);
	modelC->genMaze();
	allODLL = gcnew List<ObserverNET^>(5);

	addObsC();
}

ModelNET::ModelNET(int h, int w)
{
	modelC = new Model(h, w);
	modelC->genMaze();
	allODLL = gcnew List<ObserverNET^>(5);

	addObsC();
}
