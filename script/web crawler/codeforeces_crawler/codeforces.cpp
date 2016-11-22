//codeforces webcrawler


#include <bits/stdc++.h>
#include <CkSpider.h>
#include <CkStringArray.h>
#include <CkString.h>

using namespace std;

void ChilkatSample(void)
{

	CkSpider spider;
	CkStringArray seedUrls;

	seedUrls.put_Unique(true);
	set<string> ss;
	seedUrls.Append("http://codeforces.com/problemset/tags/math?order=BY_SOLVED_DESC");
	spider.AddMustMatchPattern("*/problemset/tags/*");
	spider.AddAvoidPattern("*/page/*");
	while (seedUrls.get_Count() > 0) 
	{
		//c++;
	    const char * url;
	    url = seedUrls.pop();
	    spider.Initialize(url);
	    int i;
	    bool success;
	    while(1) 
	    {
	        success = spider.CrawlNext();
	        if (success != true)
	            break;
	       	string s=spider.lastUrl();
	       	//cout<<s<<"\n";
	       	int len=s.size();
	       	string str=s.substr(38,s.find("?")-38);
	       	//cout<< str<<"\n";
	        if (ss.find(str)== ss.end()) 
	        {
	        	ss.insert(str);
	        	//cout<<str<<"\n";
	        	str="http://codeforces.com";
	        	str.append(s);
	        	seedUrls.Append(str.c_str());
	            //spider.SleepMs(1000);
	        }
	    }
	}
	for(set<string>:: iterator it=ss.begin();it!=ss.end();it++)
		cout<< *it<<"\n";
};

int main() {
ChilkatSample();
return 0;
}


