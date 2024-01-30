#pragma once
class OptionScene
{
public:

	void DrawFrame();
	void OptionText();

	struct OptionDate
	{
     int Option_posX,Option_posY;
	 char OptionItemName[100];
	};

	OptionDate option_date[30]
	{
		{100,200,"BGM"},
		{100,300,"DEGREE OF DIFFICULTY"},
		{100,400,"VOICE"}

	};
	

   




};



