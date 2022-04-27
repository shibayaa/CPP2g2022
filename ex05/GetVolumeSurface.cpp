#include "GetVolumeSurface.h"
void getVolumeSurface(BOX* box) {
	box->volume = box->x * box->y * box->z;
	box->surface = 2 * (box->x * box->y + box->x * box->z + box->y * box->z);
	return;
}
bool isSendable(BOX* box)
{
	bool sendable = false;
	box->packSize = -1;
	double length = box->x + box->y + box->z;
	const int packs = 5;
	double packSize[packs] = { 60,80,100,120,160 };

	for (int i = 0; i < packs; i++) {
		if (length <= packSize[i]) {
			sendable = true;
			box->packSize = packSize[i];
			break;
		}
	}
	return sendable;
}
