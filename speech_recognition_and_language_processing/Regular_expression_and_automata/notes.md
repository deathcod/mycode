# star is greedy

Suppose you want to use a regex to match an HTML tag. You know that the input will be a valid HTML file, so the regular expression does not need to exclude any invalid use of sharp brackets. If it sits between sharp brackets, it is an HTML tag.

Most people new to regular expressions will attempt to use <.+>. They will be surprised when they test it on a string like This is a <EM>first</EM> test. You might expect the regex to match <EM> and when continuing after that match, </EM>.

But it does not. The regex will match <EM>first</EM>. Obviously not what we wanted. The reason is that the plus is greedy. That is, the plus causes the regex engine to repeat the preceding token as often as possible. Only if that causes the entire regex to fail, will the regex engine backtrack. That is, it will go back to the plus, make it give up the last iteration, and proceed with the remainder of the regex. Let's take a look inside the regex engine to see in detail how this works and why this causes our regex to fail. After that, I will present you with two possible solutions.

Like the plus, the star and the repetition using curly braces are greedy.

# How star is greedy

The first token in the regex is <. This is a literal. As we already know, the first place where it will match is the first < in the string. The next token is the dot, which matches any character except newlines. The dot is repeated by the plus. The plus is greedy. Therefore, the engine will repeat the dot as many times as it can. The dot matches E, so the regex continues to try to match the dot with the next character. M is matched, and the dot is repeated once more. The next character is the >. You should see the problem by now. The dot matches the >, and the engine continues repeating the dot. The dot will match all remaining characters in the string. The dot fails when the engine has reached the void after the end of the string. Only at this point does the regex engine continue with the next token: >.

So far, <.+ has matched <EM>first</EM> test and the engine has arrived at the end of the string. > cannot match here. The engine remembers that the plus has repeated the dot more often than is required. [Remember that the plus requires the dot to match only once.] Rather than admitting failure, the engine will backtrack. It will reduce the repetition of the plus by one, and then continue trying the remainder of the regex.

So the match of .+ is reduced to EM>first</EM> tes. The next token in the regex is still >. But now the next character in the string is the last t. Again, these cannot match, causing the engine to backtrack further. The total match so far is reduced to <EM>first</EM> te. But > still cannot match. So the engine continues backtracking until the match of .+ is reduced to EM>first</EM. Now, > can match the next character in the string. The last token in the regex has been matched. The engine reports that <EM>first</EM> has been successfully matched.

Remember that the regex engine is eager to return a match. It will not continue backtracking further to see if there is another possible match. It will report the first valid match it finds. Because of greediness, this is the leftmost longest match.

____

# My Notes

![note1](https://github.com/deathcod/mycode/blob/master/speech_recognition_and_language_processing/Regular_expression_and_automata/Regular_expression/IMG_20170509_100836.jpg)

![note2](https://github.com/deathcod/mycode/blob/master/speech_recognition_and_language_processing/Regular_expression_and_automata/Regular_expression/IMG_20170509_100853.jpg)

![note3](https://github.com/deathcod/mycode/blob/master/speech_recognition_and_language_processing/Regular_expression_and_automata/Regular_expression/IMG_20170509_100902.jpg)

![note4](https://github.com/deathcod/mycode/blob/master/speech_recognition_and_language_processing/Regular_expression_and_automata/Regular_expression/IMG_20170509_100951.jpg)

![note5](https://github.com/deathcod/mycode/blob/master/speech_recognition_and_language_processing/Regular_expression_and_automata/Regular_expression/IMG_20170509_101009.jpg)

![note6](https://github.com/deathcod/mycode/blob/master/speech_recognition_and_language_processing/Regular_expression_and_automata/Regular_expression/IMG_20170509_101239_1.jpg)


![note9](https://github.com/deathcod/mycode/blob/master/speech_recognition_and_language_processing/Regular_expression_and_automata/Regular_expression/IMG_20170509_101539.jpg)

![note9](https://github.com/deathcod/mycode/blob/master/speech_recognition_and_language_processing/Regular_expression_and_automata/Regular_expression/IMG_20170509_101637_1.jpg)
