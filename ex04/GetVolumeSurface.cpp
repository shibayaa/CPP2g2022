#include"GetVolumeSurface.h"

double getVolumeSurface(double x, double y, double z, double& suraface) {
	suraface = (x * y + x * z + y * z) * 2.0;
	return  x * y * z;
}