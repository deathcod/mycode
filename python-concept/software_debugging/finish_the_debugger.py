#
# Finish the delta debug function ddmin
#


import re

def test(s):
    print s, len(s)
    if re.search("<SELECT[^>]*>", s) >= 0:
        return "FAIL"
    else:
        return "PASS"


def ddmin(s):
    assert test(s) == "FAIL"

    n = 2     # Initial granularity
    while len(s) >= 2:
        start = 0
        subset_length = len(s) / n
        some_complement_is_failing = False

        while start+subset_length < len(s)-1:
            start += subset_length
            complement1 = s[:start]
            complement2 = s[start:]
            #print "------------", s[:start] , s[start :], start , subset_length,n
            x = test(complement1) == "FAIL"
            y = test(complement2) == "FAIL"
            if x or y :
                #print "========="
                s = complement1 if x else complement2
                #print n,n-1,2
                n = max(n - 1, 2)
                
                some_complement_is_failing = True
                break
                

        if not some_complement_is_failing:
            if len(s) == n:
                break
            n = min(len(s),2*n)
            pass
            # YOUR CODE HERE
    return s

# UNCOMMENT TO TEST
html_input = '\n<td align=left valign=top>\n<SELECT NAME="op_sys" MULTIPLE SIZE=7>\n<OPTION VALUE="All">All<OPTION VALUE="Windows 3.1">Windows 3.1<OPTION\nVALUE="Windows 95">Windows 95<OPTION VALUE="Windows 98">Windows 98<OPTION\nVALUE="Windows ME">Windows ME<OPTION VALUE="Windows 2000">Windows\n2000<OPTION VALUE="Windows NT">Windows NT<OPTION VALUE="Mac System 7">Mac\nSystem 7<OPTION VALUE="Mac System 7.5">Mac System 7.5<OPTION VALUE="Mac\nSystem 7.6.1">Mac System 7.6.1<OPTION VALUE="Mac System 8.0">Mac System\n8.0<OPTION VALUE="Mac System 8.5">Mac System 8.5<OPTION VALUE="Mac\nSystem 8.6">Mac System 8.6<OPTION VALUE="Mac System 9.x">Mac System\n9.x<OPTION VALUE="MacOS X">MacOS X<OPTION VALUE="Linux">Linux<OPTION\nVALUE="BSDI">BSDI<OPTION VALUE="FreeBSD">FreeBSD<OPTION\nVALUE="NetBSD">NetBSD<OPTION VALUE="OpenBSD">OpenBSD<OPTION\nVALUE="AIX">AIX<OPTION VALUE="BeOS">BeOS<OPTION VALUE="HP-UX">HP-UX<OPTION\nVALUE="IRIX">IRIX<OPTION VALUE="Neutrino">Neutrino<OPTION\nVALUE="OpenVMS">OpenVMS<OPTION VALUE="OS/2">OS/2<OPTION\nVALUE="OSF/1">OSF/1<OPTION VALUE="Solaris">Solaris<OPTION\nVALUE="SunOS">SunOS<OPTION VALUE="other">other</SELECT>\n</td>\n<td align=left valign=top>\n<SELECT NAME="priority" MULTIPLE SIZE=7>\n<OPTION VALUE="-">-<OPTION VALUE="P1">P1<OPTION VALUE="P2">P2<OPTION\nVALUE="P3">P3<OPTION VALUE="P4">P4<OPTION VALUE="P5">P5</SELECT>\n</td>\n<td align=left valign=top>\n<SELECT NAME="bug_severity" MULTIPLE SIZE=7>\n<OPTION VALUE="blocker">blocker<OPTION VALUE="critical">critical<OPTION\nVALUE="major">major<OPTION VALUE="normal">normal<OPTION\nVALUE="minor">minor<OPTION VALUE="trivial">trivial<OPTION\nVALUE="enhancement">enhancement</SELECT>\n</tr>\n</table>\n'
print ddmin(html_input)