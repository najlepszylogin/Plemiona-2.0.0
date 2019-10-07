#pragma once
#define bloczek 219
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77


#define skret_lewo_gora 201
#define skret_prawo_gora 187
#define prosto_dol 186
#define skret_lewo_dol 188
#define skret_prawo_dol 200
#define prosto_bok 205
#define skrzyzowanie 206
#define skrzyzowanie_lewo 185
#define skrzyzowanie_prawo 204
#define skrzyzowanie_gora 202
#define skrzyzowanie_dol 203

//colors//

#define _black 0
#define _white 15
#define _red_ 4
#define _green_ 2
#define _yellow_ 6
#define _blue_ 1
#define _pink_ 5
#define _laz_ 3
#define _white_ 7
#define _gray 8
#define _red 12
#define _green 10
#define _yellow 14
#define _blue 9 
#define _pink 13
#define _laz 11

//map elements//
namespace map
{
	inline char waterch = 176;
	inline char mountainch = 94;
	inline char forestch = 178;
	inline char capitalch = 219;
	inline char grassch = 177;
	inline char riverch = 176;
	inline char playerch = 193;
	inline char blok = bloczek;
	inline char villagerch = 79;
	inline char laborch = 82;
	inline char villagech = 254;
	inline char wioska = 87;
	inline char farmch = 206;
	inline char minech = 88;
	inline char null = ' ';
	inline char millch = 84;

	inline sf::Color grass(0, 255, 0, 255);
	inline sf::Color mountain(125, 125, 125, 255);
	inline sf::Color water(0, 0, 255,255);
	inline sf::Color river(0, 255, 255, 255);
}



