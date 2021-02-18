#  TEXT.AI app
TEXT.AI is a Dev Incubator base task.
It consist from two parts:
- Anti-Plagiarism algorithm, that implemented with <b>C++</b>
- Layout representation implemented with <b>HTML/CSS/JS</b>

#  Anti-Plagiarism algorithm
Main Anti-Plagiarism function gets examples of <b>text</b>, holded in <b>db.txt</b> file and <b>fragment</b>  inputed in  textarea.

Before final check, algorithm transform inputed text to make correct character comparison - removes extra spaces, convert to lower cases.
After that main algorithm makes <b>text</b> words comparison with defined word amount(3) trough repeated loops and increasing originality counted.

Final result is percentage of originality

# Layout representation
HTML/CSS layout receives result of anti-Plagiarism function and represent it with stylistic result generation.

## Deploy Link
[My implementation](http://35.194.12.133:8080/)