#define _CRT_SECURE_NO_DEPRECATE
//requries libraies
#include <stdio.h>
#include <math.h>
#include<stdbool.h>
//const value
#define PI 3.1416
//function prototypes
bool isNorthernHemisphere(double);
bool isSouthernHemisphere(double);
double localDistanceKm(double, double,double,double);
double distanceKm(double, double, double, double);
double radianConversion(double);

int main()
{
	double lat, lon;
	do {
		printf("Enter latitude:\n");
		scanf("%lf", &lat);
		getchar();

	} 
	while (lat < -90 || lat > 90);

	do {
		printf("Enter longitude:\n");
		scanf("%lf", &lon);
		getchar();

	} while (lon < -180 || lon > 180);

	if (isNorthernHemisphere(lat) == 1)
	{
		printf("(%lf,%lf) is in Northern Hemisphere\n", lat, lon);
	}
	else
	{
		printf("(%lf,%lf) is not in Northern Hemisphere\n", lat, lon);
	}
	if (isSouthernHemisphere(lat) == 1)
	{
		printf("(%lf,%lf) is in Southern Hemisphere\n", lat, lon);
	}
	else
	{
		printf("(%lf,%lf) is not in Southern Hemisphere\n", lat, lon);
	}

	printf("Distance to HAW[km]: %.1lf\n", distanceKm(53.557078,  lat, 10.023109, lon));
	printf("Local Distance to HAW[km]: %.1lf\n", localDistanceKm(53.557078,  lat, 10.023109, lon ));

	return 0;
}

bool isNorthernHemisphere(double lat)
{
	return lat >= 0.0;
}

bool isSouthernHemisphere(double lat)
{
	return lat < 0.0;

}

double localDistanceKm(double lat1, double lat2, double lon1,double lon2)
{
	double radLat1 = radianConversion(lat1);
	double radLat2 = radianConversion(lat2);
	double delY = 111.3 * fabs(lat1 - lat2);
	double delX = 111.3 * cos(((radLat1 + radLat2) / 2.00)) * fabs(lon1 - lon2);
	return sqrt(pow(delX, 2) + pow(delY, 2));

}

double distanceKm(double lat1, double lat2, double lon1, double lon2)
{
	lat1 = radianConversion(lat1);
	lon1 = radianConversion(lon1);
	lat2 = radianConversion(lat2);
	lon2 = radianConversion(lon2);

	return 6378.388 * acos(sin((lat1)) * sin(lat2) + cos(lat1) * cos(lat2) * cos((lon2 - lon1)));
}

double radianConversion(double value)
{

	return value * (PI/180.0);
}

