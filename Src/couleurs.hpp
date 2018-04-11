#ifndef MMAZE_TERM_COLORS_HPP
#define MMAZE_TERM_COLORS_HPP

#include "RandomUniform.hpp"

namespace MMaze {

  enum Couleur {
    AUCUNE,
    JAUNE,
    VERT,
    ORANGE,
    VIOLET
  } ;

  extern const char* TXT_CLEAR ;
  extern const char* TXT_BOLD ;
  extern const char* TXT_DEFAULT ;
  extern const char* TXT_VIOLET ;
  extern const char* TXT_ORANGE ;
  extern const char* TXT_JAUNE ;
  extern const char* TXT_VERT ;
  extern const char* BG_DEFAULT ;
  extern const char* BG_VIOLET ;
  extern const char* BG_ORANGE ;
  extern const char* BG_JAUNE ;
  extern const char* BG_VERT ;

  extern const char* txt_colors[5] ;
  extern const char* bg_colors[5] ;
  extern Couleur colorsO[5];
  extern Couleur colorsS[5];
  extern int nb_S;
  extern int nb_O;
  extern RandomUniform rd;

} //end of namespace MMaze

#endif
