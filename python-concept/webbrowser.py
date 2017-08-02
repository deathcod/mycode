import urllib
import webbrowser
url='http://docs.python.org/'
#webbrowser.open_new_tab(url)
#webbrowser.open_new(url)

x=webbrowser.get(using='google-chrome')
x.open(url,new=2,autoraise=False)
'''
controller is provided to specifiy which browser we want 
to use
'''

webbrowser.open(url,new=2,autoraise=False)
"""
new =0: open in same window
new =1: open in new browser(if possible)
new =2: open in new browser page("tab")
autoraise=True,window is raised if possible.
i tried in firefox it is auto it will be done irrespective
"""


"""
now i tried to implement in commandline ,and it worked
so the code is as followed and you just have
to paste in the command line...

python -m webbrowser -t "http://www.python.org"

-n:opens the URL in new browser window
-t:opens the URL in new browser page(tab)
"""

