#include <opencv2/opencv.hpp>
#include <iostream>
#include <regex>

using namespace std;
// All OpenCV classes and functions are in this namespace.
using namespace cv;

int main(int argc, char const *argv[]) {
    // Getting compile time version.
    // The most cross-version method is to use only this "old style" macros.
    cout << "Compile-time:" << endl;
    cout << "\tOpenCV version   : " << CV_VERSION << endl;
    cout << "\tMajor version    : " << CV_MAJOR_VERSION << endl;
    cout << "\tMinor version    : " << CV_MINOR_VERSION << endl;
    cout << "\tSubminor version : " << CV_SUBMINOR_VERSION << endl;
    cout << endl;

    // Getting run time version.
    // Versions prior to 3.4.2 don't have such functions.
    // That's how we check that the compile-time version is greater then "3.4.2".
    cout << "Run-time:" << endl;
#if (CV_MAJOR_VERSION >= 3 && CV_MINOR_VERSION >= 4 && CV_SUBMINOR_VERSION >= 2) || \
    (CV_MAJOR_VERSION >= 3 && CV_MINOR_VERSION >= 5) || \
    (CV_MAJOR_VERSION >= 4)

    cout << "\tOpenCV version   : " << getVersionString() << endl;
    cout << "\tMajor version    : " << getVersionMajor() << endl;
    cout << "\tMinor version    : " << getVersionMinor() << endl;
    cout << "\tRevision version : " << getVersionRevision() << endl;
#else
    cout << "\tNo such functions in this version of library" << endl;
#endif
    cout << endl;

    // Getting build information.
    cout << "Build information:" << endl;
    const string& build_information = getBuildInformation();
    // Beautify the string a bit using regexp.
    cout << regex_replace(build_information, regex("\n"), "\n\t") << endl;

    return 0;
}
