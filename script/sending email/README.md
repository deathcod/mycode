#### This is an updated implementation of message send by gmail

The purpose of this implementation is solely to automate the application to companies for job or internship. So for that I have 
gathered a list of around 200 such companies HR emails .

#### procedure to install and use

 * first of all check if the pip version is 8.1.2 or 9.1.0 (reason 8.1.2 is for py2 and 9.1.0 is py3 and google-client-api is tested to work well in py2)
 
 * to install pip2 follow:
 ```sh
 wget --no-check-certificate http://pypi.python.org/packages/source/d/distribute/distribute-0.6.35.tar.gz
tar xf distribute-0.6.35.tar.gz
cd distribute-0.6.35
python2.7 setup.py install

easy_install-2.7 pip
```
 * to install google api client 
 ```sh 
 pip install --upgrade google-api-python-client 
 ```
 
 * a) Use [this wizard](https://console.developers.google.com/start/api?id=gmail) to create or select a project in the Google  Developers Console and automatically turn on the API. Click **Continue**, then **Go to credentials**.  
 b) On the **Add credentials to your project page**, click the **Cancel** button.  
 c) At the top of the page, select the **OAuth consent screen** tab. Select an **Email address**, enter a **Product name** if not already set, and click the **Save** button.  
 d) Select the **Credentials** tab, click the **Create credentials** button and select **OAuth client ID**.  
 e) Select the application type **Other**, enter the name "Gmail API Quickstart", and click the **Create** button.  
 f) Click **OK** to dismiss the resulting dialog.  
 g) Click the file_download (Download JSON) button to the right of the client ID.  
 h) Move this file to your working directory and rename it **client_secret.json**.   

 * Now run automated_emails.py

Please do contribute to the HR_emails :)
