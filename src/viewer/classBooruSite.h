#ifndef CLASSBOORUSITE_H_INCLUDED
#define CLASSBOORUSITE_H_INCLUDED

#include <iostream>
#include "constantes.h"
#include "json/json.h"

#include "./BooruHeaders/boorutaglist.h"

using namespace std;

class BooruTagList;

class BooruSite
{
public:
    BooruSite(string booruName, string booruUrl, int booruType, int booruIndex);
    BooruSite(string booruName, string booruUrl, string downloadPath, int booruType, int booruIndex);
    BooruSite(string booruName, string booruUrl, string searchUrl, string tagUrl, string postIndexUrl, string downloadPath, int booruType, int booruIndex);
    BooruSite(int index);
    BooruSite(Json::Value booru_root);
    BooruSite();
    ~BooruSite();

    Json::Value saveBooruSite(Json::Value root);

    void loadFromJSON(int index);
    void loadFromJSON(Json::Value booru_root);

    void loadTagList();

    /*Getters*/
    bool isTagListToLoad();
    bool isTagListLoaded();
    BooruTagList *getTagList();
    string getName();
    string getTypeString();
    string getBaseUrl();
    string getSearchUrl();
    string getTagUrl();
    string getShowIndexUrl();
    string getCachePath();
    string getDownloadPath();
    string getSearchFilePath();
    string getTagFilePath();
    int getSiteTypeInt();
    int getIndex();

    /*Setters*/
    void setName(string in_name);
    void setBaseUrl(string in_base_url);
    void setSearchUrl(string in_search_url);
    void setTagUrl(string in_tag_url);
    void setShowIndexUrl(string in_show_index_url);
    void setCachePath(string in_cache_path);
    void setDownloadPath(string in_download_path);
    void setSearchFilePath(string in_search_file_path);
    void setTagFilePath(string in_tag_file_path);
    void setSiteType(int type);
    void setIndex(int i);
	
private:
    BooruTagList *tag_list;

    string name;
    string site_type_string;

    string base_url;
    string search_url;
    string tag_url;
    string show_index_url;

    string cache_path;
    string download_path;
    string search_file_path;
    string tag_file_path;

    int siteTypeInt;
    int index;

    bool tag_list_loaded;
    bool tag_list_to_load;
};

#endif
