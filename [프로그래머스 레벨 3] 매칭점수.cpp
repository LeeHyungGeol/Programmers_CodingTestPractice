// 문자열, 구현, find(str, pos), for(int left=0,right=0; ; ) 문제

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

typedef struct Page {
    int index, basicScore, link;
    double matchingScore;
}Page;

map<string, int> Map;
vector<Page> PageLists;

bool compare(Page& a, Page& b);

int solution(string word, vector<string> pages) {
    int answer = 0;
    int wordLength = word.length();

    transform(word.begin(), word.end(), word.begin(), ::tolower);

    for (int i = 0; i < pages.size(); ++i) {
        string& page = pages[i];

        transform(page.begin(), page.end(), page.begin(), ::tolower);

        string metaTag = "<meta property=\"og:url\" content=\"";

        int left = page.find(metaTag);
        int right = page.find("\"/>", left);
        string url = page.substr(left + metaTag.length(), right - left - metaTag.length());

        left = page.find("<body>", right);
        int basic = 0;
        for (int start = left; ;) {
            start = page.find(word, start + 1);
            if (start == string::npos) {
                break;
            }
            if (!isalpha(page[start - 1]) && !isalpha(page[start + wordLength])) {
                ++basic;
                start += wordLength;
            }
        }

        int links = 0;
        for (int start = left; ;) {
            start = page.find("<a href=\"", start + 1);
            if (start == string::npos) {
                break;
            }
            ++links;
        }

        Map[url] = i;
        PageLists.push_back({ i, basic, links, (double)basic });
    }

    for (int i = 0; i < pages.size(); ++i) {
        string& page = pages[i];

        for (int left = 0, right = 0; ; ) {
            left = page.find("<a href=\"", right);

            if (left == string::npos) {
                break;
            }

            left = page.find("https://", left);
            right = page.find("\"", left);
            string linkUrl = page.substr(left, right - left);

            auto it = Map.find(linkUrl);

            if (it != Map.end()) {
                PageLists[it->second].matchingScore += (double)PageLists[i].basicScore / PageLists[i].link;
            }
        }
    }

    sort(PageLists.begin(), PageLists.end(), compare);

    answer = PageLists[0].index;

    return answer;
}

bool compare(Page& a, Page& b) {
    if (a.matchingScore == b.matchingScore) {
        return a.index < b.index;
    }
    return a.matchingScore > b.matchingScore;
}