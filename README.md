# Frequency Count

A C++ program to experiment with some of the features of `std::map` and `std::multimap`.

The code manipulates some arrays and strings to calculate the frequency of the elements they contain.

## Program Output
```
"Alan" "Bobby" "Bobby" "Bobby" "Alan" 
'Alan'   2
'Bobby'   3

'0' '0' '3' '4' '4' '4' '6' '0' '1' '4' 
'0'   3
'1'   1
'3'   1
'4'   4
'6'   1

"the quick brown fox jumps over a lazy dog"
' '   8
'a'   2
'b'   1
'c'   1
'd'   1
'e'   2
'f'   1
'g'   1
'h'   1
'i'   1
'j'   1
'k'   1
'l'   1
'm'   1
'n'   1
'o'   4
'p'   1
'q'   1
'r'   2
's'   1
't'   1
'u'   2
'v'   1
'w'   1
'x'   1
'y'   1
'z'   1

Henry V, Prologue. Letter Frequencies
"
O for a Muse of fire, that would ascend
The brightest heaven of invention,
A kingdom for a stage, princes to act
And monarchs to behold the swelling scene!
Then should the warlike Harry, like himself,
Assume the port of Mars; and at his heels,
Leash'd in like hounds, should famine, sword and fire
Crouch for employment. But pardon, and gentles all,
The flat unraised spirits that have dared
On this unworthy scaffold to bring forth
So great an object: can this cockpit hold
The vasty fields of France? or may we cram
Within this wooden O the very casques
That did affright the air at Agincourt?
O, pardon! since a crooked figure may
Attest in little place a million;
And let us, ciphers to this great accompt,
On your imaginary forces work.
Suppose within the girdle of these walls
Are now confined two mighty monarchies,
Whose high upreared and abutting fronts
The perilous narrow ocean parts asunder:
Piece out our imperfections with your thoughts;
Into a thousand parts divide on man,
And make imaginary puissance;
Think when we talk of horses, that you see them
Printing their proud hoofs i' the receiving earth;
For 'tis your thoughts that now must deck our kings,
Carry them here and there; jumping o'er times,
Turning the accomplishment of many years
Into an hour-glass: for the which supply,
Admit me Chorus to this history;
Who prologue-like your humble patience pray,
Gently to hear, kindly to judge, our play.
"

 In collating sequence order.
' ' 211
'!'   2
'''   4
','  22
'-'   2
'.'   3
':'   3
';'   7
'?'   2
'A'   9
'B'   1
'C'   3
'F'   2
'G'   1
'H'   1
'I'   2
'L'   1
'M'   2
'O'   5
'P'   2
'S'   2
'T'   8
'W'   3
'a'  78
'b'   6
'c'  34
'd'  41
'e' 111
'f'  28
'g'  27
'h'  75
'i'  78
'j'   3
'k'  14
'l'  39
'm'  30
'n'  75
'o'  89
'p'  27
'q'   1
'r'  80
's'  69
't'  94
'u'  42
'v'   7
'w'  18
'y'  24

--------------------------------------------------------------------------------
 Ignore case
' ' 211
'!'   2
'''   4
','  22
'-'   2
'.'   3
':'   3
';'   7
'?'   2
'a'  87
'b'   7
'c'  37
'd'  41
'e' 111
'f'  30
'g'  28
'h'  76
'i'  80
'j'   3
'k'  14
'l'  40
'm'  32
'n'  75
'o'  94
'p'  29
'q'   1
'r'  80
's'  71
't' 102
'u'  42
'v'   7
'w'  21
'y'  24

--------------------------------------------------------------------------------
 Remove non-alphabetic chars.
'a'  87
'b'   7
'c'  37
'd'  41
'e' 111
'f'  30
'g'  28
'h'  76
'i'  80
'j'   3
'k'  14
'l'  40
'm'  32
'n'  75
'o'  94
'p'  29
'q'   1
'r'  80
's'  71
't' 102
'u'  42
'v'   7
'w'  21
'y'  24

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 Show letter frequencies in descending order
  111 'e'
  102 't'
   94 'o'
   87 'a'
   80 'i'
   80 'r'
   76 'h'
   75 'n'
   71 's'
   42 'u'
   41 'd'
   40 'l'
   37 'c'
   32 'm'
   30 'f'
   29 'p'
   28 'g'
   24 'y'
   21 'w'
   14 'k'
    7 'b'
    7 'v'
    3 'j'
    1 'q'

 Including punctuation
  211 ' '
  111 'e'
  102 't'
   94 'o'
   87 'a'
   80 'i'
   80 'r'
   76 'h'
   75 'n'
   71 's'
   42 'u'
   41 'd'
   40 'l'
   37 'c'
   32 'm'
   30 'f'
   29 'p'
   28 'g'
   24 'y'
   22 ','
   21 'w'
   14 'k'
    7 ';'
    7 'b'
    7 'v'
    4 '''
    3 '.'
    3 ':'
    3 'j'
    2 '!'
    2 '-'
    2 '?'
    1 'q'
```
