// Created by http://oleddisplay.squix.ch/ Consider a donation
// In case of problems make sure that you are using the font file with the correct version!
const uint8_t DSEG14_Classic_Bold_5Bitmaps[] PROGMEM = {

  // Bitmap Data:
  0x00, // ' '
  0x00, // '!'
  0x00, // '"'
  0xDB,0x60, // '#'
  0xC0,0xC2,0xE0, // '$'
  0x0C,0xCE,0x20, // '%'
  0xCC,0x0E,0xE0, // '&'
  0x00, // '''
  0x88, // '('
  0x88, // ')'
  0xDB,0x00, // '*'
  0x18,0x00, // '+'
  0x80, // ','
  0xC0, // '-'
  0x00, // '.'
  0x42,0x00, // '/'
  0xEA,0xAA,0xE0, // '0'
  0xAA,0x80, // '1'
  0xE2,0xE8,0xE0, // '2'
  0xE2,0xE2,0xE0, // '3'
  0xAA,0xe2,0x20, // '4'
  0xE8,0xE2,0xE0, // '5'
  0xE8,0xEA,0xE0, // '6'
  0xE2,0x22,0x20, // '7'
  0xEA,0xEA,0xE0, // '8'
  0xEA,0xE2,0xE0, // '9'
  0x88, // ':'
  0xDB,0x60, // ';'
  0x42,0x60, // '<'
  0xC3,0x00, // '='
  0x81,0x60, // '>'
  0xE2,0x40, // '?'
  0xE2,0x42,0xE0, // '@'
  0xE2,0xC2,0x20, // 'A'
  0xE2,0x42,0xE0, // 'B'
  0xC0,0x0C, // 'C'
  0xE2,0x02,0xE0, // 'D'
  0xC3,0x0C, // 'E'
  0xC3,0x00, // 'F'
  0xC0,0x42,0xE0, // 'G'
  0x22,0xC2,0x20, // 'H'
  0xC0,0x0C, // 'I'
  0x22,0x02,0xE0, // 'J'
  0x0A,0x20, // 'K'
  0x00,0x0C, // 'L'
  0x2E,0x02,0x20, // 'M'
  0x2A,0x06,0x20, // 'N'
  0xE2,0x02,0xE0, // 'O'
  0xE2,0xC0,0x00, // 'P'
  0xE2,0x06,0xE0, // 'Q'
  0xE2,0xC4,0x00, // 'R'
  0xC8,0xC6,0xE0, // 'S'
  0xC0,0x00, // 'T'
  0x22,0x02,0xE0, // 'U'
  0x08,0x40, // 'V'
  0x22,0x0E,0x20, // 'W'
  0xC3,0x00, // 'X'
  0xC0,0x00, // 'Y'
  0xC8,0x4C, // 'Z'
  0xDB,0x60, // '['
  0x81,0x00, // '\'
  0xDB,0x60, // ']'
  0x20, // '^'
  0xC0, // '_'
  0x80, // '`'
  0xE2,0xC2,0x20, // 'a'
  0xE2,0x42,0xE0, // 'b'
  0xC0,0x0C, // 'c'
  0xE2,0x02,0xE0, // 'd'
  0xC3,0x0C, // 'e'
  0xC3,0x00, // 'f'
  0xC0,0x42,0xE0, // 'g'
  0x22,0xC2,0x20, // 'h'
  0xC0,0x0C, // 'i'
  0x22,0x02,0xE0, // 'j'
  0x0A,0x20, // 'k'
  0x00,0x0C, // 'l'
  0x2E,0x02,0x20, // 'm'
  0x2A,0x06,0x20, // 'n'
  0xE2,0x02,0xE0, // 'o'
  0xE2,0xC0,0x00, // 'p'
  0xE2,0x06,0xE0, // 'q'
  0xE2,0xC4,0x00, // 'r'
  0xC8,0xC6,0xE0, // 's'
  0xC0,0x00, // 't'
  0x22,0x02,0xE0, // 'u'
  0x08,0x40, // 'v'
  0x22,0x0E,0x20, // 'w'
  0xC3,0x00, // 'x'
  0xC0,0x00, // 'y'
  0xC8,0x4C, // 'z'
  0xDB,0x60, // '{'
  0x00,0x00, // '|'
  0xDB,0x60 // '}'
};
const GFXglyph DSEG14_Classic_Bold_5Glyphs[] PROGMEM = {
// bitmapOffset, width, height, xAdvance, xOffset, yOffset
    {     0,   1,   1,   2,    0,    0 }, // ' '
    {     1,   1,   1,   5,    0,    0 }, // '!'
    {     2,   2,   2,   5,    1,   -5 }, // '"'
    {     3,   3,   4,   3,    0,   -4 }, // '#'
    {     5,   4,   5,   5,    1,   -5 }, // '$'
    {     8,   4,   5,   5,    1,   -5 }, // '%'
    {    11,   4,   5,   5,    1,   -5 }, // '&'
    {    14,   3,   1,   5,    1,   -4 }, // '''
    {    15,   2,   3,   5,    2,   -4 }, // '('
    {    16,   2,   3,   5,    1,   -4 }, // ')'
    {    17,   3,   3,   5,    1,   -4 }, // '*'
    {    19,   3,   3,   5,    1,   -4 }, // '+'
    {    21,   2,   1,   5,    1,   -2 }, // ','
    {    22,   3,   1,   5,    1,   -3 }, // '-'
    {    23,   3,   1,   1,   -1,   -1 }, // '.'
    {    24,   3,   3,   5,    1,   -4 }, // '/'
    {    26,   4,   5,   5,    1,   -5 }, // '0'
    {    29,   2,   5,   5,    3,   -5 }, // '1'
    {    31,   4,   5,   5,    1,   -5 }, // '2'
    {    34,   4,   5,   5,    1,   -5 }, // '3'
    {    37,   4,   5,   5,    1,   -5 }, // '4'
    {    40,   4,   5,   5,    1,   -5 }, // '5'
    {    43,   4,   5,   5,    1,   -5 }, // '6'
    {    46,   4,   5,   5,    1,   -5 }, // '7'
    {    49,   4,   5,   5,    1,   -5 }, // '8'
    {    52,   4,   5,   5,    1,   -5 }, // '9'
    {    55,   2,   3,   2,    0,   -4 }, // ':'
    {    56,   3,   4,   3,    0,   -4 }, // ';'
    {    58,   3,   4,   5,    1,   -4 }, // '<'
    {    60,   3,   3,   5,    1,   -3 }, // '='
    {    62,   3,   4,   5,    1,   -4 }, // '>'
    {    64,   4,   4,   5,    1,   -5 }, // '?'
    {    66,   4,   5,   5,    1,   -5 }, // '@'
    {    69,   4,   5,   5,    1,   -5 }, // 'A'
    {    72,   4,   5,   5,    1,   -5 }, // 'B'
    {    75,   3,   5,   5,    1,   -5 }, // 'C'
    {    77,   4,   5,   5,    1,   -5 }, // 'D'
    {    80,   3,   5,   5,    1,   -5 }, // 'E'
    {    82,   3,   5,   5,    1,   -5 }, // 'F'
    {    84,   4,   5,   5,    1,   -5 }, // 'G'
    {    87,   4,   5,   5,    1,   -5 }, // 'H'
    {    90,   3,   5,   5,    1,   -5 }, // 'I'
    {    92,   4,   5,   5,    1,   -5 }, // 'J'
    {    95,   3,   5,   5,    1,   -5 }, // 'K'
    {    97,   3,   5,   5,    1,   -5 }, // 'L'
    {    99,   4,   5,   5,    1,   -5 }, // 'M'
    {   102,   4,   5,   5,    1,   -5 }, // 'N'
    {   105,   4,   5,   5,    1,   -5 }, // 'O'
    {   108,   4,   5,   5,    1,   -5 }, // 'P'
    {   111,   4,   5,   5,    1,   -5 }, // 'Q'
    {   114,   4,   5,   5,    1,   -5 }, // 'R'
    {   117,   4,   5,   5,    1,   -5 }, // 'S'
    {   120,   3,   4,   5,    1,   -5 }, // 'T'
    {   122,   4,   5,   5,    1,   -5 }, // 'U'
    {   125,   3,   5,   5,    1,   -5 }, // 'V'
    {   127,   4,   5,   5,    1,   -5 }, // 'W'
    {   130,   3,   3,   5,    1,   -4 }, // 'X'
    {   132,   3,   3,   5,    1,   -4 }, // 'Y'
    {   134,   3,   5,   5,    1,   -5 }, // 'Z'
    {   136,   3,   4,   3,    0,   -4 }, // '['
    {   138,   3,   3,   5,    1,   -4 }, // '\'
    {   140,   3,   4,   3,    0,   -4 }, // ']'
    {   142,   2,   2,   5,    1,   -5 }, // '^'
    {   143,   3,   1,   5,    1,   -1 }, // '_'
    {   144,   2,   1,   5,    1,   -4 }, // '`'
    {   145,   4,   5,   5,    1,   -5 }, // 'a'
    {   148,   4,   5,   5,    1,   -5 }, // 'b'
    {   151,   3,   5,   5,    1,   -5 }, // 'c'
    {   153,   4,   5,   5,    1,   -5 }, // 'd'
    {   156,   3,   5,   5,    1,   -5 }, // 'e'
    {   158,   3,   5,   5,    1,   -5 }, // 'f'
    {   160,   4,   5,   5,    1,   -5 }, // 'g'
    {   163,   4,   5,   5,    1,   -5 }, // 'h'
    {   166,   3,   5,   5,    1,   -5 }, // 'i'
    {   168,   4,   5,   5,    1,   -5 }, // 'j'
    {   171,   3,   5,   5,    1,   -5 }, // 'k'
    {   173,   3,   5,   5,    1,   -5 }, // 'l'
    {   175,   4,   5,   5,    1,   -5 }, // 'm'
    {   178,   4,   5,   5,    1,   -5 }, // 'n'
    {   181,   4,   5,   5,    1,   -5 }, // 'o'
    {   184,   4,   5,   5,    1,   -5 }, // 'p'
    {   187,   4,   5,   5,    1,   -5 }, // 'q'
    {   190,   4,   5,   5,    1,   -5 }, // 'r'
    {   193,   4,   5,   5,    1,   -5 }, // 's'
    {   196,   3,   4,   5,    1,   -5 }, // 't'
    {   198,   4,   5,   5,    1,   -5 }, // 'u'
    {   201,   3,   5,   5,    1,   -5 }, // 'v'
    {   203,   4,   5,   5,    1,   -5 }, // 'w'
    {   206,   3,   3,   5,    1,   -4 }, // 'x'
    {   208,   3,   3,   5,    1,   -4 }, // 'y'
    {   210,   3,   5,   5,    1,   -5 }, // 'z'
    {   212,   3,   4,   3,    0,   -4 }, // '{'
    {   214,   3,   3,   5,    1,   -4 }, // '|'
    {   216,   3,   4,   3,    0,   -4 } // '}'
};
const GFXfont DSEG14_Classic_Bold_5 PROGMEM = {
(uint8_t  *)DSEG14_Classic_Bold_5Bitmaps,(GFXglyph *)DSEG14_Classic_Bold_5Glyphs,0x20, 0x7E, 6};
