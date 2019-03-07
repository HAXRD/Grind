# Linux
## Movement
C-v: move forward one sceen
M-v: move backward one screen

C-p: previous line 
C-n: next line 
C-f: forward
C-b: backward

M-f: forward a word
M-b: backward a word 

C-a: move to the beginning of a line
C-e: move to the end of a line
M-a: move to the beginning of a sentence
M-e: move to the end of a sentence

M-<: move to the beginning of the text
M->: move to the end of the text

C-l: clear screen and redisplay all the text

C-u <Number> <Operation>: repeatedly run <Operation>
C-g: to stop a command

## Delete and Yank
<DEL>: delete the character before the cursor
C-d: delete the next character after the cursor

M-<DEL>: kill the word before the cursor
M-d: kill the word after the cursor

C-k: kill from the cursor position to end of line
M-k: kill to the end of the current sentence

### Kill a segment of text
C-<SPC>: start anchor
C-<SPC>: end anchor
C-w: kill the segment

### Reinsert
C-y: yank the killed text
M-y: yank earlier and earlier kills

## Undo
C-/ or C-_ or C-x u: undo

## File 
C-x C-f: find a file
C-x C-s: save the file

## Buffers
Emacs can store a number of files
C-x C-b: list buffers
C-x b BUFFERNAME: switch buffer
C-x s: save the current buffer

## Searching
C-s: forward search 
C-r: reverse search

## Multiwindows
C-x 2: splits the screen into two windows
C-x o: move cursor into another window
C-M-v: scroll the other window

## Multiple Frames
M-x make-frame

M-x delte-frame