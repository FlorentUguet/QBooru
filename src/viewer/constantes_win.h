/*
 * constantes_win.h
 *
 * Contains all the absolute and relative paths for the program, if compiled on Windows.
 * It eases the Debug process by allowing the executable to run directly from Qt "Run" option, by having it read the files from any folder.
 *
 * To debug easily, just replace the paths in the "Windows Debug" section with your absolute paths to the file
 */

#ifndef CONSTANTES_WIN
#define CONSTANTES_WIN

#include "constantes.h"

#define OS_ID "Windows"

#if DEBUG
/**Windows Debug**/

        #define CACHE_PATH  "E:/Qbooru/QBooru/cache/"
        #define CONFPATH     "E:/Qbooru/QBooru/conf/"
        #define CONF_FILE    "E:/Qbooru/QBooru/conf/configuration.json"
        #define LOG_FILE    "E:/Qbooru/QBooru/programLog.log"
        #define ICON_PATH "E:/Qbooru/QBooru/conf/defaultDerpibooru.png"

        #define CACHE_PATH_DERPIBOORU    "E:/Qbooru/QBooru/cache/derpibooru/"

        #define CHANGELOG_FILE "E:/Qbooru/QBooru/conf/changelog.txt"
        #define LAST_VERSION_FILE "E:/Qbooru/QBooru/conf/lastVersion.json"

        #define UPDATER_MAIN_EXECUTABLE "E:/Qbooru/QBooru/QBooruUpdater.exe"
        #define LOADING_GIF "E:/Qbooru/QBooru/conf/loader.gif"

        #define BOORU_LIST "E:/Qbooru/QBooru/conf/boorulist.json"

#else
    /**Windows Release**/

        #define CACHE_PATH  "cache/"
        #define CONFPATH     "conf/"
        #define CONF_FILE    "conf/configuration.json"
        #define LOG_FILE    "programLog.log"
        #define ICON_PATH "conf/icon.ico"

        #define CACHE_PATH_DERPIBOORU    "cache/derpibooru/"

        #define CHANGELOG_FILE "conf/changelog.txt"
        #define LAST_VERSION_FILE "conf/lastVersion.json"

        #define UPDATER_MAIN_EXECUTABLE "QBooruUpdater.exe"
        #define LOADING_GIF "/conf/loader.gif"

        #define BOORU_LIST "/conf/boorulist.json"
#endif
#endif // CONSTANTES_WIN

