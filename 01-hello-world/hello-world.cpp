#include <opencv2/opencv.hpp>
#include <iostream>
#include <regex>

int main() {
    // Getting compile time version.
    // The most cross-version method is to use only this "old style" macros.
    std::cout << "Compile-time:" << std::endl;
    std::cout << "\tOpenCV version   : " << CV_VERSION << std::endl;
    std::cout << "\tMajor version    : " << CV_MAJOR_VERSION << std::endl;
    std::cout << "\tMinor version    : " << CV_MINOR_VERSION << std::endl;
    std::cout << "\tSubminor version : " << CV_SUBMINOR_VERSION << std::endl;
    std::cout << std::endl;

    // Getting run time version.
    // Versions prior to 3.4.2 don't have such functions.
    // That's how we check that the compile-time version is greater then "3.4.2".
    std::cout << "Run-time:" << std::endl;
#if (CV_MAJOR_VERSION >= 3 && CV_MINOR_VERSION >= 4 && CV_SUBMINOR_VERSION >= 2) || \
    (CV_MAJOR_VERSION >= 3 && CV_MINOR_VERSION >= 5) || \
    (CV_MAJOR_VERSION >= 4)

    std::cout << "\tOpenCV version   : " << cv::getVersionString() << std::endl;
    std::cout << "\tMajor version    : " << cv::getVersionMajor() << std::endl;
    std::cout << "\tMinor version    : " << cv::getVersionMinor() << std::endl;
    std::cout << "\tRevision version : " << cv::getVersionRevision() << std::endl;
#else
    std::cout << "\tNo such functions in this version of library" << std::endl;
#endif
    std::cout << std::endl;

    // Getting build information.
    std::cout << "Build information:" << std::endl;
    const std::string& build_information = cv::getBuildInformation();
    // Beautify the string a bit using regexp.
    std::cout << regex_replace(build_information, std::regex("\n"), "\n\t") << std::endl;

    return 0;
}
