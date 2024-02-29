# Wordle
Fully-working clone of NYT Wordle game. Run in two separate executables.
This project was created solo by me near the end of my freshman year of college, as the final project of CSE024 Advanced Programming. It was created entirely from scratch, and took roughly two weeks, working in the background of other assignments.

Each of the two folders contain their own .exe file. Simply run those two files together, and the game will play in the Windows Command Prompt. Only minor changes ought to be required should you desire to play on a different OS.
The two executables will work fine independently, although the keyboard will simply display a message requesting that you launch the game, and I find the game much more difficult without the keyboard to look at.

The /Wordle folder contains all of the game logic, as well as the surrounding infrastructure for the game. It includes a menu, a list of possible correct words, a list of acceptable guesses(the game will refuse if you try to guess 
gibberish in an attempt to eliminate letters optimally). the ability to save stats that persist between runs of the game, the ability to wipe those stats, and of course the game itself, which is, to my knowledge, mechanically identical to the original.

The /Keyboard folder contains both code files and .txt files necessary to display a color-changing keyboard to accompany the game, just as in the original. Whenever an update is made within the game file, it also updates the .txt files which
the keyboard pulls from. Whenever you are in game, the keyboard will be accurate. It is possible to leave a keyboard from a previous game displaying by closing the game via ctrl+c rather than the intended method, but the moment the game is relaunched the
keyboard will catch up again.

Potential bug: upon first downloading the code, attempting to display the stats may cause the game to crash. It is unknown to me why this happens, and it *may* be fixed as of
the latest commit. Resetting the stats fixes this issue, and appears to do so permanently.