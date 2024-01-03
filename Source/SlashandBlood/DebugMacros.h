#pragma once

#include "DrawDebugHelpers.h"


#define DRAW_SPHERE(Location) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, 12, FColor::Red, true);
#define DRAW_SPHERE_SingleFrame(Location) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, 12, FColor::Red, false, -1.f);
#define DRAW_LINE_SPHERE(StartLocation, EndLocation) if (GetWorld()) DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, true, -1.f, 0, 2.f);
#define DRAW_LINE_SPHERE_SingleFrame(StartLocation, EndLocation) if (GetWorld()) DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, false, -1.f, 0, 2.f);
#define DRAW_POINT_SPHERE(Location) if (GetWorld()) DrawDebugPoint(GetWorld(), Location, 15.f, FColor::Green, true);
#define DRAW_POINT_SPHERE_SingleFrame(Location) if (GetWorld()) DrawDebugPoint(GetWorld(), Location, 15.f, FColor::Green, false, -1.f);
#define DRAW_VECTOR(StartLocation, EndLocation) if (GetWorld()) \
	{ \
		DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, true, -1.f, 0, 2.f); \
		DrawDebugPoint(GetWorld(), EndLocation, 15.f, FColor::Green, true); \
	}
#define DRAW_VECTOR_SingleFrame(StartLocation, EndLocation) if (GetWorld()) \
	{ \
		DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, false, -1.f, 0, 2.f); \
		DrawDebugPoint(GetWorld(), EndLocation, 15.f, FColor::Green, false, -1.f); \
	}