#include <iostream>

#include "../inc/version.h"

using namespace std;

// Use this if you want to add detail on SEMVER
// Using this cuz we cant leave an empty #define
// Yes, I know, that's ugly
string CONWAY_SEMVER_addendum("");

int version_x()
{
    return CONWAY_SEMVER_x;
}

int version_y()
{
    return CONWAY_SEMVER_x;
}

int version_z()
{
    return CONWAY_SEMVER_x;
}

string version_a()
{
    return CONWAY_SEMVER_addendum;
}

string version()
{
    string v("");
    v += to_string(CONWAY_SEMVER_x) + "." + to_string(CONWAY_SEMVER_y) + "." + to_string(CONWAY_SEMVER_z);
    if(CONWAY_SEMVER_addendum.length() != 0)
        v += CONWAY_SEMVER_addendum;
    return v;
}

string compiledate()
{
    return string(__DATE__);
}

void version_info()
{
    cout << "libconway version ";
    cout << version();
    cout << " (using SEMVER)" << endl;
    cout << "Compiled on " << compiledate() << endl;
}

std::string info()
{
    return CONWAY_INFO;
}

std::string license()
{
    return CONWAY_LICENSE;
}

std::string license_info()
{
    return CONWAY_LICENSE_INFO;
}
