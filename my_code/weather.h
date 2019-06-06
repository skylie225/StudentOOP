#ifndef WEATHER_H
#define WEATHER_H

#include <string>

struct GPS {
	double latitude;
	double longitude;
	GPS(double la, double lo) : latitude(la),
		longitude(lo) {}
};

std::ostream& operator<<(std::ostream& os, const GPS& gps);

class Date {
	friend std::ostream& operator<<(std::ostream& os, const Date& date);
public:
	Date(int d, int m, int y);
private:
	int day;
	int month;
	int year;
};

class WReading {
private:
	Date date;

};

const int UNRATED = -1;
const int BAD = 0;
const int OK = 1;
const int GOOD = 2;

class Weather {
	friend std::ostream& operator<<(std::ostream& os, const Weather& w);
public:
	Weather(std::string nm, GPS loc);
	std::string get_name() const;
	int get_rating() const;
	void set_rating(int new_rating);
private:
	std::string station_nm;
	GPS my_loc;
	int rating = UNRATED;
};


#endif
