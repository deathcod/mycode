### 2.1
1) set of alphabet using strings
```[A-Za-z]+```

2) the set of all lower case aplhabetic strings ending in a b.
```[a-z]+b```

3) the set of all strings with two consecutive repeated words (Humbert Humbert or the the)
```([a-z]*) \1```

7) Write a pattern that places the first word of an English sentence in a register.
```^[A-Z]|\. ?([A-Z])```


### 2.3 
Complete the FSA for English money expressions in Fig. 2.15 as suggested in the
text following the figure. You should handle amounts up to $100,000, and make
sure that “cent” and “dollar” have the proper plural endings when appropriate.

![2.3](https://github.com/deathcod/mycode/blob/master/speech_recognition_and_language_processing/Regular_expression_and_automata/Regular_expression/IMG_20170510_153059.jpg)

### 2.4
Design an FSA that recognizes simple date expressions like March 15, the 22nd
of November, Christmas. You should try to include all such “absolute” dates
(e.g., not “deictic” ones relative to the current day, like the day before yesterday).
Each edge of the graph should have a word or a set of words on it. You should
use some sort of shorthand for classes of words to avoid drawing too many arcs
(e.g., furniture → desk, chair, table).


![2.4](https://github.com/deathcod/mycode/blob/master/speech_recognition_and_language_processing/Regular_expression_and_automata/Regular_expression/IMG_20170510_155703.jpg)

### 2.9
Currently the function D - RECOGNIZE in Fig. 2.12 solves only a subpart of the
important problem of finding a string in some text. Extend the algorithm to solve
the following two deficiencies: (1) D - RECOGNIZE currently assumes that it is
already pointing at the string to be checked, and (2) D - RECOGNIZE fails if the
string it is pointing to includes as a proper substring a legal string for the FSA.
That is, D - RECOGNIZE fails if there is an extra character at the end of the string.
To address these problems, we will have to try to match our FSA at
each point in the tape, and we will have to accept (the current sub-
string) any time we reach an accept state. The former requires an additional outer loop, and the latter requires a slightly different struc-
ture for our case statements:
![2.9](https://github.com/deathcod/mycode/blob/master/speech_recognition_and_language_processing/Regular_expression_and_automata/Regular_expression/IMG_20170511_062058.jpg)
