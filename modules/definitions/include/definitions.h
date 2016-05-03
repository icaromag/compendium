#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define WINDOWS (defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64))
#define LINUX (defined(unix) || defined(__unix__))

#if (WINDOWS)
    #define popen std::_popen
    #define pclose std::_pclose
    #define ls "dir /b"
#endif /* WINDOWS */

#if (LINUX)
    #define ls "ls -lah"
#endif /* LINUX */

#endif /* DEFINITIONS_H */
